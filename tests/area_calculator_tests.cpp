#include "area_calculator.hpp"

#include "catch.hpp"

SCENARIO("Area of singular figure can be calculated", "[Full tests]")
{
    AreaCalculator calculator;
    GIVEN("Square data")
    {
        const char data[] = {1, 0, 0, 20};
        int dataSize{4};
        THEN("Proper area is calculated")
        {
            REQUIRE(calculator.calculateArea(data, dataSize) == 400.0);
        }
    }

    GIVEN("Rectange data")
    {
        const char data[] = {2, 10, 10, 20, 30};
        int dataSize{5};
        THEN("Proper area is calculated")
        {
            REQUIRE(calculator.calculateArea(data, dataSize) == 600.0);
        }
    }

    GIVEN("Circle data")
    {
        const char data[] = {4, -10, -10, 15};
        int dataSize{4};
        THEN("Proper area is calculated")
        {
            REQUIRE(calculator.calculateArea(data, dataSize) == 706);
        }
    }

    GIVEN("Polygon data")
    {
        const char data[] = {3, 4, 0, 0, 0, 1, 1, 1, 1, 0};
        int dataSize{10};
        THEN("Proper area is calculated")
        {
            REQUIRE(calculator.calculateArea(data, dataSize) == 1);
        }
    }
}

SCENARIO("Area of 4 figures can be calculated", "[basic tests]")
{
    AreaCalculator calculator;
    GIVEN("Square, rectangle, circle and polygon data")
    {
        const char data[] = {
            1, 0, 0, 20,
            2, 10, 10, 20, 30,
            3, 6, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
            4, -10, -10, 15
        };
        int dataSize{27};
        THEN("Cumulative area is calculated")
        {
            REQUIRE(calculator.calculateArea(data, dataSize) == 1706);
        }
    }
}
