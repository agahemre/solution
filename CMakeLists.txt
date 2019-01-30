cmake_minimum_required(VERSION 3.6)

project(solution LANGUAGES CXX)

# Enable c++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
# set(COMPILE_FLAGS -Wall -Wextra)

set(SOURCE_FILES src/Definitions.h src/Solution.h src/Solution.cpp src/Driver.cpp src/gof.h)
add_executable(solution ${SOURCE_FILES})
