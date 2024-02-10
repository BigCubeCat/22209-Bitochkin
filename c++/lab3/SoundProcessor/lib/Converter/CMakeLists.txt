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