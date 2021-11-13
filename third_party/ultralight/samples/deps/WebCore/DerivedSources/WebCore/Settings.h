/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2017 Apple Inc. All rights reserved.
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

#pragma once

#include "SettingsBase.h"
#include <wtf/RefCounted.h>

namespace WebCore {

class Page;

class Settings : public SettingsBase, public RefCounted<Settings> {
    WTF_MAKE_NONCOPYABLE(Settings); WTF_MAKE_FAST_ALLOCATED;
public:
    static Ref<Settings> create(Page*);
    ~Settings();

    bool CSSOMViewScrollingAPIEnabled() const { return m_CSSOMViewScrollingAPIEnabled; } 
    void setCSSOMViewScrollingAPIEnabled(bool CSSOMViewScrollingAPIEnabled) { m_CSSOMViewScrollingAPIEnabled = CSSOMViewScrollingAPIEnabled; }
    bool DOMPasteAllowed() const { return m_DOMPasteAllowed; } 
    void setDOMPasteAllowed(bool DOMPasteAllowed) { m_DOMPasteAllowed = DOMPasteAllowed; }
    bool HTTPSUpgradeEnabled() const { return m_HTTPSUpgradeEnabled; } 
    void setHTTPSUpgradeEnabled(bool HTTPSUpgradeEnabled) { m_HTTPSUpgradeEnabled = HTTPSUpgradeEnabled; }
    bool accelerated2dCanvasEnabled() const { return m_accelerated2dCanvasEnabled; } 
    void setAccelerated2dCanvasEnabled(bool accelerated2dCanvasEnabled) { m_accelerated2dCanvasEnabled = accelerated2dCanvasEnabled; }
    bool acceleratedCompositedAnimationsEnabled() const { return m_acceleratedCompositedAnimationsEnabled; } 
    WEBCORE_EXPORT void setAcceleratedCompositedAnimationsEnabled(bool);
    bool acceleratedCompositingEnabled() const { return m_acceleratedCompositingEnabled; } 
    WEBCORE_EXPORT void setAcceleratedCompositingEnabled(bool);
    bool acceleratedCompositingForFixedPositionEnabled() const { return m_acceleratedCompositingForFixedPositionEnabled; } 
    void setAcceleratedCompositingForFixedPositionEnabled(bool acceleratedCompositingForFixedPositionEnabled) { m_acceleratedCompositingForFixedPositionEnabled = acceleratedCompositingForFixedPositionEnabled; }
    bool acceleratedDrawingEnabled() const { return m_acceleratedDrawingEnabled; } 
    void setAcceleratedDrawingEnabled(bool acceleratedDrawingEnabled) { m_acceleratedDrawingEnabled = acceleratedDrawingEnabled; }
    bool acceleratedFiltersEnabled() const { return m_acceleratedFiltersEnabled; } 
    void setAcceleratedFiltersEnabled(bool acceleratedFiltersEnabled) { m_acceleratedFiltersEnabled = acceleratedFiltersEnabled; }
    bool adClickAttributionEnabled() const { return m_adClickAttributionEnabled; } 
    void setAdClickAttributionEnabled(bool adClickAttributionEnabled) { m_adClickAttributionEnabled = adClickAttributionEnabled; }
    bool aggressiveTileRetentionEnabled() const { return m_aggressiveTileRetentionEnabled; } 
    void setAggressiveTileRetentionEnabled(bool aggressiveTileRetentionEnabled) { m_aggressiveTileRetentionEnabled = aggressiveTileRetentionEnabled; }
    bool allowContentSecurityPolicySourceStarToMatchAnyProtocol() const { return m_allowContentSecurityPolicySourceStarToMatchAnyProtocol; } 
    void setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(bool allowContentSecurityPolicySourceStarToMatchAnyProtocol) { m_allowContentSecurityPolicySourceStarToMatchAnyProtocol = allowContentSecurityPolicySourceStarToMatchAnyProtocol; }
    bool allowCrossOriginSubresourcesToAskForCredentials() const { return m_allowCrossOriginSubresourcesToAskForCredentials; } 
    void setAllowCrossOriginSubresourcesToAskForCredentials(bool allowCrossOriginSubresourcesToAskForCredentials) { m_allowCrossOriginSubresourcesToAskForCredentials = allowCrossOriginSubresourcesToAskForCredentials; }
    bool allowDisplayOfInsecureContent() const { return m_allowDisplayOfInsecureContent; } 
    void setAllowDisplayOfInsecureContent(bool allowDisplayOfInsecureContent) { m_allowDisplayOfInsecureContent = allowDisplayOfInsecureContent; }
    bool allowFileAccessFromFileURLs() const { return m_allowFileAccessFromFileURLs; } 
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs) { m_allowFileAccessFromFileURLs = allowFileAccessFromFileURLs; }
    bool allowMediaContentTypesRequiringHardwareSupportAsFallback() const { return m_allowMediaContentTypesRequiringHardwareSupportAsFallback; } 
    void setAllowMediaContentTypesRequiringHardwareSupportAsFallback(bool allowMediaContentTypesRequiringHardwareSupportAsFallback) { m_allowMediaContentTypesRequiringHardwareSupportAsFallback = allowMediaContentTypesRequiringHardwareSupportAsFallback; }
    bool allowMultiElementImplicitSubmission() const { return m_allowMultiElementImplicitSubmission; } 
    void setAllowMultiElementImplicitSubmission(bool allowMultiElementImplicitSubmission) { m_allowMultiElementImplicitSubmission = allowMultiElementImplicitSubmission; }
    bool allowRunningOfInsecureContent() const { return m_allowRunningOfInsecureContent; } 
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent) { m_allowRunningOfInsecureContent = allowRunningOfInsecureContent; }
    bool allowSettingAnyXHRHeaderFromFileURLs() const { return m_allowSettingAnyXHRHeaderFromFileURLs; } 
    void setAllowSettingAnyXHRHeaderFromFileURLs(bool allowSettingAnyXHRHeaderFromFileURLs) { m_allowSettingAnyXHRHeaderFromFileURLs = allowSettingAnyXHRHeaderFromFileURLs; }
    bool allowUniversalAccessFromFileURLs() const { return m_allowUniversalAccessFromFileURLs; } 
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs) { m_allowUniversalAccessFromFileURLs = allowUniversalAccessFromFileURLs; }
    bool allowViewportShrinkToFitContent() const { return m_allowViewportShrinkToFitContent; } 
    void setAllowViewportShrinkToFitContent(bool allowViewportShrinkToFitContent) { m_allowViewportShrinkToFitContent = allowViewportShrinkToFitContent; }
    bool allowsInlineMediaPlayback() const { return m_allowsInlineMediaPlayback; } 
    void setAllowsInlineMediaPlayback(bool allowsInlineMediaPlayback) { m_allowsInlineMediaPlayback = allowsInlineMediaPlayback; }
    bool allowsInlineMediaPlaybackAfterFullscreen() const { return m_allowsInlineMediaPlaybackAfterFullscreen; } 
    void setAllowsInlineMediaPlaybackAfterFullscreen(bool allowsInlineMediaPlaybackAfterFullscreen) { m_allowsInlineMediaPlaybackAfterFullscreen = allowsInlineMediaPlaybackAfterFullscreen; }
    bool allowsPictureInPictureMediaPlayback() const { return m_allowsPictureInPictureMediaPlayback; } 
    void setAllowsPictureInPictureMediaPlayback(bool allowsPictureInPictureMediaPlayback) { m_allowsPictureInPictureMediaPlayback = allowsPictureInPictureMediaPlayback; }
    bool alwaysUseAcceleratedOverflowScroll() const { return m_alwaysUseAcceleratedOverflowScroll; } 
    void setAlwaysUseAcceleratedOverflowScroll(bool alwaysUseAcceleratedOverflowScroll) { m_alwaysUseAcceleratedOverflowScroll = alwaysUseAcceleratedOverflowScroll; }
    bool animatedImageAsyncDecodingEnabled() const { return m_animatedImageAsyncDecodingEnabled; } 
    void setAnimatedImageAsyncDecodingEnabled(bool animatedImageAsyncDecodingEnabled) { m_animatedImageAsyncDecodingEnabled = animatedImageAsyncDecodingEnabled; }
    bool appleMailPaginationQuirkEnabled() const { return m_appleMailPaginationQuirkEnabled; } 
    void setAppleMailPaginationQuirkEnabled(bool appleMailPaginationQuirkEnabled) { m_appleMailPaginationQuirkEnabled = appleMailPaginationQuirkEnabled; }
    bool asyncFrameScrollingEnabled() const { return m_asyncFrameScrollingEnabled; } 
    WEBCORE_EXPORT void setAsyncFrameScrollingEnabled(bool);
    bool asyncOverflowScrollingEnabled() const { return m_asyncOverflowScrollingEnabled; } 
    WEBCORE_EXPORT void setAsyncOverflowScrollingEnabled(bool);
    bool asynchronousSpellCheckingEnabled() const { return m_asynchronousSpellCheckingEnabled; } 
    void setAsynchronousSpellCheckingEnabled(bool asynchronousSpellCheckingEnabled) { m_asynchronousSpellCheckingEnabled = asynchronousSpellCheckingEnabled; }
    bool audioPlaybackRequiresUserGesture() const { return m_audioPlaybackRequiresUserGesture; } 
    void setAudioPlaybackRequiresUserGesture(bool audioPlaybackRequiresUserGesture) { m_audioPlaybackRequiresUserGesture = audioPlaybackRequiresUserGesture; }
    WEBCORE_EXPORT bool authorAndUserStylesEnabled() const;
    WEBCORE_EXPORT void setAuthorAndUserStylesEnabled(bool);
    bool autoscrollForDragAndDropEnabled() const { return m_autoscrollForDragAndDropEnabled; } 
    void setAutoscrollForDragAndDropEnabled(bool autoscrollForDragAndDropEnabled) { m_autoscrollForDragAndDropEnabled = autoscrollForDragAndDropEnabled; }
    bool autostartOriginPlugInSnapshottingEnabled() const { return m_autostartOriginPlugInSnapshottingEnabled; } 
    void setAutostartOriginPlugInSnapshottingEnabled(bool autostartOriginPlugInSnapshottingEnabled) { m_autostartOriginPlugInSnapshottingEnabled = autostartOriginPlugInSnapshottingEnabled; }
    double backForwardCacheExpirationInterval() const { return m_backForwardCacheExpirationInterval; } 
    void setBackForwardCacheExpirationInterval(double backForwardCacheExpirationInterval) { m_backForwardCacheExpirationInterval = backForwardCacheExpirationInterval; }
    bool backgroundShouldExtendBeyondPage() const { return m_backgroundShouldExtendBeyondPage; } 
    WEBCORE_EXPORT void setBackgroundShouldExtendBeyondPage(bool);
    bool backspaceKeyNavigationEnabled() const { return m_backspaceKeyNavigationEnabled; } 
    void setBackspaceKeyNavigationEnabled(bool backspaceKeyNavigationEnabled) { m_backspaceKeyNavigationEnabled = backspaceKeyNavigationEnabled; }
    bool beaconAPIEnabled() const { return m_beaconAPIEnabled; } 
    void setBeaconAPIEnabled(bool beaconAPIEnabled) { m_beaconAPIEnabled = beaconAPIEnabled; }
    bool blockingOfSmallPluginsEnabled() const { return m_blockingOfSmallPluginsEnabled; } 
    void setBlockingOfSmallPluginsEnabled(bool blockingOfSmallPluginsEnabled) { m_blockingOfSmallPluginsEnabled = blockingOfSmallPluginsEnabled; }
    bool canvasUsesAcceleratedDrawing() const { return m_canvasUsesAcceleratedDrawing; } 
    void setCanvasUsesAcceleratedDrawing(bool canvasUsesAcceleratedDrawing) { m_canvasUsesAcceleratedDrawing = canvasUsesAcceleratedDrawing; }
    bool caretBrowsingEnabled() const { return m_caretBrowsingEnabled; } 
    void setCaretBrowsingEnabled(bool caretBrowsingEnabled) { m_caretBrowsingEnabled = caretBrowsingEnabled; }
    bool clientCoordinatesRelativeToLayoutViewport() const { return m_clientCoordinatesRelativeToLayoutViewport; } 
    WEBCORE_EXPORT void setClientCoordinatesRelativeToLayoutViewport(bool);
    ClipboardAccessPolicy clipboardAccessPolicy() const { return m_clipboardAccessPolicy; } 
    void setClipboardAccessPolicy(ClipboardAccessPolicy clipboardAccessPolicy) { m_clipboardAccessPolicy = clipboardAccessPolicy; }
    bool colorFilterEnabled() const { return m_colorFilterEnabled; } 
    WEBCORE_EXPORT void setColorFilterEnabled(bool);
    bool constantPropertiesEnabled() const { return m_constantPropertiesEnabled; } 
    void setConstantPropertiesEnabled(bool constantPropertiesEnabled) { m_constantPropertiesEnabled = constantPropertiesEnabled; }
    bool contentChangeObserverEnabled() const { return m_contentChangeObserverEnabled; } 
    void setContentChangeObserverEnabled(bool contentChangeObserverEnabled) { m_contentChangeObserverEnabled = contentChangeObserverEnabled; }
    bool contentDispositionAttachmentSandboxEnabled() const { return m_contentDispositionAttachmentSandboxEnabled; } 
    void setContentDispositionAttachmentSandboxEnabled(bool contentDispositionAttachmentSandboxEnabled) { m_contentDispositionAttachmentSandboxEnabled = contentDispositionAttachmentSandboxEnabled; }
    bool cookieEnabled() const { return m_cookieEnabled; } 
    void setCookieEnabled(bool cookieEnabled) { m_cookieEnabled = cookieEnabled; }
    bool coreMathMLEnabled() const { return m_coreMathMLEnabled; } 
    WEBCORE_EXPORT void setCoreMathMLEnabled(bool);
    bool crossOriginCheckInGetMatchedCSSRulesDisabled() const { return m_crossOriginCheckInGetMatchedCSSRulesDisabled; } 
    void setCrossOriginCheckInGetMatchedCSSRulesDisabled(bool crossOriginCheckInGetMatchedCSSRulesDisabled) { m_crossOriginCheckInGetMatchedCSSRulesDisabled = crossOriginCheckInGetMatchedCSSRulesDisabled; }
    int defaultFixedFontSize() const { return m_defaultFixedFontSize; } 
    WEBCORE_EXPORT void setDefaultFixedFontSize(int);
    int defaultFontSize() const { return m_defaultFontSize; } 
    WEBCORE_EXPORT void setDefaultFontSize(int);
    const String& defaultTextEncodingName() const { return m_defaultTextEncodingName; } 
    void setDefaultTextEncodingName(const String& defaultTextEncodingName) { m_defaultTextEncodingName = defaultTextEncodingName; }
    const String& defaultVideoPosterURL() const { return m_defaultVideoPosterURL; } 
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL) { m_defaultVideoPosterURL = defaultVideoPosterURL; }
    bool deferredCSSParserEnabled() const { return m_deferredCSSParserEnabled; } 
    void setDeferredCSSParserEnabled(bool deferredCSSParserEnabled) { m_deferredCSSParserEnabled = deferredCSSParserEnabled; }
    bool delegatesPageScaling() const { return m_delegatesPageScaling; } 
    void setDelegatesPageScaling(bool delegatesPageScaling) { m_delegatesPageScaling = delegatesPageScaling; }
    bool developerExtrasEnabled() const { return m_developerExtrasEnabled; } 
    void setDeveloperExtrasEnabled(bool developerExtrasEnabled) { m_developerExtrasEnabled = developerExtrasEnabled; }
    int deviceHeight() const { return m_deviceHeight; } 
    void setDeviceHeight(int deviceHeight) { m_deviceHeight = deviceHeight; }
    int deviceWidth() const { return m_deviceWidth; } 
    void setDeviceWidth(int deviceWidth) { m_deviceWidth = deviceWidth; }
    bool diagnosticLoggingEnabled() const { return m_diagnosticLoggingEnabled; } 
    void setDiagnosticLoggingEnabled(bool diagnosticLoggingEnabled) { m_diagnosticLoggingEnabled = diagnosticLoggingEnabled; }
    bool disableScreenSizeOverride() const { return m_disableScreenSizeOverride; } 
    void setDisableScreenSizeOverride(bool disableScreenSizeOverride) { m_disableScreenSizeOverride = disableScreenSizeOverride; }
    bool displayListDrawingEnabled() const { return m_displayListDrawingEnabled; } 
    void setDisplayListDrawingEnabled(bool displayListDrawingEnabled) { m_displayListDrawingEnabled = displayListDrawingEnabled; }
    bool dnsPrefetchingEnabled() const { return m_dnsPrefetchingEnabled; } 
    WEBCORE_EXPORT void setDNSPrefetchingEnabled(bool);
    bool domPasteAccessRequestsEnabled() const { return m_domPasteAccessRequestsEnabled; } 
    void setDOMPasteAccessRequestsEnabled(bool domPasteAccessRequestsEnabled) { m_domPasteAccessRequestsEnabled = domPasteAccessRequestsEnabled; }
    bool domTimersThrottlingEnabled() const { return m_domTimersThrottlingEnabled; } 
    void setDOMTimersThrottlingEnabled(bool domTimersThrottlingEnabled) { m_domTimersThrottlingEnabled = domTimersThrottlingEnabled; }
    bool downloadableBinaryFontsEnabled() const { return m_downloadableBinaryFontsEnabled; } 
    void setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled) { m_downloadableBinaryFontsEnabled = downloadableBinaryFontsEnabled; }
    bool editableImagesEnabled() const { return m_editableImagesEnabled; } 
    void setEditableImagesEnabled(bool editableImagesEnabled) { m_editableImagesEnabled = editableImagesEnabled; }
    EditableLinkBehavior editableLinkBehavior() const { return m_editableLinkBehavior; } 
    void setEditableLinkBehavior(EditableLinkBehavior editableLinkBehavior) { m_editableLinkBehavior = editableLinkBehavior; }
    EditingBehaviorType editingBehaviorType() const { return m_editingBehaviorType; } 
    void setEditingBehaviorType(EditingBehaviorType editingBehaviorType) { m_editingBehaviorType = editingBehaviorType; }
    bool enableInheritURIQueryComponent() const { return m_enableInheritURIQueryComponent; } 
    void setEnableInheritURIQueryComponent(bool enableInheritURIQueryComponent) { m_enableInheritURIQueryComponent = enableInheritURIQueryComponent; }
    bool enforceCSSMIMETypeInNoQuirksMode() const { return m_enforceCSSMIMETypeInNoQuirksMode; } 
    void setEnforceCSSMIMETypeInNoQuirksMode(bool enforceCSSMIMETypeInNoQuirksMode) { m_enforceCSSMIMETypeInNoQuirksMode = enforceCSSMIMETypeInNoQuirksMode; }
    bool experimentalNotificationsEnabled() const { return m_experimentalNotificationsEnabled; } 
    void setExperimentalNotificationsEnabled(bool experimentalNotificationsEnabled) { m_experimentalNotificationsEnabled = experimentalNotificationsEnabled; }
    bool fixedBackgroundsPaintRelativeToDocument() const { return m_fixedBackgroundsPaintRelativeToDocument; } 
    void setFixedBackgroundsPaintRelativeToDocument(bool fixedBackgroundsPaintRelativeToDocument) { m_fixedBackgroundsPaintRelativeToDocument = fixedBackgroundsPaintRelativeToDocument; }
    bool fixedElementsLayoutRelativeToFrame() const { return m_fixedElementsLayoutRelativeToFrame; } 
    void setFixedElementsLayoutRelativeToFrame(bool fixedElementsLayoutRelativeToFrame) { m_fixedElementsLayoutRelativeToFrame = fixedElementsLayoutRelativeToFrame; }
    bool fontFallbackPrefersPictographs() const { return m_fontFallbackPrefersPictographs; } 
    WEBCORE_EXPORT void setFontFallbackPrefersPictographs(bool);
    FontLoadTimingOverride fontLoadTimingOverride() const { return m_fontLoadTimingOverride; } 
    void setFontLoadTimingOverride(FontLoadTimingOverride fontLoadTimingOverride) { m_fontLoadTimingOverride = fontLoadTimingOverride; }
    FontRenderingMode fontRenderingMode() const { return m_fontRenderingMode; } 
    void setFontRenderingMode(FontRenderingMode fontRenderingMode) { m_fontRenderingMode = fontRenderingMode; }
    bool forceCompositingMode() const { return m_forceCompositingMode; } 
    void setForceCompositingMode(bool forceCompositingMode) { m_forceCompositingMode = forceCompositingMode; }
    bool forceFTPDirectoryListings() const { return m_forceFTPDirectoryListings; } 
    void setForceFTPDirectoryListings(bool forceFTPDirectoryListings) { m_forceFTPDirectoryListings = forceFTPDirectoryListings; }
    bool isForcePendingWebGLPolicy() const { return m_forcePendingWebGLPolicy; } 
    void setForcePendingWebGLPolicy(bool forcePendingWebGLPolicy) { m_forcePendingWebGLPolicy = forcePendingWebGLPolicy; }
    bool forceSoftwareWebGLRendering() const { return m_forceSoftwareWebGLRendering; } 
    void setForceSoftwareWebGLRendering(bool forceSoftwareWebGLRendering) { m_forceSoftwareWebGLRendering = forceSoftwareWebGLRendering; }
    bool forceUpdateScrollbarsOnMainThreadForPerformanceTesting() const { return m_forceUpdateScrollbarsOnMainThreadForPerformanceTesting; } 
    void setForceUpdateScrollbarsOnMainThreadForPerformanceTesting(bool forceUpdateScrollbarsOnMainThreadForPerformanceTesting) { m_forceUpdateScrollbarsOnMainThreadForPerformanceTesting = forceUpdateScrollbarsOnMainThreadForPerformanceTesting; }
    bool forceWebGLUsesLowPower() const { return m_forceWebGLUsesLowPower; } 
    void setForceWebGLUsesLowPower(bool forceWebGLUsesLowPower) { m_forceWebGLUsesLowPower = forceWebGLUsesLowPower; }
    ForcedAccessibilityValue forcedColorsAreInvertedAccessibilityValue() const { return m_forcedColorsAreInvertedAccessibilityValue; } 
    void setForcedColorsAreInvertedAccessibilityValue(ForcedAccessibilityValue forcedColorsAreInvertedAccessibilityValue) { m_forcedColorsAreInvertedAccessibilityValue = forcedColorsAreInvertedAccessibilityValue; }
    ForcedAccessibilityValue forcedDisplayIsMonochromeAccessibilityValue() const { return m_forcedDisplayIsMonochromeAccessibilityValue; } 
    void setForcedDisplayIsMonochromeAccessibilityValue(ForcedAccessibilityValue forcedDisplayIsMonochromeAccessibilityValue) { m_forcedDisplayIsMonochromeAccessibilityValue = forcedDisplayIsMonochromeAccessibilityValue; }
    ForcedAccessibilityValue forcedPrefersReducedMotionAccessibilityValue() const { return m_forcedPrefersReducedMotionAccessibilityValue; } 
    void setForcedPrefersReducedMotionAccessibilityValue(ForcedAccessibilityValue forcedPrefersReducedMotionAccessibilityValue) { m_forcedPrefersReducedMotionAccessibilityValue = forcedPrefersReducedMotionAccessibilityValue; }
    FrameFlattening frameFlattening() const { return m_frameFlattening; } 
    WEBCORE_EXPORT void setFrameFlattening(FrameFlattening);
    const String& ftpDirectoryTemplatePath() const { return m_ftpDirectoryTemplatePath; } 
    void setFTPDirectoryTemplatePath(const String& ftpDirectoryTemplatePath) { m_ftpDirectoryTemplatePath = ftpDirectoryTemplatePath; }
    bool geolocationFloorLevelEnabled() const { return m_geolocationFloorLevelEnabled; } 
    void setGeolocationFloorLevelEnabled(bool geolocationFloorLevelEnabled) { m_geolocationFloorLevelEnabled = geolocationFloorLevelEnabled; }
    bool googleAntiFlickerOptimizationQuirkEnabled() const { return m_googleAntiFlickerOptimizationQuirkEnabled; } 
    void setGoogleAntiFlickerOptimizationQuirkEnabled(bool googleAntiFlickerOptimizationQuirkEnabled) { m_googleAntiFlickerOptimizationQuirkEnabled = googleAntiFlickerOptimizationQuirkEnabled; }
    bool hiddenPageCSSAnimationSuspensionEnabled() const { return m_hiddenPageCSSAnimationSuspensionEnabled; } 
    WEBCORE_EXPORT void setHiddenPageCSSAnimationSuspensionEnabled(bool);
    bool hiddenPageDOMTimerThrottlingAutoIncreases() const { return m_hiddenPageDOMTimerThrottlingAutoIncreases; } 
    WEBCORE_EXPORT void setHiddenPageDOMTimerThrottlingAutoIncreases(bool);
    bool hiddenPageDOMTimerThrottlingEnabled() const { return m_hiddenPageDOMTimerThrottlingEnabled; } 
    WEBCORE_EXPORT void setHiddenPageDOMTimerThrottlingEnabled(bool);
    bool httpEquivEnabled() const { return m_httpEquivEnabled; } 
    void setHttpEquivEnabled(bool httpEquivEnabled) { m_httpEquivEnabled = httpEquivEnabled; }
    bool hyperlinkAuditingEnabled() const { return m_hyperlinkAuditingEnabled; } 
    void setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled) { m_hyperlinkAuditingEnabled = hyperlinkAuditingEnabled; }
    WEBCORE_EXPORT bool iceCandidateFilteringEnabled() const;
    WEBCORE_EXPORT void setICECandidateFilteringEnabled(bool);
    bool imageSubsamplingEnabled() const { return m_imageSubsamplingEnabled; } 
    void setImageSubsamplingEnabled(bool imageSubsamplingEnabled) { m_imageSubsamplingEnabled = imageSubsamplingEnabled; }
    WEBCORE_EXPORT bool areImagesEnabled() const;
    WEBCORE_EXPORT void setImagesEnabled(bool);
    bool incompleteImageBorderEnabled() const { return m_incompleteImageBorderEnabled; } 
    void setIncompleteImageBorderEnabled(bool incompleteImageBorderEnabled) { m_incompleteImageBorderEnabled = incompleteImageBorderEnabled; }
    double incrementalRenderingSuppressionTimeoutInSeconds() const { return m_incrementalRenderingSuppressionTimeoutInSeconds; } 
    void setIncrementalRenderingSuppressionTimeoutInSeconds(double incrementalRenderingSuppressionTimeoutInSeconds) { m_incrementalRenderingSuppressionTimeoutInSeconds = incrementalRenderingSuppressionTimeoutInSeconds; }
    bool inlineMediaPlaybackRequiresPlaysInlineAttribute() const { return m_inlineMediaPlaybackRequiresPlaysInlineAttribute; } 
    void setInlineMediaPlaybackRequiresPlaysInlineAttribute(bool inlineMediaPlaybackRequiresPlaysInlineAttribute) { m_inlineMediaPlaybackRequiresPlaysInlineAttribute = inlineMediaPlaybackRequiresPlaysInlineAttribute; }
    bool inputEventsEnabled() const { return m_inputEventsEnabled; } 
    void setInputEventsEnabled(bool inputEventsEnabled) { m_inputEventsEnabled = inputEventsEnabled; }
    bool interactiveFormValidationEnabled() const { return m_interactiveFormValidationEnabled; } 
    void setInteractiveFormValidationEnabled(bool interactiveFormValidationEnabled) { m_interactiveFormValidationEnabled = interactiveFormValidationEnabled; }
    bool invisibleAutoplayNotPermitted() const { return m_invisibleAutoplayNotPermitted; } 
    void setInvisibleAutoplayNotPermitted(bool invisibleAutoplayNotPermitted) { m_invisibleAutoplayNotPermitted = invisibleAutoplayNotPermitted; }
    bool isJavaEnabled() const { return m_javaEnabled; } 
    void setJavaEnabled(bool javaEnabled) { m_javaEnabled = javaEnabled; }
    bool isJavaEnabledForLocalFiles() const { return m_javaEnabledForLocalFiles; } 
    void setJavaEnabledForLocalFiles(bool javaEnabledForLocalFiles) { m_javaEnabledForLocalFiles = javaEnabledForLocalFiles; }
    bool javaScriptCanAccessClipboard() const { return m_javaScriptCanAccessClipboard; } 
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard) { m_javaScriptCanAccessClipboard = javaScriptCanAccessClipboard; }
    bool javaScriptCanOpenWindowsAutomatically() const { return m_javaScriptCanOpenWindowsAutomatically; } 
    void setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically) { m_javaScriptCanOpenWindowsAutomatically = javaScriptCanOpenWindowsAutomatically; }
    JSC::RuntimeFlags javaScriptRuntimeFlags() const { return m_javaScriptRuntimeFlags; } 
    void setJavaScriptRuntimeFlags(JSC::RuntimeFlags javaScriptRuntimeFlags) { m_javaScriptRuntimeFlags = javaScriptRuntimeFlags; }
    bool langAttributeAwareFormControlUIEnabled() const { return m_langAttributeAwareFormControlUIEnabled; } 
    void setLangAttributeAwareFormControlUIEnabled(bool langAttributeAwareFormControlUIEnabled) { m_langAttributeAwareFormControlUIEnabled = langAttributeAwareFormControlUIEnabled; }
    bool largeImageAsyncDecodingEnabled() const { return m_largeImageAsyncDecodingEnabled; } 
    void setLargeImageAsyncDecodingEnabled(bool largeImageAsyncDecodingEnabled) { m_largeImageAsyncDecodingEnabled = largeImageAsyncDecodingEnabled; }
    int layoutFallbackWidth() const { return m_layoutFallbackWidth; } 
    void setLayoutFallbackWidth(int layoutFallbackWidth) { m_layoutFallbackWidth = layoutFallbackWidth; }
    double layoutViewportHeightExpansionFactor() const { return m_layoutViewportHeightExpansionFactor; } 
    WEBCORE_EXPORT void setLayoutViewportHeightExpansionFactor(double);
    bool linkPreconnectEnabled() const { return m_linkPreconnectEnabled; } 
    void setLinkPreconnectEnabled(bool linkPreconnectEnabled) { m_linkPreconnectEnabled = linkPreconnectEnabled; }
    bool loadDeferringEnabled() const { return m_loadDeferringEnabled; } 
    void setLoadDeferringEnabled(bool loadDeferringEnabled) { m_loadDeferringEnabled = loadDeferringEnabled; }
    bool loadsImagesAutomatically() const { return m_loadsImagesAutomatically; } 
    WEBCORE_EXPORT void setLoadsImagesAutomatically(bool);
    bool loadsSiteIconsIgnoringImageLoadingSetting() const { return m_loadsSiteIconsIgnoringImageLoadingSetting; } 
    void setLoadsSiteIconsIgnoringImageLoadingSetting(bool loadsSiteIconsIgnoringImageLoadingSetting) { m_loadsSiteIconsIgnoringImageLoadingSetting = loadsSiteIconsIgnoringImageLoadingSetting; }
    bool localFileContentSniffingEnabled() const { return m_localFileContentSniffingEnabled; } 
    void setLocalFileContentSniffingEnabled(bool localFileContentSniffingEnabled) { m_localFileContentSniffingEnabled = localFileContentSniffingEnabled; }
    const String& localStorageDatabasePath() const { return m_localStorageDatabasePath; } 
    void setLocalStorageDatabasePath(const String& localStorageDatabasePath) { m_localStorageDatabasePath = localStorageDatabasePath; }
    bool localStorageEnabled() const { return m_localStorageEnabled; } 
    void setLocalStorageEnabled(bool localStorageEnabled) { m_localStorageEnabled = localStorageEnabled; }
    bool logsPageMessagesToSystemConsoleEnabled() const { return m_logsPageMessagesToSystemConsoleEnabled; } 
    void setLogsPageMessagesToSystemConsoleEnabled(bool logsPageMessagesToSystemConsoleEnabled) { m_logsPageMessagesToSystemConsoleEnabled = logsPageMessagesToSystemConsoleEnabled; }
    bool mainContentUserGestureOverrideEnabled() const { return m_mainContentUserGestureOverrideEnabled; } 
    void setMainContentUserGestureOverrideEnabled(bool mainContentUserGestureOverrideEnabled) { m_mainContentUserGestureOverrideEnabled = mainContentUserGestureOverrideEnabled; }
    double maxParseDuration() const { return m_maxParseDuration; } 
    void setMaxParseDuration(double maxParseDuration) { m_maxParseDuration = maxParseDuration; }
    unsigned maximumAccelerated2dCanvasSize() const { return m_maximumAccelerated2dCanvasSize; } 
    void setMaximumAccelerated2dCanvasSize(unsigned maximumAccelerated2dCanvasSize) { m_maximumAccelerated2dCanvasSize = maximumAccelerated2dCanvasSize; }
    unsigned maximumHTMLParserDOMTreeDepth() const { return m_maximumHTMLParserDOMTreeDepth; } 
    void setMaximumHTMLParserDOMTreeDepth(unsigned maximumHTMLParserDOMTreeDepth) { m_maximumHTMLParserDOMTreeDepth = maximumHTMLParserDOMTreeDepth; }
    unsigned maximumPlugInSnapshotAttempts() const { return m_maximumPlugInSnapshotAttempts; } 
    void setMaximumPlugInSnapshotAttempts(unsigned maximumPlugInSnapshotAttempts) { m_maximumPlugInSnapshotAttempts = maximumPlugInSnapshotAttempts; }
    bool mediaCapabilitiesEnabled() const { return m_mediaCapabilitiesEnabled; } 
    void setMediaCapabilitiesEnabled(bool mediaCapabilitiesEnabled) { m_mediaCapabilitiesEnabled = mediaCapabilitiesEnabled; }
    bool mediaCapabilitiesExtensionsEnabled() const { return m_mediaCapabilitiesExtensionsEnabled; } 
    void setMediaCapabilitiesExtensionsEnabled(bool mediaCapabilitiesExtensionsEnabled) { m_mediaCapabilitiesExtensionsEnabled = mediaCapabilitiesExtensionsEnabled; }
    bool mediaControlsScaleWithPageZoom() const { return m_mediaControlsScaleWithPageZoom; } 
    void setMediaControlsScaleWithPageZoom(bool mediaControlsScaleWithPageZoom) { m_mediaControlsScaleWithPageZoom = mediaControlsScaleWithPageZoom; }
    bool mediaDataLoadsAutomatically() const { return m_mediaDataLoadsAutomatically; } 
    void setMediaDataLoadsAutomatically(bool mediaDataLoadsAutomatically) { m_mediaDataLoadsAutomatically = mediaDataLoadsAutomatically; }
    bool mediaEnabled() const { return m_mediaEnabled; } 
    void setMediaEnabled(bool mediaEnabled) { m_mediaEnabled = mediaEnabled; }
    const String& mediaKeysStorageDirectory() const { return m_mediaKeysStorageDirectory; } 
    void setMediaKeysStorageDirectory(const String& mediaKeysStorageDirectory) { m_mediaKeysStorageDirectory = mediaKeysStorageDirectory; }
    bool mediaPreloadingEnabled() const { return m_mediaPreloadingEnabled; } 
    void setMediaPreloadingEnabled(bool mediaPreloadingEnabled) { m_mediaPreloadingEnabled = mediaPreloadingEnabled; }
    const String& mediaTypeOverride() const { return m_mediaTypeOverride; } 
    WEBCORE_EXPORT void setMediaTypeOverride(const String&);
    bool mediaUserGestureInheritsFromDocument() const { return m_mediaUserGestureInheritsFromDocument; } 
    void setMediaUserGestureInheritsFromDocument(bool mediaUserGestureInheritsFromDocument) { m_mediaUserGestureInheritsFromDocument = mediaUserGestureInheritsFromDocument; }
    int minimumAccelerated2dCanvasSize() const { return m_minimumAccelerated2dCanvasSize; } 
    void setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize) { m_minimumAccelerated2dCanvasSize = minimumAccelerated2dCanvasSize; }
    int minimumFontSize() const { return m_minimumFontSize; } 
    WEBCORE_EXPORT void setMinimumFontSize(int);
    int minimumLogicalFontSize() const { return m_minimumLogicalFontSize; } 
    WEBCORE_EXPORT void setMinimumLogicalFontSize(int);
    bool needsAcrobatFrameReloadingQuirk() const { return m_needsAdobeFrameReloadingQuirk; } 
    void setNeedsAdobeFrameReloadingQuirk(bool needsAdobeFrameReloadingQuirk) { m_needsAdobeFrameReloadingQuirk = needsAdobeFrameReloadingQuirk; }
    bool needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk() const { return m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk; } 
    void setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(bool needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk) { m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk = needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk; }
    bool needsFrameNameFallbackToIdQuirk() const { return m_needsFrameNameFallbackToIdQuirk; } 
    void setNeedsFrameNameFallbackToIdQuirk(bool needsFrameNameFallbackToIdQuirk) { m_needsFrameNameFallbackToIdQuirk = needsFrameNameFallbackToIdQuirk; }
    bool needsIsLoadingInAPISenseQuirk() const { return m_needsIsLoadingInAPISenseQuirk; } 
    void setNeedsIsLoadingInAPISenseQuirk(bool needsIsLoadingInAPISenseQuirk) { m_needsIsLoadingInAPISenseQuirk = needsIsLoadingInAPISenseQuirk; }
    bool needsKeyboardEventDisambiguationQuirks() const { return m_needsKeyboardEventDisambiguationQuirks; } 
    void setNeedsKeyboardEventDisambiguationQuirks(bool needsKeyboardEventDisambiguationQuirks) { m_needsKeyboardEventDisambiguationQuirks = needsKeyboardEventDisambiguationQuirks; }
    WEBCORE_EXPORT bool needsSiteSpecificQuirks() const;
    void setNeedsSiteSpecificQuirks(bool needsSiteSpecificQuirks) { m_needsSiteSpecificQuirks = needsSiteSpecificQuirks; }
    bool needsStorageAccessFromFileURLsQuirk() const { return m_needsStorageAccessFromFileURLsQuirk; } 
    void setNeedsStorageAccessFromFileURLsQuirk(bool needsStorageAccessFromFileURLsQuirk) { m_needsStorageAccessFromFileURLsQuirk = needsStorageAccessFromFileURLsQuirk; }
    bool notificationsEnabled() const { return m_notificationsEnabled; } 
    void setNotificationsEnabled(bool notificationsEnabled) { m_notificationsEnabled = notificationsEnabled; }
    bool offlineWebApplicationCacheEnabled() const { return m_offlineWebApplicationCacheEnabled; } 
    void setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled) { m_offlineWebApplicationCacheEnabled = offlineWebApplicationCacheEnabled; }
    bool pageCacheSupportsPlugins() const { return m_pageCacheSupportsPlugins; } 
    void setPageCacheSupportsPlugins(bool pageCacheSupportsPlugins) { m_pageCacheSupportsPlugins = pageCacheSupportsPlugins; }
    bool paginateDuringLayoutEnabled() const { return m_paginateDuringLayoutEnabled; } 
    void setPaginateDuringLayoutEnabled(bool paginateDuringLayoutEnabled) { m_paginateDuringLayoutEnabled = paginateDuringLayoutEnabled; }
    bool passiveTouchListenersAsDefaultOnDocument() const { return m_passiveTouchListenersAsDefaultOnDocument; } 
    void setPassiveTouchListenersAsDefaultOnDocument(bool passiveTouchListenersAsDefaultOnDocument) { m_passiveTouchListenersAsDefaultOnDocument = passiveTouchListenersAsDefaultOnDocument; }
    double passwordEchoDurationInSeconds() const { return m_passwordEchoDurationInSeconds; } 
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds) { m_passwordEchoDurationInSeconds = passwordEchoDurationInSeconds; }
    bool passwordEchoEnabled() const { return m_passwordEchoEnabled; } 
    void setPasswordEchoEnabled(bool passwordEchoEnabled) { m_passwordEchoEnabled = passwordEchoEnabled; }
    PDFImageCachingPolicy pdfImageCachingPolicy() const { return m_pdfImageCachingPolicy; } 
    void setPdfImageCachingPolicy(PDFImageCachingPolicy pdfImageCachingPolicy) { m_pdfImageCachingPolicy = pdfImageCachingPolicy; }
    bool plugInSnapshottingEnabled() const { return m_plugInSnapshottingEnabled; } 
    void setPlugInSnapshottingEnabled(bool plugInSnapshottingEnabled) { m_plugInSnapshottingEnabled = plugInSnapshottingEnabled; }
    bool arePluginsEnabled() const { return m_pluginsEnabled; } 
    WEBCORE_EXPORT void setPluginsEnabled(bool);
    bool preferMIMETypeForImages() const { return m_preferMIMETypeForImages; } 
    void setPreferMIMETypeForImages(bool preferMIMETypeForImages) { m_preferMIMETypeForImages = preferMIMETypeForImages; }
    bool preventKeyboardDOMEventDispatch() const { return m_preventKeyboardDOMEventDispatch; } 
    void setPreventKeyboardDOMEventDispatch(bool preventKeyboardDOMEventDispatch) { m_preventKeyboardDOMEventDispatch = preventKeyboardDOMEventDispatch; }
    bool primaryPlugInSnapshotDetectionEnabled() const { return m_primaryPlugInSnapshotDetectionEnabled; } 
    void setPrimaryPlugInSnapshotDetectionEnabled(bool primaryPlugInSnapshotDetectionEnabled) { m_primaryPlugInSnapshotDetectionEnabled = primaryPlugInSnapshotDetectionEnabled; }
    bool punchOutWhiteBackgroundsInDarkMode() const { return m_punchOutWhiteBackgroundsInDarkMode; } 
    WEBCORE_EXPORT void setPunchOutWhiteBackgroundsInDarkMode(bool);
    bool quickTimePluginReplacementEnabled() const { return m_quickTimePluginReplacementEnabled; } 
    void setQuickTimePluginReplacementEnabled(bool quickTimePluginReplacementEnabled) { m_quickTimePluginReplacementEnabled = quickTimePluginReplacementEnabled; }
    bool repaintOutsideLayoutEnabled() const { return m_repaintOutsideLayoutEnabled; } 
    void setRepaintOutsideLayoutEnabled(bool repaintOutsideLayoutEnabled) { m_repaintOutsideLayoutEnabled = repaintOutsideLayoutEnabled; }
    bool requestAnimationFrameEnabled() const { return m_requestAnimationFrameEnabled; } 
    void setRequestAnimationFrameEnabled(bool requestAnimationFrameEnabled) { m_requestAnimationFrameEnabled = requestAnimationFrameEnabled; }
    bool requiresUserGestureToLoadVideo() const { return m_requiresUserGestureToLoadVideo; } 
    void setRequiresUserGestureToLoadVideo(bool requiresUserGestureToLoadVideo) { m_requiresUserGestureToLoadVideo = requiresUserGestureToLoadVideo; }
    bool resourceUsageOverlayVisible() const { return m_resourceUsageOverlayVisible; } 
    WEBCORE_EXPORT void setResourceUsageOverlayVisible(bool);
    WEBCORE_EXPORT bool isScriptEnabled() const;
    void setScriptEnabled(bool scriptEnabled) { m_scriptEnabled = scriptEnabled; }
    bool scriptMarkupEnabled() const { return m_scriptMarkupEnabled; } 
    void setScriptMarkupEnabled(bool scriptMarkupEnabled) { m_scriptMarkupEnabled = scriptMarkupEnabled; }
    bool scrollingCoordinatorEnabled() const { return m_scrollingCoordinatorEnabled; } 
    void setScrollingCoordinatorEnabled(bool scrollingCoordinatorEnabled) { m_scrollingCoordinatorEnabled = scrollingCoordinatorEnabled; }
    bool scrollingPerformanceLoggingEnabled() const { return m_scrollingPerformanceLoggingEnabled; } 
    WEBCORE_EXPORT void setScrollingPerformanceLoggingEnabled(bool);
    bool scrollingTreeIncludesFrames() const { return m_scrollingTreeIncludesFrames; } 
    void setScrollingTreeIncludesFrames(bool scrollingTreeIncludesFrames) { m_scrollingTreeIncludesFrames = scrollingTreeIncludesFrames; }
    bool selectTrailingWhitespaceEnabled() const { return m_selectTrailingWhitespaceEnabled; } 
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled) { m_selectTrailingWhitespaceEnabled = selectTrailingWhitespaceEnabled; }
    bool selectionAcrossShadowBoundariesEnabled() const { return m_selectionAcrossShadowBoundariesEnabled; } 
    void setSelectionAcrossShadowBoundariesEnabled(bool selectionAcrossShadowBoundariesEnabled) { m_selectionAcrossShadowBoundariesEnabled = selectionAcrossShadowBoundariesEnabled; }
    bool selectionPaintingWithoutSelectionGapsEnabled() const { return m_selectionPaintingWithoutSelectionGapsEnabled; } 
    void setSelectionPaintingWithoutSelectionGapsEnabled(bool selectionPaintingWithoutSelectionGapsEnabled) { m_selectionPaintingWithoutSelectionGapsEnabled = selectionPaintingWithoutSelectionGapsEnabled; }
    unsigned sessionStorageQuota() const { return m_sessionStorageQuota; } 
    void setSessionStorageQuota(unsigned sessionStorageQuota) { m_sessionStorageQuota = sessionStorageQuota; }
    bool shouldAllowDesignSystemUIFonts() const { return m_shouldAllowDesignSystemUIFonts; } 
    WEBCORE_EXPORT void setShouldAllowDesignSystemUIFonts(bool);
    bool shouldAllowUserInstalledFonts() const { return m_shouldAllowUserInstalledFonts; } 
    WEBCORE_EXPORT void setShouldAllowUserInstalledFonts(bool);
    bool shouldConvertInvalidURLsToBlank() const { return m_shouldConvertInvalidURLsToBlank; } 
    void setShouldConvertInvalidURLsToBlank(bool shouldConvertInvalidURLsToBlank) { m_shouldConvertInvalidURLsToBlank = shouldConvertInvalidURLsToBlank; }
    bool shouldConvertPositionStyleOnCopy() const { return m_shouldConvertPositionStyleOnCopy; } 
    void setShouldConvertPositionStyleOnCopy(bool shouldConvertPositionStyleOnCopy) { m_shouldConvertPositionStyleOnCopy = shouldConvertPositionStyleOnCopy; }
    bool shouldDecidePolicyBeforeLoadingQuickLookPreview() const { return m_shouldDecidePolicyBeforeLoadingQuickLookPreview; } 
    void setShouldDecidePolicyBeforeLoadingQuickLookPreview(bool shouldDecidePolicyBeforeLoadingQuickLookPreview) { m_shouldDecidePolicyBeforeLoadingQuickLookPreview = shouldDecidePolicyBeforeLoadingQuickLookPreview; }
    bool shouldDeferAsynchronousScriptsUntilAfterDocumentLoad() const { return m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoad; } 
    void setShouldDeferAsynchronousScriptsUntilAfterDocumentLoad(bool shouldDeferAsynchronousScriptsUntilAfterDocumentLoad) { m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoad = shouldDeferAsynchronousScriptsUntilAfterDocumentLoad; }
    bool shouldDispatchSyntheticMouseEventsWhenModifyingSelection() const { return m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection; } 
    void setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(bool shouldDispatchSyntheticMouseEventsWhenModifyingSelection) { m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection = shouldDispatchSyntheticMouseEventsWhenModifyingSelection; }
    bool shouldDispatchSyntheticMouseOutAfterSyntheticClick() const { return m_shouldDispatchSyntheticMouseOutAfterSyntheticClick; } 
    void setShouldDispatchSyntheticMouseOutAfterSyntheticClick(bool shouldDispatchSyntheticMouseOutAfterSyntheticClick) { m_shouldDispatchSyntheticMouseOutAfterSyntheticClick = shouldDispatchSyntheticMouseOutAfterSyntheticClick; }
    bool shouldIgnoreFontLoadCompletions() const { return m_shouldIgnoreFontLoadCompletions; } 
    void setShouldIgnoreFontLoadCompletions(bool shouldIgnoreFontLoadCompletions) { m_shouldIgnoreFontLoadCompletions = shouldIgnoreFontLoadCompletions; }
    bool shouldIgnoreMetaViewport() const { return m_shouldIgnoreMetaViewport; } 
    void setShouldIgnoreMetaViewport(bool shouldIgnoreMetaViewport) { m_shouldIgnoreMetaViewport = shouldIgnoreMetaViewport; }
    bool shouldInjectUserScriptsInInitialEmptyDocument() const { return m_shouldInjectUserScriptsInInitialEmptyDocument; } 
    void setShouldInjectUserScriptsInInitialEmptyDocument(bool shouldInjectUserScriptsInInitialEmptyDocument) { m_shouldInjectUserScriptsInInitialEmptyDocument = shouldInjectUserScriptsInInitialEmptyDocument; }
    bool shouldPrintBackgrounds() const { return m_shouldPrintBackgrounds; } 
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds) { m_shouldPrintBackgrounds = shouldPrintBackgrounds; }
    bool shouldRespectImageOrientation() const { return m_shouldRespectImageOrientation; } 
    void setShouldRespectImageOrientation(bool shouldRespectImageOrientation) { m_shouldRespectImageOrientation = shouldRespectImageOrientation; }
    bool shouldSuppressTextInputFromEditingDuringProvisionalNavigation() const { return m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation; } 
    void setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(bool shouldSuppressTextInputFromEditingDuringProvisionalNavigation) { m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation = shouldSuppressTextInputFromEditingDuringProvisionalNavigation; }
    bool showDebugBorders() const { return m_showDebugBorders; } 
    WEBCORE_EXPORT void setShowDebugBorders(bool);
    bool showRepaintCounter() const { return m_showRepaintCounter; } 
    WEBCORE_EXPORT void setShowRepaintCounter(bool);
    bool showTiledScrollingIndicator() const { return m_showTiledScrollingIndicator; } 
    void setShowTiledScrollingIndicator(bool showTiledScrollingIndicator) { m_showTiledScrollingIndicator = showTiledScrollingIndicator; }
    bool showsToolTipOverTruncatedText() const { return m_showsToolTipOverTruncatedText; } 
    void setShowsToolTipOverTruncatedText(bool showsToolTipOverTruncatedText) { m_showsToolTipOverTruncatedText = showsToolTipOverTruncatedText; }
    bool showsURLsInToolTips() const { return m_showsURLsInToolTips; } 
    void setShowsURLsInToolTips(bool showsURLsInToolTips) { m_showsURLsInToolTips = showsURLsInToolTips; }
    bool shrinksStandaloneImagesToFit() const { return m_shrinksStandaloneImagesToFit; } 
    void setShrinksStandaloneImagesToFit(bool shrinksStandaloneImagesToFit) { m_shrinksStandaloneImagesToFit = shrinksStandaloneImagesToFit; }
    bool simpleLineLayoutDebugBordersEnabled() const { return m_simpleLineLayoutDebugBordersEnabled; } 
    WEBCORE_EXPORT void setSimpleLineLayoutDebugBordersEnabled(bool);
    bool simpleLineLayoutEnabled() const { return m_simpleLineLayoutEnabled; } 
    WEBCORE_EXPORT void setSimpleLineLayoutEnabled(bool);
    bool smartInsertDeleteEnabled() const { return m_smartInsertDeleteEnabled; } 
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled) { m_smartInsertDeleteEnabled = smartInsertDeleteEnabled; }
    bool snapshotAllPlugIns() const { return m_snapshotAllPlugIns; } 
    void setSnapshotAllPlugIns(bool snapshotAllPlugIns) { m_snapshotAllPlugIns = snapshotAllPlugIns; }
    bool spatialNavigationEnabled() const { return m_spatialNavigationEnabled; } 
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled) { m_spatialNavigationEnabled = spatialNavigationEnabled; }
    bool springTimingFunctionEnabled() const { return m_springTimingFunctionEnabled; } 
    void setSpringTimingFunctionEnabled(bool springTimingFunctionEnabled) { m_springTimingFunctionEnabled = springTimingFunctionEnabled; }
    bool standalone() const { return m_standalone; } 
    void setStandalone(bool standalone) { m_standalone = standalone; }
    bool storageAccessAPIEnabled() const { return m_storageAccessAPIEnabled; } 
    void setStorageAccessAPIEnabled(bool storageAccessAPIEnabled) { m_storageAccessAPIEnabled = storageAccessAPIEnabled; }
    SecurityOrigin::StorageBlockingPolicy storageBlockingPolicy() const { return m_storageBlockingPolicy; } 
    WEBCORE_EXPORT void setStorageBlockingPolicy(SecurityOrigin::StorageBlockingPolicy);
    bool subpixelAntialiasedLayerTextEnabled() const { return m_subpixelAntialiasedLayerTextEnabled; } 
    WEBCORE_EXPORT void setSubpixelAntialiasedLayerTextEnabled(bool);
    bool subpixelCSSOMElementMetricsEnabled() const { return m_subpixelCSSOMElementMetricsEnabled; } 
    void setSubpixelCSSOMElementMetricsEnabled(bool subpixelCSSOMElementMetricsEnabled) { m_subpixelCSSOMElementMetricsEnabled = subpixelCSSOMElementMetricsEnabled; }
    bool subresourceIntegrityEnabled() const { return m_subresourceIntegrityEnabled; } 
    void setSubresourceIntegrityEnabled(bool subresourceIntegrityEnabled) { m_subresourceIntegrityEnabled = subresourceIntegrityEnabled; }
    bool suppressesIncrementalRendering() const { return m_suppressesIncrementalRendering; } 
    void setSuppressesIncrementalRendering(bool suppressesIncrementalRendering) { m_suppressesIncrementalRendering = suppressesIncrementalRendering; }
    bool syntheticEditingCommandsEnabled() const { return m_syntheticEditingCommandsEnabled; } 
    void setSyntheticEditingCommandsEnabled(bool syntheticEditingCommandsEnabled) { m_syntheticEditingCommandsEnabled = syntheticEditingCommandsEnabled; }
    TextDirection systemLayoutDirection() const { return m_systemLayoutDirection; } 
    void setSystemLayoutDirection(TextDirection systemLayoutDirection) { m_systemLayoutDirection = systemLayoutDirection; }
    bool telephoneNumberParsingEnabled() const { return m_telephoneNumberParsingEnabled; } 
    void setTelephoneNumberParsingEnabled(bool telephoneNumberParsingEnabled) { m_telephoneNumberParsingEnabled = telephoneNumberParsingEnabled; }
    bool temporaryTileCohortRetentionEnabled() const { return m_temporaryTileCohortRetentionEnabled; } 
    void setTemporaryTileCohortRetentionEnabled(bool temporaryTileCohortRetentionEnabled) { m_temporaryTileCohortRetentionEnabled = temporaryTileCohortRetentionEnabled; }
    bool textAreasAreResizable() const { return m_textAreasAreResizable; } 
    WEBCORE_EXPORT void setTextAreasAreResizable(bool);
    TextDirectionSubmenuInclusionBehavior textDirectionSubmenuInclusionBehavior() const { return m_textDirectionSubmenuInclusionBehavior; } 
    void setTextDirectionSubmenuInclusionBehavior(TextDirectionSubmenuInclusionBehavior textDirectionSubmenuInclusionBehavior) { m_textDirectionSubmenuInclusionBehavior = textDirectionSubmenuInclusionBehavior; }
    bool thirdPartyIframeRedirectBlockingEnabled() const { return m_thirdPartyIframeRedirectBlockingEnabled; } 
    void setThirdPartyIframeRedirectBlockingEnabled(bool thirdPartyIframeRedirectBlockingEnabled) { m_thirdPartyIframeRedirectBlockingEnabled = thirdPartyIframeRedirectBlockingEnabled; }
    Seconds timeWithoutMouseMovementBeforeHidingControls() const { return m_timeWithoutMouseMovementBeforeHidingControls; } 
    void setTimeWithoutMouseMovementBeforeHidingControls(Seconds timeWithoutMouseMovementBeforeHidingControls) { m_timeWithoutMouseMovementBeforeHidingControls = timeWithoutMouseMovementBeforeHidingControls; }
    bool treatIPAddressAsDomain() const { return m_treatIPAddressAsDomain; } 
    void setTreatIPAddressAsDomain(bool treatIPAddressAsDomain) { m_treatIPAddressAsDomain = treatIPAddressAsDomain; }
    bool treatsAnyTextCSSLinkAsStylesheet() const { return m_treatsAnyTextCSSLinkAsStylesheet; } 
    void setTreatsAnyTextCSSLinkAsStylesheet(bool treatsAnyTextCSSLinkAsStylesheet) { m_treatsAnyTextCSSLinkAsStylesheet = treatsAnyTextCSSLinkAsStylesheet; }
    bool unhandledPromiseRejectionToConsoleEnabled() const { return m_unhandledPromiseRejectionToConsoleEnabled; } 
    void setUnhandledPromiseRejectionToConsoleEnabled(bool unhandledPromiseRejectionToConsoleEnabled) { m_unhandledPromiseRejectionToConsoleEnabled = unhandledPromiseRejectionToConsoleEnabled; }
    bool unifiedTextCheckerEnabled() const { return m_unifiedTextCheckerEnabled; } 
    void setUnifiedTextCheckerEnabled(bool unifiedTextCheckerEnabled) { m_unifiedTextCheckerEnabled = unifiedTextCheckerEnabled; }
    bool useAnonymousModeWhenFetchingMaskImages() const { return m_useAnonymousModeWhenFetchingMaskImages; } 
    void setUseAnonymousModeWhenFetchingMaskImages(bool useAnonymousModeWhenFetchingMaskImages) { m_useAnonymousModeWhenFetchingMaskImages = useAnonymousModeWhenFetchingMaskImages; }
    bool useGiantTiles() const { return m_useGiantTiles; } 
    void setUseGiantTiles(bool useGiantTiles) { m_useGiantTiles = useGiantTiles; }
    bool useImageDocumentForSubframePDF() const { return m_useImageDocumentForSubframePDF; } 
    void setUseImageDocumentForSubframePDF(bool useImageDocumentForSubframePDF) { m_useImageDocumentForSubframePDF = useImageDocumentForSubframePDF; }
    bool useLegacyBackgroundSizeShorthandBehavior() const { return m_useLegacyBackgroundSizeShorthandBehavior; } 
    void setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior) { m_useLegacyBackgroundSizeShorthandBehavior = useLegacyBackgroundSizeShorthandBehavior; }
    bool useLegacyTextAlignPositionedElementBehavior() const { return m_useLegacyTextAlignPositionedElementBehavior; } 
    void setUseLegacyTextAlignPositionedElementBehavior(bool useLegacyTextAlignPositionedElementBehavior) { m_useLegacyTextAlignPositionedElementBehavior = useLegacyTextAlignPositionedElementBehavior; }
    bool usePreHTML5ParserQuirks() const { return m_usePreHTML5ParserQuirks; } 
    void setUsePreHTML5ParserQuirks(bool usePreHTML5ParserQuirks) { m_usePreHTML5ParserQuirks = usePreHTML5ParserQuirks; }
    UserInterfaceDirectionPolicy userInterfaceDirectionPolicy() const { return m_userInterfaceDirectionPolicy; } 
    void setUserInterfaceDirectionPolicy(UserInterfaceDirectionPolicy userInterfaceDirectionPolicy) { m_userInterfaceDirectionPolicy = userInterfaceDirectionPolicy; }
    const URL& userStyleSheetLocation() const { return m_userStyleSheetLocation; } 
    WEBCORE_EXPORT void setUserStyleSheetLocation(const URL&);
    bool usesEncodingDetector() const { return m_usesEncodingDetector; } 
    void setUsesEncodingDetector(bool usesEncodingDetector) { m_usesEncodingDetector = usesEncodingDetector; }
    bool usesPageCache() const { return m_usesPageCache; } 
    WEBCORE_EXPORT void setUsesPageCache(bool);
    int validationMessageTimerMagnification() const { return m_validationMessageTimerMagnification; } 
    void setValidationMessageTimerMagnification(int validationMessageTimerMagnification) { m_validationMessageTimerMagnification = validationMessageTimerMagnification; }
    bool videoPlaybackRequiresUserGesture() const { return m_videoPlaybackRequiresUserGesture; } 
    void setVideoPlaybackRequiresUserGesture(bool videoPlaybackRequiresUserGesture) { m_videoPlaybackRequiresUserGesture = videoPlaybackRequiresUserGesture; }
    bool viewportFitEnabled() const { return m_viewportFitEnabled; } 
    void setViewportFitEnabled(bool viewportFitEnabled) { m_viewportFitEnabled = viewportFitEnabled; }
    DebugOverlayRegions visibleDebugOverlayRegions() const { return m_visibleDebugOverlayRegions; } 
    void setVisibleDebugOverlayRegions(DebugOverlayRegions visibleDebugOverlayRegions) { m_visibleDebugOverlayRegions = visibleDebugOverlayRegions; }
    bool visualViewportAPIEnabled() const { return m_visualViewportAPIEnabled; } 
    void setVisualViewportAPIEnabled(bool visualViewportAPIEnabled) { m_visualViewportAPIEnabled = visualViewportAPIEnabled; }
    bool visualViewportEnabled() const { return m_visualViewportEnabled; } 
    WEBCORE_EXPORT void setVisualViewportEnabled(bool);
    bool wantsBalancedSetDefersLoadingBehavior() const { return m_wantsBalancedSetDefersLoadingBehavior; } 
    void setWantsBalancedSetDefersLoadingBehavior(bool wantsBalancedSetDefersLoadingBehavior) { m_wantsBalancedSetDefersLoadingBehavior = wantsBalancedSetDefersLoadingBehavior; }
    bool webAudioEnabled() const { return m_webAudioEnabled; } 
    void setWebAudioEnabled(bool webAudioEnabled) { m_webAudioEnabled = webAudioEnabled; }
    bool webGLEnabled() const { return m_webGLEnabled; } 
    void setWebGLEnabled(bool webGLEnabled) { m_webGLEnabled = webGLEnabled; }
    bool webGLErrorsToConsoleEnabled() const { return m_webGLErrorsToConsoleEnabled; } 
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled) { m_webGLErrorsToConsoleEnabled = webGLErrorsToConsoleEnabled; }
    WEBCORE_EXPORT bool webSecurityEnabled() const;
    void setWebSecurityEnabled(bool webSecurityEnabled) { m_webSecurityEnabled = webSecurityEnabled; }
    bool webkitImageReadyEventEnabled() const { return m_webkitImageReadyEventEnabled; } 
    void setWebkitImageReadyEventEnabled(bool webkitImageReadyEventEnabled) { m_webkitImageReadyEventEnabled = webkitImageReadyEventEnabled; }
    bool windowFocusRestricted() const { return m_windowFocusRestricted; } 
    void setWindowFocusRestricted(bool windowFocusRestricted) { m_windowFocusRestricted = windowFocusRestricted; }
    bool xssAuditorEnabled() const { return m_xssAuditorEnabled; } 
    void setXSSAuditorEnabled(bool xssAuditorEnabled) { m_xssAuditorEnabled = xssAuditorEnabled; }
    bool youTubeFlashPluginReplacementEnabled() const { return m_youTubeFlashPluginReplacementEnabled; } 
    void setYouTubeFlashPluginReplacementEnabled(bool youTubeFlashPluginReplacementEnabled) { m_youTubeFlashPluginReplacementEnabled = youTubeFlashPluginReplacementEnabled; }

