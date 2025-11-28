#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point &other);
    Point &operator = (const Point &other);
	Point(const float xf, const float yf);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif