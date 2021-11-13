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

#include <wtf/RefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class Page;

class InternalSettingsGenerated : public RefCounted<InternalSettingsGenerated> {
public:
    explicit InternalSettingsGenerated(Page*);
    virtual ~InternalSettingsGenerated();

    void resetToConsistentState();

    void setCSSOMViewScrollingAPIEnabled(bool CSSOMViewScrollingAPIEnabled);
    void setDOMPasteAllowed(bool DOMPasteAllowed);
    void setHTTPSUpgradeEnabled(bool HTTPSUpgradeEnabled);
    void setAccelerated2dCanvasEnabled(bool accelerated2dCanvasEnabled);
    void setAcceleratedCompositedAnimationsEnabled(bool acceleratedCompositedAnimationsEnabled);
    void setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled);
    void setAcceleratedCompositingForFixedPositionEnabled(bool acceleratedCompositingForFixedPositionEnabled);
    void setAcceleratedDrawingEnabled(bool acceleratedDrawingEnabled);
    void setAcceleratedFiltersEnabled(bool acceleratedFiltersEnabled);
    void setAdClickAttributionEnabled(bool adClickAttributionEnabled);
    void setAggressiveTileRetentionEnabled(bool aggressiveTileRetentionEnabled);
    void setAllowContentSecurityPolicySourceStarToMatchAnyProtocol(bool allowContentSecurityPolicySourceStarToMatchAnyProtocol);
    void setAllowCrossOriginSubresourcesToAskForCredentials(bool allowCrossOriginSubresourcesToAskForCredentials);
    void setAllowDisplayOfInsecureContent(bool allowDisplayOfInsecureContent);
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs);
    void setAllowMediaContentTypesRequiringHardwareSupportAsFallback(bool allowMediaContentTypesRequiringHardwareSupportAsFallback);
    void setAllowMultiElementImplicitSubmission(bool allowMultiElementImplicitSubmission);
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent);
    void setAllowSettingAnyXHRHeaderFromFileURLs(bool allowSettingAnyXHRHeaderFromFileURLs);
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs);
    void setAllowViewportShrinkToFitContent(bool allowViewportShrinkToFitContent);
    void setAllowsAirPlayForMediaPlayback(bool allowsAirPlayForMediaPlayback);
    void setAllowsInlineMediaPlayback(bool allowsInlineMediaPlayback);
    void setAllowsInlineMediaPlaybackAfterFullscreen(bool allowsInlineMediaPlaybackAfterFullscreen);
    void setAllowsPictureInPictureMediaPlayback(bool allowsPictureInPictureMediaPlayback);
    void setAlwaysUseAcceleratedOverflowScroll(bool alwaysUseAcceleratedOverflowScroll);
    void setAnimatedImageAsyncDecodingEnabled(bool animatedImageAsyncDecodingEnabled);
    void setAppleMailPaginationQuirkEnabled(bool appleMailPaginationQuirkEnabled);
    void setApplePayCapabilityDisclosureAllowed(bool applePayCapabilityDisclosureAllowed);
    void setApplePayEnabled(bool applePayEnabled);
    void setApplePayRemoteUIEnabled(bool applePayRemoteUIEnabled);
    void setAsyncFrameScrollingEnabled(bool asyncFrameScrollingEnabled);
    void setAsyncOverflowScrollingEnabled(bool asyncOverflowScrollingEnabled);
    void setAsynchronousSpellCheckingEnabled(bool asynchronousSpellCheckingEnabled);
    void setAudioPlaybackRequiresUserGesture(bool audioPlaybackRequiresUserGesture);
    void setAuthorAndUserStylesEnabled(bool authorAndUserStylesEnabled);
    void setAutoscrollForDragAndDropEnabled(bool autoscrollForDragAndDropEnabled);
    void setAutostartOriginPlugInSnapshottingEnabled(bool autostartOriginPlugInSnapshottingEnabled);
    void setBackForwardCacheExpirationInterval(double backForwardCacheExpirationInterval);
    void setBackgroundShouldExtendBeyondPage(bool backgroundShouldExtendBeyondPage);
    void setBackspaceKeyNavigationEnabled(bool backspaceKeyNavigationEnabled);
    void setBeaconAPIEnabled(bool beaconAPIEnabled);
    void setBlockingOfSmallPluginsEnabled(bool blockingOfSmallPluginsEnabled);
    void setCanvasUsesAcceleratedDrawing(bool canvasUsesAcceleratedDrawing);
    void setCaretBrowsingEnabled(bool caretBrowsingEnabled);
    void setClientCoordinatesRelativeToLayoutViewport(bool clientCoordinatesRelativeToLayoutViewport);
    void setColorFilterEnabled(bool colorFilterEnabled);
    void setConstantPropertiesEnabled(bool constantPropertiesEnabled);
    void setContentChangeObserverEnabled(bool contentChangeObserverEnabled);
    void setContentDispositionAttachmentSandboxEnabled(bool contentDispositionAttachmentSandboxEnabled);
    void setCookieEnabled(bool cookieEnabled);
    void setCoreMathMLEnabled(bool coreMathMLEnabled);
    void setCrossOriginCheckInGetMatchedCSSRulesDisabled(bool crossOriginCheckInGetMatchedCSSRulesDisabled);
    void setDefaultFixedFontSize(int defaultFixedFontSize);
    void setDefaultFontSize(int defaultFontSize);
    void setDefaultTextEncodingName(const String& defaultTextEncodingName);
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL);
    void setDeferredCSSParserEnabled(bool deferredCSSParserEnabled);
    void setDelegatesPageScaling(bool delegatesPageScaling);
    void setDeveloperExtrasEnabled(bool developerExtrasEnabled);
    void setDeviceHeight(int deviceHeight);
    void setDeviceOrientationEventEnabled(bool deviceOrientationEventEnabled);
    void setDeviceOrientationPermissionAPIEnabled(bool deviceOrientationPermissionAPIEnabled);
    void setDeviceWidth(int deviceWidth);
    void setDiagnosticLoggingEnabled(bool diagnosticLoggingEnabled);
    void setDisableScreenSizeOverride(bool disableScreenSizeOverride);
    void setDisplayListDrawingEnabled(bool displayListDrawingEnabled);
    void setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled);
    void setDOMPasteAccessRequestsEnabled(bool domPasteAccessRequestsEnabled);
    void setDOMTimersThrottlingEnabled(bool domTimersThrottlingEnabled);
    void setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled);
    void setEditableImagesEnabled(bool editableImagesEnabled);
    void setEnableInheritURIQueryComponent(bool enableInheritURIQueryComponent);
    void setEnforceCSSMIMETypeInNoQuirksMode(bool enforceCSSMIMETypeInNoQuirksMode);
    void setExperimentalNotificationsEnabled(bool experimentalNotificationsEnabled);
    void setFixedBackgroundsPaintRelativeToDocument(bool fixedBackgroundsPaintRelativeToDocument);
    void setFixedElementsLayoutRelativeToFrame(bool fixedElementsLayoutRelativeToFrame);
    void setFontFallbackPrefersPictographs(bool fontFallbackPrefersPictographs);
    void setForceCompositingMode(bool forceCompositingMode);
    void setForceFTPDirectoryListings(bool forceFTPDirectoryListings);
    void setForcePendingWebGLPolicy(bool forcePendingWebGLPolicy);
    void setForceSoftwareWebGLRendering(bool forceSoftwareWebGLRendering);
    void setForceUpdateScrollbarsOnMainThreadForPerformanceTesting(bool forceUpdateScrollbarsOnMainThreadForPerformanceTesting);
    void setForceWebGLUsesLowPower(bool forceWebGLUsesLowPower);
    void setFTPDirectoryTemplatePath(const String& ftpDirectoryTemplatePath);
    void setFullScreenEnabled(bool fullScreenEnabled);
    void setGeolocationFloorLevelEnabled(bool geolocationFloorLevelEnabled);
    void setGoogleAntiFlickerOptimizationQuirkEnabled(bool googleAntiFlickerOptimizationQuirkEnabled);
    void setHiddenPageCSSAnimationSuspensionEnabled(bool hiddenPageCSSAnimationSuspensionEnabled);
    void setHiddenPageDOMTimerThrottlingAutoIncreases(bool hiddenPageDOMTimerThrottlingAutoIncreases);
    void setHiddenPageDOMTimerThrottlingEnabled(bool hiddenPageDOMTimerThrottlingEnabled);
    void setHttpEquivEnabled(bool httpEquivEnabled);
    void setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled);
    void setICECandidateFilteringEnabled(bool iceCandidateFilteringEnabled);
    void setImageControlsEnabled(bool imageControlsEnabled);
    void setImageSubsamplingEnabled(bool imageSubsamplingEnabled);
    void setImagesEnabled(bool imagesEnabled);
    void setIncompleteImageBorderEnabled(bool incompleteImageBorderEnabled);
    void setIncrementalRenderingSuppressionTimeoutInSeconds(double incrementalRenderingSuppressionTimeoutInSeconds);
    void setInlineMediaPlaybackRequiresPlaysInlineAttribute(bool inlineMediaPlaybackRequiresPlaysInlineAttribute);
    void setInputEventsEnabled(bool inputEventsEnabled);
    void setInteractiveFormValidationEnabled(bool interactiveFormValidationEnabled);
    void setInvisibleAutoplayNotPermitted(bool invisibleAutoplayNotPermitted);
    void setJavaEnabled(bool javaEnabled);
    void setJavaEnabledForLocalFiles(bool javaEnabledForLocalFiles);
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard);
    void setJavaScriptCanOpenWindowsAutomatically(bool javaScriptCanOpenWindowsAutomatically);
    void setLangAttributeAwareFormControlUIEnabled(bool langAttributeAwareFormControlUIEnabled);
    void setLargeImageAsyncDecodingEnabled(bool largeImageAsyncDecodingEnabled);
    void setLayoutFallbackWidth(int layoutFallbackWidth);
    void setLayoutViewportHeightExpansionFactor(double layoutViewportHeightExpansionFactor);
    void setLegacyOverflowScrollingTouchEnabled(bool legacyOverflowScrollingTouchEnabled);
    void setLinkPreconnectEnabled(bool linkPreconnectEnabled);
    void setLoadDeferringEnabled(bool loadDeferringEnabled);
    void setLoadsImagesAutomatically(bool loadsImagesAutomatically);
    void setLoadsSiteIconsIgnoringImageLoadingSetting(bool loadsSiteIconsIgnoringImageLoadingSetting);
    void setLocalFileContentSniffingEnabled(bool localFileContentSniffingEnabled);
    void setLocalStorageDatabasePath(const String& localStorageDatabasePath);
    void setLocalStorageEnabled(bool localStorageEnabled);
    void setLogsPageMessagesToSystemConsoleEnabled(bool logsPageMessagesToSystemConsoleEnabled);
    void setMainContentUserGestureOverrideEnabled(bool mainContentUserGestureOverrideEnabled);
    void setMaxParseDuration(double maxParseDuration);
    void setMaximumAccelerated2dCanvasSize(unsigned maximumAccelerated2dCanvasSize);
    void setMaximumHTMLParserDOMTreeDepth(unsigned maximumHTMLParserDOMTreeDepth);
    void setMaximumPlugInSnapshotAttempts(unsigned maximumPlugInSnapshotAttempts);
    void setMaximumSourceBufferSize(int maximumSourceBufferSize);
    void setMediaCapabilitiesEnabled(bool mediaCapabilitiesEnabled);
    void setMediaCapabilitiesExtensionsEnabled(bool mediaCapabilitiesExtensionsEnabled);
    void setMediaCaptureRequiresSecureConnection(bool mediaCaptureRequiresSecureConnection);
    void setMediaControlsScaleWithPageZoom(bool mediaControlsScaleWithPageZoom);
    void setMediaDataLoadsAutomatically(bool mediaDataLoadsAutomatically);
    void setMediaDeviceIdentifierStorageDirectory(const String& mediaDeviceIdentifierStorageDirectory);
    void setMediaEnabled(bool mediaEnabled);
    void setMediaKeysStorageDirectory(const String& mediaKeysStorageDirectory);
    void setMediaPreloadingEnabled(bool mediaPreloadingEnabled);
    void setMediaSourceEnabled(bool mediaSourceEnabled);
    void setMediaTypeOverride(const String& mediaTypeOverride);
    void setMediaUserGestureInheritsFromDocument(bool mediaUserGestureInheritsFromDocument);
    void setMinimumAccelerated2dCanvasSize(int minimumAccelerated2dCanvasSize);
    void setMinimumFontSize(int minimumFontSize);
    void setMinimumLogicalFontSize(int minimumLogicalFontSize);
    void setMinimumZoomFontSize(float minimumZoomFontSize);
    void setMockCaptureDevicesEnabled(bool mockCaptureDevicesEnabled);
    void setNeedsAdobeFrameReloadingQuirk(bool needsAdobeFrameReloadingQuirk);
    void setNeedsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk(bool needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk);
    void setNeedsFrameNameFallbackToIdQuirk(bool needsFrameNameFallbackToIdQuirk);
    void setNeedsIsLoadingInAPISenseQuirk(bool needsIsLoadingInAPISenseQuirk);
    void setNeedsKeyboardEventDisambiguationQuirks(bool needsKeyboardEventDisambiguationQuirks);
    void setNeedsSiteSpecificQuirks(bool needsSiteSpecificQuirks);
    void setNeedsStorageAccessFromFileURLsQuirk(bool needsStorageAccessFromFileURLsQuirk);
    void setNotificationsEnabled(bool notificationsEnabled);
    void setOfflineWebApplicationCacheEnabled(bool offlineWebApplicationCacheEnabled);
    void setPageCacheSupportsPlugins(bool pageCacheSupportsPlugins);
    void setPaginateDuringLayoutEnabled(bool paginateDuringLayoutEnabled);
    void setPassiveTouchListenersAsDefaultOnDocument(bool passiveTouchListenersAsDefaultOnDocument);
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds);
    void setPasswordEchoEnabled(bool passwordEchoEnabled);
    void setPaymentRequestEnabled(bool paymentRequestEnabled);
    void setPlugInSnapshottingEnabled(bool plugInSnapshottingEnabled);
    void setPluginsEnabled(bool pluginsEnabled);
    void setPreferMIMETypeForImages(bool preferMIMETypeForImages);
    void setPreventKeyboardDOMEventDispatch(bool preventKeyboardDOMEventDispatch);
    void setPrimaryPlugInSnapshotDetectionEnabled(bool primaryPlugInSnapshotDetectionEnabled);
    void setPunchOutWhiteBackgroundsInDarkMode(bool punchOutWhiteBackgroundsInDarkMode);
    void setQuickTimePluginReplacementEnabled(bool quickTimePluginReplacementEnabled);
    void setRepaintOutsideLayoutEnabled(bool repaintOutsideLayoutEnabled);
    void setRequestAnimationFrameEnabled(bool requestAnimationFrameEnabled);
    void setRequiresUserGestureToLoadVideo(bool requiresUserGestureToLoadVideo);
    void setResizeObserverEnabled(bool resizeObserverEnabled);
    void setResourceUsageOverlayVisible(bool resourceUsageOverlayVisible);
    void setRubberBandingForSubScrollableRegionsEnabled(bool rubberBandingForSubScrollableRegionsEnabled);
    void setScriptEnabled(bool scriptEnabled);
    void setScriptMarkupEnabled(bool scriptMarkupEnabled);
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled);
    void setScrollingCoordinatorEnabled(bool scrollingCoordinatorEnabled);
    void setScrollingPerformanceLoggingEnabled(bool scrollingPerformanceLoggingEnabled);
    void setScrollingTreeIncludesFrames(bool scrollingTreeIncludesFrames);
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled);
    void setSelectionAcrossShadowBoundariesEnabled(bool selectionAcrossShadowBoundariesEnabled);
    void setSelectionPaintingWithoutSelectionGapsEnabled(bool selectionPaintingWithoutSelectionGapsEnabled);
    void setServiceControlsEnabled(bool serviceControlsEnabled);
    void setSessionStorageQuota(unsigned sessionStorageQuota);
    void setShouldAllowDesignSystemUIFonts(bool shouldAllowDesignSystemUIFonts);
    void setShouldAllowUserInstalledFonts(bool shouldAllowUserInstalledFonts);
    void setShouldConvertInvalidURLsToBlank(bool shouldConvertInvalidURLsToBlank);
    void setShouldConvertPositionStyleOnCopy(bool shouldConvertPositionStyleOnCopy);
    void setShouldDecidePolicyBeforeLoadingQuickLookPreview(bool shouldDecidePolicyBeforeLoadingQuickLookPreview);
    void setShouldDeferAsynchronousScriptsUntilAfterDocumentLoad(bool shouldDeferAsynchronousScriptsUntilAfterDocumentLoad);
    void setShouldDispatchSyntheticMouseEventsWhenModifyingSelection(bool shouldDispatchSyntheticMouseEventsWhenModifyingSelection);
    void setShouldDispatchSyntheticMouseOutAfterSyntheticClick(bool shouldDispatchSyntheticMouseOutAfterSyntheticClick);
    void setShouldDisplayCaptions(bool shouldDisplayCaptions);
    void setShouldDisplaySubtitles(bool shouldDisplaySubtitles);
    void setShouldDisplayTextDescriptions(bool shouldDisplayTextDescriptions);
    void setShouldEnableTextAutosizingBoost(bool shouldEnableTextAutosizingBoost);
    void setShouldIgnoreFontLoadCompletions(bool shouldIgnoreFontLoadCompletions);
    void setShouldIgnoreMetaViewport(bool shouldIgnoreMetaViewport);
    void setShouldInjectUserScriptsInInitialEmptyDocument(bool shouldInjectUserScriptsInInitialEmptyDocument);
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds);
    void setShouldRespectImageOrientation(bool shouldRespectImageOrientation);
    void setShouldSuppressTextInputFromEditingDuringProvisionalNavigation(bool shouldSuppressTextInputFromEditingDuringProvisionalNavigation);
    void setShowDebugBorders(bool showDebugBorders);
    void setShowRepaintCounter(bool showRepaintCounter);
    void setShowTiledScrollingIndicator(bool showTiledScrollingIndicator);
    void setShowsToolTipOverTruncatedText(bool showsToolTipOverTruncatedText);
    void setShowsURLsInToolTips(bool showsURLsInToolTips);
    void setShrinksStandaloneImagesToFit(bool shrinksStandaloneImagesToFit);
    void setSimpleLineLayoutDebugBordersEnabled(bool simpleLineLayoutDebugBordersEnabled);
    void setSimpleLineLayoutEnabled(bool simpleLineLayoutEnabled);
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled);
    void setSnapshotAllPlugIns(bool snapshotAllPlugIns);
    void setSourceBufferChangeTypeEnabled(bool sourceBufferChangeTypeEnabled);
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled);
    void setSpringTimingFunctionEnabled(bool springTimingFunctionEnabled);
    void setStandalone(bool standalone);
    void setStorageAccessAPIEnabled(bool storageAccessAPIEnabled);
    void setSubpixelAntialiasedLayerTextEnabled(bool subpixelAntialiasedLayerTextEnabled);
    void setSubpixelCSSOMElementMetricsEnabled(bool subpixelCSSOMElementMetricsEnabled);
    void setSubresourceIntegrityEnabled(bool subresourceIntegrityEnabled);
    void setSuppressesIncrementalRendering(bool suppressesIncrementalRendering);
    void setSyntheticEditingCommandsEnabled(bool syntheticEditingCommandsEnabled);
    void setTelephoneNumberParsingEnabled(bool telephoneNumberParsingEnabled);
    void setTemporaryTileCohortRetentionEnabled(bool temporaryTileCohortRetentionEnabled);
    void setTextAreasAreResizable(bool textAreasAreResizable);
    void setTextAutosizingEnabled(bool textAutosizingEnabled);
    void setTextAutosizingUsesIdempotentMode(bool textAutosizingUsesIdempotentMode);
    void setThirdPartyIframeRedirectBlockingEnabled(bool thirdPartyIframeRedirectBlockingEnabled);
    void setTouchEventEmulationEnabled(bool touchEventEmulationEnabled);
    void setTreatIPAddressAsDomain(bool treatIPAddressAsDomain);
    void setTreatsAnyTextCSSLinkAsStylesheet(bool treatsAnyTextCSSLinkAsStylesheet);
    void setUnhandledPromiseRejectionToConsoleEnabled(bool unhandledPromiseRejectionToConsoleEnabled);
    void setUnifiedTextCheckerEnabled(bool unifiedTextCheckerEnabled);
    void setUseAnonymousModeWhenFetchingMaskImages(bool useAnonymousModeWhenFetchingMaskImages);
    void setUseGiantTiles(bool useGiantTiles);
    void setUseImageDocumentForSubframePDF(bool useImageDocumentForSubframePDF);
    void setUseLegacyBackgroundSizeShorthandBehavior(bool useLegacyBackgroundSizeShorthandBehavior);
    void setUseLegacyTextAlignPositionedElementBehavior(bool useLegacyTextAlignPositionedElementBehavior);
    void setUsePreHTML5ParserQuirks(bool usePreHTML5ParserQuirks);
    void setUsesEncodingDetector(bool usesEncodingDetector);
    void setUsesPageCache(bool usesPageCache);
    void setValidationMessageTimerMagnification(int validationMessageTimerMagnification);
    void setVideoPlaybackRequiresUserGesture(bool videoPlaybackRequiresUserGesture);
    void setVideoQualityIncludesDisplayCompositingEnabled(bool videoQualityIncludesDisplayCompositingEnabled);
    void setViewportFitEnabled(bool viewportFitEnabled);
    void setVisualViewportAPIEnabled(bool visualViewportAPIEnabled);
    void setVisualViewportEnabled(bool visualViewportEnabled);
    void setWantsBalancedSetDefersLoadingBehavior(bool wantsBalancedSetDefersLoadingBehavior);
    void setWebArchiveDebugModeEnabled(bool webArchiveDebugModeEnabled);
    void setWebAudioEnabled(bool webAudioEnabled);
    void setWebGLEnabled(bool webGLEnabled);
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled);
    void setWebSecurityEnabled(bool webSecurityEnabled);
    void setWebkitImageReadyEventEnabled(bool webkitImageReadyEventEnabled);
    void setWindowFocusRestricted(bool windowFocusRestricted);
    void setXSSAuditorEnabled(bool xssAuditorEnabled);
    void setYouTubeFlashPluginReplacementEnabled(bool youTubeFlashPluginReplacementEnabled);

