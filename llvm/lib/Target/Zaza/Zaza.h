#pragma once

#include "MCTargetDesc/ZazaMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define ZAZA_DUMP(Color)                                                       \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }

#define ZAZA_DUMP_RED     ZAZA_DUMP(llvm::raw_ostream::RED    )
#define ZAZA_DUMP_GREEN   ZAZA_DUMP(llvm::raw_ostream::GREEN  )
#define ZAZA_DUMP_YELLOW  ZAZA_DUMP(llvm::raw_ostream::YELLOW )
#define ZAZA_DUMP_CYAN    ZAZA_DUMP(llvm::raw_ostream::CYAN   )
#define ZAZA_DUMP_MAGENTA ZAZA_DUMP(llvm::raw_ostream::MAGENTA)
#define ZAZA_DUMP_WHITE   ZAZA_DUMP(llvm::raw_ostream::WHITE  )

namespace llvm {
class ZazaTargetMachine;
class FunctionPass;
class ZazaSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerZazaMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                   AsmPrinter &AP);
bool LowerZazaMachineOperandToMCOperand(const MachineOperand &MO,
                                        MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createZazaISelDag(ZazaTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm