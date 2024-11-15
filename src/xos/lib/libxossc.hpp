// xOS syscall library (libxossc)

#include "../../lib/libxvm.hpp"

enum XOS_SYSCALL {
  XOS_SYSCALL_EXIT,  // Exit the program
  XOS_SYSCALL_FLUSH, // Flush data from memory into a device
  XOS_SYSCALLTABLE_LENGTH
};

constexpr uint8_t XOS_SYSCALLARGS[XOS_SYSCALLTABLE_LENGTH] = {
  1, // EXIT
  1  // FLUSH
};

void XOS_SYSCALLFUNC_EXIT(xVM& vm);
void XOS_SYSCALLFUNC_FLUSH(xVM& vm);

typedef void (*XOS_SYSCALLFUNC)(xVM&);

extern XOS_SYSCALLFUNC XOS_SYSCALLTABLE[XOS_SYSCALLTABLE_LENGTH];
