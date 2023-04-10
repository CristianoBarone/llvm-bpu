//===-- BPUTargetInfo.cpp - BPU Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/BPUTargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheBPUTarget() {
  static Target TheBPUTarget;
  return TheBPUTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeBPUTargetInfo() {
  RegisterTarget<Triple::bpu> X(getTheBPUTarget(), "bpu",
                                  "BPU");
}
