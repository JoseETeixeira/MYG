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

#include "EventTarget.h"
#include "JSDOMConvertDictionary.h"
#include "JSDOMWrapper.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSEventTarget : public JSDOMWrapper<EventTarget> {
public:
    using Base = JSDOMWrapper<EventTarget>;
    static JSEventTarget* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<EventTarget>&& impl)
    {
        JSEventTarget* ptr = new (NotNull, JSC::allocateCell<JSEventTarget>(globalObject->vm().heap)) JSEventTarget(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static EventTarget* toWrapped(JSC::VM&, JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void visitChildren(JSCell*, JSC::SlotVisitor&);
    void visitAdditionalChildren(JSC::SlotVisitor&);

    static void visitOutputConstraints(JSCell*, JSC::SlotVisitor&);
    template<typename, JSC::SubspaceAccess> static JSC::CompleteSubspace* subspaceFor(JSC::VM& vm) { return outputConstraintSubspaceFor(vm); }
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
protected:
    JSEventTarget(JSC::Structure*, JSDOMGlobalObject&, Ref<EventTarget>&&);

    void finishCreation(JSC::VM&);
};

class JSEventTargetOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, EventTarget*)
{
    static NeverDestroyed<JSEventTargetOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(EventTarget* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, EventTarget&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, EventTarget* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<EventTarget>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<EventTarget>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<EventTarget> {
    using WrapperClass = JSEventTarget;
    using ToWrappedReturnType = EventTarget*;
};
template<> EventTarget::ListenerOptions convertDictionary<EventTarget::ListenerOptions>(JSC::ExecState&, JSC::JSValue);

template<> EventTarget::AddEventListenerOptions convertDictionary<EventTarget::AddEventListenerOptions>(JSC::ExecState&, JSC::JSValue);


} // namespace WebCore
#include "JSEventTargetCustom.h"
