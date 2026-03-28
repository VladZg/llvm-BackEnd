#include "TargetInfo/ZazaTargetInfo.hpp"
#include "Zaza.hpp"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheZazaTarget() {
  ZAZA_DUMP_YELLOW
  static Target TheZazaTarget;
  return TheZazaTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeZazaTargetInfo() {
  ZAZA_DUMP_YELLOW
  RegisterTarget<Triple::zaza> X(getTheZazaTarget(), "zaza",
                                "Simulator ZAZA target for LLVM course (64-bit)", "Zaza");
}