
add_llvm_component_group(Zaza)

set(LLVM_TARGET_DEFINITIONS Zaza.td)

tablegen(LLVM ZazaGenRegisterInfo.inc     -gen-register-info  )
tablegen(LLVM ZazaGenInstrInfo.inc        -gen-instr-info     )
tablegen(LLVM ZazaGenSubtargetInfo.inc    -gen-subtarget      )
tablegen(LLVM ZazaGenMCPseudoLowering.inc -gen-pseudo-lowering)

add_public_tablegen_target(ZazaCommonTableGen)

add_llvm_target(ZazaCodeGen
  ZazaTargetMachine.cpp
  ZazaRegisterInfo.cpp
  ZazaInstrInfo.cpp
  ZazaSubtarget.cpp
  ZazaAsmPrinter.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ZazaInfo
  AsmPrinter

  ADD_TO_COMPONENT
  Zaza
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)