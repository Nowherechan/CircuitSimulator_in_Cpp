cmake_minimum_required(VERSION 3.19)
project(Pin_to_Node)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pin_to_Node main.cpp Pin_to_Node.cpp Pin_to_Node.h Graph.cpp Graph.h Wire.cpp Wire.h)