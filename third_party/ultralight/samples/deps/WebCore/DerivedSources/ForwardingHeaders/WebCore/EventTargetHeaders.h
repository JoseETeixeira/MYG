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

#ifndef EventTargetHeaders_h
#define EventTargetHeaders_h

#include "AbortSignal.h"
#include "JSAbortSignal.h"
#if ENABLE(APPLE_PAY)
#include "ApplePaySession.h"
#include "JSApplePaySession.h"
#endif
#if ENABLE(WEB_AUDIO)
#include "AudioContext.h"
#include "JSAudioContext.h"
#endif
#if ENABLE(WEB_AUDIO)
#include "AudioNode.h"
#include "JSAudioNode.h"
#endif
#if ENABLE(VIDEO_TRACK)
#include "AudioTrackList.h"
#include "JSAudioTrackList.h"
#endif
#include "DOMApplicationCache.h"
#include "JSDOMApplicationCache.h"
#include "DOMWindow.h"
#include "JSDOMWindow.h"
#include "DedicatedWorkerGlobalScope.h"
#include "JSDedicatedWorkerGlobalScope.h"
#include "EventSource.h"
#include "JSEventSource.h"
#include "FileReader.h"
#include "JSFileReader.h"
#include "FontFaceSet.h"
#include "JSFontFaceSet.h"
#if ENABLE(INDEXED_DATABASE)
#include "IDBDatabase.h"
#include "JSIDBDatabase.h"
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBOpenDBRequest.h"
#include "JSIDBOpenDBRequest.h"
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBRequest.h"
#include "JSIDBRequest.h"
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBTransaction.h"
#include "JSIDBTransaction.h"
#endif
#if ENABLE(VIDEO)
#include "MediaController.h"
#include "JSMediaController.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaDevices.h"
#include "JSMediaDevices.h"
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include "MediaKeySession.h"
#include "JSMediaKeySession.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaRecorder.h"
#include "JSMediaRecorder.h"
#endif
#if ENABLE(MEDIA_SESSION)
#include "MediaRemoteControls.h"
#include "JSMediaRemoteControls.h"
#endif
#if ENABLE(MEDIA_SOURCE)
#include "MediaSource.h"
#include "JSMediaSource.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaStream.h"
#include "JSMediaStream.h"
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaStreamTrack.h"
#include "JSMediaStreamTrack.h"
#endif
#include "MessagePort.h"
#include "JSMessagePort.h"
#include "Node.h"
#include "JSNode.h"
#if ENABLE(NOTIFICATIONS)
#include "Notification.h"
#include "JSNotification.h"
#endif
#include "OffscreenCanvas.h"
#include "JSOffscreenCanvas.h"
#if ENABLE(PAYMENT_REQUEST)
#include "PaymentRequest.h"
#include "JSPaymentRequest.h"
#endif
#if ENABLE(PAYMENT_REQUEST)
#include "PaymentResponse.h"
#include "JSPaymentResponse.h"
#endif
#include "Performance.h"
#include "JSPerformance.h"
#if ENABLE(WEB_RTC_DTMF)
#include "RTCDTMFSender.h"
#include "JSRTCDTMFSender.h"
#endif
#if ENABLE(WEB_RTC)
#include "RTCDataChannel.h"
#include "JSRTCDataChannel.h"
#endif
#if ENABLE(WEB_RTC)
#include "RTCPeerConnection.h"
#include "JSRTCPeerConnection.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "ServiceWorker.h"
#include "JSServiceWorker.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "ServiceWorkerContainer.h"
#include "JSServiceWorkerContainer.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "ServiceWorkerGlobalScope.h"
#include "JSServiceWorkerGlobalScope.h"
#endif
#if ENABLE(SERVICE_WORKER)
#include "ServiceWorkerRegistration.h"
#include "JSServiceWorkerRegistration.h"
#endif
#if ENABLE(MEDIA_SOURCE)
#include "SourceBuffer.h"
#include "JSSourceBuffer.h"
#endif
#if ENABLE(MEDIA_SOURCE)
#include "SourceBufferList.h"
#include "JSSourceBufferList.h"
#endif
#if ENABLE(SPEECH_SYNTHESIS)
#include "SpeechSynthesisUtterance.h"
#include "JSSpeechSynthesisUtterance.h"
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrack.h"
#include "JSTextTrack.h"
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrackCue.h"
#include "JSTextTrackCue.h"
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrackList.h"
#include "JSTextTrackList.h"
#endif
#include "VRDisplay.h"
#include "JSVRDisplay.h"
#if ENABLE(VIDEO_TRACK)
#include "VideoTrackList.h"
#include "JSVideoTrackList.h"
#endif
#include "VisualViewport.h"
#include "JSVisualViewport.h"
#include "WebAnimation.h"
#include "JSWebAnimation.h"
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
#include "WebKitMediaKeySession.h"
#include "JSWebKitMediaKeySession.h"
#endif
#include "WebSocket.h"
#include "JSWebSocket.h"
#include "Worker.h"
#include "JSWorker.h"
#if ENABLE(CSS_PAINTING_API)
#include "WorkletGlobalScope.h"
#include "JSWorkletGlobalScope.h"
#endif
#include "XMLHttpRequest.h"
#include "JSXMLHttpRequest.h"
#include "XMLHttpRequestUpload.h"
#include "JSXMLHttpRequestUpload.h"

#endif // EventTargetHeaders_h
