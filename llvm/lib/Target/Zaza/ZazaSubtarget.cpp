#include "ZazaSubtarget.h"
#include "Zaza.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "zaza-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ZazaGenSubtargetInfo.inc"

ZazaSubtarget::ZazaSubtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, const TargetMachine &TM)
    : ZazaGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS)
    , TLInfo(TM, *this)
    , FrameLowering(*this)
    , InstrInfo() {
    ZAZA_DUMP_CYAN
}