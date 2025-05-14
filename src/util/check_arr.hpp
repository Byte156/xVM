#include <cstring> // For strcmp

// Check if str is in arr
inline bool check_arr_str(char* arr[], const char* str, int c) {
  bool result = false;
  for (int i = 0;i < c;i++) {
    if (strcmp(arr[i], str) == 0) result = true; 
  }
  return result;
}
