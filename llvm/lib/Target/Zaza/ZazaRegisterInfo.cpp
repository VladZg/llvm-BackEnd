#include "ZazaRegisterInfo.h"
#include "Zaza.h"
#include "ZazaFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ZazaGenRegisterInfo.inc"

ZazaRegisterInfo::ZazaRegisterInfo() : ZazaGenRegisterInfo(Zaza::R0) {
  ZAZA_DUMP_GREEN
}