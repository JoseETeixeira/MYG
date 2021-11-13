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

#if ENABLE(MEDIA_STREAM)

#include "JSDOMConvertEnumeration.h"
#include "JSDOMWrapper.h"
#include "MediaDeviceInfo.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSMediaDeviceInfo : public JSDOMWrapper<MediaDeviceInfo> {
public:
    using Base = JSDOMWrapper<MediaDeviceInfo>;
    static JSMediaDeviceInfo* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<MediaDeviceInfo>&& impl)
    {
        JSMediaDeviceInfo* ptr = new (NotNull, JSC::allocateCell<JSMediaDeviceInfo>(globalObject->vm().heap)) JSMediaDeviceInfo(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static MediaDeviceInfo* toWrapped(JSC::VM&, JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static JSC::JSObject* serialize(JSC::ExecState&, JSMediaDeviceInfo& thisObject, JSDOMGlobalObject&, JSC::ThrowScope&);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
protected:
    JSMediaDeviceInfo(JSC::Structure*, JSDOMGlobalObject&, Ref<MediaDeviceInfo>&&);

    void finishCreation(JSC::VM&);
};

class JSMediaDeviceInfoOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, MediaDeviceInfo*)
{
    static NeverDestroyed<JSMediaDeviceInfoOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(MediaDeviceInfo* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, MediaDeviceInfo&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, MediaDeviceInfo* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<MediaDeviceInfo>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<MediaDeviceInfo>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<MediaDeviceInfo> {
    using WrapperClass = JSMediaDeviceInfo;
    using ToWrappedReturnType = MediaDeviceInfo*;
};
String convertEnumerationToString(MediaDeviceInfo::Kind);
template<> JSC::JSString* convertEnumerationToJS(JSC::ExecState&, MediaDeviceInfo::Kind);

template<> Optional<MediaDeviceInfo::Kind> parseEnumeration<MediaDeviceInfo::Kind>(JSC::ExecState&, JSC::JSValue);
template<> const char* expectedEnumerationValues<MediaDeviceInfo::Kind>();


} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM)
