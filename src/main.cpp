#include "area_calculator.hpp"

#include <iostream>

int main()
{
    const char data[] = {
        1, 0, 0, 20,
        2, 10, 10, 20, 30,
        3, 6, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        4, -10, -10, 15
    };
    int dataSize{27};
    AreaCalculator calculator;
    int result = calculator.calculateArea(data, dataSize);

    std::cout << "Area of figures is: " << result << std::endl;

    return 0;
}