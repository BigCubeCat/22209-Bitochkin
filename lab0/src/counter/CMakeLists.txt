cmake_minimum_required(3.6)
project(counter)

set(SOURCE_LIB counter.cpp)

add_library(foo ${SOURCE_LIB})

