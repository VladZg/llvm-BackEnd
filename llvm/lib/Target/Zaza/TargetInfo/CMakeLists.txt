add_llvm_component_library(LLVMZazaInfo
  ZazaTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Zaza
  )