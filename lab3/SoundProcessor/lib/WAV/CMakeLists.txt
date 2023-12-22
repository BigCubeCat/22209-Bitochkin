set(LIBRARY_NAME WAV)
set(LIBRARY_HEADERS_DIR include)
set(LIBRARY_HEADERS include/wav.h include/reader.h include/writer.h)
set(LIBRARY_SOURCE src/reader.cpp src/writer.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR})
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY})