cmake_minimum_required(VERSION 3.16)
project(ClusterProg)

set(CMAKE_CXX_STANDARD 14)



add_executable(ClusterProg src/main.cpp)
target_include_directories(ClusterProg PUBLIC include)
