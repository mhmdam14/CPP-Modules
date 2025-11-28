#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point A(0.0f, 0.0f);
	Point B(5.0f, 0.0f);
	Point C(2.5f, 5.0f);

	Point P1(2.5f, 2.0f);
	Point P2(0.0f, 0.0f);
	Point P3(5.0f, 0.0f);
	Point P4(2.5f, 5.0f);
	Point P5(2.5f, 0.0f);
	Point P6(3.75f, 2.5f);
	Point P7(1.25f, 2.5f);
	Point P8(-1.0f, 2.0f);
	Point P9(6.0f, 0.0f);
	Point P10(2.5f, 6.0f);
	Point P11(2.5f, -1.0f);

	Point testPoints[] = {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11};
	for (int i = 0; i < 11; i++)
	{
    	if (bsp(A, B, C, testPoints[i]))
        	std::cout << "Point " << i+1 << " is inside the triangle.\n";
    	else
        	std::cout << "Point " << i+1 << " is outside the triangle.\n";
	}
	return 0;
}