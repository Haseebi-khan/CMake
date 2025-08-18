cmake_minimum_required(VERSION 4.0.1)

project(trim)

add_executable(${PROJECT_NAME} src/main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_library(haseebMath src/adder.cpp)
