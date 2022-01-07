#include "SpreadSheetCell.h"
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <memory>
class SpreadsheetApplication { };

class SpreadSheet
{
private:
	size_t width{ 0 };
	size_t height{ 0 };
	const size_t id{ 0 };
	static inline size_t idCounter{ 0 };
	SpreadSheetCell** cells{ nullptr };
	void moveFrom(SpreadSheet& src) noexcept;
	class Implementation;
	std::unique_ptr<Implementation> impl;
public:
	SpreadSheet(size_t width, size_t height, const SpreadsheetApplication& theApp);
	SpreadSheet(const SpreadSheet& source);
	SpreadSheet(SpreadSheet&& src) noexcept; // Move constructor
	~SpreadSheet();
	SpreadSheet& operator=(const SpreadSheet& rhs);
	SpreadSheet& operator=(SpreadSheet&& rhs) noexcept; // Move operator
	void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
	SpreadSheetCell& getCellAt(size_t x, size_t y);
	const SpreadSheetCell& getCellAt(size_t x, size_t y) const;
	void verifyCoordinate(size_t x, size_t y) const;
	size_t getId() const;
	void swap(SpreadSheet& other) noexcept;

	static const size_t maxHeight{ 100 };
	static const size_t maxWidth{ 100 };

};