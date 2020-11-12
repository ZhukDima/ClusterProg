cmake_minimum_required(VERSION 3.16)
project(ClusterProg)

set(CMAKE_CXX_STANDARD 14)

link_directories(
        ${GTKMM_LIBRARY_DIRS}  )

include_directories(
        ${GTKMM_INCLUDE_DIRS}  )

add_executable(ClusterProg src/main.cpp)

target_link_libraries(ClusterProg
        ${GTKMM_LIBRARIES}  )

target_include_directories(ClusterProg PUBLIC include)
