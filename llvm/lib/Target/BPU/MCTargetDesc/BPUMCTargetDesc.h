//===-- BPUMCTargetDesc.h - BPU Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides BPU specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCTARGETDESC_H
#define LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCTARGETDESC_H

#include "BPUBaseInfo.h"

// Defines symbolic names for BPU registers. This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "BPUGenRegisterInfo.inc"

// Defines symbolic names for the BPU instructions.
#define GET_INSTRINFO_ENUM
#include "BPUGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "BPUGenSubtargetInfo.inc"

#endif // end LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCTARGETDESC_H
