/*
 * Copyright (c) 2015 Canon Inc.
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2016 Apple Inc. All rights reserved.
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

#if ENABLE(STREAMS_API)

#include <JavaScriptCore/BuiltinUtils.h>
#include <JavaScriptCore/Identifier.h>
#include <JavaScriptCore/JSFunction.h>
#include <JavaScriptCore/UnlinkedFunctionExecutable.h>

namespace JSC {
class FunctionExecutable;
}

namespace WebCore {

/* WritableStream */
extern const char* const s_writableStreamInitializeWritableStreamCode;
extern const int s_writableStreamInitializeWritableStreamCodeLength;
extern const JSC::ConstructAbility s_writableStreamInitializeWritableStreamCodeConstructAbility;
extern const char* const s_writableStreamAbortCode;
extern const int s_writableStreamAbortCodeLength;
extern const JSC::ConstructAbility s_writableStreamAbortCodeConstructAbility;
extern const char* const s_writableStreamCloseCode;
extern const int s_writableStreamCloseCodeLength;
extern const JSC::ConstructAbility s_writableStreamCloseCodeConstructAbility;
extern const char* const s_writableStreamWriteCode;
extern const int s_writableStreamWriteCodeLength;
extern const JSC::ConstructAbility s_writableStreamWriteCodeConstructAbility;
extern const char* const s_writableStreamClosedCode;
extern const int s_writableStreamClosedCodeLength;
extern const JSC::ConstructAbility s_writableStreamClosedCodeConstructAbility;
extern const char* const s_writableStreamReadyCode;
extern const int s_writableStreamReadyCodeLength;
extern const JSC::ConstructAbility s_writableStreamReadyCodeConstructAbility;
extern const char* const s_writableStreamStateCode;
extern const int s_writableStreamStateCodeLength;
extern const JSC::ConstructAbility s_writableStreamStateCodeConstructAbility;

#define WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_DATA(macro) \
    macro(initializeWritableStream, writableStreamInitializeWritableStream, 2) \
    macro(abort, writableStreamAbort, 1) \
    macro(close, writableStreamClose, 0) \
    macro(write, writableStreamWrite, 1) \
    macro(closed, writableStreamClosed, 0) \
    macro(ready, writableStreamReady, 0) \
    macro(state, writableStreamState, 0) \

#define WEBCORE_BUILTIN_WRITABLESTREAM_INITIALIZEWRITABLESTREAM 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_ABORT 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_CLOSE 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_WRITE 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_CLOSED 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_READY 1
#define WEBCORE_BUILTIN_WRITABLESTREAM_STATE 1

#define WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(macro) \
    macro(writableStreamInitializeWritableStreamCode, initializeWritableStream, static_cast<const char*>(nullptr), s_writableStreamInitializeWritableStreamCodeLength) \
    macro(writableStreamAbortCode, abort, static_cast<const char*>(nullptr), s_writableStreamAbortCodeLength) \
    macro(writableStreamCloseCode, close, static_cast<const char*>(nullptr), s_writableStreamCloseCodeLength) \
    macro(writableStreamWriteCode, write, static_cast<const char*>(nullptr), s_writableStreamWriteCodeLength) \
    macro(writableStreamClosedCode, closed, "get closed", s_writableStreamClosedCodeLength) \
    macro(writableStreamReadyCode, ready, "get ready", s_writableStreamReadyCodeLength) \
    macro(writableStreamStateCode, state, "get state", s_writableStreamStateCodeLength) \

#define WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_FUNCTION_NAME(macro) \
    macro(abort) \
    macro(close) \
    macro(closed) \
    macro(initializeWritableStream) \
    macro(ready) \
    macro(state) \
    macro(write) \

#define DECLARE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
    JSC::FunctionExecutable* codeName##Generator(JSC::VM&);

WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(DECLARE_BUILTIN_GENERATOR)
#undef DECLARE_BUILTIN_GENERATOR

class WritableStreamBuiltinsWrapper : private JSC::WeakHandleOwner {
public:
    explicit WritableStreamBuiltinsWrapper(JSC::VM* vm)
        : m_vm(*vm)
        WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_FUNCTION_NAME(INITIALIZE_BUILTIN_NAMES)
#define INITIALIZE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) , m_##name##Source(JSC::makeSource(StringImpl::createFromLiteral(s_##name, length), { }))
        WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(INITIALIZE_BUILTIN_SOURCE_MEMBERS)
#undef INITIALIZE_BUILTIN_SOURCE_MEMBERS
    {
    }

#define EXPOSE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
    JSC::UnlinkedFunctionExecutable* name##Executable(); \
    const JSC::SourceCode& name##Source() const { return m_##name##Source; }
    WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(EXPOSE_BUILTIN_EXECUTABLES)
#undef EXPOSE_BUILTIN_EXECUTABLES

    WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_IDENTIFIER_ACCESSOR)

    void exportNames();

private:
    JSC::VM& m_vm;

    WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_NAMES)

#define DECLARE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) \
    JSC::SourceCode m_##name##Source;\
    JSC::Weak<JSC::UnlinkedFunctionExecutable> m_##name##Executable;
    WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(DECLARE_BUILTIN_SOURCE_MEMBERS)
#undef DECLARE_BUILTIN_SOURCE_MEMBERS

};

#define DEFINE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
inline JSC::UnlinkedFunctionExecutable* WritableStreamBuiltinsWrapper::name##Executable() \
{\
    if (!m_##name##Executable) {\
        JSC::Identifier executableName = functionName##PublicName();\
        if (overriddenName)\
            executableName = JSC::Identifier::fromString(&m_vm, overriddenName);\
        m_##name##Executable = JSC::Weak<JSC::UnlinkedFunctionExecutable>(JSC::createBuiltinExecutable(m_vm, m_##name##Source, executableName, s_##name##ConstructAbility), this, &m_##name##Executable);\
    }\
    return m_##name##Executable.get();\
}
WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_CODE(DEFINE_BUILTIN_EXECUTABLES)
#undef DEFINE_BUILTIN_EXECUTABLES

inline void WritableStreamBuiltinsWrapper::exportNames()
{
#define EXPORT_FUNCTION_NAME(name) m_vm.propertyNames->appendExternalName(name##PublicName(), name##PrivateName());
    WEBCORE_FOREACH_WRITABLESTREAM_BUILTIN_FUNCTION_NAME(EXPORT_FUNCTION_NAME)
#undef EXPORT_FUNCTION_NAME
}

} // namespace WebCore

#endif // ENABLE(STREAMS_API)
