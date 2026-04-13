#include "ZazaInstrInfo.h"
#include "Zaza.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "ZazaGenInstrInfo.inc"

#define DEBUG_TYPE "Zaza-inst-info"

ZazaInstrInfo::ZazaInstrInfo() : ZazaGenInstrInfo() { ZAZA_DUMP_GREEN }