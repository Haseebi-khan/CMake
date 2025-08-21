cmake_minimum_required(VERSION 4.0.1)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)

target_include_directories(${PROJECT_NAME} PUBLIC C:\\Users\\NoNeo\\OneDrive\\Desktop\\learningcmake\\p4\\Adder)

target_link_directories(${PROJECT_NAME} PRIVATE C:\\Users\\NoNeo\\OneDrive\\Desktop\\learningcmake\\p4\\Adder)

target_link_libraries(${PROJECT_NAME} adder )

# add_library(adder Adder/adder.cpp Adder/adder.h)