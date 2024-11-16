#include <string>
#include "libxvmins.hpp"
#include "../xos/lib/libxossc.hpp"

void XVM_INSTRUCTIONFUNC_NULL(xVM &vm) { vm.logger.log("NULL trigerred", vm.pc); }
void XVM_INSTRUCTIONFUNC_RESET(xVM &vm) {
  // Immediatly reset the VM
  // Set program counter to zero
  vm.logger.log("RESET triggered", vm.pc);
  vm.pc = 0;
  // Run the VM if its not running
  if (vm.running == 0)
    vm.running = 1;
}
void XVM_INSTRUCTIONFUNC_HALT(xVM &vm) {
  // Stop the VM
  vm.running = 0;
  vm.logger.log("HALT: execution halted", vm.pc);
}
void XVM_INSTRUCTIONFUNC_SET(xVM &vm) {
  // Write value vm.memory arg2 at adress arg1
  vm.memory[vm.memory[vm.pc + 1]] = vm.memory[vm.pc + 2];
  // Log: SET: set arg1 to arg2
  vm.logger.log(std::string("SET: set ").append(std::to_string(vm.memory[vm.pc + 1])).append(" to ").append(std::to_string(vm.memory[vm.pc + 2])), vm.pc);
  vm.pc += 2;
}
void XVM_INSTRUCTIONFUNC_JMP(xVM &vm) {
  // Set program counter to arg1
  vm.logger.log(std::string("Jump to ").append(std::to_string(vm.memory[vm.pc + 1])), vm.pc);
  vm.pc = vm.memory[vm.pc + 1];
}
void XVM_INSTRUCTIONFUNC_RSC(xVM &vm) {
  XOS_SYSCALLTABLE[vm.memory[vm.pc + 1]](vm);
}
XVM_INSTRUCTIONFUNC XVM_INSTRUCTIONTABLE[XVM_INSTRUCTIONTABLE_LENGTH] = {
  XVM_INSTRUCTIONFUNC_NULL,
  XVM_INSTRUCTIONFUNC_RESET,
  XVM_INSTRUCTIONFUNC_HALT,
  XVM_INSTRUCTIONFUNC_SET,
  XVM_INSTRUCTIONFUNC_JMP,
  XVM_INSTRUCTIONFUNC_RSC
}; 