#if ENABLE(APPLE_PAY)
    bool applePayCapabilityDisclosureAllowed() const { return m_applePayCapabilityDisclosureAllowed; } 
    void setApplePayCapabilityDisclosureAllowed(bool applePayCapabilityDisclosureAllowed) { m_applePayCapabilityDisclosureAllowed = applePayCapabilityDisclosureAllowed; }
    bool applePayEnabled() const { return m_applePayEnabled; } 
    void setApplePayEnabled(bool applePayEnabled) { m_applePayEnabled = applePayEnabled; }
#endif

#if ENABLE(APPLE_PAY_REMOTE_UI)
    bool applePayRemoteUIEnabled() const { return m_applePayRemoteUIEnabled; } 
    void setApplePayRemoteUIEnabled(bool applePayRemoteUIEnabled) { m_applePayRemoteUIEnabled = applePayRemoteUIEnabled; }
#endif

#if ENABLE(DATA_DETECTION)
    DataDetectorTypes dataDetectorTypes() const { return m_dataDetectorTypes; } 
    void setDataDetectorTypes(DataDetectorTypes dataDetectorTypes) { m_dataDetectorTypes = dataDetectorTypes; }
#endif

#if ENABLE(DEVICE_ORIENTATION)
    bool deviceOrientationEventEnabled() const { return m_deviceOrientationEventEnabled; } 
    void setDeviceOrientationEventEnabled(bool deviceOrientationEventEnabled) { m_deviceOrientationEventEnabled = deviceOrientationEventEnabled; }
    bool deviceOrientationPermissionAPIEnabled() const { return m_deviceOrientationPermissionAPIEnabled; } 
    void setDeviceOrientationPermissionAPIEnabled(bool deviceOrientationPermissionAPIEnabled) { m_deviceOrientationPermissionAPIEnabled = deviceOrientationPermissionAPIEnabled; }
