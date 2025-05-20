// xVM DShell - Debug Shell

#include "dshell.hpp"
#include "util/to_hex.hpp"
#include "memdump.hpp"

void xVM_dsh_runcmd(xVM *vm) {
  std::string c;
  std::cout << "dsh> ";
  std::cin >> c;
  if (c == "s" || c == "stop") vm->running = 0;
  else if (c == "r"  || c == "reset" || c == "restart") vm->pc = 0;
  else if (c == "c"  || c == "continue")                vm->pc++;
  else if (c == "gt" || c == "go_to" || c == "goto") {
    std::cout << "dsh>goto/adress>";
    std::cin >> vm->pc;
  }
  else if (c == "d" || c == "dump" || c == "dmp")   {
    std::string c1;
    std::cout << "dump(r: registers, m: memory)>: ";
    std::cin >> c1;
    if (c1 == "r" || c1 == "regs" || c1 == "registers") {
      std::cout << "AR0: 0x" << to_hex(vm->ar0) << std::endl;
      std::cout << "AR1: 0x" << to_hex(vm->ar1) << std::endl;
      std::cout << "AR2: 0x" << to_hex(vm->ar2) << std::endl;
      std::cout << "GPR0: 0x" << to_hex(vm->gpr0) << std::endl;
      std::cout << "GPR1: 0x" << to_hex(vm->gpr1) << std::endl;
      std::cout << "GPR2: 0x" << to_hex(vm->gpr2) << std::endl;
      std::cout << "GPR3: 0x" << to_hex(vm->gpr3) << std::endl;
    } else if (c1 == "m" || c1 == "mem" || c1 == "memory") {
      xVM_memdump(vm);
    }
  }
}
