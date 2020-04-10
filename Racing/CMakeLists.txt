cmake_minimum_required(VERSION 3.10)
project(Racing)

set(CMAKE_CXX_STANDARD 14)

include_directories(source)

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(lib/googletest)