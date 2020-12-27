cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")

configure_file(CMakeList.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(app/clustering/test)

add_library(LevenshteinDistance STATIC ${CMAKE_CURRENT_SOURCE_DIR}/app/clustering/src/main.cpp)
target_include_directories(LevenshteinDistance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/app/clustering/include/LevenshteinDistance.hpp)
