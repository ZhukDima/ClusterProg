cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(HEADER_FILES
    includes/mainwindow.h
    includes/settingsdialog.h
    includes/settings.h
    includes/settingspresenter.h
    includes/run.h
)

set(UI_FILES
    src/mainwindow.ui
    src/settingsdialog.ui
)

set(SOURCE_FILES
    src/mainwindow.cpp
    src/settingsdialog.cpp
    src/settings.cpp
    src/settingspresenter.cpp
    src/run.cpp
)

include_directories(includes)

add_library(
    InterfaceLib
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(InterfaceLib Qt5::Widgets)
