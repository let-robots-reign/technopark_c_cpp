cmake_minimum_required(VERSION 3.16)
project(stress_test)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -pthread")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

file(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

add_executable(measure_static measure.cpp)
target_link_libraries(measure_static hw2_static_lib)

add_executable(measure_shared measure.cpp)
target_link_libraries(measure_shared hw2_shared_lib)
