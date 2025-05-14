#pragma once

#include "main.hpp"
#include "instructions.hpp"
#include "regs.hpp"
#include "util/to_hex.hpp"
#include "util/logs.hpp"
#include <iostream>

// This is so big so I put it into another file
inline void xVM_exec(xVM* vm) {
  if (vm -> verbose) std::cout << "\033[34m[0x" << to_hex(vm -> pc) << "]\033[0m \033[32m0x" << to_hex(vm -> memory[vm -> pc]) << "\033[0m" << std::endl;
  switch (vm -> memory[vm -> pc]) {
    case xVM_INSTRUCTION_NULL:
      break;
    case xVM_INSTRUCTION_RESET:
      vm -> pc = 0x00;
      break;
    case xVM_INSTRUCTION_HALT:
      // Doing nothing since break from the execution loop if halt called is already written in main.cpp
      break;
    case xVM_INSTRUCTION_LOAD:
      vm -> a0 = vm -> memory[vm -> pc + 1];  // The register to load into
      vm -> a1 = vm -> memory[vm -> pc + 2]; // The thing that we want to load
      if (vm -> a0 == xVM_REGISTER_AR0)       vm -> ar0 = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_AR1)  vm -> ar1  = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_AR2)  vm -> ar2  = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_GPR0) vm -> gpr0 = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_GPR1) vm -> gpr1 = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_GPR2) vm -> gpr2 = vm -> a1;
      else if (vm -> a0 == xVM_REGISTER_GPR3) vm -> gpr3 = vm -> a1;
      log_debug("Loaded 0x" + to_hex(vm -> a1) + " into register 0x" + to_hex(vm -> a0), vm -> debug);
      vm -> pc += 2;
      break;
    case xVM_INSTRUCTION_GOTO:
      vm -> pc = vm -> ar0;
      break;
  }
}
