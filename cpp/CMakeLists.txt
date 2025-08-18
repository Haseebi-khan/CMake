cmake_minimum_required(VERSION 4.0.1)

project(test)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories( testSome PRIVATE C:/Users/NoNeo/OneDrive/Desktop/learningcmake/p1/src/cpp)

target_link_directories(test PRIVATE C:/Users/NoNeo/OneDrive/Desktop/learningcmake/p1/build)

target_link_libraries(test haseebMath)
