#include "lib/libxvm.hpp"

int main() {
  xVM vm;
  uint8_t boot[3] = {XVM_INSTRUCTION_SET, 10, 1};
  vm.load(boot, 3, 0);
  vm.run();
  vm.dump();
  return 0;
}
