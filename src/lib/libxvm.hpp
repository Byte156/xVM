#ifndef XVM_LIBXVM
#define XVM_LIBXVM

#include <iostream>
#include <algorithm> // For std::fill
#include <cstdint> // For uint8_t
#include <fstream> // For std::ifstream
#include "libxvmdata.hpp" // For instructions
#include "libxvmlog.hpp" // For logs
#include "libxvmcfg.hpp" // For config

class xVM {
	private:
    xVM_log log; // System log

  public:
    size_t size_memory = 0; // Memory size
    size_t size_reg_int = 0; // Intenger registers counts
    size_t size_reg_char = 0; // Character registers count
    size_t pc = 0; // Program counter
    bool running = false; // Running flag

    // xVM constructor
    xVM(size_t mem_size = 128, size_t int_size = 32, size_t char_size = 32);

    // xVM destructor
    ~xVM();

    // Methods
    void interprent(uint8_t in); // Run an instruction
    void run(int startpos = 0); // Boot the VM

    // Memory and registers
    uint8_t* memory; // Main memory for programs
    int* reg_int; // Intenger registers
    char* reg_char; // Character registers
};

#endif // XVM_LIBXVM