private:
    Page* m_page;

    bool m_CSSOMViewScrollingAPIEnabled;
    bool m_DOMPasteAllowed;
    bool m_HTTPSUpgradeEnabled;
    bool m_accelerated2dCanvasEnabled;
    bool m_acceleratedCompositedAnimationsEnabled;
    bool m_acceleratedCompositingEnabled;
    bool m_acceleratedCompositingForFixedPositionEnabled;
    bool m_acceleratedDrawingEnabled;
    bool m_acceleratedFiltersEnabled;
    bool m_adClickAttributionEnabled;
    bool m_aggressiveTileRetentionEnabled;
    bool m_allowContentSecurityPolicySourceStarToMatchAnyProtocol;
    bool m_allowCrossOriginSubresourcesToAskForCredentials;
    bool m_allowDisplayOfInsecureContent;
    bool m_allowFileAccessFromFileURLs;
    bool m_allowMediaContentTypesRequiringHardwareSupportAsFallback;
    bool m_allowMultiElementImplicitSubmission;
    bool m_allowRunningOfInsecureContent;
    bool m_allowSettingAnyXHRHeaderFromFileURLs;
    bool m_allowUniversalAccessFromFileURLs;
    bool m_allowViewportShrinkToFitContent;
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    bool m_allowsAirPlayForMediaPlayback;
#endif
    bool m_allowsInlineMediaPlayback;
    bool m_allowsInlineMediaPlaybackAfterFullscreen;
    bool m_allowsPictureInPictureMediaPlayback;
    bool m_alwaysUseAcceleratedOverflowScroll;
    bool m_animatedImageAsyncDecodingEnabled;
    bool m_appleMailPaginationQuirkEnabled;
