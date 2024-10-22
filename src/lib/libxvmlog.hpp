#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class xVM_log {
	  public:
    xVM_log() {
	      createLogFile();
    }

    void log(const std::string& message) {
	      std::ofstream outfile(logFilePath, std::ios_base::app);
      if (outfile.is_open()) {
	        outfile << "[" << currentDateTime("%H%M%S") << "] " << message << std::endl;
      }
    }

  private:
    std::string logFilePath;

    void createLogFile() {
	      std::string datetime = currentDateTime("%H%M%S");
      logFilePath = "log/" + datetime + ".log";
      std::ofstream outfile(logFilePath);
      if (outfile.is_open()) {
	        outfile << "[" << datetime << "] Log start" << std::endl;
      }
    }

    std::string currentDateTime(const std::string& format = "%Y%m%d%H%M%S") {
	      std::time_t now = std::time(nullptr);
      char buf[80];
      std::strftime(buf, sizeof(buf), format.c_str(), std::localtime(&now));
      return std::string(buf);
    }
};
