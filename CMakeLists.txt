cmake_minimum_required(VERSION 2.8)
project(boost_python_tutorial CXX)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/pythonsrc")
add_definitions(-g -O2 -Wall -Wextra)

add_library(oldstyle SHARED src/oldstyle.cpp)
