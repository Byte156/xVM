#include "libxvm.hpp"
#include <iostream>      // For std::cout
#include <fstream> 
#include <algorithm>    // For std::fill
#include <string>       // For std::stringstream
#include "../xos/lib/libxossc.hpp"

xVM::xVM(size_t mem_size, size_t int_size, size_t char_size) {
  // Set up memory and registers
  memory = new uint8_t[mem_size];

  // Set size values of the class
  this->size_memory = mem_size;


  std::fill(memory, memory + size_memory, 0);
  logger.log(std::string("Mapped ").append(std::to_string(this->size_memory)).append(" bytes of memory"), pc);
  logger.log("xVM initialized", pc);
}
xVM::~xVM() {
  // Free occupied memory
  delete[] memory;
  delete[] reg_char;

  logger.log("xVM deinitialized", pc);
}
void xVM::interprent(uint8_t in) {
  if (in < XVM_INSTRUCTIONTABLE_LENGTH) {
    logger.log(std::string("Ins: ").append(std::to_string(in)), pc);
    XVM_INSTRUCTIONTABLE[in](*this);
  } else {
    logger.log(std::string("Illegal instruction ").append(std::to_string(in)), pc);
  }
}
void xVM::run(int startpos) {
  logger.log("Boot from memory at position " + std::to_string(startpos), pc);
  pc = startpos;
  running = 1; 

  while (running && pc < size_memory) {
    interprent(memory[pc]);
    if (memory[pc] != XVM_INSTRUCTION_RESET && memory[pc] != XVM_INSTRUCTION_HALT) pc++;
  }
}
void xVM::load(uint8_t arr[], size_t len, size_t pos) {
  for (; pos < len; pos++) {
    memory[pos] = arr[pos];
    pos++;
    logger.log("Loaded " + std::to_string(arr[pos]) + " into " +
               std::to_string(pos), pc);
  }
}
void xVM::dump() {
  logger.log("Memory dump to initialized", pc);
  for (size_t i = 0; i < 256; i++) {
    std::cout << unsigned(memory[i]) << " ";
  }
}
void xVM::read(std::string path, uint8_t pos) {
  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    logger.log(std::string("read: Couldn't open ").append(path), pc);
    return;
  }
  char ch;
  while (file.get(ch)) {
    uint8_t byte = static_cast<uint8_t>(ch);
    memory[pos] = byte;
    pos++;
  }
  logger.log(std::string("read: Wrote ").append(path).append(" to memory"), pc);
}
