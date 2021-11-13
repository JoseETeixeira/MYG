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

#include "HTMLAnchorElement.h"
#include "JSDOMWrapper.h"
#include "JSHTMLElement.h"

namespace WebCore {

class JSHTMLAnchorElement : public JSHTMLElement {
public:
    using Base = JSHTMLElement;
    using DOMWrapped = HTMLAnchorElement;
    static JSHTMLAnchorElement* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<HTMLAnchorElement>&& impl)
    {
        JSHTMLAnchorElement* ptr = new (NotNull, JSC::allocateCell<JSHTMLAnchorElement>(globalObject->vm().heap)) JSHTMLAnchorElement(structure, *globalObject, WTFMove(impl));
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
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    HTMLAnchorElement& wrapped() const
    {
        return static_cast<HTMLAnchorElement&>(Base::wrapped());
    }
protected:
    JSHTMLAnchorElement(JSC::Structure*, JSDOMGlobalObject&, Ref<HTMLAnchorElement>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<HTMLAnchorElement> {
    using WrapperClass = JSHTMLAnchorElement;
    using ToWrappedReturnType = HTMLAnchorElement*;
};

} // namespace WebCore
