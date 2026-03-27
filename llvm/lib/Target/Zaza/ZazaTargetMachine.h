#ifndef LLVM_LIB_TARGET_ZAZA_ZAZATARGETMACHINE_H
#define LLVM_LIB_TARGET_ZAZA_ZAZATARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheZazaTarget;

class ZazaTargetMachine : public CodeGenTargetMachineImpl {
public:
  ZazaTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
};

} // namespace llvm

#endif