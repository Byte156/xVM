#include "libxvmins.hpp"

// Do nothing
void XVM_INSTRUCTIONFUNC_NULL(xVM &vm) { vm.logger.log("NULL trigerred"); }
/* Boot the VM from pc 0 if its not already running
 * else, just set pc to 0*/
void XVM_INSTRUCTIONFUNC_RESET(xVM &vm) {
  // Run the VM if its not running
  if (vm.running == 0)
    vm.running = 1;
  // Set program counter to 0
  vm.pc = 0;
}
// Stop execution of instructions
void XVM_INSTRUCTIONFUNC_HALT(xVM &vm) {
  // Stop the VM if its running
  if (vm.running == 1) vm.running = 0;
}
void XVM_INSTRUCTIONFUNC_SET(xVM &vm) {
  // Write value vm.memory[pc + 2] at position vm.memory[vm.pc + 1]
  vm.memory[vm.memory[vm.pc + 1]] = vm.memory[vm.pc + 2];
  std::stringstream ss;
  ss << "SET: set " << reinterpret_cast<char *>(vm.memory[vm.pc + 1]) << " to "
     << reinterpret_cast<char *>(vm.memory[vm.pc + 2]);
  vm.logger.log(ss.str());
}

XVM_INSTRUCTIONFUNC XVM_INSTRUCTIONTABLE[XVM_INSTRUCTIONTABLE_LENGTH] = {
    XVM_INSTRUCTIONFUNC_NULL, XVM_INSTRUCTIONFUNC_RESET,
    XVM_INSTRUCTIONFUNC_HALT, XVM_INSTRUCTIONFUNC_SET};
