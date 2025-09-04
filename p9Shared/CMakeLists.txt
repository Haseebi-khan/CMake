cmake_minimum_required(VERSION 3.16)

project(p8)

add_subdirectory(
  ${CMAKE_SOURCE_DIR}/../multiplyShared
  ${CMAKE_BINARY_DIR}/multiply
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mathlib)
