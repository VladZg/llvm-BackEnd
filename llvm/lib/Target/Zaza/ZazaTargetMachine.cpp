#include "ZazaTargetMachine.h"
#include "Zaza.h"
#include "TargetInfo/ZazaTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
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
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  ZAZA_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Zaza Code Generator Pass Configuration Options.
class ZazaPassConfig : public TargetPassConfig {
public:
  ZazaPassConfig(ZazaTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    ZAZA_DUMP_CYAN
    return false;
  }
};

} // anonymous namespace

TargetPassConfig *ZazaTargetMachine::createPassConfig(PassManagerBase &PM) {
  ZAZA_DUMP_CYAN
  return new ZazaPassConfig(*this, PM);
}