#pragma once
#include "libxvmins.hpp" // For instructions
#include "libxvmlog.hpp" // For logs
#include <cstdint>       // For uint8_t

class xVM {
public:
  xVM_log logger;           // System log
  size_t size_memory = 0;   // Memory size
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
  void read(std::string path, uint8_t pos);

  // Memory and registers
  uint8_t *memory; // Main memory for programs
  uint8_t gpr0;    // General purpose register 0
  uint8_t gpr1;    // General purpose register 1
  uint8_t gpr2;    // General purpose register 2
  uint8_t gpr3;    // General purpose register 3
  uint8_t a;       // Accumulator register
};
