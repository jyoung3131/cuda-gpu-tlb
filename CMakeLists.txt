cmake_minimum_required (VERSION 3.10)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_COLOR_MAKEFILE ON)

# And optionally
#set(CMAKE_VERBOSE_MAKEFILE ON)

project(hip-tlb C CXX)

# Ensure we use C++11 support.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(HIP)



if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# set project build type
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
message(">> Setting up ${CMAKE_BUILD_TYPE} build")

if(HIP_FOUND)
    # We have HIP support.
    # Build the HIP versions of the benchmarks.
    message(STATUS "HIP support found at ${HIP_ROOT_DIR}.")
    
    set(CMAKE_CXX_COMPILER ${HIP_HIPCC_EXECUTABLE})
    #string(APPEND CMAKE_CXX_FLAGS ${CMAKE_HIP_FLAGS})
    string(APPEND CMAKE_CXX_FLAGS ${HIP_HIPCC_FLAGS})

    add_subdirectory(src)
else()
   message(STATUS "HIP support not found.")
endif()
