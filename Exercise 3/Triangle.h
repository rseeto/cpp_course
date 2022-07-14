//Triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle: public Shape{
	public:
		Triangle();
		Triangle(Point, Point, Point);
		void setArea();
		void setCircumference();
	private:
		double sideA;
		double sideB;
		double sideC;
		bool isTriangle;
};

#endif