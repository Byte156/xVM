#include <sstream>
#include <iostream>
#include <iomanip>

inline std::string to_hex(uint8_t value) {
  std::stringstream ss;
  ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value);
  return ss.str();
}