#if ENABLE(APPLE_PAY)
    bool m_applePayCapabilityDisclosureAllowed;
#endif
#if ENABLE(APPLE_PAY)
    bool m_applePayEnabled;
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    bool m_applePayRemoteUIEnabled;
#endif
    bool m_asyncFrameScrollingEnabled;
    bool m_asyncOverflowScrollingEnabled;
    bool m_asynchronousSpellCheckingEnabled;
    bool m_audioPlaybackRequiresUserGesture;
    bool m_authorAndUserStylesEnabled;
    bool m_autoscrollForDragAndDropEnabled;
    bool m_autostartOriginPlugInSnapshottingEnabled;
    double m_backForwardCacheExpirationInterval;
    bool m_backgroundShouldExtendBeyondPage;
    bool m_backspaceKeyNavigationEnabled;
    bool m_beaconAPIEnabled;
    bool m_blockingOfSmallPluginsEnabled;
    bool m_canvasUsesAcceleratedDrawing;
    bool m_caretBrowsingEnabled;
    bool m_clientCoordinatesRelativeToLayoutViewport;
    bool m_colorFilterEnabled;
    bool m_constantPropertiesEnabled;
    bool m_contentChangeObserverEnabled;
    bool m_contentDispositionAttachmentSandboxEnabled;
    bool m_cookieEnabled;
    bool m_coreMathMLEnabled;
    bool m_crossOriginCheckInGetMatchedCSSRulesDisabled;
    int m_defaultFixedFontSize;
    int m_defaultFontSize;
    String m_defaultTextEncodingName;
    String m_defaultVideoPosterURL;
    bool m_deferredCSSParserEnabled;
    bool m_delegatesPageScaling;
    bool m_developerExtrasEnabled;
    int m_deviceHeight;
