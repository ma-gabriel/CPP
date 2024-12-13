#ifndef POINT_HPP
# define POINT_HPP

# include <ostream>
# include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;
		Point &operator=(const Point &ref);
    
    public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const float x, const float y);
		Point(const Point &ref);
		~Point(void);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif