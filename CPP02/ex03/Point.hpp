#ifndef POINT_HPP
# define POINT_HPP

# include <ostream>
# include "Fixed.hpp"

class Point {
	private:
		Fixed	x;
		Fixed	y;
    
    public:
		Point();
		Point(const float x, const float y);
		Point(const Point &ref);
		~Point(void);
		Point &operator=(const Point &ref);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif