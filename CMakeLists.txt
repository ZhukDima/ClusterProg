cmake_minimum_required(VERSION 3.5)

project(ClusterProg LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(interface)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(interface/includes)

target_link_libraries(${PROJECT_NAME} PRIVATE InterfaceLib)
