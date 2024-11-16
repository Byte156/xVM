#include "lib/libxvm.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    xVM vm;
    vm.read(argv[1], 0);
    vm.run();
  }
  return 0;
}
