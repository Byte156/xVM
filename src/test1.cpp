#include <iostream>
#include "testcfg.hpp"
#include "lib/libxvm.hpp"

int main() {
  int status = 0;
  xVM vm;
  std::cout << "Checking memory integrity..."; // Just in case
  vm.memory[0x00] = 255;
  vm.memory[0x01] = 1;
  if (vm.memory[0] == 255 && vm.memory[1] == 1) {
    std::cout << "\033[92mok";
  } else {
    std::cout << "\033[91merror";
    status = 1;
  };
  std::cout << "\033[0m\nChecking set instruction...";
  vm.memory[0x00] = XVM_INSTRUCTION_SET; // Instruction
  vm.memory[0x01] = 0x04; // Place for number
  vm.memory[0x02] = 12; // Number
  vm.memory[0x03] = XVM_INSTRUCTION_HALT; // Exit the program safely
  vm.run(0);
  if (vm.memory[0x04] == 12) {
    std::cout << "\033[92mok";
  } else {
    std::cout << "\033[91merror";
    status = 1;
  }
  std::cout << "\033[0m\n";
  if (XVM_CFG_TEST_PRINTDUMP) vm.dump();
  return status;
}
