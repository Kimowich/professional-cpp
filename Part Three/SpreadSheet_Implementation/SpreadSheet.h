#include "SpreadSheetCell.h"
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <utility>
#include <algorithm>

class SpreadSheet
{
private:
	size_t width{ 0 };
	size_t height{ 0 };
	const size_t id{ 0 };
	static inline size_t idCounter{ 0 };
	// This could be vector instead
	SpreadSheetCell** cells{ nullptr };
	//void cleanup() noexcept;
	void moveFrom(SpreadSheet& src) noexcept;
public:
	SpreadSheet(size_t width, size_t height);
	SpreadSheet(const SpreadSheet& source);
	SpreadSheet& operator=(const SpreadSheet& rhs);
	SpreadSheet(SpreadSheet&& src) noexcept; // Move constructor
	SpreadSheet& operator=(SpreadSheet&& rhs) noexcept; // Move operator
	~SpreadSheet();
	void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
	SpreadSheetCell& getCellAt(size_t x, size_t y);
	const SpreadSheetCell& getCellAt(size_t x, size_t y) const;
	void verifyCoordinate(size_t x, size_t y) const;
	size_t getId() const;
	void swap(SpreadSheet& other) noexcept;

	static const size_t maxHeight{ 100 };
	static const size_t maxWidth{ 100 };

};