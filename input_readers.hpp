#ifndef INPUT_READERS_HPP
#define INPUT_READERS_HPP

#include <memory>
#include <vector>

#include "figures.hpp"

namespace readers
{

template<typename FigureType>
class SquareData
{
public:
    unsigned int read(const char* data, unsigned int index)
    {
        int size = static_cast<unsigned int>(data[index + sizeDataOffset_]);
        figure_ = std::make_unique<figures::Square>(size);
        return index + nextFigureIndexOffset_;
    }
private:
    int sizeDataOffset_ {3};
    int nextFigureIndexOffset_ {4};
    std::unique_ptr<FigureType> figure_;
};

template<typename FigureType>
class RectangleData
{
public:
    unsigned int read(const char* data, unsigned int index)
    {
        int size_x = static_cast<unsigned int>(data[index + sizeXDataOffset_]);
        int size_y = static_cast<unsigned int>(data[index + sizeYDataOffset_]);
        figure_ = std::make_unique<figures::Rectangle>(size_x, size_y);
        return index + nextFigureIndexOffset_;
    }
private:
    int sizeXDataOffset_ {3};
    int sizeYDataOffset_ {4};
    int nextFigureIndexOffset_ {5};
    std::unique_ptr<FigureType> figure_;
};

template<typename FigureType>
class CircleData
{
public:
    unsigned int read(const char* data, unsigned int index)
    {
        int radius = static_cast<unsigned int>(data[index + radiusDataOffset_]);
        figure_ = std::make_unique<figures::Circle>(radius);
        return index + nextFigureIndexOffset_;
    }
private:
    int radiusDataOffset_ {3};
    int nextFigureIndexOffset_ {4};
    std::unique_ptr<FigureType> figure_;
};

template<typename FigureType>
class PolygonData
{
public:
    unsigned int read(const char* data, unsigned int index)
    {
        std::vector<std::pair<int, int>> vertices;
        int verticesCount = static_cast<unsigned int>(data[index + verticesCountIndexOffset_]);
        vertices.reserve(verticesCount);
        for(unsigned int i = index + firstVerticeIndexOffset_; 
            i < (index + 1 + (elementCountInVertice_ * verticesCount)); 
            i += elementCountInVertice_)
        {
            vertices.emplace_back(std::make_pair<int, int>(static_cast<int>(data[i]), static_cast<int>(data[i + 1])));
        }
        figure_ = std::make_unique<figures::Polygon>(verticesCount, std::move(vertices));
        return index + firstVerticeIndexOffset_ + verticesCount * elementCountInVertice_;
    }
private:
    int verticesCountIndexOffset_ {1};
    int firstVerticeIndexOffset_ {2};
    int elementCountInVertice_ {2};
    std::unique_ptr<FigureType> figure_;
};


} // namespace readers

#endif // !INPUT_READERS_HPP