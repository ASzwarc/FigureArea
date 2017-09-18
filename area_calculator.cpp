#include <map>
#include <memory>

#include "area_calculator.hpp"

AreaCalculator::AreaCalculator()
{
    using namespace figures;
    using namespace readers;
    figureReaderMap_[FigureType::Square] = std::make_unique<SquareData<Square>>();
    figureReaderMap_[FigureType::Rectangle] = std::make_unique<RectangleData<Rectangle>>();
    figureReaderMap_[FigureType::Circle] = std::make_unique<CircleData<Circle>>();
    figureReaderMap_[FigureType::Polygon] = std::make_unique<PolygonData<Polygon>>();
}

int AreaCalculator::calculateArea(const char* data, unsigned int size)
{
    int sum = 0;
    for(unsigned int i = 0; i < size;)
    {
        i = addFigure(data, i, sum);
    }
    return sum;
}

int AreaCalculator::addFigure(const char* data, unsigned int index, int& cumulativeArea)
{
    figures::FigureType figureType = static_cast<figures::FigureType>(data[index]);
    unsigned int nextIndex = figureReaderMap_[figureType]->read(data, index);
    cumulativeArea += figureReaderMap_[figureType]->getFigureArea();

    return nextIndex;
}