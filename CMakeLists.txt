cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_FILES src/Definitions.h src/Solution.h src/Solution.cpp src/Driver.cpp)
add_executable(solution ${SOURCE_FILES})