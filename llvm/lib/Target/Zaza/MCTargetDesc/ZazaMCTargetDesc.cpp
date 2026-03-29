#include "MCTargetDesc/ZazaInfo.h"
#include "Zaza.h"
#include "ZazaInstPrinter.h"
#include "ZazaMCAsmInfo.h"
#include "TargetInfo/ZazaTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ZazaGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ZazaGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "ZazaGenSubtargetInfo.inc"

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

static MCSubtargetInfo *createZazaMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  ZAZA_DUMP_MAGENTA
  return createZazaMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createZazaMCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  ZAZA_DUMP_MAGENTA
  MCAsmInfo *MAI = new ZazaELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Zaza::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createZazaMCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
  ZAZA_DUMP_MAGENTA
  return new ZazaInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeZazaTargetMC() {
  ZAZA_DUMP_MAGENTA
  Target &TheZazaTarget = getTheZazaTarget();
  RegisterMCAsmInfoFn X(TheZazaTarget, createZazaMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheZazaTarget, createZazaMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheZazaTarget, createZazaMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheZazaTarget, createZazaMCSubtargetInfo);
  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(TheZazaTarget, createZazaMCInstPrinter);
  // Register the MC Code Emitter.
  TargetRegistry::RegisterMCCodeEmitter(TheZazaTarget, createZazaMCCodeEmitter);
}