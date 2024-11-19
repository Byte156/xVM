#pragma once

class xVM;

#include "libxvm.hpp"

// Instruction list
enum XVM_INSTRUCTION {
  XVM_INSTRUCTION_NULL,       // Do nothing
  XVM_INSTRUCTION_RESET,      // Reset the VM to its default state
  XVM_INSTRUCTION_HALT,       // Stop execution of instructions
  XVM_INSTRUCTION_SET,        // Write a intermidate value into memory
  XVM_INSTRUCTION_JMP,        // Set the program counter, useful for creating loops
  XVM_INSTRUCTION_RSC,        // Run a syscall
  XVM_INSTRUCTION_STORE,      // Move a value from memory to a register
  XVM_INSTRUCTIONTABLE_LENGTH // Instruction table length, not an instruction
};
// Register list (see src/lib/libxvm.hpp line 27 for register comments)
enum XVM_REGISTER {
  XVM_REGISTER_MEMORY,
  XVM_REGISTER_GPR0,
  XVM_REGISTER_GPR1,
  XVM_REGISTER_GPR2,
  XVM_REGISTER_GPR3,
  XVM_REGISTER_AR0,
  XVM_REGISTER_AR1,
  XVM_REGISTER_AR2,
  XVM_REGISTER_A
};
// Special adresses
enum XVM_ADRESS {
  XVM_ADRESS_STDOUT_BUFFER_BEGIN = 0xF0, // stdout buffer beginning adress
  XVM_ADRESS_STDOUT_BUFFER_END = 0xFF   // stdout buffer end adress
};

void XVM_INSTRUCTIONFUNC_NULL(xVM &vm);
void XVM_INSTRUCTIONFUNC_RESET(xVM &vm);
void XVM_INSTRUCTIONFUNC_HALT(xVM &vm);
void XVM_INSTRUCTIONFUNC_SET(xVM &vm);
void XVM_INSTRUCTIONFUNC_JMP(xVM &vm);
void XVM_INSTRUCTIONFUNC_RSC(xVM &vm);

// xVM instruction data type
typedef void (*XVM_INSTRUCTIONFUNC)(xVM &);

// xVM instruction table
extern XVM_INSTRUCTIONFUNC XVM_INSTRUCTIONTABLE[XVM_INSTRUCTIONTABLE_LENGTH];
