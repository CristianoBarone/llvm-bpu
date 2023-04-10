set(LLVM_TARGET_DEFINITIONS BPU.td)

tablegen(LLVM BPUGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM BPUGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM BPUGenCodeEmitter.inc -gen-emitter)
tablegen(LLVM BPUGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM BPUGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM BPUGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM BPUGenCallingConv.inc -gen-callingconv)
tablegen(LLVM BPUGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM BPUGenMCPseudoLowering.inc -gen-pseudo-lowering)

# BPUCommonTableGen must be defined
add_public_tablegen_target(BPUCommonTableGen)

# BPUCodeGen should match with LLVMBuild.txt BPUCodeGen
add_llvm_target(BPUCodeGen
  BPUAsmPrinter.cpp
  BPUFrameLowering.cpp
  BPUInstrInfo.cpp
  BPUISelLowering.cpp
  BPURegisterInfo.cpp
  BPUSubtarget.cpp
  BPUTargetObjectFile.cpp
  BPUISelDAGToDAG.cpp
  BPUTargetMachine.cpp
)

# Should match with "subdirectories =  MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
