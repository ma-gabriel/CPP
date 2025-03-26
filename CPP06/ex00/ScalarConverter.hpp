#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter &operator=(const ScalarConverter &);

		virtual ~ScalarConverter() = 0;
	public:
		static void convert(std::string);
};

#endif