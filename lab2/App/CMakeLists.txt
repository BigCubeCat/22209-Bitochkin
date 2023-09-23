project(AppLib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_library(AppLib App.h App.cpp)
include_directories(../types)
include_directories(../Life)
include_directories(../UI/Canvas)

target_link_libraries(AppLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        TypesLib
        LifeLib
        CanvasLib
)