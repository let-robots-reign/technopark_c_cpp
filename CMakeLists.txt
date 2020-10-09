cmake_minimum_required(VERSION 3.17)
project(technopark_c_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(technopark_c_cpp main.c string_functions.h string_functions.c filter.h filter.c)