#endif

#if ENABLE(FULLSCREEN_API)
    bool fullScreenEnabled() const { return m_fullScreenEnabled; } 
    void setFullScreenEnabled(bool fullScreenEnabled) { m_fullScreenEnabled = fullScreenEnabled; }
#endif

#if ENABLE(MEDIA_SOURCE)
    int maximumSourceBufferSize() const { return m_maximumSourceBufferSize; } 
    void setMaximumSourceBufferSize(int maximumSourceBufferSize) { m_maximumSourceBufferSize = maximumSourceBufferSize; }
    bool mediaSourceEnabled() const { return m_mediaSourceEnabled; } 
    void setMediaSourceEnabled(bool mediaSourceEnabled) { m_mediaSourceEnabled = mediaSourceEnabled; }
    bool sourceBufferChangeTypeEnabled() const { return m_sourceBufferChangeTypeEnabled; } 
    void setSourceBufferChangeTypeEnabled(bool sourceBufferChangeTypeEnabled) { m_sourceBufferChangeTypeEnabled = sourceBufferChangeTypeEnabled; }
#endif

#if ENABLE(MEDIA_STREAM)
    WEBCORE_EXPORT bool mediaCaptureRequiresSecureConnection() const;
    void setMediaCaptureRequiresSecureConnection(bool mediaCaptureRequiresSecureConnection) { m_mediaCaptureRequiresSecureConnection = mediaCaptureRequiresSecureConnection; }
    const String& mediaDeviceIdentifierStorageDirectory() const { return m_mediaDeviceIdentifierStorageDirectory; } 
    void setMediaDeviceIdentifierStorageDirectory(const String& mediaDeviceIdentifierStorageDirectory) { m_mediaDeviceIdentifierStorageDirectory = mediaDeviceIdentifierStorageDirectory; }
    WEBCORE_EXPORT bool mockCaptureDevicesEnabled() const;
    WEBCORE_EXPORT void setMockCaptureDevicesEnabled(bool);
