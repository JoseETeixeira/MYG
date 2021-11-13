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
#include "OffscreenCanvasRenderingContext2D.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSOffscreenCanvasRenderingContext2D : public JSDOMWrapper<OffscreenCanvasRenderingContext2D> {
public:
    using Base = JSDOMWrapper<OffscreenCanvasRenderingContext2D>;
    static JSOffscreenCanvasRenderingContext2D* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<OffscreenCanvasRenderingContext2D>&& impl)
    {
        JSOffscreenCanvasRenderingContext2D* ptr = new (NotNull, JSC::allocateCell<JSOffscreenCanvasRenderingContext2D>(globalObject->vm().heap)) JSOffscreenCanvasRenderingContext2D(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static OffscreenCanvasRenderingContext2D* toWrapped(JSC::VM&, JSC::JSValue);
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
    JSOffscreenCanvasRenderingContext2D(JSC::Structure*, JSDOMGlobalObject&, Ref<OffscreenCanvasRenderingContext2D>&&);

    void finishCreation(JSC::VM&);
};

class JSOffscreenCanvasRenderingContext2DOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, OffscreenCanvasRenderingContext2D*)
{
    static NeverDestroyed<JSOffscreenCanvasRenderingContext2DOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(OffscreenCanvasRenderingContext2D* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, OffscreenCanvasRenderingContext2D&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, OffscreenCanvasRenderingContext2D* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<OffscreenCanvasRenderingContext2D>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<OffscreenCanvasRenderingContext2D>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<OffscreenCanvasRenderingContext2D> {
    using WrapperClass = JSOffscreenCanvasRenderingContext2D;
    using ToWrappedReturnType = OffscreenCanvasRenderingContext2D*;
};

} // namespace WebCore
