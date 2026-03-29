add_llvm_component_library(LLVMZazaDesc
  ZazaMCTargetDesc.cpp
  ZazaMCAsmInfo.cpp
  ZazaInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  ZazaInfo

  ADD_TO_COMPONENT
  Zaza
 )