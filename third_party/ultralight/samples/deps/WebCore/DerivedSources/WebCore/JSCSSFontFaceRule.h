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

#include "CSSFontFaceRule.h"
#include "JSCSSRule.h"
#include "JSDOMWrapper.h"

namespace WebCore {

class JSCSSFontFaceRule : public JSCSSRule {
public:
    using Base = JSCSSRule;
    using DOMWrapped = CSSFontFaceRule;
    static JSCSSFontFaceRule* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<CSSFontFaceRule>&& impl)
    {
        JSCSSFontFaceRule* ptr = new (NotNull, JSC::allocateCell<JSCSSFontFaceRule>(globalObject->vm().heap)) JSCSSFontFaceRule(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static CSSFontFaceRule* toWrapped(JSC::VM&, JSC::JSValue);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    CSSFontFaceRule& wrapped() const
    {
        return static_cast<CSSFontFaceRule&>(Base::wrapped());
    }
protected:
    JSCSSFontFaceRule(JSC::Structure*, JSDOMGlobalObject&, Ref<CSSFontFaceRule>&&);

    void finishCreation(JSC::VM&);
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, CSSFontFaceRule&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, CSSFontFaceRule* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<CSSFontFaceRule>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<CSSFontFaceRule>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<CSSFontFaceRule> {
    using WrapperClass = JSCSSFontFaceRule;
    using ToWrappedReturnType = CSSFontFaceRule*;
};

} // namespace WebCore
