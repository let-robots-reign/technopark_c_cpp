cmake_minimum_required(VERSION 3.16)
project("hw2_shared")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread")

FILE(GLOB SOURCES src/*.c)
include_directories("../include/")

add_library(${PROJECT_NAME}_lib SHARED ${SOURCES} ${HEADERS})
add_library(${PROJECT_NAME}_module MODULE ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