#endif

#if ENABLE(OVERFLOW_SCROLLING_TOUCH)
    bool legacyOverflowScrollingTouchEnabled() const { return m_legacyOverflowScrollingTouchEnabled; } 
    WEBCORE_EXPORT void setLegacyOverflowScrollingTouchEnabled(bool);
#endif

#if ENABLE(PAYMENT_REQUEST)
    bool paymentRequestEnabled() const { return m_paymentRequestEnabled; } 
    void setPaymentRequestEnabled(bool paymentRequestEnabled) { m_paymentRequestEnabled = paymentRequestEnabled; }
#endif

#if ENABLE(RESIZE_OBSERVER)
    bool resizeObserverEnabled() const { return m_resizeObserverEnabled; } 
    void setResizeObserverEnabled(bool resizeObserverEnabled) { m_resizeObserverEnabled = resizeObserverEnabled; }
#endif

#if ENABLE(RUBBER_BANDING)
    bool rubberBandingForSubScrollableRegionsEnabled() const { return m_rubberBandingForSubScrollableRegionsEnabled; } 
    void setRubberBandingForSubScrollableRegionsEnabled(bool rubberBandingForSubScrollableRegionsEnabled) { m_rubberBandingForSubScrollableRegionsEnabled = rubberBandingForSubScrollableRegionsEnabled; }
