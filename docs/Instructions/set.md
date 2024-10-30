## `SET` instruction

Opcode: `0x03`

Set `arg 1` to `arg 2`. This means load an intermediate value into memory at a specific adress.

Usage:
```
0x03 [adress] [value]
```
Examples:

Set `12` to adress `0x0A`:
```
 0x03 0x0A 12
```
