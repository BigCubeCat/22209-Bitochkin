project(GameArenaLib)

include_directories(../../types)

add_library(GameArenaLib GameArena.cpp GameArena.h)

target_link_libraries(TypesLib)
