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
#include "SVGAnimatedPropertyImpl.h"
#include "SVGElement.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSSVGAnimatedEnumeration : public JSDOMWrapper<SVGAnimatedEnumeration> {
public:
    using Base = JSDOMWrapper<SVGAnimatedEnumeration>;
    static JSSVGAnimatedEnumeration* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<SVGAnimatedEnumeration>&& impl)
    {
        JSSVGAnimatedEnumeration* ptr = new (NotNull, JSC::allocateCell<JSSVGAnimatedEnumeration>(globalObject->vm().heap)) JSSVGAnimatedEnumeration(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static SVGAnimatedEnumeration* toWrapped(JSC::VM&, JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
protected:
    JSSVGAnimatedEnumeration(JSC::Structure*, JSDOMGlobalObject&, Ref<SVGAnimatedEnumeration>&&);

    void finishCreation(JSC::VM&);
};

class JSSVGAnimatedEnumerationOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, SVGAnimatedEnumeration*)
{
    static NeverDestroyed<JSSVGAnimatedEnumerationOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(SVGAnimatedEnumeration* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, SVGAnimatedEnumeration&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, SVGAnimatedEnumeration* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<SVGAnimatedEnumeration>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<SVGAnimatedEnumeration>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<SVGAnimatedEnumeration> {
    using WrapperClass = JSSVGAnimatedEnumeration;
    using ToWrappedReturnType = SVGAnimatedEnumeration*;
};

} // namespace WebCore
