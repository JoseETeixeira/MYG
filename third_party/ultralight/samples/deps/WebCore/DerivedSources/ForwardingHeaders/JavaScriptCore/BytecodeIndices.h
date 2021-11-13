//  SHA1Hash: da39a3ee5e6b4b0d3255bfef95601890afd80709
/*
 * Copyright (C) 2021 Apple Inc. All rights reserved.
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

 * Autogenerated from C:/Users/admin/dev/Jenkins/workspace/WebCore_master/Source/JavaScriptCore/bytecode/BytecodeList.rb, do not modify.
*/

namespace JSC {

const unsigned OpTailCallVarargs_m_dst_index = 1;
const unsigned OpTailCallVarargs_m_callee_index = 2;
const unsigned OpTailCallVarargs_m_thisValue_index = 3;
const unsigned OpTailCallVarargs_m_arguments_index = 4;
const unsigned OpTailCallVarargs_m_firstFree_index = 5;
const unsigned OpTailCallVarargs_m_firstVarArg_index = 6;
const unsigned OpTailCallVarargs_m_metadataID_index = 7;
const unsigned OpGetDirectPname_m_dst_index = 1;
const unsigned OpGetDirectPname_m_base_index = 2;
const unsigned OpGetDirectPname_m_property_index = 3;
const unsigned OpGetDirectPname_m_index_index = 4;
const unsigned OpGetDirectPname_m_enumerator_index = 5;
const unsigned OpGetDirectPname_m_metadataID_index = 6;
const unsigned OpHasIndexedProperty_m_dst_index = 1;
const unsigned OpHasIndexedProperty_m_base_index = 2;
const unsigned OpHasIndexedProperty_m_property_index = 3;
const unsigned OpHasIndexedProperty_m_metadataID_index = 4;
const unsigned OpProfileControlFlow_m_textOffset_index = 1;
const unsigned OpProfileControlFlow_m_metadataID_index = 2;
const unsigned OpProfileType_m_targetVirtualRegister_index = 1;
const unsigned OpProfileType_m_symbolTableOrScopeDepth_index = 2;
const unsigned OpProfileType_m_flag_index = 3;
const unsigned OpProfileType_m_identifier_index = 4;
const unsigned OpProfileType_m_resolveType_index = 5;
const unsigned OpProfileType_m_metadataID_index = 6;
const unsigned OpCatch_m_exception_index = 1;
const unsigned OpCatch_m_thrownValue_index = 2;
const unsigned OpCatch_m_metadataID_index = 3;
const unsigned OpGetFromArguments_m_dst_index = 1;
const unsigned OpGetFromArguments_m_arguments_index = 2;
const unsigned OpGetFromArguments_m_index_index = 3;
const unsigned OpGetFromArguments_m_metadataID_index = 4;
const unsigned OpCreateThis_m_dst_index = 1;
const unsigned OpCreateThis_m_callee_index = 2;
const unsigned OpCreateThis_m_inlineCapacity_index = 3;
const unsigned OpCreateThis_m_metadataID_index = 4;
const unsigned OpGetArgument_m_dst_index = 1;
const unsigned OpGetArgument_m_index_index = 2;
const unsigned OpGetArgument_m_metadataID_index = 3;
const unsigned OpPutToScope_m_scope_index = 1;
const unsigned OpPutToScope_m_var_index = 2;
const unsigned OpPutToScope_m_value_index = 3;
const unsigned OpPutToScope_m_getPutInfo_index = 4;
const unsigned OpPutToScope_m_symbolTableOrScopeDepth_index = 5;
const unsigned OpPutToScope_m_offset_index = 6;
const unsigned OpPutToScope_m_metadataID_index = 7;
const unsigned OpToThis_m_srcDst_index = 1;
const unsigned OpToThis_m_metadataID_index = 2;
const unsigned OpGetFromScope_m_dst_index = 1;
const unsigned OpGetFromScope_m_scope_index = 2;
const unsigned OpGetFromScope_m_var_index = 3;
const unsigned OpGetFromScope_m_getPutInfo_index = 4;
const unsigned OpGetFromScope_m_localScopeDepth_index = 5;
const unsigned OpGetFromScope_m_offset_index = 6;
const unsigned OpGetFromScope_m_metadataID_index = 7;
const unsigned OpNewObject_m_dst_index = 1;
const unsigned OpNewObject_m_inlineCapacity_index = 2;
const unsigned OpNewObject_m_metadataID_index = 3;
const unsigned OpNewArray_m_dst_index = 1;
const unsigned OpNewArray_m_argv_index = 2;
const unsigned OpNewArray_m_argc_index = 3;
const unsigned OpNewArray_m_recommendedIndexingType_index = 4;
const unsigned OpNewArray_m_metadataID_index = 5;
const unsigned OpNewArrayWithSize_m_dst_index = 1;
const unsigned OpNewArrayWithSize_m_length_index = 2;
const unsigned OpNewArrayWithSize_m_metadataID_index = 3;
const unsigned OpNewArrayBuffer_m_dst_index = 1;
const unsigned OpNewArrayBuffer_m_immutableButterfly_index = 2;
const unsigned OpNewArrayBuffer_m_recommendedIndexingType_index = 3;
const unsigned OpNewArrayBuffer_m_metadataID_index = 4;
const unsigned OpResolveScope_m_dst_index = 1;
const unsigned OpResolveScope_m_scope_index = 2;
const unsigned OpResolveScope_m_var_index = 3;
const unsigned OpResolveScope_m_resolveType_index = 4;
const unsigned OpResolveScope_m_localScopeDepth_index = 5;
const unsigned OpResolveScope_m_metadataID_index = 6;
const unsigned OpConstructVarargs_m_dst_index = 1;
const unsigned OpConstructVarargs_m_callee_index = 2;
const unsigned OpConstructVarargs_m_thisValue_index = 3;
const unsigned OpConstructVarargs_m_arguments_index = 4;
const unsigned OpConstructVarargs_m_firstFree_index = 5;
const unsigned OpConstructVarargs_m_firstVarArg_index = 6;
const unsigned OpConstructVarargs_m_metadataID_index = 7;
const unsigned OpConstruct_m_dst_index = 1;
const unsigned OpConstruct_m_callee_index = 2;
const unsigned OpConstruct_m_argc_index = 3;
const unsigned OpConstruct_m_argv_index = 4;
const unsigned OpConstruct_m_metadataID_index = 5;
const unsigned OpTailCallForwardArguments_m_dst_index = 1;
const unsigned OpTailCallForwardArguments_m_callee_index = 2;
const unsigned OpTailCallForwardArguments_m_thisValue_index = 3;
const unsigned OpTailCallForwardArguments_m_arguments_index = 4;
const unsigned OpTailCallForwardArguments_m_firstFree_index = 5;
const unsigned OpTailCallForwardArguments_m_firstVarArg_index = 6;
const unsigned OpTailCallForwardArguments_m_metadataID_index = 7;
const unsigned OpCallVarargs_m_dst_index = 1;
const unsigned OpCallVarargs_m_callee_index = 2;
const unsigned OpCallVarargs_m_thisValue_index = 3;
const unsigned OpCallVarargs_m_arguments_index = 4;
const unsigned OpCallVarargs_m_firstFree_index = 5;
const unsigned OpCallVarargs_m_firstVarArg_index = 6;
const unsigned OpCallVarargs_m_metadataID_index = 7;
const unsigned OpCallEval_m_dst_index = 1;
const unsigned OpCallEval_m_callee_index = 2;
const unsigned OpCallEval_m_argc_index = 3;
const unsigned OpCallEval_m_argv_index = 4;
const unsigned OpCallEval_m_metadataID_index = 5;
const unsigned OpTailCall_m_dst_index = 1;
const unsigned OpTailCall_m_callee_index = 2;
const unsigned OpTailCall_m_argc_index = 3;
const unsigned OpTailCall_m_argv_index = 4;
const unsigned OpTailCall_m_metadataID_index = 5;
const unsigned OpCall_m_dst_index = 1;
const unsigned OpCall_m_callee_index = 2;
const unsigned OpCall_m_argc_index = 3;
const unsigned OpCall_m_argv_index = 4;
const unsigned OpCall_m_metadataID_index = 5;
const unsigned OpJneqPtr_m_value_index = 1;
const unsigned OpJneqPtr_m_specialPointer_index = 2;
const unsigned OpJneqPtr_m_targetLabel_index = 3;
const unsigned OpJneqPtr_m_metadataID_index = 4;
const unsigned OpPutByValDirect_m_base_index = 1;
const unsigned OpPutByValDirect_m_property_index = 2;
const unsigned OpPutByValDirect_m_value_index = 3;
const unsigned OpPutByValDirect_m_metadataID_index = 4;
const unsigned OpPutByVal_m_base_index = 1;
const unsigned OpPutByVal_m_property_index = 2;
const unsigned OpPutByVal_m_value_index = 3;
const unsigned OpPutByVal_m_metadataID_index = 4;
const unsigned OpGetByVal_m_dst_index = 1;
const unsigned OpGetByVal_m_base_index = 2;
const unsigned OpGetByVal_m_property_index = 3;
const unsigned OpGetByVal_m_metadataID_index = 4;
const unsigned OpPutById_m_base_index = 1;
const unsigned OpPutById_m_property_index = 2;
const unsigned OpPutById_m_value_index = 3;
const unsigned OpPutById_m_flags_index = 4;
const unsigned OpPutById_m_metadataID_index = 5;
const unsigned OpTryGetById_m_dst_index = 1;
const unsigned OpTryGetById_m_base_index = 2;
const unsigned OpTryGetById_m_property_index = 3;
const unsigned OpTryGetById_m_metadataID_index = 4;
const unsigned OpGetByIdDirect_m_dst_index = 1;
const unsigned OpGetByIdDirect_m_base_index = 2;
const unsigned OpGetByIdDirect_m_property_index = 3;
const unsigned OpGetByIdDirect_m_metadataID_index = 4;
const unsigned OpGetByValWithThis_m_dst_index = 1;
const unsigned OpGetByValWithThis_m_base_index = 2;
const unsigned OpGetByValWithThis_m_thisValue_index = 3;
const unsigned OpGetByValWithThis_m_property_index = 4;
const unsigned OpGetByValWithThis_m_metadataID_index = 5;
const unsigned OpGetByIdWithThis_m_dst_index = 1;
const unsigned OpGetByIdWithThis_m_base_index = 2;
const unsigned OpGetByIdWithThis_m_thisValue_index = 3;
const unsigned OpGetByIdWithThis_m_property_index = 4;
const unsigned OpGetByIdWithThis_m_metadataID_index = 5;
const unsigned OpGetById_m_dst_index = 1;
const unsigned OpGetById_m_base_index = 2;
const unsigned OpGetById_m_property_index = 3;
const unsigned OpGetById_m_metadataID_index = 4;
const unsigned OpAdd_m_dst_index = 1;
const unsigned OpAdd_m_lhs_index = 2;
const unsigned OpAdd_m_rhs_index = 3;
const unsigned OpAdd_m_operandTypes_index = 4;
const unsigned OpAdd_m_metadataID_index = 5;
const unsigned OpMul_m_dst_index = 1;
const unsigned OpMul_m_lhs_index = 2;
const unsigned OpMul_m_rhs_index = 3;
const unsigned OpMul_m_operandTypes_index = 4;
const unsigned OpMul_m_metadataID_index = 5;
const unsigned OpDiv_m_dst_index = 1;
const unsigned OpDiv_m_lhs_index = 2;
const unsigned OpDiv_m_rhs_index = 3;
const unsigned OpDiv_m_operandTypes_index = 4;
const unsigned OpDiv_m_metadataID_index = 5;
const unsigned OpSub_m_dst_index = 1;
const unsigned OpSub_m_lhs_index = 2;
const unsigned OpSub_m_rhs_index = 3;
const unsigned OpSub_m_operandTypes_index = 4;
const unsigned OpSub_m_metadataID_index = 5;
const unsigned OpBitand_m_dst_index = 1;
const unsigned OpBitand_m_lhs_index = 2;
const unsigned OpBitand_m_rhs_index = 3;
const unsigned OpBitand_m_metadataID_index = 4;
const unsigned OpBitor_m_dst_index = 1;
const unsigned OpBitor_m_lhs_index = 2;
const unsigned OpBitor_m_rhs_index = 3;
const unsigned OpBitor_m_metadataID_index = 4;
const unsigned OpBitxor_m_dst_index = 1;
const unsigned OpBitxor_m_lhs_index = 2;
const unsigned OpBitxor_m_rhs_index = 3;
const unsigned OpBitxor_m_metadataID_index = 4;
const unsigned OpLshift_m_dst_index = 1;
const unsigned OpLshift_m_lhs_index = 2;
const unsigned OpLshift_m_rhs_index = 3;
const unsigned OpLshift_m_metadataID_index = 4;
const unsigned OpBitnot_m_dst_index = 1;
const unsigned OpBitnot_m_operand_index = 2;
const unsigned OpBitnot_m_metadataID_index = 3;
const unsigned OpInByVal_m_dst_index = 1;
const unsigned OpInByVal_m_base_index = 2;
const unsigned OpInByVal_m_property_index = 3;
const unsigned OpInByVal_m_metadataID_index = 4;
const unsigned OpNegate_m_dst_index = 1;
const unsigned OpNegate_m_operand_index = 2;
const unsigned OpNegate_m_operandTypes_index = 3;
const unsigned OpNegate_m_metadataID_index = 4;
const unsigned OpToNumber_m_dst_index = 1;
const unsigned OpToNumber_m_operand_index = 2;
const unsigned OpToNumber_m_metadataID_index = 3;
const unsigned OpToObject_m_dst_index = 1;
const unsigned OpToObject_m_operand_index = 2;
const unsigned OpToObject_m_message_index = 3;
const unsigned OpToObject_m_metadataID_index = 4;

const unsigned OpIsUndefined_m_dst_index = 1;
const unsigned OpIsUndefined_m_operand_index = 2;
const unsigned OpIsUndefinedOrNull_m_dst_index = 1;
const unsigned OpIsUndefinedOrNull_m_operand_index = 2;
const unsigned OpIsBoolean_m_dst_index = 1;
const unsigned OpIsBoolean_m_operand_index = 2;
const unsigned OpIsNumber_m_dst_index = 1;
const unsigned OpIsNumber_m_operand_index = 2;
const unsigned OpIsObject_m_dst_index = 1;
const unsigned OpIsObject_m_operand_index = 2;
const unsigned OpIsObjectOrNull_m_dst_index = 1;
const unsigned OpIsObjectOrNull_m_operand_index = 2;
const unsigned OpIsFunction_m_dst_index = 1;
const unsigned OpIsFunction_m_operand_index = 2;
const unsigned OpInc_m_srcDst_index = 1;
const unsigned OpDec_m_srcDst_index = 1;
const unsigned OpUnsigned_m_dst_index = 1;
const unsigned OpUnsigned_m_operand_index = 2;
const unsigned OpToString_m_dst_index = 1;
const unsigned OpToString_m_operand_index = 2;
const unsigned OpNeqNull_m_dst_index = 1;
const unsigned OpNeqNull_m_operand_index = 2;
const unsigned OpNot_m_dst_index = 1;
const unsigned OpNot_m_operand_index = 2;
const unsigned OpIdentityWithProfile_m_srcDst_index = 1;
const unsigned OpIdentityWithProfile_m_topProfile_index = 2;
const unsigned OpIdentityWithProfile_m_bottomProfile_index = 3;
const unsigned OpOverridesHasInstance_m_dst_index = 1;
const unsigned OpOverridesHasInstance_m_constructor_index = 2;
const unsigned OpOverridesHasInstance_m_hasInstanceValue_index = 3;
const unsigned OpInstanceof_m_dst_index = 1;
const unsigned OpInstanceof_m_value_index = 2;
const unsigned OpInstanceof_m_prototype_index = 3;
const unsigned OpInstanceofCustom_m_dst_index = 1;
const unsigned OpInstanceofCustom_m_value_index = 2;
const unsigned OpInstanceofCustom_m_constructor_index = 3;
const unsigned OpInstanceofCustom_m_hasInstanceValue_index = 4;
const unsigned OpTypeof_m_dst_index = 1;
const unsigned OpTypeof_m_value_index = 2;
const unsigned OpIsCellWithType_m_dst_index = 1;
const unsigned OpIsCellWithType_m_operand_index = 2;
const unsigned OpIsCellWithType_m_type_index = 3;
const unsigned OpEqNull_m_dst_index = 1;
const unsigned OpEqNull_m_operand_index = 2;
const unsigned OpInById_m_dst_index = 1;
const unsigned OpInById_m_base_index = 2;
const unsigned OpInById_m_property_index = 3;
const unsigned OpUrshift_m_dst_index = 1;
const unsigned OpUrshift_m_lhs_index = 2;
const unsigned OpUrshift_m_rhs_index = 3;
const unsigned OpRshift_m_dst_index = 1;
const unsigned OpRshift_m_lhs_index = 2;
const unsigned OpRshift_m_rhs_index = 3;
const unsigned OpPow_m_dst_index = 1;
const unsigned OpPow_m_lhs_index = 2;
const unsigned OpPow_m_rhs_index = 3;
const unsigned OpMod_m_dst_index = 1;
const unsigned OpMod_m_lhs_index = 2;
const unsigned OpMod_m_rhs_index = 3;
const unsigned OpBeloweq_m_dst_index = 1;
const unsigned OpBeloweq_m_lhs_index = 2;
const unsigned OpBeloweq_m_rhs_index = 3;
const unsigned OpBelow_m_dst_index = 1;
const unsigned OpBelow_m_lhs_index = 2;
const unsigned OpBelow_m_rhs_index = 3;
const unsigned OpPutByIdWithThis_m_base_index = 1;
const unsigned OpPutByIdWithThis_m_thisValue_index = 2;
const unsigned OpPutByIdWithThis_m_property_index = 3;
const unsigned OpPutByIdWithThis_m_value_index = 4;
const unsigned OpDelById_m_dst_index = 1;
const unsigned OpDelById_m_base_index = 2;
const unsigned OpDelById_m_property_index = 3;
const unsigned OpGreatereq_m_dst_index = 1;
const unsigned OpGreatereq_m_lhs_index = 2;
const unsigned OpGreatereq_m_rhs_index = 3;
const unsigned OpGreater_m_dst_index = 1;
const unsigned OpGreater_m_lhs_index = 2;
const unsigned OpGreater_m_rhs_index = 3;
const unsigned OpPutByValWithThis_m_base_index = 1;
const unsigned OpPutByValWithThis_m_thisValue_index = 2;
const unsigned OpPutByValWithThis_m_property_index = 3;
const unsigned OpPutByValWithThis_m_value_index = 4;
const unsigned OpLesseq_m_dst_index = 1;
const unsigned OpLesseq_m_lhs_index = 2;
const unsigned OpLesseq_m_rhs_index = 3;
const unsigned OpDelByVal_m_dst_index = 1;
const unsigned OpDelByVal_m_base_index = 2;
const unsigned OpDelByVal_m_property_index = 3;
const unsigned OpPutGetterById_m_base_index = 1;
const unsigned OpPutGetterById_m_property_index = 2;
const unsigned OpPutGetterById_m_attributes_index = 3;
const unsigned OpPutGetterById_m_accessor_index = 4;
const unsigned OpPutSetterById_m_base_index = 1;
const unsigned OpPutSetterById_m_property_index = 2;
const unsigned OpPutSetterById_m_attributes_index = 3;
const unsigned OpPutSetterById_m_accessor_index = 4;
const unsigned OpPutGetterSetterById_m_base_index = 1;
const unsigned OpPutGetterSetterById_m_property_index = 2;
const unsigned OpPutGetterSetterById_m_attributes_index = 3;
const unsigned OpPutGetterSetterById_m_getter_index = 4;
const unsigned OpPutGetterSetterById_m_setter_index = 5;
const unsigned OpPutGetterByVal_m_base_index = 1;
const unsigned OpPutGetterByVal_m_property_index = 2;
const unsigned OpPutGetterByVal_m_attributes_index = 3;
const unsigned OpPutGetterByVal_m_accessor_index = 4;
const unsigned OpPutSetterByVal_m_base_index = 1;
const unsigned OpPutSetterByVal_m_property_index = 2;
const unsigned OpPutSetterByVal_m_attributes_index = 3;
const unsigned OpPutSetterByVal_m_accessor_index = 4;
const unsigned OpDefineDataProperty_m_base_index = 1;
const unsigned OpDefineDataProperty_m_property_index = 2;
const unsigned OpDefineDataProperty_m_value_index = 3;
const unsigned OpDefineDataProperty_m_attributes_index = 4;
const unsigned OpDefineAccessorProperty_m_base_index = 1;
const unsigned OpDefineAccessorProperty_m_property_index = 2;
const unsigned OpDefineAccessorProperty_m_getter_index = 3;
const unsigned OpDefineAccessorProperty_m_setter_index = 4;
const unsigned OpDefineAccessorProperty_m_attributes_index = 5;
const unsigned OpJmp_m_targetLabel_index = 1;
const unsigned OpJtrue_m_condition_index = 1;
const unsigned OpJtrue_m_targetLabel_index = 2;
const unsigned OpJfalse_m_condition_index = 1;
const unsigned OpJfalse_m_targetLabel_index = 2;
const unsigned OpJeqNull_m_value_index = 1;
const unsigned OpJeqNull_m_targetLabel_index = 2;
const unsigned OpJneqNull_m_value_index = 1;
const unsigned OpJneqNull_m_targetLabel_index = 2;
const unsigned OpLess_m_dst_index = 1;
const unsigned OpLess_m_lhs_index = 2;
const unsigned OpLess_m_rhs_index = 3;
const unsigned OpJeq_m_lhs_index = 1;
const unsigned OpJeq_m_rhs_index = 2;
const unsigned OpJeq_m_targetLabel_index = 3;
const unsigned OpJstricteq_m_lhs_index = 1;
const unsigned OpJstricteq_m_rhs_index = 2;
const unsigned OpJstricteq_m_targetLabel_index = 3;
const unsigned OpJneq_m_lhs_index = 1;
const unsigned OpJneq_m_rhs_index = 2;
const unsigned OpJneq_m_targetLabel_index = 3;
const unsigned OpJnstricteq_m_lhs_index = 1;
const unsigned OpJnstricteq_m_rhs_index = 2;
const unsigned OpJnstricteq_m_targetLabel_index = 3;
const unsigned OpJless_m_lhs_index = 1;
const unsigned OpJless_m_rhs_index = 2;
const unsigned OpJless_m_targetLabel_index = 3;
const unsigned OpJlesseq_m_lhs_index = 1;
const unsigned OpJlesseq_m_rhs_index = 2;
const unsigned OpJlesseq_m_targetLabel_index = 3;
const unsigned OpJgreater_m_lhs_index = 1;
const unsigned OpJgreater_m_rhs_index = 2;
const unsigned OpJgreater_m_targetLabel_index = 3;
const unsigned OpJgreatereq_m_lhs_index = 1;
const unsigned OpJgreatereq_m_rhs_index = 2;
const unsigned OpJgreatereq_m_targetLabel_index = 3;
const unsigned OpJnless_m_lhs_index = 1;
const unsigned OpJnless_m_rhs_index = 2;
const unsigned OpJnless_m_targetLabel_index = 3;
const unsigned OpJnlesseq_m_lhs_index = 1;
const unsigned OpJnlesseq_m_rhs_index = 2;
const unsigned OpJnlesseq_m_targetLabel_index = 3;
const unsigned OpJngreater_m_lhs_index = 1;
const unsigned OpJngreater_m_rhs_index = 2;
const unsigned OpJngreater_m_targetLabel_index = 3;
const unsigned OpJngreatereq_m_lhs_index = 1;
const unsigned OpJngreatereq_m_rhs_index = 2;
const unsigned OpJngreatereq_m_targetLabel_index = 3;
const unsigned OpJbelow_m_lhs_index = 1;
const unsigned OpJbelow_m_rhs_index = 2;
const unsigned OpJbelow_m_targetLabel_index = 3;
const unsigned OpJbeloweq_m_lhs_index = 1;
const unsigned OpJbeloweq_m_rhs_index = 2;
const unsigned OpJbeloweq_m_targetLabel_index = 3;

const unsigned OpSwitchImm_m_tableIndex_index = 1;
const unsigned OpSwitchImm_m_defaultOffset_index = 2;
const unsigned OpSwitchImm_m_scrutinee_index = 3;
const unsigned OpSwitchChar_m_tableIndex_index = 1;
const unsigned OpSwitchChar_m_defaultOffset_index = 2;
const unsigned OpSwitchChar_m_scrutinee_index = 3;
const unsigned OpSwitchString_m_tableIndex_index = 1;
const unsigned OpSwitchString_m_defaultOffset_index = 2;
const unsigned OpSwitchString_m_scrutinee_index = 3;
const unsigned OpNewFunc_m_dst_index = 1;
const unsigned OpNewFunc_m_scope_index = 2;
const unsigned OpNewFunc_m_functionDecl_index = 3;
const unsigned OpNewFuncExp_m_dst_index = 1;
const unsigned OpNewFuncExp_m_scope_index = 2;
const unsigned OpNewFuncExp_m_functionDecl_index = 3;
const unsigned OpNewGeneratorFunc_m_dst_index = 1;
const unsigned OpNewGeneratorFunc_m_scope_index = 2;
const unsigned OpNewGeneratorFunc_m_functionDecl_index = 3;
const unsigned OpNewGeneratorFuncExp_m_dst_index = 1;
const unsigned OpNewGeneratorFuncExp_m_scope_index = 2;
const unsigned OpNewGeneratorFuncExp_m_functionDecl_index = 3;
const unsigned OpNewAsyncFunc_m_dst_index = 1;
const unsigned OpNewAsyncFunc_m_scope_index = 2;
const unsigned OpNewAsyncFunc_m_functionDecl_index = 3;
const unsigned OpNewAsyncFuncExp_m_dst_index = 1;
const unsigned OpNewAsyncFuncExp_m_scope_index = 2;
const unsigned OpNewAsyncFuncExp_m_functionDecl_index = 3;
const unsigned OpNewAsyncGeneratorFunc_m_dst_index = 1;
const unsigned OpNewAsyncGeneratorFunc_m_scope_index = 2;
const unsigned OpNewAsyncGeneratorFunc_m_functionDecl_index = 3;
const unsigned OpNewAsyncGeneratorFuncExp_m_dst_index = 1;
const unsigned OpNewAsyncGeneratorFuncExp_m_scope_index = 2;
const unsigned OpNewAsyncGeneratorFuncExp_m_functionDecl_index = 3;
const unsigned OpSetFunctionName_m_function_index = 1;
const unsigned OpSetFunctionName_m_name_index = 2;
const unsigned OpNstricteq_m_dst_index = 1;
const unsigned OpNstricteq_m_lhs_index = 2;
const unsigned OpNstricteq_m_rhs_index = 3;
const unsigned OpStricteq_m_dst_index = 1;
const unsigned OpStricteq_m_lhs_index = 2;
const unsigned OpStricteq_m_rhs_index = 3;
const unsigned OpNeq_m_dst_index = 1;
const unsigned OpNeq_m_lhs_index = 2;
const unsigned OpNeq_m_rhs_index = 3;
const unsigned OpEq_m_dst_index = 1;
const unsigned OpEq_m_lhs_index = 2;
const unsigned OpEq_m_rhs_index = 3;
const unsigned OpIsEmpty_m_dst_index = 1;
const unsigned OpIsEmpty_m_operand_index = 2;
const unsigned OpMov_m_dst_index = 1;
const unsigned OpMov_m_src_index = 2;
const unsigned OpNewRegexp_m_dst_index = 1;
const unsigned OpNewRegexp_m_regexp_index = 2;
const unsigned OpSpread_m_dst_index = 1;
const unsigned OpSpread_m_argument_index = 2;
const unsigned OpRet_m_value_index = 1;
const unsigned OpStrcat_m_dst_index = 1;
const unsigned OpStrcat_m_src_index = 2;
const unsigned OpStrcat_m_count_index = 3;
const unsigned OpToPrimitive_m_dst_index = 1;
const unsigned OpToPrimitive_m_src_index = 2;
const unsigned OpNewArrayWithSpread_m_dst_index = 1;
const unsigned OpNewArrayWithSpread_m_argv_index = 2;
const unsigned OpNewArrayWithSpread_m_argc_index = 3;
const unsigned OpNewArrayWithSpread_m_bitVector_index = 4;
const unsigned OpCheckTdz_m_targetVirtualRegister_index = 1;
const unsigned OpArgumentCount_m_dst_index = 1;
const unsigned OpCreateClonedArguments_m_dst_index = 1;
const unsigned OpPutToArguments_m_arguments_index = 1;
const unsigned OpPutToArguments_m_index_index = 2;
const unsigned OpPutToArguments_m_value_index = 3;
const unsigned OpPushWithScope_m_dst_index = 1;
const unsigned OpPushWithScope_m_currentScope_index = 2;
const unsigned OpPushWithScope_m_newScope_index = 3;
const unsigned OpCreateLexicalEnvironment_m_dst_index = 1;
const unsigned OpCreateLexicalEnvironment_m_scope_index = 2;
const unsigned OpCreateLexicalEnvironment_m_symbolTable_index = 3;
const unsigned OpCreateLexicalEnvironment_m_initialValue_index = 4;
const unsigned OpCreateGeneratorFrameEnvironment_m_dst_index = 1;
const unsigned OpCreateGeneratorFrameEnvironment_m_scope_index = 2;
const unsigned OpCreateGeneratorFrameEnvironment_m_symbolTable_index = 3;
const unsigned OpCreateGeneratorFrameEnvironment_m_initialValue_index = 4;
const unsigned OpGetParentScope_m_dst_index = 1;
const unsigned OpGetParentScope_m_scope_index = 2;
const unsigned OpCreateScopedArguments_m_dst_index = 1;
const unsigned OpCreateScopedArguments_m_scope_index = 2;
const unsigned OpThrow_m_value_index = 1;
const unsigned OpThrowStaticError_m_message_index = 1;
const unsigned OpThrowStaticError_m_errorType_index = 2;
const unsigned OpDebug_m_debugHookType_index = 1;
const unsigned OpDebug_m_hasBreakpoint_index = 2;
const unsigned OpEnd_m_value_index = 1;
const unsigned OpCreateDirectArguments_m_dst_index = 1;
const unsigned OpGetScope_m_dst_index = 1;
const unsigned OpGetEnumerableLength_m_dst_index = 1;
const unsigned OpGetEnumerableLength_m_base_index = 2;

const unsigned OpHasStructureProperty_m_dst_index = 1;
const unsigned OpHasStructureProperty_m_base_index = 2;
const unsigned OpHasStructureProperty_m_property_index = 3;
const unsigned OpHasStructureProperty_m_enumerator_index = 4;
const unsigned OpHasGenericProperty_m_dst_index = 1;
const unsigned OpHasGenericProperty_m_base_index = 2;
const unsigned OpHasGenericProperty_m_property_index = 3;

const unsigned OpGetPropertyEnumerator_m_dst_index = 1;
const unsigned OpGetPropertyEnumerator_m_base_index = 2;
const unsigned OpEnumeratorStructurePname_m_dst_index = 1;
const unsigned OpEnumeratorStructurePname_m_enumerator_index = 2;
const unsigned OpEnumeratorStructurePname_m_index_index = 3;
const unsigned OpEnumeratorGenericPname_m_dst_index = 1;
const unsigned OpEnumeratorGenericPname_m_enumerator_index = 2;
const unsigned OpEnumeratorGenericPname_m_index_index = 3;
const unsigned OpToIndexString_m_dst_index = 1;
const unsigned OpToIndexString_m_index_index = 2;

const unsigned OpCreateRest_m_dst_index = 1;
const unsigned OpCreateRest_m_arraySize_index = 2;
const unsigned OpCreateRest_m_numParametersToSkip_index = 3;
const unsigned OpGetRestLength_m_dst_index = 1;
const unsigned OpGetRestLength_m_numParametersToSkip_index = 2;
const unsigned OpYield_m_generator_index = 1;
const unsigned OpYield_m_yieldPoint_index = 2;
const unsigned OpYield_m_argument_index = 3;

const unsigned OpLogShadowChickenPrologue_m_scope_index = 1;
const unsigned OpLogShadowChickenTail_m_thisValue_index = 1;
const unsigned OpLogShadowChickenTail_m_scope_index = 2;
const unsigned OpResolveScopeForHoistingFuncDeclInEval_m_dst_index = 1;
const unsigned OpResolveScopeForHoistingFuncDeclInEval_m_scope_index = 2;
const unsigned OpResolveScopeForHoistingFuncDeclInEval_m_property_index = 3;




} // namespace JSC
