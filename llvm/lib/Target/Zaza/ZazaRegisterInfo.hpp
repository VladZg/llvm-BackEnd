#pragma once

#define GET_REGINFO_HEADER
#include "ZazaGenRegisterInfo.inc"

namespace llvm {

struct ZazaRegisterInfo : public ZazaGenRegisterInfo {
public:
  ZazaRegisterInfo();
};

} // namespace llvm
