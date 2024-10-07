/* xVM boot programs */

#include "libxvmdata.h"


/* Write: strreg[0]: Press 1 to continue
 * Print:            strreg[0]
   Get character:    strreg[0]
 */

const uint8_t loadstr = XVM_INSTRUCTION_LOADSTR; /* Short for load string */
const uint8_t printstr = XVM_INSTRUCTION_PRINTSTR; /* Short fot print string */
const uint8_t getch = XVM_INSTRUCTION_GETCH; /* Short for get character */
const uint8_t halt = XVM_INSTRUCTION_HALT; /* Short for halt */
const uint8_t if_equ = XVM_INSTRUCTION_IF_EQU /* Short for if equals */

const uint8_t XVM_PROGRAM_BOOT_1[] = {
  loadstr, 0,
  'P','r','e','s','s',' ','1',' ','t','o',' ',
  'c','o','n','t','i','n','u','e','\n',0,
  printstr, 0,
  getch, 0,
  if_equ, 0, '1', 2,
  halt,
  print, 0,
  halt
};
