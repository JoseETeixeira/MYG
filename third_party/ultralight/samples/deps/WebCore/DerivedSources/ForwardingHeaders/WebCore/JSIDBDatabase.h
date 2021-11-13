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

#if ENABLE(INDEXED_DATABASE)

#include "IDBDatabase.h"
#include "JSDOMConvertDictionary.h"
#include "JSDOMWrapper.h"
#include "JSEventTarget.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSIDBDatabase : public JSEventTarget {
public:
    using Base = JSEventTarget;
    using DOMWrapped = IDBDatabase;
    static JSIDBDatabase* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<IDBDatabase>&& impl)
    {
        JSIDBDatabase* ptr = new (NotNull, JSC::allocateCell<JSIDBDatabase>(globalObject->vm().heap)) JSIDBDatabase(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static IDBDatabase* toWrapped(JSC::VM&, JSC::JSValue);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    IDBDatabase& wrapped() const
    {
        return static_cast<IDBDatabase&>(Base::wrapped());
    }
protected:
    JSIDBDatabase(JSC::Structure*, JSDOMGlobalObject&, Ref<IDBDatabase>&&);

    void finishCreation(JSC::VM&);
};

class JSIDBDatabaseOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, IDBDatabase*)
{
    static NeverDestroyed<JSIDBDatabaseOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(IDBDatabase* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, IDBDatabase&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, IDBDatabase* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<IDBDatabase>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<IDBDatabase>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<IDBDatabase> {
    using WrapperClass = JSIDBDatabase;
    using ToWrappedReturnType = IDBDatabase*;
};
template<> IDBDatabase::ObjectStoreParameters convertDictionary<IDBDatabase::ObjectStoreParameters>(JSC::ExecState&, JSC::JSValue);


} // namespace WebCore

#endif // ENABLE(INDEXED_DATABASE)
