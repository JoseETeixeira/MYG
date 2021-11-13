/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016 Ericsson AB. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016 Apple Inc. All rights reserved.
 * Copyright (c) 2017 Apple Inc.
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
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#pragma once

#include "ByteLengthQueuingStrategyBuiltins.h"
#include "CountQueuingStrategyBuiltins.h"
#include "JSDOMBindingInternalsBuiltins.h"
#include "RTCPeerConnectionBuiltins.h"
#include "RTCPeerConnectionInternalsBuiltins.h"
#include "ReadableByteStreamControllerBuiltins.h"
#include "ReadableByteStreamInternalsBuiltins.h"
#include "ReadableStreamBYOBReaderBuiltins.h"
#include "ReadableStreamBYOBRequestBuiltins.h"
#include "ReadableStreamBuiltins.h"
#include "ReadableStreamDefaultControllerBuiltins.h"
#include "ReadableStreamDefaultReaderBuiltins.h"
#include "ReadableStreamInternalsBuiltins.h"
#include "StreamInternalsBuiltins.h"
#include "WritableStreamBuiltins.h"
#include "WritableStreamInternalsBuiltins.h"
#include <JavaScriptCore/VM.h>

namespace WebCore {

class JSBuiltinFunctions {
public:
    explicit JSBuiltinFunctions(JSC::VM& vm)
        : m_vm(vm)
#if ENABLE(WEB_RTC)
        , m_rtcPeerConnectionBuiltins(&m_vm)
#endif // ENABLE(WEB_RTC)
#if ENABLE(WEB_RTC)
        , m_rtcPeerConnectionInternalsBuiltins(&m_vm)
#endif // ENABLE(WEB_RTC)
#if ENABLE(STREAMS_API)
        , m_byteLengthQueuingStrategyBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_countQueuingStrategyBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableByteStreamControllerBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableByteStreamInternalsBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamBYOBReaderBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamBYOBRequestBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamDefaultControllerBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamDefaultReaderBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_readableStreamInternalsBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_streamInternalsBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_writableStreamBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        , m_writableStreamInternalsBuiltins(&m_vm)
#endif // ENABLE(STREAMS_API)
        , m_jsDOMBindingInternalsBuiltins(&m_vm)
    {
#if ENABLE(WEB_RTC)
        m_rtcPeerConnectionInternalsBuiltins.exportNames();
#endif // ENABLE(WEB_RTC)
#if ENABLE(STREAMS_API)
        m_readableByteStreamInternalsBuiltins.exportNames();
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        m_readableStreamInternalsBuiltins.exportNames();
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        m_streamInternalsBuiltins.exportNames();
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
        m_writableStreamInternalsBuiltins.exportNames();
#endif // ENABLE(STREAMS_API)
        m_jsDOMBindingInternalsBuiltins.exportNames();
    }

#if ENABLE(WEB_RTC)
    RTCPeerConnectionBuiltinsWrapper& rtcPeerConnectionBuiltins() { return m_rtcPeerConnectionBuiltins; }
#endif // ENABLE(WEB_RTC)
#if ENABLE(WEB_RTC)
    RTCPeerConnectionInternalsBuiltinsWrapper& rtcPeerConnectionInternalsBuiltins() { return m_rtcPeerConnectionInternalsBuiltins; }
#endif // ENABLE(WEB_RTC)
#if ENABLE(STREAMS_API)
    ByteLengthQueuingStrategyBuiltinsWrapper& byteLengthQueuingStrategyBuiltins() { return m_byteLengthQueuingStrategyBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    CountQueuingStrategyBuiltinsWrapper& countQueuingStrategyBuiltins() { return m_countQueuingStrategyBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableByteStreamControllerBuiltinsWrapper& readableByteStreamControllerBuiltins() { return m_readableByteStreamControllerBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableByteStreamInternalsBuiltinsWrapper& readableByteStreamInternalsBuiltins() { return m_readableByteStreamInternalsBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBuiltinsWrapper& readableStreamBuiltins() { return m_readableStreamBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBYOBReaderBuiltinsWrapper& readableStreamBYOBReaderBuiltins() { return m_readableStreamBYOBReaderBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBYOBRequestBuiltinsWrapper& readableStreamBYOBRequestBuiltins() { return m_readableStreamBYOBRequestBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamDefaultControllerBuiltinsWrapper& readableStreamDefaultControllerBuiltins() { return m_readableStreamDefaultControllerBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamDefaultReaderBuiltinsWrapper& readableStreamDefaultReaderBuiltins() { return m_readableStreamDefaultReaderBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamInternalsBuiltinsWrapper& readableStreamInternalsBuiltins() { return m_readableStreamInternalsBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    StreamInternalsBuiltinsWrapper& streamInternalsBuiltins() { return m_streamInternalsBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    WritableStreamBuiltinsWrapper& writableStreamBuiltins() { return m_writableStreamBuiltins; }
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    WritableStreamInternalsBuiltinsWrapper& writableStreamInternalsBuiltins() { return m_writableStreamInternalsBuiltins; }
#endif // ENABLE(STREAMS_API)
    JSDOMBindingInternalsBuiltinsWrapper& jsDOMBindingInternalsBuiltins() { return m_jsDOMBindingInternalsBuiltins; }

private:
    JSC::VM& m_vm;
#if ENABLE(WEB_RTC)
    RTCPeerConnectionBuiltinsWrapper m_rtcPeerConnectionBuiltins;
#endif // ENABLE(WEB_RTC)
#if ENABLE(WEB_RTC)
    RTCPeerConnectionInternalsBuiltinsWrapper m_rtcPeerConnectionInternalsBuiltins;
#endif // ENABLE(WEB_RTC)
#if ENABLE(STREAMS_API)
    ByteLengthQueuingStrategyBuiltinsWrapper m_byteLengthQueuingStrategyBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    CountQueuingStrategyBuiltinsWrapper m_countQueuingStrategyBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableByteStreamControllerBuiltinsWrapper m_readableByteStreamControllerBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableByteStreamInternalsBuiltinsWrapper m_readableByteStreamInternalsBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBuiltinsWrapper m_readableStreamBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBYOBReaderBuiltinsWrapper m_readableStreamBYOBReaderBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamBYOBRequestBuiltinsWrapper m_readableStreamBYOBRequestBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamDefaultControllerBuiltinsWrapper m_readableStreamDefaultControllerBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamDefaultReaderBuiltinsWrapper m_readableStreamDefaultReaderBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    ReadableStreamInternalsBuiltinsWrapper m_readableStreamInternalsBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    StreamInternalsBuiltinsWrapper m_streamInternalsBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    WritableStreamBuiltinsWrapper m_writableStreamBuiltins;
#endif // ENABLE(STREAMS_API)
#if ENABLE(STREAMS_API)
    WritableStreamInternalsBuiltinsWrapper m_writableStreamInternalsBuiltins;
#endif // ENABLE(STREAMS_API)
    JSDOMBindingInternalsBuiltinsWrapper m_jsDOMBindingInternalsBuiltins;
};

} // namespace WebCore
