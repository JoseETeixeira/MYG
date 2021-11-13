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

#include "JSDOMWrapper.h"
#include "JSEvent.h"
#include "UIEvent.h"

namespace WebCore {

class JSUIEvent : public JSEvent {
public:
    using Base = JSEvent;
    using DOMWrapped = UIEvent;
    static JSUIEvent* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<UIEvent>&& impl)
    {
        JSUIEvent* ptr = new (NotNull, JSC::allocateCell<JSUIEvent>(globalObject->vm().heap)) JSUIEvent(structure, *globalObject, WTFMove(impl));
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
    UIEvent& wrapped() const
    {
        return static_cast<UIEvent&>(Base::wrapped());
    }
protected:
    JSUIEvent(JSC::Structure*, JSDOMGlobalObject&, Ref<UIEvent>&&);

    void finishCreation(JSC::VM&);
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, UIEvent&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, UIEvent* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<UIEvent>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<UIEvent>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<UIEvent> {
    using WrapperClass = JSUIEvent;
    using ToWrappedReturnType = UIEvent*;
};

} // namespace WebCore
