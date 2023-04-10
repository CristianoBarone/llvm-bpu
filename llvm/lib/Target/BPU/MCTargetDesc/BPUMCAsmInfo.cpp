//===-- BPUMCAsmInfo.cpp - BPU Asm Properties -------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the BPUMCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "BPUMCAsmInfo.h"

#include "llvm/ADT/Triple.h"

using namespace llvm;

void BPUMCAsmInfo::anchor() { }

BPUMCAsmInfo::BPUMCAsmInfo(const Triple &TheTriple) {
  // This architecture is little endian only
  IsLittleEndian = true;

  AlignmentIsInBytes          = false;
  Data8bitsDirective          = "\t.byte\t";
  Data16bitsDirective         = "\t.word\t";
  Data32bitsDirective         = "\t.dword\t";
  Data64bitsDirective         = "\t.qword\t";

  PrivateGlobalPrefix         = ".L";
  PrivateLabelPrefix          = ".L";

  LabelSuffix                 = ":";

  CommentString               = ";";

  //ZeroDirective               = "\t.zero\t";

  UseAssignmentForEHBegin     = true;

  SupportsDebugInformation    = false;
  /*ExceptionsType              = ExceptionHandling::DwarfCFI;
  DwarfRegNumForCFI           = true;*/
}
