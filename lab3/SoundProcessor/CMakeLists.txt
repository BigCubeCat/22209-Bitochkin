cmake_minimum_required(VERSION 3.27)
project(SoundProcessor)

set(SOURCE_LIB main.cpp)

include_directories(Configurator)

add_executable(SoundProcessor ${SOURCE_LIB})

add_subdirectory(Configurator)

target_link_libraries(SoundProcessor Configurator)