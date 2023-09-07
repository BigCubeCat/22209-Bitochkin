cmake_minimum_required(VERSION 3.5)
project(BitArray)

set(SOURCE_LIB BitArray.cpp BitArray.h utils.h utils.cpp)

add_library(BitArray ${SOURCE_LIB})
