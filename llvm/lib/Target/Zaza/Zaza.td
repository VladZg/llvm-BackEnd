include "llvm/Target/Target.td"
include "ZazaRegisterInfo.td"
include "ZazaInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def ZazaInstrInfo : InstrInfo;
def Zaza : Target {
  let InstructionSet = ZazaInstrInfo;
}