add_library(adder adder.cpp adder.h)

target_include_directories(adder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGET adder DESTINATION lib)
install(FILES adder.h DESTINATION include )
