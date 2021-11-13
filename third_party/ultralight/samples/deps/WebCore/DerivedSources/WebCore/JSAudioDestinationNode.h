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

#if ENABLE(WEB_AUDIO)

#include "AudioDestinationNode.h"
#include "JSAudioNode.h"
#include "JSDOMWrapper.h"

namespace WebCore {

class JSAudioDestinationNode : public JSAudioNode {
public:
    using Base = JSAudioNode;
    using DOMWrapped = AudioDestinationNode;
    static JSAudioDestinationNode* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<AudioDestinationNode>&& impl)
    {
        JSAudioDestinationNode* ptr = new (NotNull, JSC::allocateCell<JSAudioDestinationNode>(globalObject->vm().heap)) JSAudioDestinationNode(structure, *globalObject, WTFMove(impl));
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
    AudioDestinationNode& wrapped() const
    {
        return static_cast<AudioDestinationNode&>(Base::wrapped());
    }
protected:
    JSAudioDestinationNode(JSC::Structure*, JSDOMGlobalObject&, Ref<AudioDestinationNode>&&);

    void finishCreation(JSC::VM&);
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, AudioDestinationNode&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, AudioDestinationNode* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<AudioDestinationNode>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<AudioDestinationNode>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<AudioDestinationNode> {
    using WrapperClass = JSAudioDestinationNode;
    using ToWrappedReturnType = AudioDestinationNode*;
};

} // namespace WebCore

#endif // ENABLE(WEB_AUDIO)
