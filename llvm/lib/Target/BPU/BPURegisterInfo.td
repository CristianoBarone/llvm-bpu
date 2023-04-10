//===-- BPURegisterInfo.td - BPU Register defs ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the RISC-W register file
//===----------------------------------------------------------------------===//

let Namespace = "BPU" in {
class BPUReg<bits<4> Enc, string n, list<Register> sub = []> : Register<n> {
  let HWEncoding{3-0} = Enc;
  let SubRegs = sub;
}
} // end Namespace

def r0b  : BPUReg<0, "r0b", []>;
def r0w  : BPUReg<0, "r0w", [r0b]>;
def r0d  : BPUReg<0, "r0d", [r0w]>;
def r0   : BPUReg<0, "r0", [r0d]>;

def r1b  : BPUReg<1, "r1b", []>;
def r1w  : BPUReg<1, "r1w", [r1b]>;
def r1d  : BPUReg<1, "r1d", [r1w]>;
def r1   : BPUReg<1, "r1", [r1d]>;

def r2b  : BPUReg<2, "r2b", []>;
def r2w  : BPUReg<2, "r2w", [r2b]>;
def r2d  : BPUReg<2, "r2d", [r2w]>;
def r2   : BPUReg<2, "r2", [r2d]>;

def r3b  : BPUReg<3, "r3b", []>;
def r3w  : BPUReg<3, "r3w", [r3b]>;
def r3d  : BPUReg<3, "r3d", [r3w]>;
def r3   : BPUReg<3, "r3", [r3d]>;

def r4b  : BPUReg<4, "r4b", []>;
def r4w  : BPUReg<4, "r4w", [r4b]>;
def r4d  : BPUReg<4, "r4d", [r4w]>;
def r4   : BPUReg<4, "r4", [r4d]>;

def r5b  : BPUReg<5, "r5b", []>;
def r5w  : BPUReg<5, "r5w", [r5b]>;
def r5d  : BPUReg<5, "r5d", [r5w]>;
def r5   : BPUReg<5, "r5", [r5d]>;

def r6b  : BPUReg<6, "r6b", []>;
def r6w  : BPUReg<6, "r6w", [r6b]>;
def r6d  : BPUReg<6, "r6d", [r6w]>;
def r6   : BPUReg<6, "r6", [r6d]>;

def r7b  : BPUReg<7, "r7b", []>;
def r7w  : BPUReg<7, "r7w", [r7b]>;
def r7d  : BPUReg<7, "r7d", [r7w]>;
def r7   : BPUReg<7, "r7", [r7d]>;

def r8b  : BPUReg<8, "r8b", []>;
def r8w  : BPUReg<8, "r8w", [r8b]>;
def r8d  : BPUReg<8, "r8d", [r8w]>;
def r8   : BPUReg<8, "r8", [r8d]>;

def r9b  : BPUReg<9, "r9b", []>;
def r9w  : BPUReg<9, "r9w", [r9b]>;
def r9d  : BPUReg<9, "r9d", [r9w]>;
def r9   : BPUReg<9, "r9", [r9d]>;

def r10b  : BPUReg<10, "r10b", []>;
def r10w  : BPUReg<10, "r10w", [r10b]>;
def r10d  : BPUReg<10, "r10d", [r10w]>;
def r10   : BPUReg<10, "r10", [r10d]>;

def r11b  : BPUReg<11, "r11b", []>;
def r11w  : BPUReg<11, "r11w", [r11b]>;
def r11d  : BPUReg<11, "r11d", [r11w]>;
def r11   : BPUReg<11, "r11", [r11d]>;

// The order of registers represents the preferred allocation sequence.
// Registers are listed in the order caller-save, callee-save, specials.

def GPR8  : RegisterClass<"BPU", [i8], 8, (add r0b, r1b, r2b, r3b, r4b, r5b, r6b, r7b, r8b, r9b, r10b, r11b)>;
def GPR16 : RegisterClass<"BPU", [i16], 16, (add r0w, r1w, r2w, r3w, r4w, r5w, r6w, r7w, r8w, r9w, r10w, r11w)>;
def GPR32 : RegisterClass<"BPU", [i32], 32, (add r0d, r1d, r2d, r3d, r4d, r5d, r6d, r7d, r8d, r9d, r10d, r11d)>;
def GPR64 : RegisterClass<"BPU", [i64], 64, (add r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11)>;