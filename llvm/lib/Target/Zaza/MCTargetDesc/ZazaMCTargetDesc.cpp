#include "MCTargetDesc/ZazaInfo.h"
#include "Zaza.h"
#include "TargetInfo/ZazaTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ZazaGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ZazaGenInstrInfo.inc"

static MCRegisterInfo *createZazaMCRegisterInfo(const Triple &TT) {
  ZAZA_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitZazaMCRegisterInfo(X, Zaza::R0);
  return X;
}

static MCInstrInfo *createZazaMCInstrInfo() {
  ZAZA_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitZazaMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeZazaTargetMC() {
  ZAZA_DUMP_MAGENTA
  Target &TheZazaTarget = getTheZazaTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheZazaTarget, createZazaMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheZazaTarget, createZazaMCInstrInfo);
}