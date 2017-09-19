set(TESTS_NAME "${PROJECT_NAME}Tests" )

set(CATCH_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${TESTS_NAME}
    main_tests.cpp
    area_calculator_tests.cpp
    figures_tests.cpp
    input_readers_tests.cpp
    )
  
target_link_libraries(${TESTS_NAME} 
    AreaCalculator
    Catch)