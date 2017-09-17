#ifndef INPUT_READERS_HPP
#define INPUT_READERS_HPP

#include <memory>
#include <vector>

namespace readers
{

template<typename FigureType>
class SquareData
{
public:
    unsigned int read(const char* data, unsigned int index)
    {
        //int temp = static_cast<unsigned int>(data[index + sizeDataOffset_]);
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
        //int temp1 = static_cast<unsigned int>(data[index + sizeXDataOffset_]);
        //int temp2 = static_cast<unsigned int>(data[index + sizeYDataOffset_]);
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
        //int temp = static_cast<unsigned int>(data[index + radiusDataOffset_]);
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