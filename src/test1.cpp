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
  vm.run(0x00);
  if (vm.memory[0x04] == 12) {
    std::cout << "\033[92mok";
  } else {
    std::cout << "\033[91merror";
    status = 1;
  }
  std::cout << "\033[0m\nChecking jmp instruction...";
  vm.memory[0x05] = XVM_INSTRUCTION_JMP;
  vm.memory[0x06] = 0x08;
  vm.memory[0x07] = XVM_INSTRUCTION_HALT;
  vm.memory[0x08] = 0;
  vm.memory[0x09] = XVM_INSTRUCTION_SET;
  vm.memory[0x0A] = 0x0C;
  vm.memory[0x0B] = 6;
  vm.memory[0x0C] = XVM_INSTRUCTION_HALT;
  vm.run(0x05);
  if (vm.memory[0x0C] == 6) {
    std::cout << "\033[92mok";
  } else {
    std::cout << "\033[91merror";
    status = 1;
  }
  std::cout << "\033[0m";
  if (XVM_CFG_TEST_PRINTDUMP && status != 0) vm.dump();
  return status;
}
