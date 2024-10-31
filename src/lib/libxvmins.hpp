#pragma once

class xVM;

#include "libxvm.hpp"

// Instruction list
enum XVM_INSTRUCTION {
  XVM_INSTRUCTION_NULL,       // Do nothing
  XVM_INSTRUCTION_RESET,      // Reset the VM to its default state
  XVM_INSTRUCTION_HALT,       // Stop execution of instructions
  XVM_INSTRUCTION_SET,        // Write a intermidate value into memory
  XVM_INSTRUCTIONTABLE_LENGTH // Instruction table length, not an instruction
};
// Register list
enum XVM_REGISTER {
  XVM_REGISTER_MEMORY, // Main memory        (uint8_t)
  XVM_REGISTER_NUM,    // Number register    (uint8_t)
  XVM_REGISTER_CHAR    // Character register (char)
};

void XVM_INSTRUCTIONFUNC_NULL(xVM &vm);
void XVM_INSTRUCTIONFUNC_SET(xVM &vm);
void XVM_INSTRUCTIONFUNC_RESET(xVM &vm);
void XVM_INSTRUCTIONFUNC_HALT(xVM &vm);
void XVM_INSTRUCTIONFUNC_SET(xVM &vm);

// xVM instruction data type
typedef void (*XVM_INSTRUCTIONFUNC)(xVM &);

// xVM instruction table
extern XVM_INSTRUCTIONFUNC XVM_INSTRUCTIONTABLE[XVM_INSTRUCTIONTABLE_LENGTH];
