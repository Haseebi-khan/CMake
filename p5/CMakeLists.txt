cmake_minimum_required(VERSION 3.15)   # Minimum required CMake version

project(p5)  # Project name and version

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory( ../p4/Adder Adder)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC ../p4/Adder/
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ../p4/Adder/
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} adder glfw)

# Link libraries (if any)
# target_link_libraries(${PROJECT_NAME} PRIVATE mylib)

# Optional: Add subdirectories (for libraries, modules, etc.)
# add_subdirectory(lib)

# Install target (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
