cmake_minimum_required(VERSION 3.5)
project(usbmuxd_list C)

set(CMAKE_C_STANDARD 11)

find_library(LibUsbmuxd usbmuxd PATHS "/usr/local/lib")
include_directories("/usr/local/include")

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_LIST_DIR}/usbmuxd_list.c")
target_link_libraries(${PROJECT_NAME} ${LibUsbmuxd})