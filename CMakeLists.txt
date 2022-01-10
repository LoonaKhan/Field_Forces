cmake_minimum_required(VERSION 3.20)
project(Field_Forces)

set(CMAKE_CXX_STANDARD 14)

add_executable(Field_Forces main.cpp node.cpp node.h segment.cpp segment.h chain.cpp chain.h globvars.h)

target_link_libraries(Field_Forces sfml-graphics sfml-window sfml-system)