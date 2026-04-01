cmake_minimum_required(VERSION 3.10)
project(MatrixProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(src)

add_executable(matrix_tests tests/matrix_tests.cpp)

target_link_libraries(matrix_tests 
    GTest::GTest 
    GTest::Main 
    pthread
)
