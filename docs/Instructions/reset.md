## `RESET` instruction

Opcode: `0x01`

`RESET` the VM to it's default state. This **doesn't mean reboot**, so it doesn't clear the memory, but this means start execution all over again and run the VM if it was stopped using [`HALT`](./halt.md) instruction.
