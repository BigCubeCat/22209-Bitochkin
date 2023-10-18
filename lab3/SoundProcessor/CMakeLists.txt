cmake_minimum_required(VERSION 3.27)
project(SoundProcessor)

set(SOURCE_LIB main.cpp)

include_directories(Configurator)
include_directories(ArgParser)

add_executable(SoundProcessor ${SOURCE_LIB})

add_subdirectory(Configurator)
add_subdirectory(ArgParser)

target_link_libraries(SoundProcessor Configurator ArgParser)