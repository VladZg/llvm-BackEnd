#include "ZazaISelLowering.h"
#include "Zaza.h"
#include "ZazaRegisterInfo.h"
#include "ZazaSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "zaza-lower"

using namespace llvm;

ZazaTargetLowering::ZazaTargetLowering(const TargetMachine &TM,
                                       const ZazaSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  ZAZA_DUMP_RED
  addRegisterClass(MVT::i32, &Zaza::GPRRegClass);
}

const char *ZazaTargetLowering::getTargetNodeName(unsigned Opcode) const {
  ZAZA_DUMP_RED
  switch (Opcode) {
  case ZazaISD::CALL:
    return "ZazaISD::CALL";
  case ZazaISD::RET:
    return "ZazaISD::RET";
  }
  return nullptr;
}