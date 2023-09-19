cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled main.cpp)

add_subdirectory(CmdManager)
add_subdirectory(types)
add_subdirectory(Life/GameArena)

target_link_libraries(untitled
        Qt::Core
        Qt::Gui
        Qt::Widgets
        CmdManagerLib
        TypesLib
        GameArenaLib
)

