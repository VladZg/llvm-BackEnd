#pragma once

#include "Zaza.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class ZazaSubtarget;
class ZazaTargetMachine;

namespace ZazaISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace ZazaISD

class ZazaTargetLowering : public TargetLowering {
public:
  explicit ZazaTargetLowering(const TargetMachine &TM, const ZazaSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  ZazaSubtarget const &getSubtarget() const { return STI; }

private:
  const ZazaSubtarget &STI;
};

} // namespace llvm