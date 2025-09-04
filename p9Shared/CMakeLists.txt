# STATIC BUILD
# ➡️ Produces myApp.exe only. No DLL needed.

# SHARED BUILD 
# ➡️ Produces myApp.exe + mathlib.dll + mathlib.lib.
# Move myApp.exe elsewhere → it won’t run without mathlib.dll.

# ==============================================================================================================

cmake_minimum_required(VERSION 3.16)

project(p8)

add_subdirectory(
  ${CMAKE_SOURCE_DIR}/../multiplyShared
  ${CMAKE_BINARY_DIR}/multiplyShared
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mathlib)

# ==============================================================================================================

# Static linking = library code copied inside exe (no extra files needed).

# Shared linking = exe depends on external DLL/SO at runtime.

# CMake switches this with STATIC/SHARED keyword or BUILD_SHARED_LIBS.