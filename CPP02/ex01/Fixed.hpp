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
};

std::ostream &operator<<(std::ostream & os, const Fixed &t);

#endif