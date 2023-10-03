cmake_minimum_required(VERSION 3.5)

project(test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        App/main.cpp
        App/ui/mainwindow/mainwindow.cpp
        App/ui/mainwindow/mainwindow.h
        App/ui/mainwindow/mainwindow.ui

        App/ui/panel/panel.cpp
        App/ui/panel/panel.h
        App/ui/panel/panel.ui

        App/ui/Canvas/Canvas.cpp
        App/ui/Canvas/Canvas.h

        App/ui/stepper/stepper.cpp
        App/ui/stepper/stepper.h
        App/ui/stepper/stepper.ui

        App/ui/rule/rule.cpp
        App/ui/rule/rule.h
        App/ui/rule/rule.ui

        App/ui/neighborhoodselect/neighborhoodselect.cpp
        App/ui/neighborhoodselect/neighborhoodselect.h
        App/ui/neighborhoodselect/neighborhoodselect.ui

        App/types/TNeighborhood.cpp
        App/types/TNeighborhood.h

        App/types/TRules.cpp
        App/types/TRules.h

        App/Life/Life.cpp
        App/Life/Life.h

        App/StateStorage/StateStorage.cpp
        App/StateStorage/StateStorage.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(test
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET test APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(test SHARED
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(test
                ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.test)
endif()
set_target_properties(test PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS test
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(test)
endif()
