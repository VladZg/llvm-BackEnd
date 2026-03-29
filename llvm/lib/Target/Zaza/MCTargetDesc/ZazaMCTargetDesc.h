#pragma once

// Defines symbolic names for Zaza registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "ZazaGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "ZazaGenInstrInfo.inc"

#include <memory>

namespace llvm {

class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createZazaMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createZazaAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                   const MCRegisterInfo &MRI,
                                   const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createZazaELFObjectWriter(bool Is64Bit,
                                                                uint8_t OSABI);
} // namespace llvm