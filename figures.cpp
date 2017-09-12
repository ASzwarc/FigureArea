#include "figures.hpp"

#include <vector>
#include <utility>
#include <cstdlib>

namespace figures
{

FigureInterface::FigureInterface(FigureType type):
    type_(type)
{}

Square::Square(unsigned int size):
    FigureInterface(FigureType::Rectangle),
    size_(size)
{}

int Square::calculateArea() const
{
    return size_ * size_;
}

Rectangle::Rectangle(unsigned int size_x, unsigned int size_y):
    FigureInterface(FigureType::Rectangle),
    size_x_(size_x),
    size_y_(size_y)
{}
    
int Rectangle::calculateArea() const
{
    return size_x_*size_y_;
}

Circle::Circle(unsigned int radius):
    FigureInterface(FigureType::Circle),
    radius_(radius)
{}

int Circle::calculateArea() const
{
    return pi_ * radius_ * radius_;
}

Polygon::Polygon(unsigned int vertexCount, std::vector<std::pair<int, int>>&& vertices):
    FigureInterface(FigureType::Polygon),
    vertexCount_(vertexCount),
    vertices_(std::move(vertices))
{}

int Polygon::calculateArea() const
{
    using ConstIter = std::vector<std::pair<int, int>>::const_iterator;
    int sum = 0;
    for(ConstIter it = std::begin(vertices_); it != std::end(vertices_); ++it)
    {
        if (it + 1 >= std::end(vertices_))
        {
            ConstIter firstElem = std::begin(vertices_);
            sum += ((it->first) * (firstElem->second)) - ((it->second) * (firstElem->first));
            break;
        }
        sum += ((it->first) * ((it + 1)->second)) - ((it->second) * ((it + 1)->first));
    }
    return std::abs(sum / 2);
}

} // namespace figures