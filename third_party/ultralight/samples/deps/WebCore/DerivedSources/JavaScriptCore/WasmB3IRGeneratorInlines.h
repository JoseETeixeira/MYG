/*
 * Copyright (C) 2016-2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// DO NO EDIT! - This file was generated by C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/wasm/generateWasmB3IRGeneratorInlinesHeader.py

#pragma once

#if ENABLE(WEBASSEMBLY)

namespace JSC { namespace Wasm {


template<> auto B3IRGenerator::addOp<OpType::F32Ceil>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Ceil, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64ShrS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp3 = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg1);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::SShr, origin(), arg0, temp3);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Mul>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Mul, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Sub>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sub, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Le>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32DemoteF64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::DoubleToFloat, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Ne>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::NotEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Lt>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Max>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);    
Value* temp7 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), arg0, arg1);    
Value* temp14 = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);    
Value* temp22 = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);    
Value* temp28 = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);    
Value* temp20 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp22, arg0, temp28);    
Value* temp12 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp14, arg1, temp20);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp2, temp7, temp12);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Mul>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Mul, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Div>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Div, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Clz>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Clz, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Copysign>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp6 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg1);    
Value* temp12 = constant(Int32, 0x80000000);    
Value* temp4 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), temp6, temp12);    
Value* temp17 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);    
Value* temp23 = constant(Int32, 0x7fffffff);    
Value* temp15 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), temp17, temp23);    
Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), temp4, temp15);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), temp2);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64ConvertUI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::ZExt32, origin(), arg0);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::IToD, origin(), temp2);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32ReinterpretI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64And>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Ne>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::NotEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Gt>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Sqrt>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sqrt, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Ge>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64GtS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64GtU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Above, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Eqz>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    Value* temp4 = constant(Int64, 0);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), temp4, arg0);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Div>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Div, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Add>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Or>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32LeU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BelowEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32LeS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Ne>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::NotEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Clz>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Clz, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Neg>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Neg, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32And>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32LtU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Below, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Rotr>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp3 = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg1);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::RotR, origin(), arg0, temp3);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Abs>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Abs, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32LtS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Eq>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Copysign>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp6 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg1);    
Value* temp12 = constant(Int64, 0x8000000000000000);    
Value* temp4 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), temp6, temp12);    
Value* temp17 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);    
Value* temp23 = constant(Int64, 0x7fffffffffffffff);    
Value* temp15 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), temp17, temp23);    
Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), temp4, temp15);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), temp2);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32ConvertSI64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::IToF, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Rotl>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp3 = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg1);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::RotL, origin(), arg0, temp3);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Lt>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64ConvertSI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::IToD, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Eq>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Le>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Ge>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32ShrU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::ZShr, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32ConvertUI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::ZExt32, origin(), arg0);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::IToF, origin(), temp2);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32ShrS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::SShr, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32GeU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::AboveEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Ceil>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Ceil, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32GeS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Shl>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Shl, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Floor>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Floor, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Xor>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitXor, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Abs>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Abs, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Min>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);    
Value* temp7 = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), arg0, arg1);    
Value* temp14 = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);    
Value* temp22 = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);    
Value* temp28 = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);    
Value* temp20 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp22, arg1, temp28);    
Value* temp12 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp14, arg0, temp20);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp2, temp7, temp12);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Mul>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Mul, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Sub>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sub, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32ReinterpretF32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Add>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Sub>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sub, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Or>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64LtU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Below, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64LtS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64ConvertSI64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::IToD, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Xor>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitXor, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64GeU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::AboveEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Min>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);    
Value* temp7 = m_currentBlock->appendNew<Value>(m_proc, B3::BitOr, origin(), arg0, arg1);    
Value* temp14 = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);    
Value* temp22 = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);    
Value* temp28 = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);    
Value* temp20 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp22, arg1, temp28);    
Value* temp12 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp14, arg0, temp20);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp2, temp7, temp12);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Mul>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Mul, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Sub>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sub, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64PromoteF32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::FloatToDouble, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Add>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64GeS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64ExtendUI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::ZExt32, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Ne>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::NotEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64ReinterpretI64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Eq>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Eq>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Floor>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Floor, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32ConvertSI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::IToF, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Eqz>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    Value* temp4 = constant(Int32, 0);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), temp4, arg0);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64ReinterpretF64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BitwiseCast, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64ShrU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp3 = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg1);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::ZShr, origin(), arg0, temp3);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Sqrt>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Sqrt, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Shl>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp3 = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg1);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Shl, origin(), arg0, temp3);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F32Gt>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32WrapI64>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Trunc, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Rotl>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::RotL, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32Rotr>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::RotR, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32GtU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Above, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64ExtendSI32>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::SExt32, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I32GtS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Neg>(ExpressionType arg0, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Neg, origin(), arg0);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::F64Max>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    Value* temp2 = m_currentBlock->appendNew<Value>(m_proc, B3::Equal, origin(), arg0, arg1);    
Value* temp7 = m_currentBlock->appendNew<Value>(m_proc, B3::BitAnd, origin(), arg0, arg1);    
Value* temp14 = m_currentBlock->appendNew<Value>(m_proc, B3::LessThan, origin(), arg0, arg1);    
Value* temp22 = m_currentBlock->appendNew<Value>(m_proc, B3::GreaterThan, origin(), arg0, arg1);    
Value* temp28 = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);    
Value* temp20 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp22, arg0, temp28);    
Value* temp12 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp14, arg1, temp20);    
Value* temp0 = m_currentBlock->appendNew<Value>(m_proc, B3::Select, origin(), temp2, temp7, temp12);    
result = temp0;
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64LeU>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::BelowEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64LeS>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::LessEqual, origin(), arg0, arg1);
    return { };
}

template<> auto B3IRGenerator::addOp<OpType::I64Add>(ExpressionType arg0, ExpressionType arg1, ExpressionType& result) -> PartialResult
{
    result = m_currentBlock->appendNew<Value>(m_proc, B3::Add, origin(), arg0, arg1);
    return { };
}


} } // namespace JSC::Wasm

#endif // ENABLE(WEBASSEMBLY)

