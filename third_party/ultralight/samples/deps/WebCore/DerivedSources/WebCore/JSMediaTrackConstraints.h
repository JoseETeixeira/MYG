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

#include "JSDOMConvertDictionary.h"
#include "MediaTrackConstraints.h"

namespace WebCore {

template<> MediaTrackConstraints convertDictionary<MediaTrackConstraints>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const MediaTrackConstraints&);

#if ENABLE(MEDIA_STREAM)

template<> MediaTrackConstraintSet convertDictionary<MediaTrackConstraintSet>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const MediaTrackConstraintSet&);

#endif

#if ENABLE(MEDIA_STREAM)

template<> ConstrainBooleanParameters convertDictionary<ConstrainBooleanParameters>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const ConstrainBooleanParameters&);

#endif

#if ENABLE(MEDIA_STREAM)

template<> ConstrainDOMStringParameters convertDictionary<ConstrainDOMStringParameters>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const ConstrainDOMStringParameters&);

#endif

#if ENABLE(MEDIA_STREAM)

template<> ConstrainDoubleRange convertDictionary<ConstrainDoubleRange>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const ConstrainDoubleRange&);

#endif

#if ENABLE(MEDIA_STREAM)

template<> ConstrainLongRange convertDictionary<ConstrainLongRange>(JSC::ExecState&, JSC::JSValue);

JSC::JSObject* convertDictionaryToJS(JSC::ExecState&, JSDOMGlobalObject&, const ConstrainLongRange&);

#endif

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM)
