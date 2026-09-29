// SPDX-License-Identifier: MIT
// Copyright (c) 2026 DeepSeek
//
// Editor stubs for SIMT declarations and no-op macros used by clangd.

#ifndef __CCE_SIMT_STUBS_H__
#define __CCE_SIMT_STUBS_H__

extern __simt_callee__ void __sync_workitems();
extern __simt_callee__ void __fence_workitems();
extern __simt_callee__ void __fenceblock_workitems();

#define __cce_simt_get_BLOCKID() 0
#define __cce_simt_get_BLOCKDIM() 0

#define __cce_simt_get_TID_X() 0
#define __cce_simt_get_TID_Y() 0
#define __cce_simt_get_TID_Z() 0
#define __cce_simt_get_BLOCK_DIM_X() 0
#define __cce_simt_get_BLOCK_DIM_Y() 0
#define __cce_simt_get_BLOCK_DIM_Z() 0
#define __cce_simt_get_SUBBLOCKDIM() 0
#define __cce_simt_get_SUBBLOCKID() 0
#define __cce_simt_get_VECCOREID() 0
#define __cce_simt_get_COREID() 0
#define __cce_simt_get_CLOCK64() 0
#define __cce_simt_get_CLOCK32() 0
#define __cce_simt_get_laneID() 0
#define __cce_simt_get_LANEMASK_EQ() 0
#define __cce_simt_get_LANEMASK_LE() 0
#define __cce_simt_get_LANEMASK_LT() 0
#define __cce_simt_get_LANEMASK_GE() 0
#define __cce_simt_get_LANEMASK_GT() 0

#define __builtin_cce_atom_sub_G_u32(...) 0
#define __builtin_cce_atom_cas_G_u32(...) 0
#define __builtin_cce_atom_exch_G_u32(...) 0
#define __builtin_cce_atom_sub_G_s32(...) 0
#define __builtin_cce_atom_cas_G_s32(...) 0
#define __builtin_cce_atom_exch_G_s32(...) 0
#define __builtin_cce_atom_sub_G_u64(...) 0
#define __builtin_cce_atom_cas_G_u64(...) 0
#define __builtin_cce_atom_exch_G_u64(...) 0
#define __builtin_cce_atom_sub_G_s64(...) 0
#define __builtin_cce_atom_cas_G_s64(...) 0
#define __builtin_cce_atom_exch_G_s64(...) 0
#define __builtin_cce_atom_sub_G_fp32(...) 0
#define __builtin_cce_atom_cas_G_fp32(...) 0
#define __builtin_cce_atom_exch_G_fp32(...) 0

#define __builtin_cce_atom_add_G_u32(...) 0
#define __builtin_cce_atom_min_G_u32(...) 0
#define __builtin_cce_atom_max_G_u32(...) 0
#define __builtin_cce_atom_add_G_s32(...) 0
#define __builtin_cce_atom_min_G_s32(...) 0
#define __builtin_cce_atom_max_G_s32(...) 0
#define __builtin_cce_atom_add_G_u64(...) 0
#define __builtin_cce_atom_min_G_u64(...) 0
#define __builtin_cce_atom_max_G_u64(...) 0
#define __builtin_cce_atom_add_G_s64(...) 0
#define __builtin_cce_atom_min_G_s64(...) 0
#define __builtin_cce_atom_max_G_s64(...) 0
#define __builtin_cce_atom_add_G_fp32(...) 0
#define __builtin_cce_atom_min_G_fp32(...) 0
#define __builtin_cce_atom_max_G_fp32(...) 0

#define __builtin_cce_atom_and_G_u32(...) 0
#define __builtin_cce_atom_or_G_u32(...) 0
#define __builtin_cce_atom_xor_G_u32(...) 0
#define __builtin_cce_atom_and_G_s32(...) 0
#define __builtin_cce_atom_or_G_s32(...) 0
#define __builtin_cce_atom_xor_G_s32(...) 0
#define __builtin_cce_atom_and_G_u64(...) 0
#define __builtin_cce_atom_or_G_u64(...) 0
#define __builtin_cce_atom_xor_G_u64(...) 0
#define __builtin_cce_atom_and_G_s64(...) 0
#define __builtin_cce_atom_or_G_s64(...) 0
#define __builtin_cce_atom_xor_G_s64(...) 0

