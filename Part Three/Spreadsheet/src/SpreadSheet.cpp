#include "SpreadSheet.h"

void mySwap(SpreadSheet& first, SpreadSheet& second) noexcept;

class SpreadSheet::Implementation
{
public: 
	Implementation(size_t width, size_t height);
	Implementation(const Implementation& src);
	Implementation(Implementation&&) noexcept = default;
	~Implementation();
	Implementation& operator=(const Implementation& rhs);
	Implementation& operator=(Implementation &&) noexcept = default;
	void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
	SpreadSheetCell& getCellAt(size_t x, size_t y);
	size_t getId() const;
	void swap(Implementation& other) noexcept;
private:
};

SpreadSheet::Implementation::Implementation(const SpreadSh)

/* Deep Copy Constructor */
/* The initialiser first init. a SpreadSheet with the correct sizes (delagates memory) */
SpreadSheet::SpreadSheet(const SpreadSheet& source) : SpreadSheet{ source.width,source.height }
{
	for (size_t i{ 0 }; i < width; i++)
	{
		for (size_t j{ 0 }; j < width; j++)
		{
			cells[i][j] = source.cells[i][j];
		}
	}
}

/* Assignment operator */
SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
{
	SpreadSheet tmp{ rhs };

	swap(tmp);

	return *this;
}

/* Move Constructior */
SpreadSheet::SpreadSheet(SpreadSheet&& src) noexcept
{
	//moveFrom(src);

	//swap can be used to create a more general move constructor
	// moveFrom would require constant maintenance.
	mySwap(*this, src);

}

/* Move Operator */
SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhs) noexcept
{
	//Check self-assignment
	if (this == &rhs)
	{
		return *this;
	}

	//// Free the old memory and move ownership
	//cleanup();
	//moveFrom(rhs);

	//swap can be used instead
	mySwap(*this, rhs);

	return *this;
}


SpreadSheet::~SpreadSheet()
{
	// delete allocated memory
	for (size_t i{ 0 }; i < width; i++)
	{
		delete[] cells[i];
	}
	delete[] cells;
	cells = nullptr;

}

void SpreadSheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= width)
	{
		throw std::out_of_range{ "x is out of range" };
	}
	if (y >= height)
	{
		throw std::out_of_range{ "y is out of range" };
	}
}

void SpreadSheet::setCellAt(size_t x, size_t y, const SpreadSheetCell& cell)
{
	verifyCoordinate(x, y);
	cells[x][y] = cell;
}

SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y)
{
	return const_cast<SpreadSheetCell&>(std::as_const(*this).getCellAt(x, y));
}

const SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return cells[x][y];
}

// Exception-safe swap
void SpreadSheet::swap(SpreadSheet& other) noexcept
{
	std::swap(width, other.width);
	std::swap(height, other.height);
	std::swap(cells, other.cells);
}

void mySwap(SpreadSheet& first, SpreadSheet& second) noexcept
{
	first.swap(second);
}

//void SpreadSheet::cleanup() noexcept
//{
//	for (size_t i{ 0 }; i < width; i++)
//	{
//		delete[] cells[i];
//	}
//	delete[] cells;
//	cells = nullptr;
//	this->width = this->height = 0;
//}

void SpreadSheet::moveFrom(SpreadSheet& src) noexcept
{
	//// shallow copy
	//this->width = src.width;
	//this->height = src.height;
	//this->cells = src.cells;

	//// Reset the object source, because ownership has been moved.
	//src.width = 0;
	//src.height = 0;
	//src.cells = nullptr;

	// using std::exchange instead.
	this->width = std::exchange(src.width, 0);
	this->height = std::exchange(src.height, 0);
	this->cells = std::exchange(src.cells, nullptr);
}