#if ENABLE(DEVICE_ORIENTATION)
    bool m_deviceOrientationEventEnabled;
#endif
#if ENABLE(DEVICE_ORIENTATION)
    bool m_deviceOrientationPermissionAPIEnabled;
#endif
    int m_deviceWidth;
    bool m_diagnosticLoggingEnabled;
    bool m_disableScreenSizeOverride;
    bool m_displayListDrawingEnabled;
    bool m_dnsPrefetchingEnabled;
    bool m_domPasteAccessRequestsEnabled;
    bool m_domTimersThrottlingEnabled;
    bool m_downloadableBinaryFontsEnabled;
    bool m_editableImagesEnabled;
    bool m_enableInheritURIQueryComponent;
    bool m_enforceCSSMIMETypeInNoQuirksMode;
    bool m_experimentalNotificationsEnabled;
    bool m_fixedBackgroundsPaintRelativeToDocument;
    bool m_fixedElementsLayoutRelativeToFrame;
    bool m_fontFallbackPrefersPictographs;
    bool m_forceCompositingMode;
    bool m_forceFTPDirectoryListings;
    bool m_forcePendingWebGLPolicy;
    bool m_forceSoftwareWebGLRendering;
    bool m_forceUpdateScrollbarsOnMainThreadForPerformanceTesting;
    bool m_forceWebGLUsesLowPower;
    String m_ftpDirectoryTemplatePath;
