#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float x = point.getX().toFloat();
	float y = point.getY().toFloat();

	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();

	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();

	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();

	float denom = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
	float alpha = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denom;
	float beta = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denom;
	float gamma = 1.0f - alpha - beta;

	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1)
		return true;

	return false;
}