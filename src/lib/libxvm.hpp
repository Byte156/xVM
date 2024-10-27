#pragma once
#include "libxvmins.hpp" // For instructions
#include "libxvmlog.hpp" // For logs
#include <algorithm>     // For std::fill
#include <cstdint>       // For uint8_t
#include <fstream>       // For std::ifstream
#include <iostream>      // For std::cout
#include <sstream>       // For std::stringstream

class xVM {
public:
  xVM_log logger;           // System log
  size_t size_memory = 0;   // Memory size
  size_t size_reg_int = 0;  // Intenger registers counts
  size_t size_reg_char = 0; // Character registers count
  size_t pc = 0;            // Program counter
  bool running = false;     // Running flag

  // xVM constructor
  xVM(size_t mem_size = 128, size_t int_size = 32, size_t char_size = 32);

  // xVM destructor
  ~xVM();

  // Methods
  void interprent(uint8_t in); // Run an instruction
  void run(int startpos = 0);  // Boot the VM
  void dump();                 // Dump the memory
  void load(uint8_t app[], size_t len,
            size_t pos = 0); // Load a program into memory

  // Memory and registers
  uint8_t *memory; // Main memory for programs
  int *reg_int;    // Intenger registers
  char *reg_char;  // Character registers
};
