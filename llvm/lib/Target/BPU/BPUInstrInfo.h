//===-- BPUInstrInfo.h - BPU Instruction Information ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the BPU implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_BPU_BPUINSTRINFO_H
#define LLVM_LIB_TARGET_BPU_BPUINSTRINFO_H

#include "BPU.h"
#include "BPURegisterInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "BPUGenInstrInfo.inc"

namespace llvm {

class BPUInstrInfo : public BPUGenInstrInfo {
public:
  explicit BPUInstrInfo(const BPUSubtarget &STI);

protected:
  const BPUSubtarget &Subtarget;
};
}

#endif // end LLVM_LIB_TARGET_BPU_BPUINSTRINFO_H
