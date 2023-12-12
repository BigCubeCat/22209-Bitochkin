set(LIBRARY_NAME Converter)
set(LIBRARY_HEADERS_DIR include)

set(LIBRARY_HEADERS include/converter.h
        include/converterFactory.h
        include/mix.h
        include/noise.h
        include/mute.h
        include/cut.h
        include/crop.h
)

set(LIBRARY_SOURCE
        src/mix.cpp
        src/noise.cpp
        src/mute.cpp
        src/cut.cpp
        src/crop.cpp
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/WAV/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} WAV)

set(TEST_LIBRARY_NAME converter_tests)
set(TEST_SOURCE test/converter_tests.cpp)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})