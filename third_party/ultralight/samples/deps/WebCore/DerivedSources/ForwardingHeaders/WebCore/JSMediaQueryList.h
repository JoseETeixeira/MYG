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
#include "MediaQueryList.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSMediaQueryList : public JSDOMWrapper<MediaQueryList> {
public:
    using Base = JSDOMWrapper<MediaQueryList>;
    static JSMediaQueryList* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<MediaQueryList>&& impl)
    {
        JSMediaQueryList* ptr = new (NotNull, JSC::allocateCell<JSMediaQueryList>(globalObject->vm().heap)) JSMediaQueryList(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static MediaQueryList* toWrapped(JSC::VM&, JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
protected:
    JSMediaQueryList(JSC::Structure*, JSDOMGlobalObject&, Ref<MediaQueryList>&&);

    void finishCreation(JSC::VM&);
};

class JSMediaQueryListOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, MediaQueryList*)
{
    static NeverDestroyed<JSMediaQueryListOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(MediaQueryList* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, MediaQueryList&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, MediaQueryList* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<MediaQueryList>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<MediaQueryList>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<MediaQueryList> {
    using WrapperClass = JSMediaQueryList;
    using ToWrappedReturnType = MediaQueryList*;
};

} // namespace WebCore
