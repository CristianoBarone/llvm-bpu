//=== BPUMachineFunctionInfo.h - Private data used for BPU ----*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the BPU specific subclass of MachineFunctionInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_BPU_BPUMACHINEFUNCTION_H
#define LLVM_LIB_TARGET_BPU_BPUMACHINEFUNCTION_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

/// BPUFunctionInfo - This class is derived from MachineFunction private
/// BPU target-specific information for each MachineFunction.
class BPUFunctionInfo : public MachineFunctionInfo {
private:
  MachineFunction &MF;

public:
  BPUFunctionInfo(MachineFunction &MF) : MF(MF) {}
};

} // end of namespace llvm

#endif // end LLVM_LIB_TARGET_BPU_BPUMACHINEFUNCTION_H
