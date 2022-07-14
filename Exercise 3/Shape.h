//Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point.h"


class Shape{
	public:
		Shape();
		virtual void setArea();
		virtual void setCircumference();
		void display();
		void setClassName(std::string);
		double lineLength(Point, Point);
	protected:
		Point bBox[4];
		std::string className;
		double area;
		double circumference;
};

#endif