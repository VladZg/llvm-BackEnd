#include "ZazaTargetMachine.hpp"
#include "Zaza.hpp"
#include "TargetInfo/ZazaTargetInfo.hpp"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeZazaTarget() {
  // Register the target.
  ZAZA_DUMP_CYAN
  RegisterTargetMachine<ZazaTargetMachine> A(getTheZazaTarget());
}

ZazaTargetMachine::ZazaTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:64:64-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,  // FIXME: choose archoitecture
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  ZAZA_DUMP_CYAN
  initAsmInfo();
}