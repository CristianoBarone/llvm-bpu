//===-- BPURegisterInfo.cpp - BPU Register Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the BPU implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "BPURegisterInfo.h"
#include "BPUSubtarget.h"
#include "llvm/Support/Debug.h"

#define GET_REGINFO_TARGET_DESC
#include "BPUGenRegisterInfo.inc"

#define DEBUG_TYPE "bpu-reginfo"

using namespace llvm;

BPURegisterInfo::BPURegisterInfo(const BPUSubtarget &ST)
  : BPUGenRegisterInfo(BPU::X1, /*DwarfFlavour*/0, /*EHFlavor*/0,
                         /*PC*/0), Subtarget(ST) {}

const MCPhysReg *
BPURegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return BPU_CalleeSavedRegs_SaveList;
}

const TargetRegisterClass *BPURegisterInfo::intRegClass(unsigned Size) const {
  return &BPU::GPRRegClass;
}

const uint32_t *
BPURegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                        CallingConv::ID) const {
  return BPU_CalleeSavedRegs_RegMask;
}

BitVector BPURegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  markSuperRegs(Reserved, BPU::X0); // zero
  markSuperRegs(Reserved, BPU::X2); // sp
  markSuperRegs(Reserved, BPU::X3); // gp
  markSuperRegs(Reserved, BPU::X4); // tp

  return Reserved;
}

void BPURegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj,
                                           unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  llvm_unreachable("Unsupported eliminateFrameIndex");
}

bool
BPURegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
  return true;
}

bool
BPURegisterInfo::requiresFrameIndexScavenging(
                                            const MachineFunction &MF) const {
  return true;
}

bool
BPURegisterInfo::requiresFrameIndexReplacementScavenging(
                                            const MachineFunction &MF) const {
  return true;
}

bool
BPURegisterInfo::trackLivenessAfterRegAlloc(const MachineFunction &MF) const {
  return true;
}

Register BPURegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  llvm_unreachable("Unsupported getFrameRegister");
}

