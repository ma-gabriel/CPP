#include "Data.hpp"


Data::Data()
	:_val(15)
{}

Data::Data(Data const &ref)
	:_val(ref._val)
{}

Data::~Data()
{}


int Data::getValue(void) const
{
	return (_val);
}

void Data::setValue(int const &value)
{
	_val = value;
}