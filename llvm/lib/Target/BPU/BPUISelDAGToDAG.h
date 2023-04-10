//===---- BPUISelDAGToDAG.h - A Dag to Dag Inst Selector for BPU ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the BPU target.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_BPU_BPUISELDAGTODAG_H
#define LLVM_LIB_TARGET_BPU_BPUISELDAGTODAG_H

#include "BPUSubtarget.h"
#include "BPUTargetMachine.h"
#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {
class BPUDAGToDAGISel : public SelectionDAGISel {
public:
  explicit BPUDAGToDAGISel(BPUTargetMachine &TM, CodeGenOpt::Level OL)
      : SelectionDAGISel(TM, OL), Subtarget(nullptr) {}

  // Pass Name
  StringRef getPassName() const override {
    return "BPU DAG->DAG Pattern Instruction Selection";
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  void Select(SDNode *Node) override;

#include "BPUGenDAGISel.inc"

private:
  const BPUSubtarget *Subtarget;
};
}

#endif // end LLVM_LIB_TARGET_BPU_BPUISELDAGTODAG_H
