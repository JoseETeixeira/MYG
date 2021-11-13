/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

WI.DOMNodeStyles = class DOMNodeStyles extends WI.Object
{
    constructor(node)
    {
        super();

        console.assert(node);
        this._node = node || null;

        this._rulesMap = new Map;
        this._stylesMap = new Multimap;

        this._matchedRules = [];
        this._inheritedRules = [];
        this._pseudoElements = new Map;
        this._inlineStyle = null;
        this._attributesStyle = null;
        this._computedStyle = null;
        this._orderedStyles = [];

        this._propertyNameToEffectivePropertyMap = {};

        this._pendingRefreshTask = null;
        this.refresh();
    }

    // Static

    static parseSelectorListPayload(selectorList)
    {
        let selectors = selectorList.selectors;
        if (!selectors.length)
            return [];

        // COMPATIBILITY (iOS 8): The selectorList payload was an array of selector text strings.
        // Now they are CSSSelector objects with multiple properties.
        if (typeof selectors[0] === "string") {
            return selectors.map(function(selectorText) {
                return new WI.CSSSelector(selectorText);
            });
        }

        return selectors.map(function(selectorPayload) {
            return new WI.CSSSelector(selectorPayload.text, selectorPayload.specificity, selectorPayload.dynamic);
        });
    }

    static createSourceCodeLocation(sourceURL, {line, column, documentNode} = {})
    {
        if (!sourceURL)
            return null;

        let sourceCode = null;

        // Try to use the node to find the frame which has the correct resource first.
        if (documentNode) {
            let mainResource = WI.networkManager.resourceForURL(documentNode.documentURL);
            if (mainResource) {
                let parentFrame = mainResource.parentFrame;
                sourceCode = parentFrame.resourceForURL(sourceURL);
            }
        }

        // If that didn't find the resource, then search all frames.
        if (!sourceCode)
            sourceCode = WI.networkManager.resourceForURL(sourceURL);

        if (!sourceCode)
            return null;

        return sourceCode.createSourceCodeLocation(line || 0, column || 0);
    }

    static uniqueOrderedStyles(orderedStyles)
    {
        let uniqueOrderedStyles = [];

        for (let style of orderedStyles) {
            let rule = style.ownerRule;
            if (!rule) {
                uniqueOrderedStyles.push(style);
                continue;
            }

            let found = false;
            for (let existingStyle of uniqueOrderedStyles) {
                if (rule.isEqualTo(existingStyle.ownerRule)) {
                    found = true;
                    break;
                }
            }
            if (!found)
                uniqueOrderedStyles.push(style);
        }

        return uniqueOrderedStyles;
    }

    // Public

    get node()
    {
        return this._node;
    }

    get needsRefresh()
    {
        return this._pendingRefreshTask || this._needsRefresh;
    }

    refreshIfNeeded()
    {
        if (this._pendingRefreshTask)
            return this._pendingRefreshTask;
        if (!this._needsRefresh)
            return Promise.resolve(this);
        return this.refresh();
    }

    refresh()
    {
        if (this._pendingRefreshTask)
            return this._pendingRefreshTask;

        this._needsRefresh = false;

        let previousStylesMap = this._stylesMap.copy();

        let fetchedMatchedStylesPromise = new WI.WrappedPromise;
        let fetchedInlineStylesPromise = new WI.WrappedPromise;
        let fetchedComputedStylesPromise = new WI.WrappedPromise;

        // Ensure we resolve these promises even in the case of an error.
        function wrap(func, promise) {
            return (...args) => {
                try {
                    func.apply(this, args);
                } catch (e) {
                    console.error(e);
                    promise.resolve();
                }
            };
        }

        let parseRuleMatchArrayPayload = (matchArray, node, inherited, pseudoId) => {
            var result = [];

            // Iterate in reverse order to match the cascade order.
            var ruleOccurrences = {};
            for (var i = matchArray.length - 1; i >= 0; --i) {
                var rule = this._parseRulePayload(matchArray[i].rule, matchArray[i].matchingSelectors, node, inherited, pseudoId, ruleOccurrences);
                if (!rule)
                    continue;
                result.push(rule);
            }

            return result;
        };

        function fetchedMatchedStyles(error, matchedRulesPayload, pseudoElementRulesPayload, inheritedRulesPayload)
        {
            matchedRulesPayload = matchedRulesPayload || [];
            pseudoElementRulesPayload = pseudoElementRulesPayload || [];
            inheritedRulesPayload = inheritedRulesPayload || [];

            this._matchedRules = parseRuleMatchArrayPayload(matchedRulesPayload, this._node);

            this._pseudoElements.clear();
            for (let {pseudoId, matches} of pseudoElementRulesPayload) {
                let pseudoElementRules = parseRuleMatchArrayPayload(matches, this._node, false, pseudoId);
                this._pseudoElements.set(pseudoId, {matchedRules: pseudoElementRules});
            }

            this._inheritedRules = [];

            var i = 0;
            var currentNode = this._node.parentNode;
            while (currentNode && i < inheritedRulesPayload.length) {
                var inheritedRulePayload = inheritedRulesPayload[i];

                var inheritedRuleInfo = {node: currentNode};
                inheritedRuleInfo.inlineStyle = inheritedRulePayload.inlineStyle ? this._parseStyleDeclarationPayload(inheritedRulePayload.inlineStyle, currentNode, true, null, WI.CSSStyleDeclaration.Type.Inline) : null;
                inheritedRuleInfo.matchedRules = inheritedRulePayload.matchedCSSRules ? parseRuleMatchArrayPayload(inheritedRulePayload.matchedCSSRules, currentNode, true) : [];

                if (inheritedRuleInfo.inlineStyle || inheritedRuleInfo.matchedRules.length)
                    this._inheritedRules.push(inheritedRuleInfo);

                currentNode = currentNode.parentNode;
                ++i;
            }

            fetchedMatchedStylesPromise.resolve();
        }

        function fetchedInlineStyles(error, inlineStylePayload, attributesStylePayload)
        {
            this._inlineStyle = inlineStylePayload ? this._parseStyleDeclarationPayload(inlineStylePayload, this._node, false, null, WI.CSSStyleDeclaration.Type.Inline) : null;
            this._attributesStyle = attributesStylePayload ? this._parseStyleDeclarationPayload(attributesStylePayload, this._node, false, null, WI.CSSStyleDeclaration.Type.Attribute) : null;

            this._updateStyleCascade();

            fetchedInlineStylesPromise.resolve();
        }

        function fetchedComputedStyle(error, computedPropertiesPayload)
        {
            var properties = [];
            for (var i = 0; computedPropertiesPayload && i < computedPropertiesPayload.length; ++i) {
                var propertyPayload = computedPropertiesPayload[i];

                var canonicalName = WI.cssManager.canonicalNameForPropertyName(propertyPayload.name);
                propertyPayload.implicit = !this._propertyNameToEffectivePropertyMap[canonicalName];

                var property = this._parseStylePropertyPayload(propertyPayload, NaN, this._computedStyle);
                if (!property.implicit)
                    property.implicit = !this._isPropertyFoundInMatchingRules(property.name);
                properties.push(property);
            }

            if (this._computedStyle)
                this._computedStyle.update(null, properties);
            else
                this._computedStyle = new WI.CSSStyleDeclaration(this, null, null, WI.CSSStyleDeclaration.Type.Computed, this._node, false, null, properties);

            let significantChange = false;
            for (let [key, styles] of this._stylesMap.sets()) {
                let previousStyles = previousStylesMap.get(key);
                if (previousStyles) {
                    // Some styles have selectors such that they will match with the DOM node twice (for example "::before, ::after").
                    // In this case a second style for a second matching may be generated and added which will cause the shallowEqual
                    // to not return true, so in this case we just want to ensure that all the current styles existed previously.
                    let styleFound = false;
                    for (let style of styles) {
                        if (previousStyles.has(style)) {
                            styleFound = true;
                            break;
                        }
                    }

                    if (styleFound)
                        continue;
                }

                if (!this._includeUserAgentRulesOnNextRefresh) {
                    // We can assume all the styles with the same key are from the same stylesheet and rule, so we only check the first.
                    let firstStyle = styles.firstValue;
                    if (firstStyle && firstStyle.ownerRule && firstStyle.ownerRule.type === WI.CSSStyleSheet.Type.UserAgent) {
                        // User Agent styles get different identifiers after some edits. This would cause us to fire a significant refreshed
                        // event more than it is helpful. And since the user agent stylesheet is static it shouldn't match differently
                        // between refreshes for the same node. This issue is tracked by: https://webkit.org/b/110055
                        continue;
                    }
                }

                // This key is new or has different style objects than before. This is a significant change.
                significantChange = true;
                break;
            }

            if (!significantChange) {
                for (let [key, previousStyles] of previousStylesMap.sets()) {
                    // Check if the same key exists in current map. If it does exist it was already checked for equality above.
                    if (this._stylesMap.has(key))
                        continue;

                    if (!this._includeUserAgentRulesOnNextRefresh) {
                        // See above for why we skip user agent style rules.
                        let firstStyle = previousStyles.firstValue;
                        if (firstStyle && firstStyle.ownerRule && firstStyle.ownerRule.type === WI.CSSStyleSheet.Type.UserAgent)
                            continue;
                    }

                    // This key no longer exists. This is a significant change.
                    significantChange = true;
                    break;
                }
            }

            this._includeUserAgentRulesOnNextRefresh = false

            this.dispatchEventToListeners(WI.DOMNodeStyles.Event.Refreshed, {significantChange});

            fetchedComputedStylesPromise.resolve();
        }

        // FIXME: Convert to pushing StyleSheet information to the frontend. <rdar://problem/13213680>
        WI.cssManager.fetchStyleSheetsIfNeeded();

        CSSAgent.getMatchedStylesForNode.invoke({nodeId: this._node.id, includePseudo: true, includeInherited: true}, wrap.call(this, fetchedMatchedStyles, fetchedMatchedStylesPromise));
        CSSAgent.getInlineStylesForNode.invoke({nodeId: this._node.id}, wrap.call(this, fetchedInlineStyles, fetchedInlineStylesPromise));
        CSSAgent.getComputedStyleForNode.invoke({nodeId: this._node.id}, wrap.call(this, fetchedComputedStyle, fetchedComputedStylesPromise));

        this._pendingRefreshTask = Promise.all([fetchedMatchedStylesPromise.promise, fetchedInlineStylesPromise.promise, fetchedComputedStylesPromise.promise])
        .then(() => {
            this._pendingRefreshTask = null;
            return this;
        });

        return this._pendingRefreshTask;
    }

    addRule(selector, text, styleSheetId)
    {
        selector = selector || this._node.appropriateSelectorFor(true);

        function completed()
        {
            DOMAgent.markUndoableState();
            this.refresh();
        }

        function styleChanged(error, stylePayload)
        {
            if (error)
                return;

            completed.call(this);
        }

        function addedRule(error, rulePayload)
        {
            if (error)
                return;

            if (!text || !text.length) {
                completed.call(this);
                return;
            }

            CSSAgent.setStyleText(rulePayload.style.styleId, text, styleChanged.bind(this));
        }

        // COMPATIBILITY (iOS 9): Before CSS.createStyleSheet, CSS.addRule could be called with a contextNode.
        if (!CSSAgent.createStyleSheet) {
            CSSAgent.addRule.invoke({contextNodeId: this._node.id, selector}, addedRule.bind(this));
            return;
        }

        function inspectorStyleSheetAvailable(styleSheet)
        {
            if (!styleSheet)
                return;

            CSSAgent.addRule(styleSheet.id, selector, addedRule.bind(this));
        }

        if (styleSheetId)
            inspectorStyleSheetAvailable.call(this, WI.cssManager.styleSheetForIdentifier(styleSheetId));
        else
            WI.cssManager.preferredInspectorStyleSheetForFrame(this._node.frame, inspectorStyleSheetAvailable.bind(this));
    }

    rulesForSelector(selector)
    {
        selector = selector || this._node.appropriateSelectorFor(true);

        function ruleHasSelector(rule) {
            return !rule.mediaList.length && rule.selectorText === selector;
        }

        let rules = this._matchedRules.filter(ruleHasSelector);

        for (let pseudoElementInfo of this._pseudoElements.values())
            rules = rules.concat(pseudoElementInfo.matchedRules.filter(ruleHasSelector));

        return rules;
    }

    get matchedRules()
    {
        return this._matchedRules;
    }

    get inheritedRules()
    {
        return this._inheritedRules;
    }

    get inlineStyle()
    {
        return this._inlineStyle;
    }

    get attributesStyle()
    {
        return this._attributesStyle;
    }

    get pseudoElements()
    {
        return this._pseudoElements;
    }

    get computedStyle()
    {
        return this._computedStyle;
    }

    get orderedStyles()
    {
        return this._orderedStyles;
    }

    get uniqueOrderedStyles()
    {
        return WI.DOMNodeStyles.uniqueOrderedStyles(this._orderedStyles);
    }

    effectivePropertyForName(name)
    {
        let property = this._propertyNameToEffectivePropertyMap[name];
        if (property)
            return property;

        let canonicalName = WI.cssManager.canonicalNameForPropertyName(name);
        return this._propertyNameToEffectivePropertyMap[canonicalName] || null;
    }

    // Protected

    mediaQueryResultDidChange()
    {
        this._markAsNeedsRefresh();
    }

    pseudoClassesDidChange(node)
    {
        this._includeUserAgentRulesOnNextRefresh = true;
        this._markAsNeedsRefresh();
    }

    attributeDidChange(node, attributeName)
    {
        this._markAsNeedsRefresh();
    }

    changeRuleSelector(rule, selector)
    {
        selector = selector || "";
        let result = new WI.WrappedPromise;

        function ruleSelectorChanged(error, rulePayload)
        {
            if (error) {
                result.reject(error);
                return;
            }

            DOMAgent.markUndoableState();

            // Do a full refresh incase the rule no longer matches the node or the
            // matched selector indices changed.
            this.refresh().then(() => {
                result.resolve(rulePayload);
            });
        }

        this._needsRefresh = true;
        this._ignoreNextContentDidChangeForStyleSheet = rule.ownerStyleSheet;

        CSSAgent.setRuleSelector(rule.id, selector, ruleSelectorChanged.bind(this));
        return result.promise;
    }

    changeStyleText(style, text, callback)
    {
        if (!style.ownerStyleSheet || !style.styleSheetTextRange) {
            callback();
            return;
        }

        text = text || "";

        let didSetStyleText = (error, stylePayload) => {
            if (error) {
                callback(error);
                return;
            }

            callback();
            this.refresh();
        };

        CSSAgent.setStyleText(style.id, text, didSetStyleText);
    }

    // Private

    _parseSourceRangePayload(payload)
    {
        if (!payload)
            return null;

        return new WI.TextRange(payload.startLine, payload.startColumn, payload.endLine, payload.endColumn);
    }

    _parseStylePropertyPayload(payload, index, styleDeclaration)
    {
        var text = payload.text || "";
        var name = payload.name;
        var value = payload.value || "";
        var priority = payload.priority || "";
        let range = payload.range || null;

        var enabled = true;
        var overridden = false;
        var implicit = payload.implicit || false;
        var anonymous = false;
        var valid = "parsedOk" in payload ? payload.parsedOk : true;

        switch (payload.status || "style") {
        case "active":
            enabled = true;
            break;
        case "inactive":
            overridden = true;
            enabled = true;
            break;
        case "disabled":
            enabled = false;
            break;
        case "style":
            // FIXME: Is this still needed? This includes UserAgent styles and HTML attribute styles.
            anonymous = true;
            break;
        }

        if (range) {
            // Last property of inline style has mismatching range.
            // The actual text has one line, but the range spans two lines.
            let rangeLineCount = 1 + range.endLine - range.startLine;
            if (rangeLineCount > 1) {
                let textLineCount = text.lineCount;
                if (textLineCount === rangeLineCount - 1) {
                    range.endLine = range.startLine + (textLineCount - 1);
                    range.endColumn = range.startColumn + text.lastLine.length;
                }
            }
        }

        var styleSheetTextRange = this._parseSourceRangePayload(payload.range);

        if (styleDeclaration) {
            // Use propertyForName when the index is NaN since propertyForName is fast in that case.
            var property = isNaN(index) ? styleDeclaration.propertyForName(name, true) : styleDeclaration.enabledProperties[index];

            // Reuse a property if the index and name matches. Otherwise it is a different property
            // and should be created from scratch. This works in the simple cases where only existing
            // properties change in place and no properties are inserted or deleted at the beginning.
            // FIXME: This could be smarter by ignoring index and just go by name. However, that gets
            // tricky for rules that have more than one property with the same name.
            if (property && property.name === name && (property.index === index || (isNaN(property.index) && isNaN(index)))) {
                property.update(text, name, value, priority, enabled, overridden, implicit, anonymous, valid, styleSheetTextRange);
                return property;
            }

            // Reuse a pending property with the same name. These properties are pending being committed,
            // so if we find a match that likely means it got committed and we should use it.
            var pendingProperties = styleDeclaration.pendingProperties;
            for (var i = 0; i < pendingProperties.length; ++i) {
                var pendingProperty = pendingProperties[i];
                if (pendingProperty.name === name && isNaN(pendingProperty.index)) {
                    pendingProperty.index = index;
                    pendingProperty.update(text, name, value, priority, enabled, overridden, implicit, anonymous, valid, styleSheetTextRange);
                    return pendingProperty;
                }
            }
        }

        return new WI.CSSProperty(index, text, name, value, priority, enabled, overridden, implicit, anonymous, valid, styleSheetTextRange);
    }

    _parseStyleDeclarationPayload(payload, node, inherited, pseudoId, type, rule)
    {
        if (!payload)
            return null;

        rule = rule || null;
        inherited = inherited || false;

        var id = payload.styleId;
        var mapKey = id ? id.styleSheetId + ":" + id.ordinal : null;
        if (pseudoId)
            mapKey += ":" + pseudoId;
        if (type === WI.CSSStyleDeclaration.Type.Attribute)
            mapKey += ":" + node.id + ":attribute";

        let style = rule ? rule.style : null;

        let existingStyles = this._stylesMap.get(mapKey);
        if (existingStyles && !style) {
            for (let existingStyle of existingStyles) {
                if (existingStyle.node === node && existingStyle.inherited === inherited) {
                    style = existingStyle;
                    break;
                }
            }
        }

        if (style)
            this._stylesMap.add(mapKey, style);

        var shorthands = {};
        for (var i = 0; payload.shorthandEntries && i < payload.shorthandEntries.length; ++i) {
            var shorthand = payload.shorthandEntries[i];
            shorthands[shorthand.name] = shorthand.value;
        }

        var inheritedPropertyCount = 0;

        var properties = [];
        for (var i = 0; payload.cssProperties && i < payload.cssProperties.length; ++i) {
            var propertyPayload = payload.cssProperties[i];

            if (inherited && WI.CSSProperty.isInheritedPropertyName(propertyPayload.name))
                ++inheritedPropertyCount;

            let property = this._parseStylePropertyPayload(propertyPayload, i, style);
            properties.push(property);
        }

        let text = payload.cssText;
        var styleSheetTextRange = this._parseSourceRangePayload(payload.range);

        if (style) {
            style.update(text, properties, styleSheetTextRange);
            return style;
        }

        var styleSheet = id ? WI.cssManager.styleSheetForIdentifier(id.styleSheetId) : null;
        if (styleSheet) {
            if (type === WI.CSSStyleDeclaration.Type.Inline)
                styleSheet.markAsInlineStyleAttributeStyleSheet();
            styleSheet.addEventListener(WI.CSSStyleSheet.Event.ContentDidChange, this._styleSheetContentDidChange, this);
        }

        if (inherited && !inheritedPropertyCount)
            return null;

        style = new WI.CSSStyleDeclaration(this, styleSheet, id, type, node, inherited, text, properties, styleSheetTextRange);

        if (mapKey)
            this._stylesMap.add(mapKey, style);

        return style;
    }

    _parseRulePayload(payload, matchedSelectorIndices, node, inherited, pseudoId, ruleOccurrences)
    {
        if (!payload)
            return null;

        // User and User Agent rules don't have 'ruleId' in the payload. However, their style's have 'styleId' and
        // 'styleId' is the same identifier the backend uses for Author rule identifiers, so do the same here.
        // They are excluded by the backend because they are not editable, however our front-end does not determine
        // editability solely based on the existence of the id like the open source front-end does.
        var id = payload.ruleId || payload.style.styleId;

        var mapKey = id ? id.styleSheetId + ":" + id.ordinal + ":" + (inherited ? "I" : "N") + ":" + (pseudoId ? pseudoId + ":" : "") + node.id : null;

        // Rules can match multiple times if they have multiple selectors or because of inheritance. We keep a count
        // of occurrences so we have unique rules per occurrence, that way properties will be correctly marked as overridden.
        var occurrence = 0;
        if (mapKey) {
            if (mapKey in ruleOccurrences)
                occurrence = ++ruleOccurrences[mapKey];
            else
                ruleOccurrences[mapKey] = occurrence;

            // Append the occurrence number to the map key for lookup in the rules map.
            mapKey += ":" + occurrence;
        }

        let rule = this._rulesMap.get(mapKey);

        var style = this._parseStyleDeclarationPayload(payload.style, node, inherited, pseudoId, WI.CSSStyleDeclaration.Type.Rule, rule);
        if (!style)
            return null;

        var styleSheet = id ? WI.cssManager.styleSheetForIdentifier(id.styleSheetId) : null;

        var selectorText = payload.selectorList.text;
        let selectors = DOMNodeStyles.parseSelectorListPayload(payload.selectorList);
        var type = WI.CSSManager.protocolStyleSheetOriginToEnum(payload.origin);

        var sourceCodeLocation = null;
        var sourceRange = payload.selectorList.range;
        if (sourceRange) {
            sourceCodeLocation = DOMNodeStyles.createSourceCodeLocation(payload.sourceURL, {
                line: sourceRange.startLine,
                column: sourceRange.startColumn,
                documentNode: this._node.ownerDocument,
            });
        } else {
            // FIXME: Is it possible for a CSSRule to have a sourceLine without its selectorList having a sourceRange? Fall back just in case.
            sourceCodeLocation = DOMNodeStyles.createSourceCodeLocation(payload.sourceURL, {
                line: payload.sourceLine,
                documentNode: this._node.ownerDocument,
            });
        }

        if (styleSheet) {
            if (!sourceCodeLocation && styleSheet.isInspectorStyleSheet())
                sourceCodeLocation = styleSheet.createSourceCodeLocation(sourceRange.startLine, sourceRange.startColumn);

            sourceCodeLocation = styleSheet.offsetSourceCodeLocation(sourceCodeLocation);
        }

        var mediaList = [];
        for (var i = 0; payload.media && i < payload.media.length; ++i) {
            var mediaItem = payload.media[i];
            var mediaType = WI.CSSManager.protocolMediaSourceToEnum(mediaItem.source);
            var mediaText = mediaItem.text;
            let mediaSourceCodeLocation = DOMNodeStyles.createSourceCodeLocation(mediaItem.sourceURL, {line: mediaItem.sourceLine});
            if (styleSheet)
                mediaSourceCodeLocation = styleSheet.offsetSourceCodeLocation(mediaSourceCodeLocation);

            mediaList.push(new WI.CSSMedia(mediaType, mediaText, mediaSourceCodeLocation));
        }

        if (rule) {
            rule.update(sourceCodeLocation, selectorText, selectors, matchedSelectorIndices, style, mediaList);
            return rule;
        }

        if (styleSheet)
            styleSheet.addEventListener(WI.CSSStyleSheet.Event.ContentDidChange, this._styleSheetContentDidChange, this);

        rule = new WI.CSSRule(this, styleSheet, id, type, sourceCodeLocation, selectorText, selectors, matchedSelectorIndices, style, mediaList);

        if (mapKey)
            this._rulesMap.set(mapKey, rule);

        return rule;
    }

    _markAsNeedsRefresh()
    {
        this._needsRefresh = true;
        this.dispatchEventToListeners(WI.DOMNodeStyles.Event.NeedsRefresh);
    }

    _styleSheetContentDidChange(event)
    {
        var styleSheet = event.target;
        console.assert(styleSheet);
        if (!styleSheet)
            return;

        // Ignore the stylesheet we know we just changed and handled above.
        if (styleSheet === this._ignoreNextContentDidChangeForStyleSheet) {
            this._ignoreNextContentDidChangeForStyleSheet = null;
            return;
        }

        this._markAsNeedsRefresh();
    }

    _updateStyleCascade()
    {
        var cascadeOrderedStyleDeclarations = this._collectStylesInCascadeOrder(this._matchedRules, this._inlineStyle, this._attributesStyle);

        for (var i = 0; i < this._inheritedRules.length; ++i) {
            var inheritedStyleInfo = this._inheritedRules[i];
            var inheritedCascadeOrder = this._collectStylesInCascadeOrder(inheritedStyleInfo.matchedRules, inheritedStyleInfo.inlineStyle, null);
            cascadeOrderedStyleDeclarations = cascadeOrderedStyleDeclarations.concat(inheritedCascadeOrder);
        }

        this._orderedStyles = cascadeOrderedStyleDeclarations;

        this._propertyNameToEffectivePropertyMap = {};

        this._associateRelatedProperties(cascadeOrderedStyleDeclarations, this._propertyNameToEffectivePropertyMap);
        this._markOverriddenProperties(cascadeOrderedStyleDeclarations, this._propertyNameToEffectivePropertyMap);

        for (let pseudoElementInfo of this._pseudoElements.values()) {
            pseudoElementInfo.orderedStyles = this._collectStylesInCascadeOrder(pseudoElementInfo.matchedRules, null, null);
            this._associateRelatedProperties(pseudoElementInfo.orderedStyles);
            this._markOverriddenProperties(pseudoElementInfo.orderedStyles);
        }
    }

    _collectStylesInCascadeOrder(matchedRules, inlineStyle, attributesStyle)
    {
        var result = [];

        // Inline style has the greatest specificity. So it goes first in the cascade order.
        if (inlineStyle)
            result.push(inlineStyle);

        var userAndUserAgentStyles = [];

        for (var i = 0; i < matchedRules.length; ++i) {
            var rule = matchedRules[i];

            // Only append to the result array here for author and inspector rules since attribute
            // styles come between author rules and user/user agent rules.
            switch (rule.type) {
            case WI.CSSStyleSheet.Type.Inspector:
            case WI.CSSStyleSheet.Type.Author:
                result.push(rule.style);
                break;

            case WI.CSSStyleSheet.Type.User:
            case WI.CSSStyleSheet.Type.UserAgent:
                userAndUserAgentStyles.push(rule.style);
                break;
            }
        }

        // Style properties from HTML attributes are next.
        if (attributesStyle)
            result.push(attributesStyle);

        // Finally add the user and user stylesheet's matched style rules we collected earlier.
        result = result.concat(userAndUserAgentStyles);

        return result;
    }

    _markOverriddenProperties(styles, propertyNameToEffectiveProperty)
    {
        propertyNameToEffectiveProperty = propertyNameToEffectiveProperty || {};

        function isOverriddenByRelatedShorthand(property) {
            let shorthand = property.relatedShorthandProperty;
            if (!shorthand)
                return false;

            if (property.important && !shorthand.important)
                return false;

            if (!property.important && shorthand.important)
                return true;

            if (property.ownerStyle === shorthand.ownerStyle)
                return shorthand.index > property.index;

            let propertyStyleIndex = styles.indexOf(property.ownerStyle);
            let shorthandStyleIndex = styles.indexOf(shorthand.ownerStyle);
            return shorthandStyleIndex > propertyStyleIndex;
        }

        for (var i = 0; i < styles.length; ++i) {
            var style = styles[i];
            var properties = style.enabledProperties;

            for (var j = 0; j < properties.length; ++j) {
                var property = properties[j];
                if (!property.attached || !property.valid) {
                    property.overridden = false;
                    continue;
                }

                if (style.inherited && !property.inherited) {
                    property.overridden = false;
                    continue;
                }

                var canonicalName = property.canonicalName;
                if (canonicalName in propertyNameToEffectiveProperty) {
                    var effectiveProperty = propertyNameToEffectiveProperty[canonicalName];

                    if (effectiveProperty.ownerStyle === property.ownerStyle) {
                        if (effectiveProperty.important && !property.important) {
                            property.overridden = true;
                            property.overridingProperty = effectiveProperty;
                            continue;
                        }
                    } else if (effectiveProperty.important || !property.important || effectiveProperty.ownerStyle.node !== property.ownerStyle.node) {
                        property.overridden = true;
                        property.overridingProperty = effectiveProperty;
                        continue;
                    }

                    if (!property.anonymous) {
                        effectiveProperty.overridden = true;
                        effectiveProperty.overridingProperty = property;
                    }
                }

                if (isOverriddenByRelatedShorthand(property)) {
                    property.overridden = true;
                    property.overridingProperty = property.relatedShorthandProperty;
                } else
                    property.overridden = false;

                propertyNameToEffectiveProperty[canonicalName] = property;
            }
        }
    }

    _associateRelatedProperties(styles, propertyNameToEffectiveProperty)
    {
        for (var i = 0; i < styles.length; ++i) {
            var properties = styles[i].enabledProperties;

            var knownShorthands = {};

            for (var j = 0; j < properties.length; ++j) {
                var property = properties[j];

                if (!property.valid)
                    continue;

                if (!WI.CSSCompletions.cssNameCompletions.isShorthandPropertyName(property.name))
                    continue;

                if (knownShorthands[property.canonicalName] && !knownShorthands[property.canonicalName].overridden) {
                    console.assert(property.overridden);
                    continue;
                }

                knownShorthands[property.canonicalName] = property;
            }

            for (var j = 0; j < properties.length; ++j) {
                var property = properties[j];

                if (!property.valid)
                    continue;

                var shorthandProperty = null;

                if (!isEmptyObject(knownShorthands)) {
                    var possibleShorthands = WI.CSSCompletions.cssNameCompletions.shorthandsForLonghand(property.canonicalName);
                    for (var k = 0; k < possibleShorthands.length; ++k) {
                        if (possibleShorthands[k] in knownShorthands) {
                            shorthandProperty = knownShorthands[possibleShorthands[k]];
                            break;
                        }
                    }
                }

                if (!shorthandProperty || shorthandProperty.overridden !== property.overridden) {
                    property.relatedShorthandProperty = null;
                    property.clearRelatedLonghandProperties();
                    continue;
                }

                shorthandProperty.addRelatedLonghandProperty(property);
                property.relatedShorthandProperty = shorthandProperty;

                if (propertyNameToEffectiveProperty && propertyNameToEffectiveProperty[shorthandProperty.canonicalName] === shorthandProperty)
                    propertyNameToEffectiveProperty[property.canonicalName] = property;
            }
        }
    }

    _isPropertyFoundInMatchingRules(propertyName)
    {
        return this._orderedStyles.some((style) => {
            return style.enabledProperties.some((property) => property.name === propertyName);
        });
    }
};

WI.DOMNodeStyles.Event = {
    NeedsRefresh: "dom-node-styles-needs-refresh",
    Refreshed: "dom-node-styles-refreshed"
};
