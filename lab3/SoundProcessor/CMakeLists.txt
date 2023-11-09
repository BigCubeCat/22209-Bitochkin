cmake_minimum_required(VERSION 3.27)

set(PROJECT_NAME SoundProcessor)
set(SOURCE src/main.cpp src/Processor/Processor.h src/Processor/Processor.cpp)
set(LIBRARY_DIR lib)
set(LIBRARY WAV Configurator ArgParser Converter ErrorHandler)

project(${PROJECT_NAME} CXX)

add_executable(${PROJECT_NAME} ${SOURCE})

foreach(LIBRARY ${LIBRARY})
    add_subdirectory("${LIBRARY_DIR}/${LIBRARY}")
    message(STATUS "Add subdirectory ${LIBRARY_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME} ${LIBRARY})
