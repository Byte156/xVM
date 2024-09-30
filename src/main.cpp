#include <iostream>
#include "lib/libvm.hpp"
#include "lib/libxvmdata.h" 
#include "lib/libxvmcfg.h"

int main(int argc, char *argv[]) {
  VM vm;
  std::string input;
  if (XVM_CFG_PREBOOT_SHOWLOGS) std::cout << "Writing bootloader to memory...";
  vm.memory[0] = XVM_INSTRUCTION_LOAD;
  if (XVM_CFG_PREBOOT_SHOWWRITELOGS) std::cout << "Loaded " << XVM_INSTRUCTION_LOAD << std::endl;
  vm.memory[1] = 0;
  if (XVM_CFG_PREBOOT_SHOWWRITELOGS) std::cout << "Loaded " << 0 << std::endl;
  vm.memory[2] = 65;
  if (XVM_CFG_PREBOOT_SHOWWRITELOGS) std::cout << "Loaded " << 65 << std::endl;
  vm.memory[3] = XVM_INSTRUCTION_PRINT;
  if (XVM_CFG_PREBOOT_SHOWWRITELOGS) std::cout << "Loaded " << XVM_INSTRUCTION_PRINT;
  vm.memory[4] = 0;
  if (XVM_CFG_PREBOOT_SHOWWRITELOGS) std::cout << "Loaded " << 0 << std::endl;
  if (XVM_CFG_PREBOOT_SHOWLOGS) std::cout << "Success! Booting...";
  vm.boot();
  std::cin >> input;
  return 0;
}