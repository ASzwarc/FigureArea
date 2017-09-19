#ifndef FIGURES_HPP
#define FIGURES_HPP

#include <vector>
#include <utility>

namespace figures
{

enum class FigureType
{
    Square = 1,
    Rectangle = 2,
    Polygon = 3,
    Circle = 4,
};


class FigureInterface
{
public:
    FigureInterface(FigureType type);
    virtual int calculateArea() const = 0;
private:
    FigureType type_;
};

class Square: public FigureInterface
{
public:
    Square(unsigned int size);
    virtual int calculateArea() const override;
private:
    unsigned int size_;
};

class Rectangle: public FigureInterface
{
public:
    Rectangle(unsigned int size_x, unsigned int size_y);
    virtual int calculateArea() const override;
private:
    unsigned int size_x_;
    unsigned int size_y_;
};

class Circle: public FigureInterface
{
public:
    Circle(unsigned int radius);
    virtual int calculateArea() const override;
private:
    unsigned int radius_;
    float pi_{3.14};
};

class Polygon: public FigureInterface
{
public:
    Polygon(unsigned int vertexCount, std::vector<std::pair<int, int>>&& vertices);
    virtual int calculateArea() const override;
private:
    unsigned int vertexCount_;
    std::vector<std::pair<int, int>> vertices_;
};

} // namespace figures

#endif // FIGURES_HPP