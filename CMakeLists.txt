cmake_minimum_required(VERSION 3.16)
project(ClusterProg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

include(ExternalProject)
find_package(Git REQUIRED)

##
### Test definitions ###
##

configure_file(CMakeList.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

##
### End test definition ###
##


add_executable(ClusterProg src/main.cpp)
target_include_directories(ClusterProg PUBLIC include src)
include_directories(include)
add_library(cluster_prog_lib STATIC src/FileReaderImpl.cpp src/FileReader.cpp src/FileInfo.cpp src/FileInfoImpl.cpp src/DirHandler.cpp src/FileMover.cpp)
target_link_libraries(ClusterProg PRIVATE cluster_prog_lib)
