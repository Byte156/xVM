#ifndef XVM_LIBLOG
#define XVM_LIBLOG
#include <iostream>
#include <vector>

class xVM_log {
  private:
    std::vector<std::string> logs; /* Logs xontainer */
  public:
    /* Log something */
    void log(const std::string txt) {
      logs.push_back(txt);
    }
    /* Print all logs */
    void list() {
      size_t i = 0;
      for (const std::string txt : logs) {
      	std::cout << "[" << i << "] " << txt << std::endl;
      	i++;
      }
    }
};
#endif
