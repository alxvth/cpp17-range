cmake_minimum_required (VERSION 3.21)

set(RANGE_TEST "RANGE_TEST")
project(${RANGE_TEST} CXX)

add_executable(${RANGE_TEST} "main.cpp")

target_compile_features(${RANGE_TEST} PUBLIC cxx_std_17)

target_include_directories(${RANGE_TEST} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../range")
