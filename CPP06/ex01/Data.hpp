#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {
	private:
		int _val;
	public:
		Data();
		Data(Data const &ref);
		~Data();
		int getValue(void) const;
		void setValue(int const &value);
};

#endif