#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {
	private:
		int _val;

	public:
		Data();
		Data(int const &);
		Data(Data const &);
		~Data();
		int getValue(void) const;
		void setValue(int const &);
		Data &operator=(const Data &);
		Data &operator=(const int &);
		bool operator==(const Data &);
		bool operator==(const int &);
};

#endif