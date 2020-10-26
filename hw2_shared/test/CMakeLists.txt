cmake_minimum_required(VERSION 3.16)
project(unit_tests_shared)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread --coverage")
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

FILE(GLOB SOURCES *.cpp ../src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
