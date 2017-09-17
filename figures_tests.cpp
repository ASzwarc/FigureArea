#include "catch.hpp"
#include "figures.hpp"

SCENARIO("Area of singular figure can calculated", "[figures tests]")
{
    GIVEN("Square")
    {
        figures::Square square(20);
        THEN("Area of figure is returned")
        {
            REQUIRE(square.calculateArea() == 400);
        }
    }

    GIVEN("Rectange data")
    {
        figures::Rectangle rectangle(10, 20);
        THEN("Area of figure is returned")
        {
            REQUIRE(rectangle.calculateArea() == 200);
        }
    }

    GIVEN("Circle data")
    {
        figures::Circle circle(5);
        THEN("Area of figure is returned")
        {
            REQUIRE(circle.calculateArea() == 78);
        }
    }

    GIVEN("Polygon data")
    {
        unsigned int vertexCount{4};
        std::vector<std::pair<int, int>> vertices{{0, 0}, {0, 1}, {1, 1}, {1, 0}};
        figures::Polygon polygon(vertexCount, std::move(vertices));
        THEN("Proper area is calculated")
        {
            REQUIRE(polygon.calculateArea() == 1);
        }
    }
}