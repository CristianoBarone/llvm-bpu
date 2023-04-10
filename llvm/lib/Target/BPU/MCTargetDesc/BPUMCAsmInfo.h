//===-- BPUMCAsmInfo.h - BPU Asm Info ------------------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the BPUMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCASMINFO_H
#define LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
  class Triple;

class BPUMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit BPUMCAsmInfo(const Triple &TheTriple);
};

} // namespace llvm

#endif // end LLVM_LIB_TARGET_BPU_MCTARGETDESC_BPUMCASMINFO_H
