#include "input_readers.hpp"
#include <vector>

namespace readers
{

unsigned int SquareData::read(const char* data, unsigned int index)
{
    int temp = static_cast<unsigned int>(data[index + sizeDataOffset_]);
    return index + nextFigureIndexOffset_;
}

unsigned int RectangleData::read(const char* data, unsigned int index)
{
    int temp1 = static_cast<unsigned int>(data[index + sizeXDataOffset_]);
    int temp2 = static_cast<unsigned int>(data[index + sizeYDataOffset_]);
    return index + nextFigureIndexOffset_;
}

unsigned int CircleData::read(const char* data, unsigned int index)
{
    int temp = static_cast<unsigned int>(data[index + radiusDataOffset_]);
    return index + nextFigureIndexOffset_;
}

unsigned int PolygonData::read(const char* data, unsigned int index)
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

}//namespace readers