cmake_minimum_required(VERSION 3.16)
project(unit_tests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread -Wall -Werror -Wpedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -pthread")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME}_with_static ${SOURCES})
target_link_libraries(${PROJECT_NAME}_with_static hw2_static_lib)
target_link_libraries(${PROJECT_NAME}_with_static ${GTEST_LIBRARIES} pthread)

add_executable(${PROJECT_NAME}_with_shared ${SOURCES})
target_link_libraries(${PROJECT_NAME}_with_shared hw2_shared_lib)
target_link_libraries(${PROJECT_NAME}_with_shared ${GTEST_LIBRARIES} pthread)
