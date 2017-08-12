cmake_minimum_required(VERSION 3.8)
project(n_queens)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "${CMAKE_C_FLAGS} -std=c++11 -pthread")
set(SOURCE_FILES main.cpp nQueens.cpp)
add_executable(n_queens ${SOURCE_FILES})