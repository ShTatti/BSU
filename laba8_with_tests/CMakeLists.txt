cmake_minimum_required(VERSION 3.20)
project(laba8)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba8 Calculator.cpp main.cpp)



# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run main.cpp Calculator.cpp Calculator.h Stack.h)
target_link_libraries(Google_Tests_run gtest gtest_main)