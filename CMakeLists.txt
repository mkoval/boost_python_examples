cmake_minimum_required(VERSION 2.8)
project(boost_python_tutorial CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/pythonsrc")
add_definitions(-g -O2 -Wall)

find_package(PythonLibs)
include_directories(${PYTHON_INCLUDE_PATH})

add_library(capi_function SHARED src/capi_function.cpp)
set_target_properties(capi_function PROPERTIES PREFIX "" SUFFIX ".so")
target_link_libraries(capi_function ${PYTHON_LIBRARIES})
