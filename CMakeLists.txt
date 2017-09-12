cmake_minimum_required(VERSION 3.0)

project(FigureArea)

set(SOURCE main.cpp
           figures.cpp)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(${PROJECT_NAME} ${SOURCE})
