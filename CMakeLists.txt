cmake_minimum_required(VERSION 3.5)

project(OrangeCloud VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Network Gui Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Gui Network REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        resources.qrc
        
        # UI
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/weatheritem.h
        src/weatheritem.cpp
        src/weatheritem.ui
        
        # Weather
        src/weather.cpp
        src/weather.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OrangeCloud
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(OrangeCloud PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Network
    ${CMAKE_CURRENT_SOURCE_DIR}/bin/openweather3parthlib
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OrangeCloud)
endif()
