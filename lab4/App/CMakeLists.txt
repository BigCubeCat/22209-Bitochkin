cmake_minimum_required(VERSION 3.5)

project(CSVParser)

set(SOURCE_EXE
        src/main.cpp
        src/parser/IFStream.h
        src/parser/parser.h
        src/parser/TupleUtil.h
        src/parser/TuplePrint.h
)

# include_directories(src/parser)

add_executable(CSVParser ${SOURCE_EXE})

# add_subdirectory(src/parser)

# target_link_libraries(CSVParser parser)