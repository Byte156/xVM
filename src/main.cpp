#include <iostream>
#include "lib/libvm.hpp"
#include "lib/libxvmboot.hpp"

int main(int argc, char *argv[]) {
  VM vm;
  vm.writearr_mem(0, XVM_PROGRAM_BOOT_1);
  vm.boot();
  return 0;
}
