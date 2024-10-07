#ifndef XVM_LIBVM
#define XVM_LIBVM

#include <iostream>
#include <fstream>

#include "libxvmdata.h"
#include "libxvmcfg.h"
#include "libgetch.h"

class xVM {
  public:
    int size_mem; /* Memory size */
    int size_intreg; /* Intenger register size */
    int size_strreg; /*  String/character register size*/
    int pc = 0; /* Program counter */

    bool running = 0; /* Running flag */

    xVM(int sm = 128, int si = 32, int ss = 64, uint8_t mpd = 64) {
      this->size_mem = sm;
      this->size_intreg = si;
      this->size_strreg = ss;
      /* Redeclare registers with specified size */
      memory = new uint8_t[sm];
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
    void write_mem(int pos, uint8_t data) {
      memory[pos] = data;
      if (XVM_CFG_VMDEBUG_SHOWWRITELOGS) std::cout << "[VM][Debug] Wrote " << unsigned(data) << " to position " << pos << " in memory" << std::endl;
    }
    void write_intreg(int pos, int data) {
      intreg[pos] = data;
      if (XVM_CFG_VMDEBUG_SHOWWRITELOGS) std::cout << "[VM][Debug] Wrote " << unsigned(data) << " to position " << pos << " in intreg" << std::endl;
    }
    void writearr_mem(int pos, const uint8_t data[]) {
      int datai = 0;
      for (int i = pos; i < size_mem; i++) {
        write_mem(i, data[datai]);
        datai++;
      }
    }
    void debug_printmem() {
      std::cout << "Memory: " << std::endl;
      for (int i = 0; i < size_mem; i++) {
        std::cout << "[" << i << "] " << memory[i] << std::endl;
      }
    }
    void boot() {
      pc = 0; /* Reset */
      int ins = 0; /* Current instruction */
      int len = 0; /* For LOADSTR */
      int pos; /* For LOADSTR */
      /* Set up variables */
      write_intreg(XVM_POSITION_MEMORY_WORKINGREG, XVM_REGISTER_MEMORY);
      running = 1;
      while (pc < size_mem && running) {
        if (XVM_CFG_VMDEBUG_SHOWINSTRUCTION) std::cout << "[xVM][Debug] pc=" << pc << ", ins=" << ins << std::endl;
        ins = memory[pc];
        switch (ins) {
          case XVM_INSTRUCTION_NULL:
            if (XVM_CFG_VMDEBUG_SHOWCASEINSTRUCTION) std::cout << "[xVM][Debug] pc=" << pc << ", ins=" << "NULL" << std::endl;
            break;
          case XVM_INSTRUCTION_HALT:
            if (XVM_CFG_VMDEBUG_SHOWCASEINSTRUCTION) std::cout << "[xVM][Debug] pc=" << pc << ", ins=" << "HALT" << std::endl;
            running = 0;
            break;
          case XVM_INSTRUCTION_SET:
            write_mem(memory[pc++], memory[pc + 2]);
            pc += 2;
            break;

          default:
            break;
        }
        pc++;
      }
    }
    ~xVM() {
      /* Free the memory */
      delete[] memory;
      delete[] intreg;
      delete[] strreg;
    }
    uint8_t *memory; /* Program memory */
    int *intreg; /* Intenger register */
    char *strreg; /* String/character register */
};
#endif
