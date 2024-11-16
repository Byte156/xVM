#include "libxossc.hpp"

void XOS_SYSCALLFUNC_EXIT(xVM& vm) {
  // This 
  // PC is currently at the syscall ins
  // so the args are vm.memory[vm.pc + arg_num]
  // well, same as halt, for now, just set the exit code

  vm.gpr0 = vm.memory[vm.pc + 1];
  vm.running = 0;
}
void XOS_SYSCALLFUNC_FLUSH(xVM& vm) {
  // Not implemented yet
}
XOS_SYSCALLFUNC XOS_SYSCALLTABLE[XOS_SYSCALLTABLE_LENGTH] = {
  XOS_SYSCALLFUNC_EXIT,
  XOS_SYSCALLFUNC_FLUSH
};
