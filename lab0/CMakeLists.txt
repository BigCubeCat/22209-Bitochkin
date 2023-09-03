cmake_minimum_required(VERSION 3.5)

project(lab0)

set(SOURCE_EXE src/main.cpp)

include_directories(src/counter)

add_executable(lab0 ${SOURCE_EXE})

add_subdirectory(src/counter)

target_link_libraries(lab0 counter)

