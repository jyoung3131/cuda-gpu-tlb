
#include <hip/hip_runtime.h>
#include <iostream>

// check Errors
#ifndef HIP_DISABLE_ERROR_CHECKING
#define CHECK_HIP(ans) check_hip((ans), "", #ans, __FILE__, __LINE__)
#define CHECK_LAST(msg) check_hip(hipGetLastError(), msg, "CHECK_LAST", __FILE__, __LINE__)
#else
#define CHECK_HIP(ans) {}
#define CHECK_LAST(msg) {}
#endif
inline
void check_hip(hipError_t code, const char* msg, const char *func, const char *file, int line) {
    if (code != hipSuccess) {
      std::cerr << "HIP error "
                << msg
                << ": " << hipGetErrorString(code)
                << "(" << code
                << ") " << file
                << ":" << line
                << " in " << func
                << "\n";
      exit(1);
    }
}