#define __builtin_cce_atom_cas_S_u32(...) 0
#define __builtin_cce_atom_exch_S_u32(...) 0
#define __builtin_cce_atom_sub_S_u32(...) 0
#define __builtin_cce_atom_cas_S_s32(...) 0
#define __builtin_cce_atom_exch_S_s32(...) 0
#define __builtin_cce_atom_sub_S_s32(...) 0
#define __builtin_cce_atom_cas_S_fp32(...) 0
#define __builtin_cce_atom_exch_S_fp32(...) 0
#define __builtin_cce_atom_sub_S_fp32(...) 0

#define __builtin_cce_atom_add_S_u32(...) 0
#define __builtin_cce_atom_min_S_u32(...) 0
#define __builtin_cce_atom_max_S_u32(...) 0
#define __builtin_cce_atom_add_S_s32(...) 0
#define __builtin_cce_atom_min_S_s32(...) 0
#define __builtin_cce_atom_max_S_s32(...) 0
#define __builtin_cce_atom_add_S_fp32(...) 0
#define __builtin_cce_atom_min_S_fp32(...) 0
#define __builtin_cce_atom_max_S_fp32(...) 0

#define __builtin_cce_atom_and_S_u32(...) 0
#define __builtin_cce_atom_or_S_u32(...) 0
#define __builtin_cce_atom_xor_S_u32(...) 0
#define __builtin_cce_atom_and_S_s32(...) 0
#define __builtin_cce_atom_or_S_s32(...) 0
#define __builtin_cce_atom_xor_S_s32(...) 0

#define __builtin_cce_atom_cas_G_bf16x2(...) 0
#define __builtin_cce_atom_exch_G_bf16x2(...) 0
#define __builtin_cce_atom_sub_G_bf16x2(...) 0
#define __builtin_cce_atom_add_G_bf16(...) 0
#define __builtin_cce_atom_min_G_bf16(...) 0
#define __builtin_cce_atom_max_G_bf16(...) 0
#define __builtin_cce_atom_add_G_bf16x2(...) 0
#define __builtin_cce_atom_min_G_bf16x2(...) 0
#define __builtin_cce_atom_max_G_bf16x2(...) 0
#define __builtin_cce_atom_cas_S_bf16x2(...) 0
#define __builtin_cce_atom_exch_S_bf16x2(...) 0
#define __builtin_cce_atom_sub_S_bf16x2(...) 0
#define __builtin_cce_atom_add_S_bf16(...) 0
#define __builtin_cce_atom_min_S_bf16(...) 0
#define __builtin_cce_atom_max_S_bf16(...) 0
#define __builtin_cce_atom_add_S_bf16x2(...) 0
#define __builtin_cce_atom_min_S_bf16x2(...) 0
#define __builtin_cce_atom_max_S_bf16x2(...) 0

#define __builtin_isnan_bf162(...) 0

#define __builtin_cce_atom_cas_G_f16x2(...) 0
#define __builtin_cce_atom_exch_G_f16x2(...) 0
#define __builtin_cce_atom_sub_G_f16x2(...) 0
#define __builtin_cce_atom_add_G_fp16(...) 0
#define __builtin_cce_atom_min_G_fp16(...) 0
#define __builtin_cce_atom_max_G_fp16(...) 0
#define __builtin_cce_atom_add_G_f16x2(...) 0
#define __builtin_cce_atom_min_G_f16x2(...) 0
#define __builtin_cce_atom_max_G_f16x2(...) 0
#define __builtin_cce_atom_cas_S_f16x2(...) 0
#define __builtin_cce_atom_exch_S_f16x2(...) 0
#define __builtin_cce_atom_sub_S_f16x2(...) 0
#define __builtin_cce_atom_add_S_fp16(...) 0
#define __builtin_cce_atom_min_S_fp16(...) 0
#define __builtin_cce_atom_max_S_fp16(...) 0
#define __builtin_cce_atom_add_S_f16x2(...) 0
#define __builtin_cce_atom_min_S_f16x2(...) 0
#define __builtin_cce_atom_max_S_f16x2(...) 0

#define __builtin_isnan_half162(...) 0



#endif
