cmake_minimum_required(VERSION 2.8)

# this should be the name of your homework assignment
project(Euchre)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(euchre src/main.cpp)