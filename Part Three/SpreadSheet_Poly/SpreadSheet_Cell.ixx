export module SpreadSheet_Cell;

import<string>;
import<string_view>;

export class SpreadSheetCell
{
public:
	virtual ~SpreadSheetCell() = default;
	virtual void set(std::string_view value);
	virtual std::string getString() const;
};