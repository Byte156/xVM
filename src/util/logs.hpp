#pragma once

#include <iostream>

// Made for writing logs easier
inline void log_debug(const std::string msg, bool debug = false) {
  if (debug) std::cout << "\033[1m\033[36mDebug\033[0m: " << msg;
}
