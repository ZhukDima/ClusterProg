cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

# include(ExternalProject)
# find_package(Git REQUIRED)

# ##
# ### Test definitions ###
# ##

# configure_file(CMakeList.txt.in
#         googletest-download/CMakeLists.txt)
# execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
# execute_process(COMMAND ${CMAKE_COMMAND} --build .
#         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
#         ${CMAKE_BINARY_DIR}/googletest-build)

# enable_testing()
# add_subdirectory(test)

# ##
# ### End test definition ###
# ##

file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

include_directories(include)

add_library(cluster_prog_lib STATIC ${sources})

target_include_directories(cluster_prog_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
