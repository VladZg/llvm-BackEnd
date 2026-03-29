#include "ZazaSubtarget.h"
#include "Zaza.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "zaza-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ZazaGenSubtargetInfo.inc"

ZazaSubtarget::ZazaSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : ZazaGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  ZAZA_DUMP_CYAN
}