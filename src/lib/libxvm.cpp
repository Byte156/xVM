#include "libxvm.hpp"

// Constructor
xVM::xVM(size_t mem_size, size_t int_size, size_t char_size) {
	// Set up memory and registers
  memory = new uint8_t[mem_size];
  reg_int = new int[int_size];
  reg_char = new char[char_size];

  // Set size values of the class
  this->size_memory = mem_size;
  this->size_reg_int = int_size;
  this->size_reg_char = char_size;

  // Fill all the arrays with null (zeros)
  std::fill(memory, memory + size_memory, 0);
  std::fill(reg_int, reg_int + size_reg_int, 0);
  std::fill(reg_char, reg_char + size_reg_char, 0);

  logger.log("xVM initialized");
}

// Destructor
xVM::~xVM() {
	  // Free occupied memory
  delete[] memory;
  delete[] reg_int;
  delete[] reg_char;

  logger.log("xVM deinitialized");
}

// Interpreter method
void xVM::interprent(uint8_t in) {
	  switch (in) {
	    // TODO: implement instructions actually
  }
}

// Run method
void xVM::run(int startpos) {
	  logger.log("Boot from memory at position" + std::to_string(startpos));
  pc = startpos;

  while (running && pc < size_memory) {
	    interprent(memory[pc]);
    pc++;
  }
}
