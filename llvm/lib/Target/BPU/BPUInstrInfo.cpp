//===-- BPUInstrInfo.cpp - BPU Instruction Information ----------------===//
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

#include "BPUInstrInfo.h"

#include "BPUTargetMachine.h"
#include "BPUMachineFunction.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "bpu-instrinfo"

#define GET_INSTRINFO_CTOR_DTOR
#include "BPUGenInstrInfo.inc"

BPUInstrInfo::BPUInstrInfo(const BPUSubtarget &STI)
    : BPUGenInstrInfo(BPU::ADJCALLSTACKDOWN, BPU::ADJCALLSTACKUP),
      Subtarget(STI)
{
}