#endif

#if ENABLE(SERVICE_CONTROLS)
    bool imageControlsEnabled() const { return m_imageControlsEnabled; } 
    void setImageControlsEnabled(bool imageControlsEnabled) { m_imageControlsEnabled = imageControlsEnabled; }
    bool serviceControlsEnabled() const { return m_serviceControlsEnabled; } 
    void setServiceControlsEnabled(bool serviceControlsEnabled) { m_serviceControlsEnabled = serviceControlsEnabled; }
#endif

#if ENABLE(SMOOTH_SCROLLING)
    bool scrollAnimatorEnabled() const { return m_scrollAnimatorEnabled; } 
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled) { m_scrollAnimatorEnabled = scrollAnimatorEnabled; }
#endif

#if ENABLE(TEXT_AUTOSIZING)
    float minimumZoomFontSize() const { return m_minimumZoomFontSize; } 
    void setMinimumZoomFontSize(float minimumZoomFontSize) { m_minimumZoomFontSize = minimumZoomFontSize; }
    bool shouldEnableTextAutosizingBoost() const { return m_shouldEnableTextAutosizingBoost; } 
    WEBCORE_EXPORT void setShouldEnableTextAutosizingBoost(bool);
    bool textAutosizingEnabled() const { return m_textAutosizingEnabled; } 
    WEBCORE_EXPORT void setTextAutosizingEnabled(bool);
    bool textAutosizingUsesIdempotentMode() const { return m_textAutosizingUsesIdempotentMode; } 
    WEBCORE_EXPORT void setTextAutosizingUsesIdempotentMode(bool);
    IntSize textAutosizingWindowSizeOverride() const { return m_textAutosizingWindowSizeOverride; } 
    WEBCORE_EXPORT void setTextAutosizingWindowSizeOverride(IntSize);
