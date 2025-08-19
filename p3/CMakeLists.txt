cmake_minimum_required(VERSION 4.0.1)

project(p3)

add_library(p3 SHARED adder.cpp)

set_target_properties(p3 PROPERTIES PUBLIC_HEADER adder.h)

install(TARGETS p3 LIBRARY DESTINATION lib 
    PUBLIC_HEADER DESTINATION  include/p3)
