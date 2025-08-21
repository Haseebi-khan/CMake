cmake_minimum_required(VERSION 4.0.1)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder/
    PUBLIC external/glfw/include
    )

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
    )

target_link_libraries(${PROJECT_NAME} adder glfw)

# add_library(adder Adder/adder.cpp Adder/adder.h)