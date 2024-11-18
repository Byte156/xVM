#include "lib/libxvm.hpp"
#include <cstring>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    xVM vm;
    vm.read(argv[1], 0);
    vm.run();
    if (argc > 2) {
      // Dump if asked
      if (strcmp(argv[2], "--dump") == 0 || strcmp(argv[2], "-d") == 0) {
        vm.dump();
      }
    }
  }
  return 0;
}
