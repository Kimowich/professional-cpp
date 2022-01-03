#include <SpreadSheetCell.h>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <utility>

class SpreadSheet
{
private:
    bool inRange(size_t value, size_t upper) const;
    size_t width{0};
    size_t height{0};
    // This could be vector instead
    SpreadSheetCell** cells{nullptr};
public:
    SpreadSheet(size_t width, size_t height);
    SpreadSheet(const SpreadSheet& source);
    SpreadSheet& operator=(const SpreadSheet& rhs);
    ~SpreadSheet();
    void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
    SpreadSheetCell& getCellAt(size_t x, size_t y);
    void verifyCoordinate(size_t x, size_t y) const;

    // This function is not allowed to call exceptions
    void swap(SpreadSheet& other) noexcept;
};

SpreadSheet::SpreadSheet(size_t width, size_t height) : width{width},height{height}
{   
    // raw points for learning purposes
    cells = new SpreadSheetCell*[this->width];
    for (size_t i{0}; i < this->width; i++)
    {
        cells[i] = new SpreadSheetCell[height];
    }
}

/* Deep Copy Constructor */
/* The initialiser first init. a SpreadSheet with the correct sizes (delagates memory) */
SpreadSheet::SpreadSheet(const SpreadSheet& source) : SpreadSheet{source.width,source.height}
{
    for (size_t i{0}; i < width; i++)
    {
        for (size_t j{0}; j < width; j++)
        {
            cells[i][j] = source.cells[i][j];
        }
    }
    
}

/* Assignment operator */
SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
{
    SpreadSheet tmp{rhs};

    swap(tmp);

    return *this;
}

SpreadSheet::~SpreadSheet()
{
    // delete allocated memory
    for (size_t i{0}; i < width; i++)
    {
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;
    
}

void SpreadSheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x>=width)
    {
        throw std::out_of_range{"x is out of range"};
    }
    if (y>=height)
    {
        throw std::out_of_range{"y is out of range"};
    }
}

void SpreadSheet::setCellAt(size_t x, size_t y, const SpreadSheetCell& cell)
{
    verifyCoordinate(x,y);
    cells[x][y] = cell;
}

SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x,y);
    return cells[x][y];
}

// Exception-safe swap
void SpreadSheet::swap(SpreadSheet& other) noexcept
{
    std::swap(width, other.width);    
    std::swap(height, other.height);
    std::swap(cells, other.cells);
}

void swap(SpreadSheet& first, SpreadSheet& second) noexcept
{
    first.swap(second);
}