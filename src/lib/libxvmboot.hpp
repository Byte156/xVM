/* xVM boot programs */

#include "libxvmdata.h"


/* Write strreg[0]: Press 1 to continue
 * Print:           strreg[0]
 */
const uint8_t XVM_PROGRAM_BOOT_1[] = {
  XVM_INSTRUCTION_LOADSTR, 0,
  'P','r','e','s','s',' ','1',' ','t','o',' ',
  'c','o','n','t','i','n','u','e','\n',0,
  XVM_INSTRUCTION_PRINTSTR, 0,
  XVM_INSTRUCTION_GETCH, 0,
  XVM_INSTRUCTION_HALT
};
