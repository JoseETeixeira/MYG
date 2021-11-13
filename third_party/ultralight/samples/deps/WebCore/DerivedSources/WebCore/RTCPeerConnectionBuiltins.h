/*
 * Copyright (c) 2015, 2016 Ericsson AB. All rights reserved.
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

#if ENABLE(WEB_RTC)

#include <JavaScriptCore/BuiltinUtils.h>
#include <JavaScriptCore/Identifier.h>
#include <JavaScriptCore/JSFunction.h>
#include <JavaScriptCore/UnlinkedFunctionExecutable.h>

namespace JSC {
class FunctionExecutable;
}

namespace WebCore {

/* RTCPeerConnection */
extern const char* const s_rtcPeerConnectionInitializeRTCPeerConnectionCode;
extern const int s_rtcPeerConnectionInitializeRTCPeerConnectionCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionInitializeRTCPeerConnectionCodeConstructAbility;
extern const char* const s_rtcPeerConnectionCreateOfferCode;
extern const int s_rtcPeerConnectionCreateOfferCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionCreateOfferCodeConstructAbility;
extern const char* const s_rtcPeerConnectionCreateAnswerCode;
extern const int s_rtcPeerConnectionCreateAnswerCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionCreateAnswerCodeConstructAbility;
extern const char* const s_rtcPeerConnectionSetLocalDescriptionCode;
extern const int s_rtcPeerConnectionSetLocalDescriptionCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionSetLocalDescriptionCodeConstructAbility;
extern const char* const s_rtcPeerConnectionSetRemoteDescriptionCode;
extern const int s_rtcPeerConnectionSetRemoteDescriptionCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionSetRemoteDescriptionCodeConstructAbility;
extern const char* const s_rtcPeerConnectionAddIceCandidateCode;
extern const int s_rtcPeerConnectionAddIceCandidateCodeLength;
extern const JSC::ConstructAbility s_rtcPeerConnectionAddIceCandidateCodeConstructAbility;

#define WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_DATA(macro) \
    macro(initializeRTCPeerConnection, rtcPeerConnectionInitializeRTCPeerConnection, 1) \
    macro(createOffer, rtcPeerConnectionCreateOffer, 0) \
    macro(createAnswer, rtcPeerConnectionCreateAnswer, 0) \
    macro(setLocalDescription, rtcPeerConnectionSetLocalDescription, 1) \
    macro(setRemoteDescription, rtcPeerConnectionSetRemoteDescription, 1) \
    macro(addIceCandidate, rtcPeerConnectionAddIceCandidate, 1) \

#define WEBCORE_BUILTIN_RTCPEERCONNECTION_INITIALIZERTCPEERCONNECTION 1
#define WEBCORE_BUILTIN_RTCPEERCONNECTION_CREATEOFFER 1
#define WEBCORE_BUILTIN_RTCPEERCONNECTION_CREATEANSWER 1
#define WEBCORE_BUILTIN_RTCPEERCONNECTION_SETLOCALDESCRIPTION 1
#define WEBCORE_BUILTIN_RTCPEERCONNECTION_SETREMOTEDESCRIPTION 1
#define WEBCORE_BUILTIN_RTCPEERCONNECTION_ADDICECANDIDATE 1

#define WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(macro) \
    macro(rtcPeerConnectionInitializeRTCPeerConnectionCode, initializeRTCPeerConnection, static_cast<const char*>(nullptr), s_rtcPeerConnectionInitializeRTCPeerConnectionCodeLength) \
    macro(rtcPeerConnectionCreateOfferCode, createOffer, static_cast<const char*>(nullptr), s_rtcPeerConnectionCreateOfferCodeLength) \
    macro(rtcPeerConnectionCreateAnswerCode, createAnswer, static_cast<const char*>(nullptr), s_rtcPeerConnectionCreateAnswerCodeLength) \
    macro(rtcPeerConnectionSetLocalDescriptionCode, setLocalDescription, static_cast<const char*>(nullptr), s_rtcPeerConnectionSetLocalDescriptionCodeLength) \
    macro(rtcPeerConnectionSetRemoteDescriptionCode, setRemoteDescription, static_cast<const char*>(nullptr), s_rtcPeerConnectionSetRemoteDescriptionCodeLength) \
    macro(rtcPeerConnectionAddIceCandidateCode, addIceCandidate, static_cast<const char*>(nullptr), s_rtcPeerConnectionAddIceCandidateCodeLength) \

#define WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_FUNCTION_NAME(macro) \
    macro(addIceCandidate) \
    macro(createAnswer) \
    macro(createOffer) \
    macro(initializeRTCPeerConnection) \
    macro(setLocalDescription) \
    macro(setRemoteDescription) \

#define DECLARE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
    JSC::FunctionExecutable* codeName##Generator(JSC::VM&);

WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(DECLARE_BUILTIN_GENERATOR)
#undef DECLARE_BUILTIN_GENERATOR

class RTCPeerConnectionBuiltinsWrapper : private JSC::WeakHandleOwner {
public:
    explicit RTCPeerConnectionBuiltinsWrapper(JSC::VM* vm)
        : m_vm(*vm)
        WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_FUNCTION_NAME(INITIALIZE_BUILTIN_NAMES)
#define INITIALIZE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) , m_##name##Source(JSC::makeSource(StringImpl::createFromLiteral(s_##name, length), { }))
        WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(INITIALIZE_BUILTIN_SOURCE_MEMBERS)
#undef INITIALIZE_BUILTIN_SOURCE_MEMBERS
    {
    }

#define EXPOSE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
    JSC::UnlinkedFunctionExecutable* name##Executable(); \
    const JSC::SourceCode& name##Source() const { return m_##name##Source; }
    WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(EXPOSE_BUILTIN_EXECUTABLES)
#undef EXPOSE_BUILTIN_EXECUTABLES

    WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_IDENTIFIER_ACCESSOR)

    void exportNames();

private:
    JSC::VM& m_vm;

    WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_NAMES)

#define DECLARE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) \
    JSC::SourceCode m_##name##Source;\
    JSC::Weak<JSC::UnlinkedFunctionExecutable> m_##name##Executable;
    WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(DECLARE_BUILTIN_SOURCE_MEMBERS)
#undef DECLARE_BUILTIN_SOURCE_MEMBERS

};

#define DEFINE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
inline JSC::UnlinkedFunctionExecutable* RTCPeerConnectionBuiltinsWrapper::name##Executable() \
{\
    if (!m_##name##Executable) {\
        JSC::Identifier executableName = functionName##PublicName();\
        if (overriddenName)\
            executableName = JSC::Identifier::fromString(&m_vm, overriddenName);\
        m_##name##Executable = JSC::Weak<JSC::UnlinkedFunctionExecutable>(JSC::createBuiltinExecutable(m_vm, m_##name##Source, executableName, s_##name##ConstructAbility), this, &m_##name##Executable);\
    }\
    return m_##name##Executable.get();\
}
WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_CODE(DEFINE_BUILTIN_EXECUTABLES)
#undef DEFINE_BUILTIN_EXECUTABLES

inline void RTCPeerConnectionBuiltinsWrapper::exportNames()
{
#define EXPORT_FUNCTION_NAME(name) m_vm.propertyNames->appendExternalName(name##PublicName(), name##PrivateName());
    WEBCORE_FOREACH_RTCPEERCONNECTION_BUILTIN_FUNCTION_NAME(EXPORT_FUNCTION_NAME)
#undef EXPORT_FUNCTION_NAME
}

} // namespace WebCore

#endif // ENABLE(WEB_RTC)
