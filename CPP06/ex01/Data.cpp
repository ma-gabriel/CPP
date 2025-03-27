#include "Data.hpp"


Data::Data()
	:_val(0)
{}

Data::Data(Data const &ref)
	:_val(ref._val)
{}

Data::Data(int const &val)
:_val(val)
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

Data &Data::operator=(const Data &ref)
{
	_val = ref._val;
	return (*this);
}

Data &Data::operator=(const int &ref)
{
	_val = ref;
	return (*this);
}

bool Data::operator==(const Data &ref)
{
	return _val == ref._val;
}

bool Data::operator==(const int &ref)
{
	return _val == ref;
}

