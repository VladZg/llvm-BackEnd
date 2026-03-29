#pragma once

#include "Zaza.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class ZazaSubtarget;

class ZazaFrameLowering : public TargetFrameLowering {
public:
  ZazaFrameLowering(const ZazaSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0)
      , STI(STI) {
    ZAZA_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const ZazaSubtarget &STI;
};

} // namespace llvm