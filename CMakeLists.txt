cmake_minimum_required(VERSION 2.8)
project(boost_python_tutorial CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/pythonsrc")
add_definitions(-g -O2 -Wall)

# C API
find_package(PythonLibs)
include_directories(${PYTHON_INCLUDE_PATH})

add_library(capi_function SHARED src/capi_function.cpp)
set_target_properties(capi_function PROPERTIES PREFIX "" SUFFIX ".so")
target_link_libraries(capi_function ${PYTHON_LIBRARIES})

add_library(capi_class SHARED src/capi_class.cpp)
set_target_properties(capi_class PROPERTIES PREFIX "" SUFFIX ".so")
target_link_libraries(capi_class ${PYTHON_LIBRARIES})

# Boost.Python
find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})

add_library(bp_class SHARED src/bp_class.cpp)
set_target_properties(bp_class PROPERTIES PREFIX "" SUFFIX ".so")
target_link_libraries(bp_class boost-python)
