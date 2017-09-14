#ifndef INPUT_READERS_HPP
#define INPUT_READERS_HPP

#include <memory>

namespace readers
{

class SquareData
{
public:
    unsigned int read(const char* data, unsigned int index);
private:
    int sizeDataOffset_ {3};
    int nextFigureDataOffset_ {4};

};

class RectangleData
{
public:
    unsigned int read(const char* data, unsigned int index);
private:
    int sizeXDataOffset_ {3};
    int sizeYDataOffset_ {4};
    int nextFigureDataOffset_ {5};

};

class CircleData
{
public:
    unsigned int read(const char* data, unsigned int index);
private:
    int radiusDataOffset_ {3};
    int nextFigureDataOffset_ {4};
};

class PolygonData
{
public:
    unsigned int read(const char* data, unsigned int index);
private:
    int firstVerticeDataOffset_ {2};
    int elementCountInVertice_ {2};
};


} // namespace readers

#endif // !INPUT_READERS_HPP