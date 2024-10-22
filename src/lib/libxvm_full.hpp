#ifndef XVM_LIBXVM
#define XVM_LIBXVM
#include <iostream>
#include <algorithm>

#include "libxvmdata.hpp"
#include "libxvmlog.hpp"
#include "libxvmcfg.hpp"

class xVM {
  private:
    xVM_log log;
  public:
  size_t size_memory = 0;
  size_t size_reg_int = 0;
  size_t size_reg_char = 0;

  size_t pc = 0;

  bool running = false;
  
  xVM(size_t mem_size = 128, size_t int_size = 32, size_t char_size = 32) {
    /* Set up memory and registers */
  	memory = new uint8_t[mem_size];
  	reg_int = new int[int_size];
  	reg_char = new char[char_size];
  	/* Set size values of the class */
  	this->size_memory = mem_size;
  	this->size_reg_int = int_size;
  	this->size_reg_char = char_size;
  	/* Fill all the arrays with null (zeros) */
  	std::fill(memory, memory + size_memory, 0);
    std::fill(reg_int, reg_int + size_reg_int, 0);
  	std::fill(reg_char, reg_char + size_reg_char, 0);
  	log.log("xVM initialized");
  }
  void interprent(uint8_t in) {
  	switch (in) {
  	  /* TODO: interprent instructions actually */
  	}
  }
  void run(int startpos = 0) {
    log.log("Run from " + startpos);
    while (running && pc < size_memory) {
  	  interprent(memory[pc]);
      pc++;
  	}
  }
  ~xVM() {
    /* Free occupied memory */
  	delete[] memory;
  	delete[] reg_int;
  	delete [] reg_char;
  	log.log("xVM deinitialized");
  	if (XVM_CFG_DEBUG_PRINTLOGS) log.list();
  }
  uint8_t* memory; /* Main program memory */
  int* reg_int; /* Intenger registers */
  char* reg_char; /* Character registers */
};
#endif
