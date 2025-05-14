// xVM DShell - Debug Shell

#include "dshell.hpp"
#include "util/to_hex.hpp"

void xVM_dsh_runcmd(xVM *vm) {
  std::string c;
  std::cout << "Enter command: ";
  std::cin >> c;
  if (c == "s" || c == "stop") vm->running = 0;
  else if (c == "r"  || c == "reset" || c == "restart") vm->pc = 0;
  else if (c == "c"  || c == "continue")                vm->pc++;
  else if (c == "gt" || c == "go_to") {
    std::cout << "Enter adress:";
    std::cin >> vm->pc;
  }
  else if (c == "dr" || c == "rd" || c == "regdata" || c == "register_data" || c == "data_registers")   {
    std::cout << "AR0: 0x" << to_hex(vm->ar0) << std::endl;
    std::cout << "AR1: 0x" << to_hex(vm->ar1) << std::endl;
    std::cout << "AR2: 0x" << to_hex(vm->ar2) << std::endl;
    std::cout << "GPR0: 0x" << to_hex(vm->gpr0) << std::endl;
    std::cout << "GPR1: 0x" << to_hex(vm->gpr1) << std::endl;
    std::cout << "GPR2: 0x" << to_hex(vm->gpr2) << std::endl;
    std::cout << "GPR3: 0x" << to_hex(vm->gpr3) << std::endl;
  } 
}