#if ENABLE(FULLSCREEN_API)
    bool m_fullScreenEnabled;
#endif
    bool m_geolocationFloorLevelEnabled;
    bool m_googleAntiFlickerOptimizationQuirkEnabled;
    bool m_hiddenPageCSSAnimationSuspensionEnabled;
    bool m_hiddenPageDOMTimerThrottlingAutoIncreases;
    bool m_hiddenPageDOMTimerThrottlingEnabled;
    bool m_httpEquivEnabled;
    bool m_hyperlinkAuditingEnabled;
    bool m_iceCandidateFilteringEnabled;
#if ENABLE(SERVICE_CONTROLS)
    bool m_imageControlsEnabled;
#endif
    bool m_imageSubsamplingEnabled;
    bool m_imagesEnabled;
    bool m_incompleteImageBorderEnabled;
    double m_incrementalRenderingSuppressionTimeoutInSeconds;
    bool m_inlineMediaPlaybackRequiresPlaysInlineAttribute;
    bool m_inputEventsEnabled;
    bool m_interactiveFormValidationEnabled;
    bool m_invisibleAutoplayNotPermitted;
    bool m_javaEnabled;
    bool m_javaEnabledForLocalFiles;
    bool m_javaScriptCanAccessClipboard;
    bool m_javaScriptCanOpenWindowsAutomatically;
    bool m_langAttributeAwareFormControlUIEnabled;
    bool m_largeImageAsyncDecodingEnabled;
    int m_layoutFallbackWidth;
    double m_layoutViewportHeightExpansionFactor;
