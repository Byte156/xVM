#include <iostream>
#include "lib/libxvm.hpp"
#include "lib/libxvmboot.hpp"

int main(int argc, char *argv[]) {
  xVM vm;
  vm.writearr_mem(0, XVM_PROGRAM_BOOT_1);
  vm.boot();
  return 0;
}
