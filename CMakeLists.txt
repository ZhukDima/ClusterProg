cmake_minimum_required(VERSION 3.5)

project(ClusterProg LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -std=c++17")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(app)

include_directories(app/includes)

target_link_libraries(${PROJECT_NAME} PRIVATE InterfaceLib)