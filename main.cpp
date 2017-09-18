#include <memory>
#include <map>

#include "figures.hpp"
#include "input_readers.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class CumulativeAreaCalc
{
public:
    CumulativeAreaCalc()
    {
        using namespace figures;
        using namespace readers;
        figureReaderMap_[FigureType::Square] = std::make_unique<SquareData<Square>>();
        figureReaderMap_[FigureType::Rectangle] = std::make_unique<RectangleData<Rectangle>>();
        figureReaderMap_[FigureType::Circle] = std::make_unique<CircleData<Circle>>();
        figureReaderMap_[FigureType::Polygon] = std::make_unique<PolygonData<Polygon>>();
    }
    int calculateArea(const char* data, unsigned int size)
    {
        int sum = 0;
        for(unsigned int i = 0; i < size;)
        {
            i = addFigure(data, i, sum);
        }
        return sum;
    }

private:
    int addFigure(const char* data, unsigned int index, int& cumulativeArea)
    {
        figures::FigureType figureType = static_cast<figures::FigureType>(data[index]);
        unsigned int nextIndex = figureReaderMap_[figureType]->read(data, index);
        cumulativeArea += figureReaderMap_[figureType]->getFigureArea();

        return nextIndex;
    }
    std::map<figures::FigureType, std::unique_ptr<readers::DataReaderInterface>> figureReaderMap_;
};

//TODO Refactor test. Currently these are module tests, not UTs

SCENARIO("Area of singular figure can be calculated", "[basic tests]")
{
    CumulativeAreaCalc calculator;
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
    CumulativeAreaCalc calculator;
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
