
add_llvm_component_group(Zaza)

add_llvm_target(ZazaCodeGen
  ZazaTargetMachine.cpp

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