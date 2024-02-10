cmake_minimum_required(VERSION 3.5)
project(counter)

set(SOURCE_LIB counter.cpp counter.h row.h row.cpp)

add_library(counter ${SOURCE_LIB})

