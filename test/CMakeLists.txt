cmake_minimum_required(VERSION 3.16)
project(unit_tests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread --coverage")
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME}_with_static ${SOURCES})
target_link_libraries(${PROJECT_NAME}_with_static LINK_PUBLIC hw2_static_lib)
target_link_libraries(${PROJECT_NAME}_with_static LINK_PUBLIC ${GTEST_LIBRARIES})

add_executable(${PROJECT_NAME}_with_shared ${SOURCES})
target_link_libraries(${PROJECT_NAME}_with_shared LINK_PUBLIC hw2_shared_lib)
target_link_libraries(${PROJECT_NAME}_with_shared LINK_PUBLIC ${GTEST_LIBRARIES})
