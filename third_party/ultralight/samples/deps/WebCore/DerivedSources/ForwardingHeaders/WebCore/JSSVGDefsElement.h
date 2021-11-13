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
#include "JSSVGGraphicsElement.h"
#include "SVGDefsElement.h"
#include "SVGElement.h"

namespace WebCore {

class JSSVGDefsElement : public JSSVGGraphicsElement {
public:
    using Base = JSSVGGraphicsElement;
    using DOMWrapped = SVGDefsElement;
    static JSSVGDefsElement* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<SVGDefsElement>&& impl)
    {
        JSSVGDefsElement* ptr = new (NotNull, JSC::allocateCell<JSSVGDefsElement>(globalObject->vm().heap)) JSSVGDefsElement(structure, *globalObject, WTFMove(impl));
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
    SVGDefsElement& wrapped() const
    {
        return static_cast<SVGDefsElement&>(Base::wrapped());
    }
protected:
    JSSVGDefsElement(JSC::Structure*, JSDOMGlobalObject&, Ref<SVGDefsElement>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<SVGDefsElement> {
    using WrapperClass = JSSVGDefsElement;
    using ToWrappedReturnType = SVGDefsElement*;
};

} // namespace WebCore
