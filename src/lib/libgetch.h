#ifndef XVM_LIBGETCH
#define XVM_LIBGETCH
#include <iostream>
#include <termios.h>
#include <unistd.h>

char getch() {
  char buf = 0;
  struct termios old = {0};
  /* Get current terminal settings */
  tcgetattr(0, &old);
  old.c_lflag &= ~ICANON; /* Disable canonical mode */
  old.c_lflag &= ~ECHO;   /* Disable echo */
  tcsetattr(0, TCSANOW, &old); /* Apply changes */
  /* Read a single character */
  read(0, &buf, 1);
  /* Restore old terminal settings */
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  tcsetattr(0, TCSADRAIN, &old);
  return buf; /* Return the character read */
}
#endif
