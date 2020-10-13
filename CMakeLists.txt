cmake_minimum_required(VERSION 3.16)
project(technopark_c_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "--coverage")

set(LIB_SOURCE src/string_functions.h src/string_functions.c src/filter.h src/filter.c src/strings_vector.h src/strings_vector.c)
add_library(filter_lib STATIC ${LIB_SOURCE})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest test/string_functions_test.cpp test/strings_vector_test.cpp test/filter_test.cpp test/main_test.cpp)
target_link_libraries(gtest filter_lib)
target_link_libraries(gtest ${GTEST_LIBRARIES} pthread)

add_executable(hw1 src/main.c)
target_link_libraries(hw1 filter_lib)
