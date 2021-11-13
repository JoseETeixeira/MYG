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
#include "JSSVGPathSeg.h"
#include "SVGElement.h"
#include "SVGPathSegImpl.h"

namespace WebCore {

class JSSVGPathSegArcAbs : public JSSVGPathSeg {
public:
    using Base = JSSVGPathSeg;
    using DOMWrapped = SVGPathSegArcAbs;
    static JSSVGPathSegArcAbs* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<SVGPathSegArcAbs>&& impl)
    {
        JSSVGPathSegArcAbs* ptr = new (NotNull, JSC::allocateCell<JSSVGPathSegArcAbs>(globalObject->vm().heap)) JSSVGPathSegArcAbs(structure, *globalObject, WTFMove(impl));
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
    SVGPathSegArcAbs& wrapped() const
    {
        return static_cast<SVGPathSegArcAbs&>(Base::wrapped());
    }
protected:
    JSSVGPathSegArcAbs(JSC::Structure*, JSDOMGlobalObject&, Ref<SVGPathSegArcAbs>&&);

    void finishCreation(JSC::VM&);
};


template<> struct JSDOMWrapperConverterTraits<SVGPathSegArcAbs> {
    using WrapperClass = JSSVGPathSegArcAbs;
    using ToWrappedReturnType = SVGPathSegArcAbs*;
};

} // namespace WebCore
