cmake_minimum_required(VERSION 3.19)
project(Pin_to_Node)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pin_to_Node main.cpp Graph.cpp Graph.h G_Wire.cpp G_Wire.h Matrix.cpp Matrix.h)