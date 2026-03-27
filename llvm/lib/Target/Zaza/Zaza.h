#ifndef LLVM_LIB_TARGET_ZAZA_TARGETINFO_ZAZA_H
#define LLVM_LIB_TARGET_ZAZA_TARGETINFO_ZAZA_H

#include "llvm/Support/raw_ostream.h"

#define ZAZA_DUMP(Color)                                                       \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ZAZA_DUMP(Color) {}

#define ZAZA_DUMP_RED     ZAZA_DUMP(llvm::raw_ostream::RED    )
#define ZAZA_DUMP_GREEN   ZAZA_DUMP(llvm::raw_ostream::GREEN  )
#define ZAZA_DUMP_YELLOW  ZAZA_DUMP(llvm::raw_ostream::YELLOW )
#define ZAZA_DUMP_CYAN    ZAZA_DUMP(llvm::raw_ostream::CYAN   )
#define ZAZA_DUMP_MAGENTA ZAZA_DUMP(llvm::raw_ostream::MAGENTA)

#endif