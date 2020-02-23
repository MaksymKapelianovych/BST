cmake_minimum_required(VERSION 3.15)
project(bts)

set(CMAKE_CXX_STANDARD 14)

add_executable(bts main.cpp tree.cpp node.cpp node.h tree.h color.h)