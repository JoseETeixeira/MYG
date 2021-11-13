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
#include "JSSVGElement.h"
#include "SVGElement.h"
#include "SVGGraphicsElement.h"

namespace WebCore {

class JSSVGGraphicsElement : public JSSVGElement {
public:
    using Base = JSSVGElement;
    using DOMWrapped = SVGGraphicsElement;
    static JSSVGGraphicsElement* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<SVGGraphicsElement>&& impl)
    {
        JSSVGGraphicsElement* ptr = new (NotNull, JSC::allocateCell<JSSVGGraphicsElement>(globalObject->vm().heap)) JSSVGGraphicsElement(structure, *globalObject, WTFMove(impl));
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
    SVGGraphicsElement& wrapped() const
    {
        return static_cast<SVGGraphicsElement&>(Base::wrapped());
    }
protected:
    JSSVGGraphicsElement(JSC::Structure*, JSDOMGlobalObject&, Ref<SVGGraphicsElement>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<SVGGraphicsElement> {
    using WrapperClass = JSSVGGraphicsElement;
    using ToWrappedReturnType = SVGGraphicsElement*;
};

} // namespace WebCore
