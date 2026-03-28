
add_llvm_component_group(Zaza)

set(LLVM_TARGET_DEFINITIONS Zaza.td)

tablegen(LLVM ZazaGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(ZazaCommonTableGen)

add_llvm_target(ZazaCodeGen
  ZazaTargetMachine.cpp
  ZazaRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ZazaInfo

  ADD_TO_COMPONENT
  Zaza
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)