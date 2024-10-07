/* Basic xVM instruction set
 */

#ifndef XVM_LIBXVMDATA
#define XVM_LIBXVMDATA

enum XVM_INSTRUCTION { /* xVM instruction numbers */
  XVM_INSTRUCTION_NULL,    /* Null instruction, used as separator to stop argument skipping */
  XVM_INSTRUCTION_HALT,    /* Halt instruction, quit current program and reset program counter to 0 */
  XVM_INSTRUCTION_LOAD,    /* Load instruction, load something into a register */
  XVM_INSTRUCTION_MOVE,    /* Move instruction, move something from a register to another position in that register */
  XVM_INSTRUCTION_DEL,     /* Delete instruction, delete something from memory (overwrite with \0 for char register and 0 with memory or int register) */
  XVM_INSTRUCTION_COPY,    /* Copy instruction, copy something in a register to another place in that or another register */
  XVM_INSTRUCTION_PRINT,   /* Print instruction, write a character from char register to screen */
  XVM_INSTRUCTION_ADD,     /* Add instruction, add two numbers in the int register */
  XVM_INSTRUCTION_SUBT,    /* Substract instruction, substract two numbers in the int register */
  XVM_INSTRUCTION_LOADSTR, /* Load string instruction, load a string into char register */
  XVM_INSTRUCTION_PRINTSTR,/* Print string instruction, same as print instruction, but print multiple characters (a string) */
  XVM_INSTRUCTION_GETCH,   /* Get key instruction, read a single character from standart input and then save it in a certain location in character register */
  XVM_INSTRUCTION_GOTO,    /* Go to instruction, set program counter to next argument (memory[pc + 1]) */
  XVM_INSTRUCTION_IF_EQU   /* If equals instruction, if value memory[pc + 1] in working register == memoey[pc + 2], then go memory[pc + 3] instructions up */
};
enum XVM_REGISTER { /* Register numbers */
  XVM_REGISTER_MEMORY, /* Program memory register */
  XVM_REGISTER_INTREG, /* Intenger register */
  XVM_REGISTER_STRREG  /* String/character register */
};
enum XVM_POSITION_INTREG {
  XVM_POSITION_INTREG_WORKINGREG = 60 /* Position of current working register value in intreg */
}
#endif
