cmake_minimum_required(VERSION 3.5)

project(lab1)

set(SOURCE_EXE src/main.cpp)

include_directories(src/BitArray)

add_executable(lab1 ${SOURCE_EXE})

add_subdirectory(src/BitArray)

target_link_libraries(lab1 BitArray)
