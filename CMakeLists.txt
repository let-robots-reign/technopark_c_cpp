cmake_minimum_required(VERSION 3.16)
project(technopark_c_cpp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread")

add_subdirectory(hw2_static)
add_subdirectory(hw2_shared)
add_subdirectory(test)
file(COPY test_input_files DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME}_with_static main.c)
target_link_libraries(${PROJECT_NAME}_with_static LINK_PUBLIC hw2_static_lib)

add_executable(${PROJECT_NAME}_with_shared main.c)
target_link_libraries(${PROJECT_NAME}_with_shared LINK_PUBLIC hw2_shared_lib)
