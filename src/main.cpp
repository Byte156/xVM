#include <iostream>
#include <fstream>
#include <string>
#include "main.hpp"
#include "instructions.hpp"
#include "exec.hpp"
#include "util/check_arr.hpp"
#include "util/logs.hpp"
#include "dshell.hpp"

xVM::xVM() {
  // Map the memory
  memory = new uint8_t[size_memory];
  std::memset(memory, 0, size_memory); 
}
xVM::~xVM() {
  delete[] memory;
}
void xVM::run(uint8_t startpos) {
  log_debug("VM started with size_memory=" + std::to_string(size_memory) + " bytes\n", debug);
  pc = startpos;
  running = 1;
  while (running) {
    if (pc > size_memory) {running = false;}
    if (memory[pc] == xVM_INSTRUCTION_HALT) {running = 0;}
    if (memory[pc] == xVM_INSTRUCTION_RESET) pc = 0;
    xVM_exec(this);
    if (!debug)pc++;
    if (debug) {
       xVM_dsh_runcmd(this);
    }
  }
  log_debug("VM stopped with pc=0x" + to_hex(pc) + "\n", debug);
  // This snippet is not working for some reason, it worked fine in v.0.02.0 Alpha
  // Dump the memory to the console
  log_debug("Memory dump:", debug);
  if (debug) {
    for (size_t i = 0; i < size_memory; i++) {
      std::cout << unsigned(memory[i]) << " ";
    }
  }
}

int main(int argc, char* argv[]) {
  std::cout << "xVM v.1.0.0 Alpha" << std::endl;

  // Check if file exists
  if (argc < 2) {
    std::cerr << "\033[31m\033[1mError\033[0m: no file supplied" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1], std::ios::binary);
  if (!file) {
    std::cerr << "\033[31m\033[1mError\033[0m: " << std::string(argv[2]) << ": couldn't open file'";
    return 1;
  }
  // Initialize the VM
  xVM vm;

  // Check for flags
  if (check_arr_str(argv, std::string("-v").c_str(), argc) || check_arr_str(argv, std::string("--verbose").c_str(), argc)) vm.verbose = true; // Enable verbose mode
  if (check_arr_str(argv, std::string("--debug").c_str(), argc)) {
    vm.debug = true; // Enable debug mode
    vm.verbose = true; // Enable verbose mode
    // Verbose is enabled automatically when debug is enabled
    // Debug mode wont slow the execution down, probably
    std::cout << "\033[1m\033[36mDebug mode is enabled\n\033[0m" << std::endl;
  }

  // Read file into the memory
  file.read(reinterpret_cast<char*>(vm.memory), sizeof(vm.memory));

  // Start the VM
  vm.run(0x00);

  return 0;
}
