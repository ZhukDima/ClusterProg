cmake_minimum_required(VERSION 3.5)

set(SOURCE_FILES
    src/mainwindow.ui
    src/settingsdialog.ui
    src/mainwindow.cpp
    includes/mainwindow.h
    src/settingsdialog.cpp
    includes/settingsdialog.h
    src/settings.cpp
    includes/settings.h
    src/run.cpp
    includes/run.h
    )

include_directories(includes)

add_library(
    InterfaceLib
    ${SOURCE_FILES}
)


find_package(Qt5Widgets CONFIG
    PATHS /home/vadim/Applications/5.14.2/gcc_64/lib/cmake/Qt5Widgets
    NO_DEFAULT_PATH)

target_link_libraries(InterfaceLib PUBLIC Qt5::Widgets)

target_include_directories(InterfaceLib PUBLIC "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/includes")
