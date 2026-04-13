#pragma once

#include "ZazaSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheZazaTarget;

class ZazaTargetMachine : public CodeGenTargetMachineImpl {

  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  ZazaSubtarget Subtarget;

public:
  ZazaTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const ZazaSubtarget *getSubtargetImpl(const Function &) const override {
      ZAZA_DUMP_CYAN
      return &Subtarget;
    }
  
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};

} // namespace llvm
