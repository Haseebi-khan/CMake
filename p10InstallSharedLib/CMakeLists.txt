cmake_minimum_required(VERSION 3.16)

project(p10)

# it tells Install output of build install into build dir to binary dir. 

# Set output directories BEFORE creating targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/../multiplyShared/
    ${CMAKE_BINARY_DIR}/multiplySharedlib
)
    
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mathlib)

install(TARGETS mathlib
        EXPORT mathlibTargets 
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib        
        RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/../multiplyShared/
        DESTINATION include/mathlib
        FILES_MATCHING 
        PATTERN "*.h"
        PATTERN "*hpp"
)

install(EXPORT mathlibTargets
        FILE mathlibConfig.cmake
        NAMESPACE math::
        DESTINATION lib/cmake/mathlib
)

# find_package(mathlib REQUIRED)  
# target_link_libraries(${PROJECT_NAME} PRIVATE mathlib )
