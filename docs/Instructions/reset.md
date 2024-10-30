## `RESET` instruction

`RESET` instruction is used to reset the VM to its default state, this **doesn't mean reboot**, so it doesn't clear the memory, but this means start execution all over again and run the VM if it was stopped using [`HALT`](./halt.md) instruction. Here's a code representation of what it does:
```cpp
vm.pc = 0;
if (!vm.running) vm.running = true;
```
