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

#if ENABLE(VIDEO)

#include "HTMLAudioElement.h"
#include "JSDOMWrapper.h"
#include "JSHTMLMediaElement.h"
#include "JSNode.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSHTMLAudioElement : public JSHTMLMediaElement {
public:
    using Base = JSHTMLMediaElement;
    using DOMWrapped = HTMLAudioElement;
    static JSHTMLAudioElement* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<HTMLAudioElement>&& impl)
    {
        JSHTMLAudioElement* ptr = new (NotNull, JSC::allocateCell<JSHTMLAudioElement>(globalObject->vm().heap)) JSHTMLAudioElement(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::JSType(JSElementType), StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static JSC::JSValue getNamedConstructor(JSC::VM&, JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    HTMLAudioElement& wrapped() const
    {
        return static_cast<HTMLAudioElement&>(Base::wrapped());
    }
protected:
    JSHTMLAudioElement(JSC::Structure*, JSDOMGlobalObject&, Ref<HTMLAudioElement>&&);

    void finishCreation(JSC::VM&);
};

class JSHTMLAudioElementOwner : public JSNodeOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&, const char**);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, HTMLAudioElement*)
{
    static NeverDestroyed<JSHTMLAudioElementOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(HTMLAudioElement* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, HTMLAudioElement&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, HTMLAudioElement* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<HTMLAudioElement>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<HTMLAudioElement>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<HTMLAudioElement> {
    using WrapperClass = JSHTMLAudioElement;
    using ToWrappedReturnType = HTMLAudioElement*;
};

} // namespace WebCore

#endif // ENABLE(VIDEO)
