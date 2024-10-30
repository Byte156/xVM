## `RESET` instruction

Opcode: `0x01`

`RESET` instruction is used to reset the VM to its default state, this **doesn't mean reboot**, so it doesn't clear the memory, but this means start execution all over again and run the VM if it was stopped using [`HALT`](./halt.md) instruction.
