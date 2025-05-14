#pragma once
#include <cstdint>       // For uint8_t

class xVM {
public:
  // This is supposed to be 8-bit and the maximum number it knows is 256, you still can get more than 256 bytes of RAM but idk what can happen
  size_t size_memory = 256;   // Memory size
  size_t pc = 0;            // Program counter
  bool running = false;     // Running flag

  // Config
  bool verbose = false; // Verbose mode
  bool debug = false;   // Debug mode

  xVM(); // Constructor
  ~xVM(); // Destructor
  void run(uint8_t startpos /* Start position (e.g pc is gonna be set to this when run() is called */); // Start the vm

  // Memory and registers, all 8 bit here too so it doesnt take up too much RAM. I know that 300 bytes is nothing these days, but why would u need more?
  uint8_t *memory; // Main memory for programs
  uint8_t gpr0;    // General purpose register 0, used for storing stuff or output
  uint8_t gpr1;    // General purpose register 1, used for storing stuff or output
  uint8_t gpr2;    // General purpose register 2, used for storing stuff or output
  uint8_t gpr3;    // General purpose register 3, used for storing stuff or output
  uint8_t ar0;     // Argument register 0, stores args
  uint8_t ar1;     // Argument register 1, stores args
  uint8_t ar2;     // Argument register 2, stores args
  uint8_t a0;      // Accumulator register 0, can be used as a temp variable
  uint8_t a1;      // Accumulator register 1, can be used as a temp variable
};