#if ENABLE(OVERFLOW_SCROLLING_TOUCH)
    bool m_legacyOverflowScrollingTouchEnabled;
#endif
    bool m_linkPreconnectEnabled;
    bool m_loadDeferringEnabled;
    bool m_loadsImagesAutomatically;
    bool m_loadsSiteIconsIgnoringImageLoadingSetting;
    bool m_localFileContentSniffingEnabled;
    String m_localStorageDatabasePath;
    bool m_localStorageEnabled;
    bool m_logsPageMessagesToSystemConsoleEnabled;
    bool m_mainContentUserGestureOverrideEnabled;
    double m_maxParseDuration;
    unsigned m_maximumAccelerated2dCanvasSize;
    unsigned m_maximumHTMLParserDOMTreeDepth;
    unsigned m_maximumPlugInSnapshotAttempts;
#if ENABLE(MEDIA_SOURCE)
    int m_maximumSourceBufferSize;
#endif
    bool m_mediaCapabilitiesEnabled;
    bool m_mediaCapabilitiesExtensionsEnabled;
#if ENABLE(MEDIA_STREAM)
    bool m_mediaCaptureRequiresSecureConnection;
#endif
    bool m_mediaControlsScaleWithPageZoom;
    bool m_mediaDataLoadsAutomatically;
