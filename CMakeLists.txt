cmake_minimum_required(VERSION 3.0)

project(FigureArea)
set(PROJECT_NAME FigureArea)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)