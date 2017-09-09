cmake_minimum_required(VERSION 3.0)

project(FigureArea)

set(SOURCE main.cpp)
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${PROJECT_NAME} ${SOURCE})