#if ENABLE(MEDIA_STREAM)
    String m_mediaDeviceIdentifierStorageDirectory;
#endif
    bool m_mediaEnabled;
    String m_mediaKeysStorageDirectory;
    bool m_mediaPreloadingEnabled;
#if ENABLE(MEDIA_SOURCE)
    bool m_mediaSourceEnabled;
#endif
    String m_mediaTypeOverride;
    bool m_mediaUserGestureInheritsFromDocument;
    int m_minimumAccelerated2dCanvasSize;
    int m_minimumFontSize;
    int m_minimumLogicalFontSize;
#if ENABLE(TEXT_AUTOSIZING)
    float m_minimumZoomFontSize;
#endif
#if ENABLE(MEDIA_STREAM)
    bool m_mockCaptureDevicesEnabled;
#endif
    bool m_needsAdobeFrameReloadingQuirk;
    bool m_needsDeferKeyDownAndKeyPressTimersUntilNextEditingCommandQuirk;
    bool m_needsFrameNameFallbackToIdQuirk;
    bool m_needsIsLoadingInAPISenseQuirk;
    bool m_needsKeyboardEventDisambiguationQuirks;
    bool m_needsSiteSpecificQuirks;
    bool m_needsStorageAccessFromFileURLsQuirk;
    bool m_notificationsEnabled;
    bool m_offlineWebApplicationCacheEnabled;
    bool m_pageCacheSupportsPlugins;
    bool m_paginateDuringLayoutEnabled;
    bool m_passiveTouchListenersAsDefaultOnDocument;
    double m_passwordEchoDurationInSeconds;
    bool m_passwordEchoEnabled;
#if ENABLE(PAYMENT_REQUEST)
    bool m_paymentRequestEnabled;
#endif
    bool m_plugInSnapshottingEnabled;
    bool m_pluginsEnabled;
    bool m_preferMIMETypeForImages;
    bool m_preventKeyboardDOMEventDispatch;
    bool m_primaryPlugInSnapshotDetectionEnabled;
    bool m_punchOutWhiteBackgroundsInDarkMode;
    bool m_quickTimePluginReplacementEnabled;
    bool m_repaintOutsideLayoutEnabled;
    bool m_requestAnimationFrameEnabled;
    bool m_requiresUserGestureToLoadVideo;
#if ENABLE(RESIZE_OBSERVER)
    bool m_resizeObserverEnabled;
#endif
    bool m_resourceUsageOverlayVisible;
#if ENABLE(RUBBER_BANDING)
    bool m_rubberBandingForSubScrollableRegionsEnabled;
#endif
    bool m_scriptEnabled;
    bool m_scriptMarkupEnabled;
#if ENABLE(SMOOTH_SCROLLING)
    bool m_scrollAnimatorEnabled;
#endif
    bool m_scrollingCoordinatorEnabled;
    bool m_scrollingPerformanceLoggingEnabled;
    bool m_scrollingTreeIncludesFrames;
    bool m_selectTrailingWhitespaceEnabled;
    bool m_selectionAcrossShadowBoundariesEnabled;
    bool m_selectionPaintingWithoutSelectionGapsEnabled;
