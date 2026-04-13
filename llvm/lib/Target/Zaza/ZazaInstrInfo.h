#pragma once

#include "ZazaRegisterInfo.h"
#include "MCTargetDesc/ZazaInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "ZazaGenInstrInfo.inc"

namespace llvm {

class ZazaSubtarget;

class ZazaInstrInfo : public ZazaGenInstrInfo {
public:
  ZazaInstrInfo();

};

} // namespace llvm