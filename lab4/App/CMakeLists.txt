cmake_minimum_required(VERSION 3.5)

project(CSVParser)

set(SOURCE_EXE
        src/main.cpp
        src/parser/IFStream.h
        src/parser/parser.h
        src/parser/TupleUtil.h
        src/parser/TuplePrint.h
)


add_executable(CSVParser ${SOURCE_EXE})

