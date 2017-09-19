#include "input_readers.hpp"
#include "catch.hpp"
#include "figures.hpp"

SCENARIO("Data for singular figure can be read", "[input readers tests]")
{
    GIVEN("Square data")
    {
        readers::SquareData<figures::Square> squareDataReader;
        const char data[] = {1, 0, 0, 20};
        int index{0};
        THEN("Index of next data set is returned")
        {
            REQUIRE(squareDataReader.read(data, index) == 4);
        }
    }

    GIVEN("Rectange data")
    {
        readers::RectangleData<figures::Rectangle> rectangleDataReader;
        const char data[] = {2, 10, 10, 20, 30};
        int index{0};
        THEN("Index of next data set is returned")
        {
            REQUIRE(rectangleDataReader.read(data, index) == 5);
        }
    }

    GIVEN("Circle data")
    {
        readers::CircleData<figures::Circle> circleDataReader;
        const char data[] = {4, -10, -10, 15};
        int index{0};
        THEN("Index of next data set is returned")
        {
            REQUIRE(circleDataReader.read(data, index) == 4);
        }
    }

    GIVEN("Polygon data")
    {
        readers::PolygonData<figures::Polygon> polygonDataReader;
        const char data[] = {3, 4, 0, 0, 0, 1, 1, 1, 1, 0};
        int index{0};
        THEN("Proper area is calculated")
        {
            REQUIRE(polygonDataReader.read(data, index) == 10);
        }
    }
}