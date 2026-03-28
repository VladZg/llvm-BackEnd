#pragma once

#include "llvm/CodeGen/CodeGenTargetMachineImpl.hpp"
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
