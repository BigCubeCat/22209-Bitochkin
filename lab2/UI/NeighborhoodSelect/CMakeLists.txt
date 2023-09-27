project(NeighborhoodSelectLib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_library(NeighborhoodSelectLib
        NeighborhoodSelect.cpp
        NeighborhoodSelect.h
)

include_directories(../types)

target_link_libraries(NeighborhoodSelectLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        TypesLib
)