#endif

#if ENABLE(TOUCH_EVENTS)
    bool isTouchEventEmulationEnabled() const { return m_touchEventEmulationEnabled; } 
    void setTouchEventEmulationEnabled(bool touchEventEmulationEnabled) { m_touchEventEmulationEnabled = touchEventEmulationEnabled; }
#endif

#if ENABLE(VIDEO)
    bool videoQualityIncludesDisplayCompositingEnabled() const { return m_videoQualityIncludesDisplayCompositingEnabled; } 
    void setVideoQualityIncludesDisplayCompositingEnabled(bool videoQualityIncludesDisplayCompositingEnabled) { m_videoQualityIncludesDisplayCompositingEnabled = videoQualityIncludesDisplayCompositingEnabled; }
#endif

#if ENABLE(VIDEO_TRACK)
    bool shouldDisplayCaptions() const { return m_shouldDisplayCaptions; } 
    void setShouldDisplayCaptions(bool shouldDisplayCaptions) { m_shouldDisplayCaptions = shouldDisplayCaptions; }
    bool shouldDisplaySubtitles() const { return m_shouldDisplaySubtitles; } 
    void setShouldDisplaySubtitles(bool shouldDisplaySubtitles) { m_shouldDisplaySubtitles = shouldDisplaySubtitles; }
    bool shouldDisplayTextDescriptions() const { return m_shouldDisplayTextDescriptions; } 
    void setShouldDisplayTextDescriptions(bool shouldDisplayTextDescriptions) { m_shouldDisplayTextDescriptions = shouldDisplayTextDescriptions; }
