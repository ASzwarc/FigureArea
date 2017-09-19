add_library(AreaCalculator 
    area_calculator.cpp
    area_calculator.hpp
    figures.cpp
    figures.hpp
    input_readers.hpp
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} AreaCalculator)