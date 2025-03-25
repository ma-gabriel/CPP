#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	public:
		static void convert(std::string);
		virtual ~ScalarConverter() = 0;
};

#endif