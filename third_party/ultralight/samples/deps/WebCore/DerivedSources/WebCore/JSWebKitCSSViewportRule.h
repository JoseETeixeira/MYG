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

#if ENABLE(CSS_DEVICE_ADAPTATION)

#include "JSCSSRule.h"
#include "JSDOMWrapper.h"
#include "WebKitCSSViewportRule.h"

namespace WebCore {

class JSWebKitCSSViewportRule : public JSCSSRule {
public:
    using Base = JSCSSRule;
    using DOMWrapped = WebKitCSSViewportRule;
    static JSWebKitCSSViewportRule* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<WebKitCSSViewportRule>&& impl)
    {
        JSWebKitCSSViewportRule* ptr = new (NotNull, JSC::allocateCell<JSWebKitCSSViewportRule>(globalObject->vm().heap)) JSWebKitCSSViewportRule(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    WebKitCSSViewportRule& wrapped() const
    {
        return static_cast<WebKitCSSViewportRule&>(Base::wrapped());
    }
protected:
    JSWebKitCSSViewportRule(JSC::Structure*, JSDOMGlobalObject&, Ref<WebKitCSSViewportRule>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<WebKitCSSViewportRule> {
    using WrapperClass = JSWebKitCSSViewportRule;
    using ToWrappedReturnType = WebKitCSSViewportRule*;
};

} // namespace WebCore

#endif // ENABLE(CSS_DEVICE_ADAPTATION)
