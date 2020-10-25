cmake_minimum_required(VERSION 3.16)
project(technopark_c_cpp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread")

add_subdirectory(hw2_static)

add_executable(technopark_c_cpp main.c)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC hw2_static_lib)
