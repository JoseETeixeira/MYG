// Automatically generated from C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/runtime/SymbolConstructor.cpp using C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "Lookup.h"

namespace JSC {

static const struct CompactHashIndex symbolConstructorTableIndex[4] = {
    { 0, -1 },
    { -1, -1 },
    { -1, -1 },
    { 1, -1 },
};

static const struct HashTableValue symbolConstructorTableValues[2] = {
   { "for", static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(symbolConstructorFor), (intptr_t)(1) } },
   { "keyFor", static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(symbolConstructorKeyFor), (intptr_t)(1) } },
};

static const struct HashTable symbolConstructorTable =
    { 2, 3, false, nullptr, symbolConstructorTableValues, symbolConstructorTableIndex };

} // namespace JSC
