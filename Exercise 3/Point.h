//Point.h

#ifndef POINT_H
#define POINT_H

#include <iostream>


class Point{
	public:
		Point();	
		Point(double pX, double pY);
		double getX();
		double getY();		
		Point operator+(Point pt);
		Point operator-(Point pt);
		friend std::ostream &operator << (std::ostream &output, Point &p);
	private:
		double x;
		double y;
};

#endif