#if ENABLE(SERVICE_CONTROLS)
    bool m_serviceControlsEnabled;
#endif
    unsigned m_sessionStorageQuota;
    bool m_shouldAllowDesignSystemUIFonts;
    bool m_shouldAllowUserInstalledFonts;
    bool m_shouldConvertInvalidURLsToBlank;
    bool m_shouldConvertPositionStyleOnCopy;
    bool m_shouldDecidePolicyBeforeLoadingQuickLookPreview;
    bool m_shouldDeferAsynchronousScriptsUntilAfterDocumentLoad;
    bool m_shouldDispatchSyntheticMouseEventsWhenModifyingSelection;
    bool m_shouldDispatchSyntheticMouseOutAfterSyntheticClick;
#if ENABLE(VIDEO_TRACK)
    bool m_shouldDisplayCaptions;
#endif
#if ENABLE(VIDEO_TRACK)
    bool m_shouldDisplaySubtitles;
#endif
#if ENABLE(VIDEO_TRACK)
    bool m_shouldDisplayTextDescriptions;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    bool m_shouldEnableTextAutosizingBoost;
#endif
    bool m_shouldIgnoreFontLoadCompletions;
    bool m_shouldIgnoreMetaViewport;
    bool m_shouldInjectUserScriptsInInitialEmptyDocument;
    bool m_shouldPrintBackgrounds;
    bool m_shouldRespectImageOrientation;
    bool m_shouldSuppressTextInputFromEditingDuringProvisionalNavigation;
    bool m_showDebugBorders;
    bool m_showRepaintCounter;
    bool m_showTiledScrollingIndicator;
    bool m_showsToolTipOverTruncatedText;
    bool m_showsURLsInToolTips;
    bool m_shrinksStandaloneImagesToFit;
    bool m_simpleLineLayoutDebugBordersEnabled;
    bool m_simpleLineLayoutEnabled;
    bool m_smartInsertDeleteEnabled;
    bool m_snapshotAllPlugIns;
#if ENABLE(MEDIA_SOURCE)
    bool m_sourceBufferChangeTypeEnabled;
#endif
    bool m_spatialNavigationEnabled;
    bool m_springTimingFunctionEnabled;
    bool m_standalone;
    bool m_storageAccessAPIEnabled;
    bool m_subpixelAntialiasedLayerTextEnabled;
    bool m_subpixelCSSOMElementMetricsEnabled;
    bool m_subresourceIntegrityEnabled;
    bool m_suppressesIncrementalRendering;
    bool m_syntheticEditingCommandsEnabled;
    bool m_telephoneNumberParsingEnabled;
    bool m_temporaryTileCohortRetentionEnabled;
    bool m_textAreasAreResizable;
#if ENABLE(TEXT_AUTOSIZING)
    bool m_textAutosizingEnabled;
#endif
#if ENABLE(TEXT_AUTOSIZING)
    bool m_textAutosizingUsesIdempotentMode;
#endif
    bool m_thirdPartyIframeRedirectBlockingEnabled;
#if ENABLE(TOUCH_EVENTS)
    bool m_touchEventEmulationEnabled;
#endif
    bool m_treatIPAddressAsDomain;
    bool m_treatsAnyTextCSSLinkAsStylesheet;
    bool m_unhandledPromiseRejectionToConsoleEnabled;
    bool m_unifiedTextCheckerEnabled;
    bool m_useAnonymousModeWhenFetchingMaskImages;
    bool m_useGiantTiles;
    bool m_useImageDocumentForSubframePDF;
    bool m_useLegacyBackgroundSizeShorthandBehavior;
    bool m_useLegacyTextAlignPositionedElementBehavior;
    bool m_usePreHTML5ParserQuirks;
    bool m_usesEncodingDetector;
    bool m_usesPageCache;
    int m_validationMessageTimerMagnification;
    bool m_videoPlaybackRequiresUserGesture;
#if ENABLE(VIDEO)
    bool m_videoQualityIncludesDisplayCompositingEnabled;
#endif
    bool m_viewportFitEnabled;
    bool m_visualViewportAPIEnabled;
    bool m_visualViewportEnabled;
    bool m_wantsBalancedSetDefersLoadingBehavior;
#if ENABLE(WEB_ARCHIVE)
    bool m_webArchiveDebugModeEnabled;
#endif
    bool m_webAudioEnabled;
    bool m_webGLEnabled;
    bool m_webGLErrorsToConsoleEnabled;
    bool m_webSecurityEnabled;
    bool m_webkitImageReadyEventEnabled;
    bool m_windowFocusRestricted;
    bool m_xssAuditorEnabled;
    bool m_youTubeFlashPluginReplacementEnabled;
};

} // namespace WebCore
