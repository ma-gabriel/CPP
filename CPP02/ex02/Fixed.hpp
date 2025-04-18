#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
	private:
		int	_value;
        static const int _bits = 8;
    
    public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed(const int ref);
		Fixed(const double ref);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator=(const Fixed &ref);
		bool operator==(const Fixed &ref);
		bool operator>(const Fixed &ref);
		bool operator<(const Fixed &ref);
		bool operator>=(const Fixed &ref);
		bool operator<=(const Fixed &ref);
		bool operator!=(const Fixed &ref);

		Fixed operator*(const Fixed &ref);
		Fixed operator-(const Fixed &ref);
		Fixed operator+(const Fixed &ref);
		Fixed operator/(const Fixed &ref);

		float operator++(void);
		float operator++(int);
		float operator--(void);
		float operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream & os, const Fixed &t);

#endif