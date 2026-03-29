#include "ZazaRegisterInfo.h"
#include "Zaza.h"
#include "ZazaFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ZazaGenRegisterInfo.inc"

ZazaRegisterInfo::ZazaRegisterInfo() : ZazaGenRegisterInfo(Zaza::R0) {
  ZAZA_DUMP_GREEN
}

const MCPhysReg *
ZazaRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ZAZA_DUMP_GREEN
  return CSR_Zaza_SaveList;
}

BitVector ZazaRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ZAZA_DUMP_GREEN
  ZazaFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Zaza::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Zaza::R2);
  }
  return Reserved;
}

bool ZazaRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool ZazaRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  ZAZA_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register ZazaRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ZAZA_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Zaza::R2 : Zaza::R1;
}

const uint32_t* ZazaRegisterInfo::getCallPreservedMask(const MachineFunction &MF, CallingConv::ID CC) const {
  ZAZA_DUMP_GREEN
  return CSR_Zaza_RegMask;
}