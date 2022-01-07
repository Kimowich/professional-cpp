#pragma once
#include <string>
#include <string_view>
class SpreadSheet_Cell
{
public:
	virtual ~SpreadSheet_Cell() = default;
	virtual void set(std::string_view value) =0;
	virtual std::string getString() const =0;	
};

