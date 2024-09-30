#ifndef XVM_LIBVM
#define XVM_LIBVM

#include <iostream>

#include "libxvmdata.h"

class VM {
  public:
    int size_mem; /* Memory size */
    int size_intreg; /* Intenger register size */
    int size_strreg; /*  String/character register size*/
    int pc = 0; /* Program counter */
    bool running = 0; /* Running flag */
    VM(int sm = 128, int si = 32, int ss = 64) {
      this->size_mem = sm;
      this->size_intreg = si;
      this->size_strreg = ss;
      /* Redeclare registers with specified size */
      memory = new int[sm];
      intreg = new int[si];
      strreg = new char[ss];
      /* Fill the registers with zeros */
      for (int i = 0; i < sm; ++i) {
        memory[i] = 0;
      }
      for (int i = 0; i < si; ++i) {
        intreg[i] = 0;
      }
      for (int i = 0; i < ss; ++i) {
        strreg[i] = 0;
      }
    }
    void boot() {
      int ins; /* Current instruction */
      running = 1;
      while (pc < size_mem) {
        ins = memory[pc];
        switch (ins) {
          case XVM_INSTRUCTION_NULL:
            break;
          case XVM_INSTRUCTION_HALT:
            pc = 0;
            std::cout << "exit";
            return;
            break;
          case XVM_INSTRUCTION_LOAD:
            strreg[memory[pc + 1]] = memory[pc + 2];
            pc =+ 2;
            break;
          case XVM_INSTRUCTION_PRINT:
            std::cout << strreg[memory[pc + 1]];
            pc++;
            break;
          default:
            break;
        }
        pc++;
      }
    }
    ~VM() {
      /* Free the memory */
      delete[] memory;
      delete[] intreg;
      delete[] strreg;
    }
    int *memory; /* Program memory */
    int *intreg; /* Intenger register */
    char *strreg; /* String/character register */
};
#endif
