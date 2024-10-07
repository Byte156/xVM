/* xVM boot programs */

#ifndef XVM_LIBXVMBOOT
#define XVM_LIBXVMBOOT

#include "libxvmdata.h"

using namespace XVM_ALIASES;  

/* Write: strreg[0]: Press 1 to continue
 * Print:            strreg[0]
   Get character
 */

const uint8_t XVM_PROGRAM_BOOT_1[] = {
  loadstr, 0,
  'P','r','e','s','s',' ','1',' ','t','o',' ',
  'c','o','n','t','i','n','u','e','\n',0,
  print, 0,
  getch_,
  if_equ, 
};
#endif