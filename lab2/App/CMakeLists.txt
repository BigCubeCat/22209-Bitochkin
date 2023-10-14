cmake_minimum_required(VERSION 3.5)

project(gameoflife VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        ui/mainwindow/MainWindow.cpp
        ui/mainwindow/MainWindow.h
        ui/mainwindow/mainwindow.ui

        ui/Panel/Panel.cpp
        ui/Panel/Panel.h
        ui/Panel/panel.ui

        ui/Canvas/Canvas.cpp
        ui/Canvas/Canvas.h

        ui/Stepper/Stepper.cpp
        ui/Stepper/Stepper.h
        ui/Stepper/stepper.ui

        ui/Rule/Rule.cpp
        ui/Rule/Rule.h
        ui/Rule/rule.ui

        ui/NeighborhoodSelect/NeighborhoodSelect.cpp
        ui/NeighborhoodSelect/NeighborhoodSelect.h
        ui/NeighborhoodSelect/neighborhoodselect.ui

        StateStorage/StateStorage.cpp
        StateStorage/StateStorage.h

        ui/Conf/Conf.h
        ui/Conf/Conf.cpp
        ui/Conf/conf.ui

        FileWorker/FileWorker.cpp
        FileWorker/FileWorker.h
)

include_directories(Kernel)
add_subdirectory(Kernel)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(gameoflife
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
else ()
    add_executable(gameoflife
            ${PROJECT_SOURCES}
    )
endif ()

target_link_libraries(gameoflife PRIVATE Kernel Qt${QT_VERSION_MAJOR}::Widgets)

if (${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.gameoflife)
endif ()
set_target_properties(gameoflife PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gameoflife
        BUNDLE DESTINATION ..
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gameoflife)
endif ()
