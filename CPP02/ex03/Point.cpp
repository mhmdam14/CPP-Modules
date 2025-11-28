#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float xf, const float yf) : x(xf), y(yf)
{}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
