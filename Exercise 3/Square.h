//Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"


class Square: public Shape{
	public:
		Square();
		Square(Point, Point, Point, Point);
		void setArea();
		void setCircumference();
	private:
		double sideA;
		bool isSquare;

};

#endif