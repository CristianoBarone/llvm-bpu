//===-- BPUMCTargetDesc.cpp - BPU Target Descriptions -----------------===//
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

#include "BPUMCTargetDesc.h"
#include "BPUInstPrinter.h"
#include "BPUMCAsmInfo.h"
#include "TargetInfo/BPUTargetInfo.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "BPUGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "BPUGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "BPUGenRegisterInfo.inc"

static MCInstrInfo *createBPUMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitBPUMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createBPUMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  return X;
}

static MCSubtargetInfo *
createBPUMCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  std::string CPUName = CPU;
  if (CPUName.empty())
    CPUName = "generic";
  return createBPUMCSubtargetInfoImpl(TT, CPUName, FS);
}

static MCInstPrinter *createBPUMCInstPrinter(const Triple &T,
                                               unsigned SyntaxVariant,
                                               const MCAsmInfo &MAI,
                                               const MCInstrInfo &MII,
                                               const MCRegisterInfo &MRI) {
  return new BPUInstPrinter(MAI, MII, MRI);
}

static MCAsmInfo *createBPUMCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT,
                                       const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new BPUMCAsmInfo(TT);

  unsigned WP = MRI.getDwarfRegNum(BPU::X2, true);
  MCCFIInstruction Inst = MCCFIInstruction::createDefCfa(nullptr, WP, 0);
  MAI->addInitialFrameState(Inst);

  return MAI;
}

extern "C" void LLVMInitializeBPUTargetMC() {
  for (Target *T : {&getTheBPUTarget()}) {
    // Register the MC asm info.
    TargetRegistry::RegisterMCAsmInfo(*T, createBPUMCAsmInfo);

    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(*T, createBPUMCInstrInfo);

    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(*T, createBPUMCRegisterInfo);

    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(*T, createBPUMCSubtargetInfo);

    // Register the MCInstPrinter.
    TargetRegistry::RegisterMCInstPrinter(*T, createBPUMCInstPrinter);
  }
}
