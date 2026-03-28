#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace ZazaOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace ZazaOp

} // namespace llvm
