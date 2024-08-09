cmake_minimum_required(VERSION 3.10)

# Project name
project(GeometryToolkit)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the examples
add_executable(DistanceCalculator examples/DistanceCalculator.cpp src/Point.cpp src/GeometryUtils.cpp src/input.cpp)

# Add the tests
add_executable(TestGeometryUtils tests/TestGeometryUtils.cpp src/Point.cpp src/GeometryUtils.cpp)
add_executable(TestDegeneracy tests/TestDegeneracy.cpp src/Point.cpp src/GeometryUtils.cpp)

# Specify output directories
set_target_properties(DistanceCalculator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples)
set_target_properties(TestGeometryUtils PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
set_target_properties(TestDegeneracy PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)