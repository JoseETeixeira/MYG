// Automatically generated from C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/runtime/ErrorPrototype.cpp using C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "Lookup.h"

namespace JSC {

static const struct CompactHashIndex errorPrototypeTableIndex[2] = {
    { 0, -1 },
    { -1, -1 },
};

static const struct HashTableValue errorPrototypeTableValues[1] = {
   { "toString", static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(errorProtoFuncToString), (intptr_t)(0) } },
};

static const struct HashTable errorPrototypeTable =
    { 1, 1, false, nullptr, errorPrototypeTableValues, errorPrototypeTableIndex };

} // namespace JSC
