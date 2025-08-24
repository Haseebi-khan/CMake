cmake_minimum_required( VERSION  4.0.1)

project(optionalLib VERSION 1.0)

# =======================================================================

option(USE_ADDER "A Simple Library For Adding Two Numbers" ON)
if(USE_ADDER)

    add_subdirectory(adder)
    list(APPEND EXTRA_LIBS Adder)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Adder")
    list(APPEND EXTRA_LINKS adder)
    
    # =======================================================================
    #                     NOW WE DONT NEED IT
    # =======================================================================
    # target_include_directories(${PROJECT_NAME}
    #     PUBLIC ../p4/Adder/
    # )
    # target_link_directories(${PROJECT_NAME}
    #     PRIVATE ../p4/Adder/
    # )
endif()

# =======================================================================

configure_file( OptionalLibConfig.h.in OptionalLibConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# =======================================================================
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
# =======================================================================

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    ${EXTRA_LIBS}
)

target_link_libraries(${PROJECT_NAME} glfw ${EXTRA_LINKS})

