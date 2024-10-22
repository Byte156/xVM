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

    // Constructor
    xVM(size_t mem_size = 128, size_t int_size = 32, size_t char_size = 32);

    // Destructor
    ~xVM();

    // Methods
    void interprent(uint8_t in);
    void run(int startpos = 0);

    // Memory and registers
    uint8_t* memory;
    int* reg_int;
    char* reg_char;
};

#endif // XVM_LIBXVM
