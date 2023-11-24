cmake_minimum_required(VERSION 3.5)
project(parser)

set(SOURCE_LIB parser.h IFStream.h TuplePrint.h TupleUtil.h)

add_library(parser ${SOURCE_LIB})
