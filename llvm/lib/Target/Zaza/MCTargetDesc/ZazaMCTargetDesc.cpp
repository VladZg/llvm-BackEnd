#include "Zaza.h"
#include "TargetInfo/ZazaTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ZazaGenRegisterInfo.inc"

static MCRegisterInfo *createZazaMCRegisterInfo(const Triple &TT) {
  ZAZA_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitZazaMCRegisterInfo(X, Zaza::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeZazaTargetMC() {
  ZAZA_DUMP_MAGENTA
  Target &TheZazaTarget = getTheZazaTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheZazaTarget, createZazaMCRegisterInfo);
}