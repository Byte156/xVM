#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>

inline std::string to_hex(uint8_t value, size_t digits = 2) {
  std::stringstream ss;
  ss << std::hex << std::setw(digits) << std::setfill('0') << static_cast<int>(value);
  return ss.str();
}
