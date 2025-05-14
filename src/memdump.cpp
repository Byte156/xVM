#include "memdump.hpp"
#include "util/to_hex.hpp"
#include <iostream>

void xVM_memdump(xVM* vm) {
  for (size_t i = 0; i < vm->size_memory; i++) {
    std::cout << "0x" << to_hex(vm->memory[i], 2) << " ";
  }
}
