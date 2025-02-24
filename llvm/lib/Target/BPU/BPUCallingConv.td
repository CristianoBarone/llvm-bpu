//=== BPUCallingConv.td - Calling Conventions for BPU --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for BPU architecture.
//===----------------------------------------------------------------------===//

def BPU_CCallingConv : CallingConv<[
  // Handles byval parameters. Tell LLVM what the size and alignment
  // requirements of each stack slot are
  CCIfByVal<CCPassByVal<4, 4>>,

  // Promote i8/i16 to i64
  CCIfType<[i1, i8, i16, i32], CCPromoteToType<i64>>,

  // The first 4 arguments are passed in X0, X1, X2, X3
  CCIfType<[i32], CCAssignToReg<[X0, X1, X2, X3]>>,

  // Integer values get stored in stack slots that are 4 bytes in size and
  // 4-byte aligned
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

// BeyondRISC C Return Convention
def BPU_CRetConv : CallingConv<[
  CCIfType<[i1, i8, i16], CCPromoteToType<i32>>,

  // i32 are returned in registers X0, X1
  CCIfType<[i32], CCAssignToReg<[X0, X1, X2, X3]>>,

  // Integer values get stored in stack slots that are 4 bytes in size and
  // 4-byte aligned
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

def BPU_CalleeSavedRegs : CalleeSavedRegs<(add X8, X9)>;
