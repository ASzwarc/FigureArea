#include <map>
#include <memory>

#include "figures.hpp"
#include "input_readers.hpp"

class AreaCalculator
{
public:
    AreaCalculator();
    int calculateArea(const char* data, unsigned int size);

private:
    int addFigure(const char* data, unsigned int index, int& cumulativeArea);
    std::map<figures::FigureType, std::unique_ptr<readers::DataReaderInterface>> figureReaderMap_;
};