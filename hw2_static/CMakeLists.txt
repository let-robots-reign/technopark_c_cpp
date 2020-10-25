cmake_minimum_required(VERSION 3.16)
project("hw2_static")

set(CMAKE_C_STANDARD 11)

set(SOURCES src/read_comments.c)
include_directories("include/")

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