#endif

#if ENABLE(WEB_ARCHIVE)
    bool webArchiveDebugModeEnabled() const { return m_webArchiveDebugModeEnabled; } 
    void setWebArchiveDebugModeEnabled(bool webArchiveDebugModeEnabled) { m_webArchiveDebugModeEnabled = webArchiveDebugModeEnabled; }
#endif

#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool allowsAirPlayForMediaPlayback() const { return m_allowsAirPlayForMediaPlayback; } 
    void setAllowsAirPlayForMediaPlayback(bool allowsAirPlayForMediaPlayback) { m_allowsAirPlayForMediaPlayback = allowsAirPlayForMediaPlayback; }
#endif

    WEBCORE_EXPORT void setAuthorAndUserStylesEnabledInspectorOverride(Optional<bool>);
    WEBCORE_EXPORT void setICECandidateFilteringEnabledInspectorOverride(Optional<bool>);
    WEBCORE_EXPORT void setImagesEnabledInspectorOverride(Optional<bool>);
    void setMediaCaptureRequiresSecureConnectionInspectorOverride(Optional<bool> mediaCaptureRequiresSecureConnectionInspectorOverride) { m_mediaCaptureRequiresSecureConnectionInspectorOverride = mediaCaptureRequiresSecureConnectionInspectorOverride; }
    WEBCORE_EXPORT void setMockCaptureDevicesEnabledInspectorOverride(Optional<bool>);
    void setNeedsSiteSpecificQuirksInspectorOverride(Optional<bool> needsSiteSpecificQuirksInspectorOverride) { m_needsSiteSpecificQuirksInspectorOverride = needsSiteSpecificQuirksInspectorOverride; }
    void setScriptEnabledInspectorOverride(Optional<bool> scriptEnabledInspectorOverride) { m_scriptEnabledInspectorOverride = scriptEnabledInspectorOverride; }
    void setWebSecurityEnabledInspectorOverride(Optional<bool> webSecurityEnabledInspectorOverride) { m_webSecurityEnabledInspectorOverride = webSecurityEnabledInspectorOverride; }

private:
    explicit Settings(Page*);

    Optional<bool> m_authorAndUserStylesEnabledInspectorOverride;
    Optional<bool> m_iceCandidateFilteringEnabledInspectorOverride;
    Optional<bool> m_imagesEnabledInspectorOverride;
    Optional<bool> m_mediaCaptureRequiresSecureConnectionInspectorOverride;
    Optional<bool> m_mockCaptureDevicesEnabledInspectorOverride;
    Optional<bool> m_needsSiteSpecificQuirksInspectorOverride;
    Optional<bool> m_scriptEnabledInspectorOverride;
    Optional<bool> m_webSecurityEnabledInspectorOverride;

    double m_backForwardCacheExpirationInterval;
    ClipboardAccessPolicy m_clipboardAccessPolicy;
    int m_defaultFixedFontSize;
    int m_defaultFontSize;
    String m_defaultTextEncodingName;
    String m_defaultVideoPosterURL;
    int m_deviceHeight;
    int m_deviceWidth;
    EditableLinkBehavior m_editableLinkBehavior;
    EditingBehaviorType m_editingBehaviorType;
    FontLoadTimingOverride m_fontLoadTimingOverride;
    FontRenderingMode m_fontRenderingMode;
    ForcedAccessibilityValue m_forcedColorsAreInvertedAccessibilityValue;
    ForcedAccessibilityValue m_forcedDisplayIsMonochromeAccessibilityValue;
    ForcedAccessibilityValue m_forcedPrefersReducedMotionAccessibilityValue;
    FrameFlattening m_frameFlattening;
    String m_ftpDirectoryTemplatePath;
    double m_incrementalRenderingSuppressionTimeoutInSeconds;
    JSC::RuntimeFlags m_javaScriptRuntimeFlags;
    int m_layoutFallbackWidth;
    double m_layoutViewportHeightExpansionFactor;
    String m_localStorageDatabasePath;
    double m_maxParseDuration;
    unsigned m_maximumAccelerated2dCanvasSize;
    unsigned m_maximumHTMLParserDOMTreeDepth;
    unsigned m_maximumPlugInSnapshotAttempts;
    String m_mediaKeysStorageDirectory;
    String m_mediaTypeOverride;
    int m_minimumAccelerated2dCanvasSize;
    int m_minimumFontSize;
    int m_minimumLogicalFontSize;
    double m_passwordEchoDurationInSeconds;
    PDFImageCachingPolicy m_pdfImageCachingPolicy;
    unsigned m_sessionStorageQuota;
    SecurityOrigin::StorageBlockingPolicy m_storageBlockingPolicy;
    TextDirection m_systemLayoutDirection;
    TextDirectionSubmenuInclusionBehavior m_textDirectionSubmenuInclusionBehavior;
    Seconds m_timeWithoutMouseMovementBeforeHidingControls;
    UserInterfaceDirectionPolicy m_userInterfaceDirectionPolicy;
    URL m_userStyleSheetLocation;
    int m_validationMessageTimerMagnification;
    DebugOverlayRegions m_visibleDebugOverlayRegions;

#if ENABLE(DATA_DETECTION)
    DataDetectorTypes m_dataDetectorTypes;
#endif
#if ENABLE(MEDIA_SOURCE)
    int m_maximumSourceBufferSize;
#endif
#if ENABLE(MEDIA_STREAM)
    String m_mediaDeviceIdentifierStorageDirectory;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    float m_minimumZoomFontSize;
    IntSize m_textAutosizingWindowSizeOverride;
