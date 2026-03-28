include "llvm/Target/Target.td"
include "ZazaRegisterInfo.td"
include "ZazaInstrInfo.td"

def ZazaInstrInfo : InstrInfo;
def Zaza : Target {
  let InstructionSet = ZazaInstrInfo;
}