#pragma once

#include "libxvm.hpp"

enum XVM_INSTRUCTION {
  XVM_INSTRUCTION_NULL,
  XVM_INSTRUCTION_SET,
  XVM_INSTRUCTION_LOADSTR,
  XVM_INSTRUCTION_PRINT
};
enum XVM_RUN_STATUS { XVM_RUN_STATUS_OK, XVM_RUN_STATUS_UNKNOWN };