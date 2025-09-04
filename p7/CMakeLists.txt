cmake_minimum_required(VERSION 4.0)

project(p7 VERSION 1.0)

option(USE_ADDER "Library To Add Two Numbers." ON)
if(USE_ADDER)
    add_subdirectory(${PROJECT_SOURCE_DIR}/../p4/Adder ${CMAKE_BINARY_DIR}/Adder_buil)
    list(APPEND EXTRA_LIBS adder)
    list(APPEND EXTRA_INCLUDE "${PROJECT_SOURCE_DIR}../p4/Adder")
    list(APPEND EXTRA_LINKS adder)
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/p7Config.h.in 
    ${CMAKE_CURRENT_BINARY_DIR}/p7Config.h
)    

add_executable(${PROJECT_NAME} main.cpp)
    
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
    
# ============================================================================================================
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
if(NOT EXISTS0 "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# ============================================================================================================

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    ${EXTRA_LIBS}
)

target_include_directories(p7 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} glfw ${EXTRA_LINKS})


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/p7Config.h" DESTINATION include)
