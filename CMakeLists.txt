cmake_minimum_required(VERSION 3.16)
project(ClusterProg)

set(CMAKE_CXX_STANDARD 14)

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


add_executable(ClusterProg src/main.cpp src/FileReaderImpl.cpp src/FileReader.cpp)

target_include_directories(ClusterProg PUBLIC include src)
