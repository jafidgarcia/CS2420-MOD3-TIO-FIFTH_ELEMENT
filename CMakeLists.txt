# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(FifthElement)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Adding the executable (test file)
add_executable(FifthElementTester FifthElementTester.cpp)

# Include directories for header files
target_include_directories(FifthElementTester PUBLIC ./)
