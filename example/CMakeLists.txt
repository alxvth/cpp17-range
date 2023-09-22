cmake_minimum_required (VERSION 3.21)

set(RANGE_PCA "RANGE_TEST")
project(${RANGE_PCA} CXX)

add_executable(${RANGE_PCA} "main.cpp")

target_compile_features(${RANGE_PCA} PUBLIC cxx_std_17)

target_include_directories(${RANGE_PCA} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../range")
