#include "libxvm.hpp"

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
xVM::~xVM() {
  // Free occupied memory
  delete[] memory;
  delete[] reg_int;
  delete[] reg_char;

  logger.log("xVM deinitialized");
}
void xVM::interprent(uint8_t in) {
  if (in < XVM_INSTRUCTIONTABLE_LENGTH) {
    XVM_INSTRUCTIONTABLE[in](*this);
  } else {
    std::stringstream ss;
    ss << "Invalid instruction: " << reinterpret_cast<char *>(in);
    logger.log(ss.str());
  }
}
void xVM::run(int startpos) {
  logger.log("Boot from memory at position " + std::to_string(startpos));
  pc = startpos;

  while (running && pc < size_memory) {
    interprent(memory[pc]);
    pc++;
  }
}
void xVM::load(uint8_t arr[], size_t len, size_t pos) {
  for (; pos < len; pos++) {
    memory[pos] = arr[pos];
    pos++;
    logger.log("Loaded " + std::to_string(arr[pos]) + " into " +
               std::to_string(pos));
  }
}
void xVM::dump() {
  for (size_t i = 0; i < 256; i++) {
    std::cout << unsigned(memory[i]) << " ";
  }
}
