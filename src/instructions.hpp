#pragma once

// Every xVM instruction, defined in a enum so you can access the instructions by their names (not by these crazy hex numbers)
enum xVM_INSTRUCTIONS {
  xVM_INSTRUCTION_NULL,  // Do nothing, relax
  xVM_INSTRUCTION_RESET, // Reset the pc to 0x00
  xVM_INSTRUCTION_HALT,  // Stop the execution
  xVM_INSTRUCTION_LOAD,  // Set [register] to ar1
  xVM_INSTRUCTION_GOTO   // Set pc to ar1
};
