#include <memory>
#include <list>

#include "figures.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
Assumptions:
1. Input is always correct
2. Cumulative area is sum of areas of each figures. Overlaps are ignored

Example data:
    const char data[] = {
    1, 0, 0, 20, // square [figure_id, x, y, size]
    2, 10, 10, 20, 30, // rectangle [figure_id, x, y, size_x, size_y]
    3, 6, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, // polygon [figure_id, vertex_count, x1, y1, x2, y2, x3, y3, ..., x_vertex_count, y_vertex_count]
    4, -10, -10, 15 // circle [figure_id, x, y, radius]
    };
*/

class CumulativeAreaCalc
{
public:
    void readData(const char* data, unsigned int size)
    {
        for(unsigned int i = 0; i < size;)
        {
            i = addFigure(data, i);
        }
    }

    int calculateArea()
    {
        int sum = 0.0;
        for(const auto& elem: figuresList_)
        {
            sum += elem->calculateArea();
        }
        return sum;
    } 

private:
    int addFigure(const char* data, unsigned int index)
    {
        using namespace figures;

        int verticesCount;
        std::vector<std::pair<int, int>> vertices;
        FigureType figureType = static_cast<FigureType>(data[index]);
        switch(figureType)
        {
            case FigureType::Square:
                figuresList_.push_back(std::make_unique<Square>(static_cast<unsigned int>(data[index + 3])));
                return index + 4;
            case FigureType::Circle:
                figuresList_.push_back(std::make_unique<Circle>(static_cast<unsigned int>(data[index + 3])));
                return index + 4;
            case FigureType::Polygon:
                verticesCount = static_cast<unsigned int>(data[index + 1]);
                vertices.reserve(verticesCount);
                for(unsigned int i = index + 2; i < (index + 1 + (2 * verticesCount)); i += 2)
                {
                    vertices.emplace_back(std::make_pair<int, int>(static_cast<int>(data[i]), static_cast<int>(data[i + 1])));
                }
                figuresList_.push_back(std::make_unique<Polygon>(verticesCount, std::move(vertices)));
                return index + 2 + verticesCount * 2;
            case FigureType::Rectangle:
                figuresList_.push_back(std::make_unique<Rectangle>(static_cast<unsigned int>(data[index + 3]),
                                                                   static_cast<unsigned int>(data[index + 4])
                                                                  )
                                      );
                return index + 5;
        }
        return 0;
    }

    std::list<std::unique_ptr<figures::FigureInterface>> figuresList_;
};

SCENARIO("Area of singular figure can be calculated", "[basic tests]")
{
    CumulativeAreaCalc calculator;
    GIVEN("Square data")
    {
        const char data[] = {1, 0, 0, 20};
        int dataSize{4};
        THEN("Proper area is calculated")
        {
            calculator.readData(data, dataSize);
            REQUIRE(calculator.calculateArea() == 400.0);
        }
    }

    GIVEN("Rectange data")
    {
        const char data[] = {2, 10, 10, 20, 30};
        int dataSize{5};
        THEN("Proper area is calculated")
        {
            calculator.readData(data, dataSize);
            REQUIRE(calculator.calculateArea() == 600.0);
        }
    }

    GIVEN("Circle data")
    {
        const char data[] = {4, -10, -10, 15};
        int dataSize{4};
        THEN("Proper area is calculated")
        {
            calculator.readData(data, dataSize);
            REQUIRE(calculator.calculateArea() == 706);
        }
    }

    GIVEN("Polygon data")
    {
        const char data[] = {3, 4, 0, 0, 0, 1, 1, 1, 1, 0};
        int dataSize{10};
        THEN("Proper area is calculated")
        {
            calculator.readData(data, dataSize);
            REQUIRE(calculator.calculateArea() == 1);
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
            calculator.readData(data, dataSize);
            REQUIRE(calculator.calculateArea() == 1706);
        }
    }
}
