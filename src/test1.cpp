#include <iostream>
#include "lib/libxvm.hpp"

int main() {
  xVM vm;
  std::cout << "Checking memory integrity..."; // Just in case
  vm.memory[0x00] = 255;
  vm.memory[0x01] = 1;
  std::cout << ((vm.memory[0] == 255 && vm.memory[1] == 1) ? "\033[92mok" : "\033[91merror");
  std::cout << "\033[0m\nChecking set instruction...";
  vm.memory[0x00] = XVM_INSTRUCTION_SET; // Instruction
  vm.memory[0x01] = 0x04; // Place for number (10)
  vm.memory[0x02] = 12; // Number
  vm.memory[0x03] = XVM_INSTRUCTION_HALT; // Exit the program safely
  vm.run(0);
  std::cout << ((vm.memory[0x04] == 12) ? "\033[92mok" : "\033[91merror") << "\033[0m";
}
