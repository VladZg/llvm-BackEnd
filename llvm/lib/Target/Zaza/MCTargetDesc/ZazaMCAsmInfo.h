#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class ZazaELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit ZazaELFMCAsmInfo(const Triple &TheTriple);
};

} // namespace llvm