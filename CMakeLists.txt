cmake_minimum_required(VERSION 3.17)
project(technopark_c_cpp)

set(CMAKE_CXX_STANDARD 17)

set(LIB_SOURCE src/string_functions.h src/string_functions.c src/filter.h src/filter.c)
add_library(filter_lib STATIC ${LIB_SOURCE})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_string test/string_functions_test.cpp)
target_link_libraries(test_string filter_lib)
target_link_libraries(test_string ${GTEST_LIBRARIES} pthread)

add_executable(hw1 src/main.c)
target_link_libraries(hw1 filter_lib)
