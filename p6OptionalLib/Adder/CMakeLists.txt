add_library(adder adder.cpp adder.h)

target_include_directories(adder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Install the library
install(TARGETS adder DESTINATION lib)

# Install the header
install(FILES adder.h DESTINATION include)
