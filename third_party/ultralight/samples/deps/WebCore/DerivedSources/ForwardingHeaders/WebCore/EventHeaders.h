/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2011 Google Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY GOOGLE, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EventHeaders_h
#define EventHeaders_h

#include "AnimationEvent.h"
#include "JSAnimationEvent.h"
#include "AnimationPlaybackEvent.h"
#include "JSAnimationPlaybackEvent.h"
#if ENABLE(APPLE_PAY)
#include "ApplePayCancelEvent.h"
#include "JSApplePayCancelEvent.h"
#endif
#if ENABLE(APPLE_PAY)
#include "ApplePayPaymentAuthorizedEvent.h"
#include "JSApplePayPaymentAuthorizedEvent.h"
#endif
#if ENABLE(APPLE_PAY)
#include "ApplePayPaymentMethodSelectedEvent.h"
#include "JSApplePayPaymentMethodSelectedEvent.h"
#endif
#if ENABLE(APPLE_PAY)
#include "ApplePayShippingContactSelectedEvent.h"
#include "JSApplePayShippingContactSelectedEvent.h"
#endif
#if ENABLE(APPLE_PAY)
#include "ApplePayShippingMethodSelectedEvent.h"
#include "JSApplePayShippingMethodSelectedEvent.h"
#endif
#if ENABLE(APPLE_PAY)
#include "ApplePayValidateMerchantEvent.h"
#include "JSApplePayValidateMerchantEvent.h"
#endif
#if ENABLE(WEB_AUDIO)
#include "AudioProcessingEvent.h"
#include "JSAudioProcessingEvent.h"
#endif
#include "BeforeLoadEvent.h"
#include "JSBeforeLoadEvent.h"
#include "BeforeUnloadEvent.h"
#include "JSBeforeUnloadEvent.h"
#if ENABLE(MEDIA_STREAM)
#include "BlobEvent.h"
#include "JSBlobEvent.h"
#endif
#include "ClipboardEvent.h"
#include "JSClipboardEvent.h"
#include "CloseEvent.h"
#include "JSCloseEvent.h"
#include "CompositionEvent.h"
#include "JSCompositionEvent.h"
#include "CustomEvent.h"
#include "JSCustomEvent.h"
#if ENABLE(DEVICE_ORIENTATION)
#include "DeviceMotionEvent.h"
#include "JSDeviceMotionEvent.h"
#endif
#if ENABLE(DEVICE_ORIENTATION)
#include "DeviceOrientationEvent.h"
#include "JSDeviceOrientationEvent.h"
#endif
#include "ErrorEvent.h"
#include "JSErrorEvent.h"
#include "Event.h"
#include "JSEvent.h"
#if ENABLE(SERVICE_WORKER)
#include "ExtendableEvent.h"
#include "JSExtendableEvent.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "ExtendableMessageEvent.h"
#include "JSExtendableMessageEvent.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "FetchEvent.h"
#include "JSFetchEvent.h"
#endif
#include "FocusEvent.h"
#include "JSFocusEvent.h"
#if ENABLE(GAMEPAD)
#include "GamepadEvent.h"
#include "JSGamepadEvent.h"
#endif
#if ENABLE(IOS_GESTURE_EVENTS) || ENABLE(MAC_GESTURE_EVENTS)
#include "GestureEvent.h"
#include "JSGestureEvent.h"
#endif
#include "HashChangeEvent.h"
#include "JSHashChangeEvent.h"
#if ENABLE(INDEXED_DATABASE)
#include "IDBVersionChangeEvent.h"
#include "JSIDBVersionChangeEvent.h"
#endif
#include "InputEvent.h"
#include "JSInputEvent.h"
#include "KeyboardEvent.h"
#include "JSKeyboardEvent.h"
#if ENABLE(ENCRYPTED_MEDIA)
#include "MediaEncryptedEvent.h"
#include "JSMediaEncryptedEvent.h"
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include "MediaKeyMessageEvent.h"
#include "JSMediaKeyMessageEvent.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaRecorderErrorEvent.h"
#include "JSMediaRecorderErrorEvent.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaStreamTrackEvent.h"
#include "JSMediaStreamTrackEvent.h"
#endif
#if ENABLE(PAYMENT_REQUEST)
#include "MerchantValidationEvent.h"
#include "JSMerchantValidationEvent.h"
#endif
#include "MessageEvent.h"
#include "JSMessageEvent.h"
#include "MouseEvent.h"
#include "JSMouseEvent.h"
#include "MutationEvent.h"
#include "JSMutationEvent.h"
#if ENABLE(WEB_AUDIO)
#include "OfflineAudioCompletionEvent.h"
#include "JSOfflineAudioCompletionEvent.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "OverconstrainedErrorEvent.h"
#include "JSOverconstrainedErrorEvent.h"
#endif
#include "OverflowEvent.h"
#include "JSOverflowEvent.h"
#include "PageTransitionEvent.h"
#include "JSPageTransitionEvent.h"
#if ENABLE(PAYMENT_REQUEST)
#include "PaymentMethodChangeEvent.h"
#include "JSPaymentMethodChangeEvent.h"
#endif
#if ENABLE(PAYMENT_REQUEST)
#include "PaymentRequestUpdateEvent.h"
#include "JSPaymentRequestUpdateEvent.h"
#endif
#if ENABLE(POINTER_EVENTS)
#include "PointerEvent.h"
#include "JSPointerEvent.h"
#endif
#include "PopStateEvent.h"
#include "JSPopStateEvent.h"
#include "ProgressEvent.h"
#include "JSProgressEvent.h"
#include "PromiseRejectionEvent.h"
#include "JSPromiseRejectionEvent.h"
#if ENABLE(WEB_RTC_DTMF)
#include "RTCDTMFToneChangeEvent.h"
#include "JSRTCDTMFToneChangeEvent.h"
#endif
#if ENABLE(WEB_RTC)
#include "RTCDataChannelEvent.h"
#include "JSRTCDataChannelEvent.h"
#endif
#if ENABLE(WEB_RTC)
#include "RTCPeerConnectionIceEvent.h"
#include "JSRTCPeerConnectionIceEvent.h"
#endif
#if ENABLE(WEB_RTC)
#include "RTCTrackEvent.h"
#include "JSRTCTrackEvent.h"
#endif
#include "SVGZoomEvent.h"
#include "JSSVGZoomEvent.h"
#include "SecurityPolicyViolationEvent.h"
#include "JSSecurityPolicyViolationEvent.h"
#if ENABLE(SPEECH_SYNTHESIS)
#include "SpeechSynthesisEvent.h"
#include "JSSpeechSynthesisEvent.h"
#endif
#include "StorageEvent.h"
#include "JSStorageEvent.h"
#include "TextEvent.h"
#include "JSTextEvent.h"
#if ENABLE(TOUCH_EVENTS)
#include "TouchEvent.h"
#include "JSTouchEvent.h"
#endif
#if ENABLE(VIDEO_TRACK)
#include "TrackEvent.h"
#include "JSTrackEvent.h"
#endif
#include "TransitionEvent.h"
#include "JSTransitionEvent.h"
#include "UIEvent.h"
#include "JSUIEvent.h"
#include "VRDisplayEvent.h"
#include "JSVRDisplayEvent.h"
#if ENABLE(WEBGL)
#include "WebGLContextEvent.h"
#include "JSWebGLContextEvent.h"
#endif
#include "WebKitAnimationEvent.h"
#include "JSWebKitAnimationEvent.h"
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
#include "WebKitMediaKeyMessageEvent.h"
#include "JSWebKitMediaKeyMessageEvent.h"
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
#include "WebKitMediaKeyNeededEvent.h"
#include "JSWebKitMediaKeyNeededEvent.h"
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
#include "WebKitPlaybackTargetAvailabilityEvent.h"
#include "JSWebKitPlaybackTargetAvailabilityEvent.h"
#endif
#include "WebKitTransitionEvent.h"
#include "JSWebKitTransitionEvent.h"
#include "WheelEvent.h"
#include "JSWheelEvent.h"
#include "XMLHttpRequestProgressEvent.h"
#include "JSXMLHttpRequestProgressEvent.h"

#endif // EventHeaders_h
