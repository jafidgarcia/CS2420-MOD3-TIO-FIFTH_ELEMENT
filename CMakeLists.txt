# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(LinkedListProject)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)

# Adding the executable (test file)
add_executable(FifthElementTester main.cpp LinkedList.cpp FifthElement.cpp)

# Include directories for header files
target_include_directories(FifthElementTester PUBLIC ./)
