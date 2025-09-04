# STATIC BUILD
# ➡️ Produces myApp.exe only. No DLL needed.

# SHARED BUILD 
# ➡️ Produces myApp.exe + mathlib.dll + mathlib.lib.
# Move myApp.exe elsewhere → it won’t run without mathlib.dll.

add_library(mathlib SHARED multipier.cpp)

target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

