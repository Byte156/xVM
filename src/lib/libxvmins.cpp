#include <string>
#include "libxvmins.hpp"

void XVM_INSTRUCTIONFUNC_NULL(xVM &vm) { vm.logger.log("NULL trigerred"); }
void XVM_INSTRUCTIONFUNC_RESET(xVM &vm) {
  // Run the VM if its not running
  if (vm.running == 0)
    vm.running = 1;
  // Set program counter to 0
  vm.pc = 0;
}
void XVM_INSTRUCTIONFUNC_HALT(xVM &vm) {
  // Stop the VM if its running
  if (vm.running == 1) vm.running = 0;
  vm.logger.log("HALT: execution halted");
}
void XVM_INSTRUCTIONFUNC_SET(xVM &vm) {
  // Write value vm.memory arg2 at adress arg1
  vm.memory[vm.memory[vm.pc + 1]] = vm.memory[vm.pc + 2];
  // Log: SET: set arg1 to arg2
  vm.logger.log(std::string("SET: set ").append(std::to_string(vm.memory[vm.pc + 1])).append(" to ").append(std::to_string(vm.memory[vm.pc + 2])));
}
void XVM_INSTRUCTIONFUNC_JMP(xVM &vm) {
  // Set program counter to arg1
  vm.pc = vm.memory[vm.pc + 1];
  vm.pc++;
}
XVM_INSTRUCTIONFUNC XVM_INSTRUCTIONTABLE[XVM_INSTRUCTIONTABLE_LENGTH] = {
  XVM_INSTRUCTIONFUNC_NULL,
  XVM_INSTRUCTIONFUNC_RESET,
  XVM_INSTRUCTIONFUNC_HALT,
  XVM_INSTRUCTIONFUNC_SET
}; 
