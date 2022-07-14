//Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle: public Shape{
	public:
		Circle();
		Circle(Point, Point);
		void setArea();
		void setCircumference();
	private:
		double radius;
};

#endif