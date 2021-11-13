/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#pragma once

#if ENABLE(SPEECH_SYNTHESIS)

#include "JSDOMWrapper.h"
#include "JSEvent.h"
#include "SpeechSynthesisEvent.h"

namespace WebCore {

class JSSpeechSynthesisEvent : public JSEvent {
public:
    using Base = JSEvent;
    using DOMWrapped = SpeechSynthesisEvent;
    static JSSpeechSynthesisEvent* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<SpeechSynthesisEvent>&& impl)
    {
        JSSpeechSynthesisEvent* ptr = new (NotNull, JSC::allocateCell<JSSpeechSynthesisEvent>(globalObject->vm().heap)) JSSpeechSynthesisEvent(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::JSType(JSEventType), StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    SpeechSynthesisEvent& wrapped() const
    {
        return static_cast<SpeechSynthesisEvent&>(Base::wrapped());
    }
protected:
    JSSpeechSynthesisEvent(JSC::Structure*, JSDOMGlobalObject&, Ref<SpeechSynthesisEvent>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<SpeechSynthesisEvent> {
    using WrapperClass = JSSpeechSynthesisEvent;
    using ToWrappedReturnType = SpeechSynthesisEvent*;
};

} // namespace WebCore

#endif // ENABLE(SPEECH_SYNTHESIS)