#endif

    bool m_CSSOMViewScrollingAPIEnabled : 1;
    bool m_DOMPasteAllowed : 1;
    bool m_HTTPSUpgradeEnabled : 1;
    bool m_accelerated2dCanvasEnabled : 1;
    bool m_acceleratedCompositedAnimationsEnabled : 1;
    bool m_acceleratedCompositingEnabled : 1;
    bool m_acceleratedCompositingForFixedPositionEnabled : 1;
    bool m_acceleratedDrawingEnabled : 1;
    bool m_acceleratedFiltersEnabled : 1;
    bool m_adClickAttributionEnabled : 1;
    bool m_aggressiveTileRetentionEnabled : 1;
    bool m_allowContentSecurityPolicySourceStarToMatchAnyProtocol : 1;
    bool m_allowCrossOriginSubresourcesToAskForCredentials : 1;
    bool m_allowDisplayOfInsecureContent : 1;
    bool m_allowFileAccessFromFileURLs : 1;
    bool m_allowMediaContentTypesRequiringHardwareSupportAsFallback : 1;
    bool m_allowMultiElementImplicitSubmission : 1;
    bool m_allowRunningOfInsecureContent : 1;
    bool m_allowSettingAnyXHRHeaderFromFileURLs : 1;
    bool m_allowUniversalAccessFromFileURLs : 1;
    bool m_allowViewportShrinkToFitContent : 1;
    bool m_allowsInlineMediaPlayback : 1;
    bool m_allowsInlineMediaPlaybackAfterFullscreen : 1;
    bool m_allowsPictureInPictureMediaPlayback : 1;
    bool m_alwaysUseAcceleratedOverflowScroll : 1;
    bool m_animatedImageAsyncDecodingEnabled : 1;
    bool m_appleMailPaginationQuirkEnabled : 1;
    bool m_asyncFrameScrollingEnabled : 1;
    bool m_asyncOverflowScrollingEnabled : 1;
    bool m_asynchronousSpellCheckingEnabled : 1;
    bool m_audioPlaybackRequiresUserGesture : 1;
    bool m_authorAndUserStylesEnabled : 1;
    bool m_autoscrollForDragAndDropEnabled : 1;
    bool m_autostartOriginPlugInSnapshottingEnabled : 1;
    bool m_backgroundShouldExtendBeyondPage : 1;
    bool m_backspaceKeyNavigationEnabled : 1;
    bool m_beaconAPIEnabled : 1;
    bool m_blockingOfSmallPluginsEnabled : 1;
    bool m_canvasUsesAcceleratedDrawing : 1;
    bool m_caretBrowsingEnabled : 1;
    bool m_clientCoordinatesRelativeToLayoutViewport : 1;
    bool m_colorFilterEnabled : 1;
    bool m_constantPropertiesEnabled : 1;
    bool m_contentChangeObserverEnabled : 1;
    bool m_contentDispositionAttachmentSandboxEnabled : 1;
    bool m_cookieEnabled : 1;
    bool m_coreMathMLEnabled : 1;
    bool m_crossOriginCheckInGetMatchedCSSRulesDisabled : 1;
    bool m_deferredCSSParserEnabled : 1;
    bool m_delegatesPageScaling : 1;
    bool m_developerExtrasEnabled : 1;
    bool m_diagnosticLoggingEnabled : 1;
    bool m_disableScreenSizeOverride : 1;
    bool m_displayListDrawingEnabled : 1;
    bool m_dnsPrefetchingEnabled : 1;
    bool m_domPasteAccessRequestsEnabled : 1;
    bool m_domTimersThrottlingEnabled : 1;
    bool m_downloadableBinaryFontsEnabled : 1;
    bool m_editableImagesEnabled : 1;
    bool m_enableInheritURIQueryComponent : 1;
    bool m_enforceCSSMIMETypeInNoQuirksMode : 1;
    bool m_experimentalNotificationsEnabled : 1;
    bool m_fixedBackgroundsPaintRelativeToDocument : 1;
    bool m_fixedElementsLayoutRelativeToFrame : 1;
    bool m_fontFallbackPrefersPictographs : 1;
    bool m_forceCompositingMode : 1;
    bool m_forceFTPDirectoryListings : 1;
    bool m_forcePendingWebGLPolicy : 1;
    bool m_forceSoftwareWebGLRendering : 1;
    bool m_forceUpdateScrollbarsOnMainThreadForPerformanceTesting : 1;
    bool m_forceWebGLUsesLowPower : 1;
    bool m_geolocationFloorLevelEnabled : 1;
    bool m_googleAntiFlickerOptimizationQuirkEnabled : 1;
    bool m_hiddenPageCSSAnimationSuspensionEnabled : 1;
    bool m_hiddenPageDOMTimerThrottlingAutoIncreases : 1;
    bool m_hiddenPageDOMTimerThrottlingEnabled : 1;
    bool m_httpEquivEnabled : 1;
    bool m_hyperlinkAuditingEnabled : 1;
    bool m_iceCandidateFilteringEnabled : 1;
    bool m_imageSubsamplingEnabled : 1;
    bool m_imagesEnabled : 1;
    bool m_incompleteImageBorderEnabled : 1;
    bool m_inlineMediaPlaybackRequiresPlaysInlineAttribute : 1;
    bool m_inputEventsEnabled : 1;
    bool m_interactiveFormValidationEnabled : 1;
    bool m_invisibleAutoplayNotPermitted : 1;
    bool m_javaEnabled : 1;
    bool m_javaEnabledForLocalFiles : 1;
    bool m_javaScriptCanAccessClipboard : 1;
    bool m_javaScriptCanOpenWindowsAutomatically : 1;
    bool m_langAttributeAwareFormControlUIEnabled : 1;
    bool m_largeImageAsyncDecodingEnabled : 1;
    bool m_linkPreconnectEnabled : 1;
    bool m_loadDeferringEnabled : 1;
    bool m_loadsImagesAutomatically : 1;
    bool m_loadsSiteIconsIgnoringImageLoadingSetting : 1;
    bool m_localFileContentSniffingEnabled : 1;
    bool m_localStorageEnabled : 1;
    bool m_logsPageMessagesToSystemConsoleEnabled : 1;
    bool m_mainContentUserGestureOverrideEnabled : 1;
    bool m_mediaCapabilitiesEnabled : 1;
    bool m_mediaCapabilitiesExtensionsEnabled : 1;
    bool m_mediaControlsScaleWithPageZoom : 1;
    bool m_mediaDataLoadsAutomatically : 1;
    bool m_mediaEnabled : 1;
    bool m_mediaPreloadingEnabled : 1;
    bool m_mediaUserGestureInheritsFromDocument : 1;
    bool m_needsAdobeFrameReloadingQuirk : 1;
    bool m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk : 1;
    bool m_needsFrameNameFallbackToIdQuirk : 1;
    bool m_needsIsLoadingInAPISenseQuirk : 1;
    bool m_needsKeyboardEventDisambiguationQuirks : 1;
    bool m_needsSiteSpecificQuirks : 1;
    bool m_needsStorageAccessFromFileURLsQuirk : 1;
    bool m_notificationsEnabled : 1;
    bool m_offlineWebApplicationCacheEnabled : 1;
    bool m_pageCacheSupportsPlugins : 1;
    bool m_paginateDuringLayoutEnabled : 1;
    bool m_passiveTouchListenersAsDefaultOnDocument : 1;
    bool m_passwordEchoEnabled : 1;
    bool m_plugInSnapshottingEnabled : 1;
    bool m_pluginsEnabled : 1;
    bool m_preferMIMETypeForImages : 1;
    bool m_preventKeyboardDOMEventDispatch : 1;
    bool m_primaryPlugInSnapshotDetectionEnabled : 1;
    bool m_punchOutWhiteBackgroundsInDarkMode : 1;
    bool m_quickTimePluginReplacementEnabled : 1;
    bool m_repaintOutsideLayoutEnabled : 1;
    bool m_requestAnimationFrameEnabled : 1;
    bool m_requiresUserGestureToLoadVideo : 1;
    bool m_resourceUsageOverlayVisible : 1;
    bool m_scriptEnabled : 1;
    bool m_scriptMarkupEnabled : 1;
    bool m_scrollingCoordinatorEnabled : 1;
    bool m_scrollingPerformanceLoggingEnabled : 1;
    bool m_scrollingTreeIncludesFrames : 1;
    bool m_selectTrailingWhitespaceEnabled : 1;
    bool m_selectionAcrossShadowBoundariesEnabled : 1;
    bool m_selectionPaintingWithoutSelectionGapsEnabled : 1;
    bool m_shouldAllowDesignSystemUIFonts : 1;
    bool m_shouldAllowUserInstalledFonts : 1;
    bool m_shouldConvertInvalidURLsToBlank : 1;
    bool m_shouldConvertPositionStyleOnCopy : 1;
    bool m_shouldDecidePolicyBeforeLoadingQuickLookPreview : 1;
    bool m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoad : 1;
    bool m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection : 1;
    bool m_shouldDispatchSyntheticMouseOutAfterSyntheticClick : 1;
    bool m_shouldIgnoreFontLoadCompletions : 1;
    bool m_shouldIgnoreMetaViewport : 1;
    bool m_shouldInjectUserScriptsInInitialEmptyDocument : 1;
    bool m_shouldPrintBackgrounds : 1;
    bool m_shouldRespectImageOrientation : 1;
    bool m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation : 1;
    bool m_showDebugBorders : 1;
    bool m_showRepaintCounter : 1;
    bool m_showTiledScrollingIndicator : 1;
    bool m_showsToolTipOverTruncatedText : 1;
    bool m_showsURLsInToolTips : 1;
    bool m_shrinksStandaloneImagesToFit : 1;
    bool m_simpleLineLayoutDebugBordersEnabled : 1;
    bool m_simpleLineLayoutEnabled : 1;
    bool m_smartInsertDeleteEnabled : 1;
    bool m_snapshotAllPlugIns : 1;
    bool m_spatialNavigationEnabled : 1;
    bool m_springTimingFunctionEnabled : 1;
    bool m_standalone : 1;
    bool m_storageAccessAPIEnabled : 1;
    bool m_subpixelAntialiasedLayerTextEnabled : 1;
    bool m_subpixelCSSOMElementMetricsEnabled : 1;
    bool m_subresourceIntegrityEnabled : 1;
    bool m_suppressesIncrementalRendering : 1;
    bool m_syntheticEditingCommandsEnabled : 1;
    bool m_telephoneNumberParsingEnabled : 1;
    bool m_temporaryTileCohortRetentionEnabled : 1;
    bool m_textAreasAreResizable : 1;
    bool m_thirdPartyIframeRedirectBlockingEnabled : 1;
    bool m_treatIPAddressAsDomain : 1;
    bool m_treatsAnyTextCSSLinkAsStylesheet : 1;
    bool m_unhandledPromiseRejectionToConsoleEnabled : 1;
    bool m_unifiedTextCheckerEnabled : 1;
    bool m_useAnonymousModeWhenFetchingMaskImages : 1;
    bool m_useGiantTiles : 1;
    bool m_useImageDocumentForSubframePDF : 1;
    bool m_useLegacyBackgroundSizeShorthandBehavior : 1;
    bool m_useLegacyTextAlignPositionedElementBehavior : 1;
    bool m_usePreHTML5ParserQuirks : 1;
    bool m_usesEncodingDetector : 1;
    bool m_usesPageCache : 1;
    bool m_videoPlaybackRequiresUserGesture : 1;
    bool m_viewportFitEnabled : 1;
    bool m_visualViewportAPIEnabled : 1;
    bool m_visualViewportEnabled : 1;
    bool m_wantsBalancedSetDefersLoadingBehavior : 1;
    bool m_webAudioEnabled : 1;
    bool m_webGLEnabled : 1;
    bool m_webGLErrorsToConsoleEnabled : 1;
    bool m_webSecurityEnabled : 1;
    bool m_webkitImageReadyEventEnabled : 1;
    bool m_windowFocusRestricted : 1;
    bool m_xssAuditorEnabled : 1;
    bool m_youTubeFlashPluginReplacementEnabled : 1;

#if ENABLE(APPLE_PAY)
    bool m_applePayCapabilityDisclosureAllowed : 1;
    bool m_applePayEnabled : 1;
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    bool m_applePayRemoteUIEnabled : 1;
#endif
#if ENABLE(DEVICE_ORIENTATION)
    bool m_deviceOrientationEventEnabled : 1;
    bool m_deviceOrientationPermissionAPIEnabled : 1;
#endif
#if ENABLE(FULLSCREEN_API)
    bool m_fullScreenEnabled : 1;
#endif
#if ENABLE(MEDIA_SOURCE)
    bool m_mediaSourceEnabled : 1;
    bool m_sourceBufferChangeTypeEnabled : 1;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_mediaCaptureRequiresSecureConnection : 1;
    bool m_mockCaptureDevicesEnabled : 1;
#endif
#if ENABLE(OVERFLOW_SCROLLING_TOUCH)
    bool m_legacyOverflowScrollingTouchEnabled : 1;
#endif
#if ENABLE(PAYMENT_REQUEST)
    bool m_paymentRequestEnabled : 1;
#endif
#if ENABLE(RESIZE_OBSERVER)
    bool m_resizeObserverEnabled : 1;
#endif
#if ENABLE(RUBBER_BANDING)
    bool m_rubberBandingForSubScrollableRegionsEnabled : 1;
#endif
#if ENABLE(SERVICE_CONTROLS)
    bool m_imageControlsEnabled : 1;
    bool m_serviceControlsEnabled : 1;
#endif
#if ENABLE(SMOOTH_SCROLLING)
    bool m_scrollAnimatorEnabled : 1;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    bool m_shouldEnableTextAutosizingBoost : 1;
    bool m_textAutosizingEnabled : 1;
    bool m_textAutosizingUsesIdempotentMode : 1;
#endif
#if ENABLE(TOUCH_EVENTS)
    bool m_touchEventEmulationEnabled : 1;
#endif
#if ENABLE(VIDEO)
    bool m_videoQualityIncludesDisplayCompositingEnabled : 1;
#endif
#if ENABLE(VIDEO_TRACK)
    bool m_shouldDisplayCaptions : 1;
    bool m_shouldDisplaySubtitles : 1;
    bool m_shouldDisplayTextDescriptions : 1;
#endif
#if ENABLE(WEB_ARCHIVE)
    bool m_webArchiveDebugModeEnabled : 1;
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool m_allowsAirPlayForMediaPlayback : 1;
#endif
};

}
