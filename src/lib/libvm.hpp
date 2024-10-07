#ifndef XVM_LIBVM
#define XVM_LIBVM

#include <iostream>
#include <fstream>

#include "libxvmdata.h"
#include "libxvmcfg.h"
#include "libgetch.h"

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
      if (XVM_CFG_VMDEBUG_SHOWWRITELOGS) std::cout << "[VM] Wrote " << unsigned(data) << " to position " << pos << std::endl;
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
            pc = 0;
            return;
          case XVM_INSTRUCTION_LOAD:
            if (XVM_CFG_VMDEBUG_SHOWCASEINSTRUCTION) std::cout << "[xVM][Debug] pc=" << pc << ", ins=" << "LOAD" << std::endl;
            switch (memory[pc + 1]) {
              case XVM_REGISTER_STRREG:
                strreg[memory[pc + 2]] = memory[pc + 3];
                pc += 3;
                break;
              case XVM_REGISTER_MEMORY:
                memory[memory[pc + 2]] = memory[pc + 3];
                pc += 3;
                break;
              case XVM_REGISTER_INTREG:
                intreg[memory[pc + 2]] = memory[pc + 3];
                pc += 3;
                break;
            }
            break;
          case XVM_INSTRUCTION_MOVE:
            switch (memory[pc + 1]) {
              case XVM_REGISTER_MEMORY:
                /* memory[pc + 2] is what to move
                 * memory[pc + 3] is where to move */
                memory[memory[pc + 3]] = memory[memory[pc + 2]]; /* Copy it */
                memory[pc + 2] = 0; /* Set to null */
                break;
              case XVM_REGISTER_INTREG:
                intreg[memory[pc + 3]] = intreg[memory[pc + 2]]; /* Copy it */
                intreg[pc + 2] = 0; /* Set to null */
                break;
              case XVM_REGISTER_STRREG:
                strreg[memory[pc + 3]] = strreg[memory[pc + 2]]; /* Copy it */
                strreg[pc + 2] = 0; /* Set to null */
            }
            break;
          case XVM_INSTRUCTION_PRINT:
            std::cout << strreg[memory[pc + 1]];
            pc++;
            break;
          case XVM_INSTRUCTION_LOADSTR:
            len = 0; /* String lenth */
            pos = 0; /* Current position in string register */
            for (int i = 0; i < size_mem; i++) {
              if (memory[pc + 2 + i] == 0) {
                strreg[pos] = 0;
                break;
              } else {
                strreg[pos] = memory[pc + 2 + i];
              }
              len++;
              pos++;
            }
            pc += len + 1;
            break;
          case XVM_INSTRUCTION_PRINTSTR:
            for (int i = 0; i < size_strreg; i++) {
              if (strreg[i] == 0) {break;} else {
                std::cout << strreg[i];
              }
            }
            break;
          case XVM_INSTRUCTION_GETCH:
            strreg[memory[pc + 1]] = getch();
            pc++;
            break;
          case XVM_INSTRUCTION_GOTO:
            pc = memory[pc + 1];
            break;
          case XVM_INSTRUCTION_IF:
            switch (memory[pc + 1]) {
              default:
                if (XVM_CFG_VMLOGS_SHOWERRORS) std::cout << "[xVM][Error] Runtime error at position " << pc << ": if: unknown register";
                break;
            }
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
    uint8_t *memory; /* Program memory */
    int *intreg; /* Intenger register */
    char *strreg; /* String/character register */
};
#endif
