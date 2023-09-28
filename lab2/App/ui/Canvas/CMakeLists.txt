project(CanvasLib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_library(CanvasLib Canvas.h Canvas.cpp)

target_link_libraries(CanvasLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
)