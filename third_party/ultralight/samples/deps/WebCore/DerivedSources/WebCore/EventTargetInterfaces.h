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

#pragma once

namespace WebCore {

enum EventTargetInterface {
#if ENABLE(APPLE_PAY)
    ApplePaySessionEventTargetInterfaceType = 1,
#endif
#if ENABLE(CSS_PAINTING_API)
    WorkletGlobalScopeEventTargetInterfaceType = 2,
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    MediaKeySessionEventTargetInterfaceType = 3,
#endif
#if ENABLE(INDEXED_DATABASE)
    IDBDatabaseEventTargetInterfaceType = 4,
    IDBOpenDBRequestEventTargetInterfaceType = 5,
    IDBRequestEventTargetInterfaceType = 6,
    IDBTransactionEventTargetInterfaceType = 7,
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    WebKitMediaKeySessionEventTargetInterfaceType = 8,
#endif
#if ENABLE(MEDIA_SESSION)
    MediaRemoteControlsEventTargetInterfaceType = 9,
#endif
#if ENABLE(MEDIA_SOURCE)
    MediaSourceEventTargetInterfaceType = 10,
    SourceBufferEventTargetInterfaceType = 11,
    SourceBufferListEventTargetInterfaceType = 12,
#endif
#if ENABLE(MEDIA_STREAM)
    MediaDevicesEventTargetInterfaceType = 13,
    MediaRecorderEventTargetInterfaceType = 14,
    MediaStreamEventTargetInterfaceType = 15,
    MediaStreamTrackEventTargetInterfaceType = 16,
#endif
#if ENABLE(NOTIFICATIONS)
    NotificationEventTargetInterfaceType = 17,
#endif
#if ENABLE(PAYMENT_REQUEST)
    PaymentRequestEventTargetInterfaceType = 18,
    PaymentResponseEventTargetInterfaceType = 19,
#endif
#if ENABLE(SERVICE_WORKER)
    ServiceWorkerEventTargetInterfaceType = 20,
    ServiceWorkerContainerEventTargetInterfaceType = 21,
    ServiceWorkerGlobalScopeEventTargetInterfaceType = 22,
    ServiceWorkerRegistrationEventTargetInterfaceType = 23,
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    SpeechSynthesisUtteranceEventTargetInterfaceType = 24,
#endif
#if ENABLE(VIDEO)
    MediaControllerEventTargetInterfaceType = 25,
#endif
#if ENABLE(VIDEO_TRACK)
    AudioTrackListEventTargetInterfaceType = 26,
    TextTrackEventTargetInterfaceType = 27,
    TextTrackCueEventTargetInterfaceType = 28,
    TextTrackListEventTargetInterfaceType = 29,
    VideoTrackListEventTargetInterfaceType = 30,
#endif
#if ENABLE(WEB_AUDIO)
    AudioContextEventTargetInterfaceType = 31,
    AudioNodeEventTargetInterfaceType = 32,
#endif
#if ENABLE(WEB_RTC)
    RTCDataChannelEventTargetInterfaceType = 33,
    RTCPeerConnectionEventTargetInterfaceType = 34,
#endif
#if ENABLE(WEB_RTC_DTMF)
    RTCDTMFSenderEventTargetInterfaceType = 35,
#endif
    AbortSignalEventTargetInterfaceType = 36,
    DOMApplicationCacheEventTargetInterfaceType = 37,
    DOMWindowEventTargetInterfaceType = 38,
    DedicatedWorkerGlobalScopeEventTargetInterfaceType = 39,
    EventSourceEventTargetInterfaceType = 40,
    FileReaderEventTargetInterfaceType = 41,
    FontFaceSetEventTargetInterfaceType = 42,
    MessagePortEventTargetInterfaceType = 43,
    NodeEventTargetInterfaceType = 44,
    OffscreenCanvasEventTargetInterfaceType = 45,
    PerformanceEventTargetInterfaceType = 46,
    VRDisplayEventTargetInterfaceType = 47,
    VisualViewportEventTargetInterfaceType = 48,
    WebAnimationEventTargetInterfaceType = 49,
    WebSocketEventTargetInterfaceType = 50,
    WorkerEventTargetInterfaceType = 51,
    XMLHttpRequestEventTargetInterfaceType = 52,
    XMLHttpRequestUploadEventTargetInterfaceType = 53,
};

} // namespace WebCore
