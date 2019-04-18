cmake_minimum_required(VERSION 3.13)
project(fast_rgba_to_bgra C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_LIST_DIR}/fast_rgba_to_bgra.c")
export(TARGETS ${PROJECT_NAME} FILE fast_rgba_to_bgra.cmake)