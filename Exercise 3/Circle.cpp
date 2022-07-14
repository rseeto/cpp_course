//: Circle.cpp

#include <iostream>
#include "Circle.h"

using namespace std;


Circle::Circle(){
}

Circle::Circle(Point one, Point two){	
	Shape::setClassName("Circle");	
	radius = lineLength(one, two);
	bBox[0] = Point(one.getX() + radius, one.getY() + radius); //set dimension of bounding box
	bBox[1] = Point(one.getX() + radius, one.getY() - radius);
	bBox[2] = Point(one.getX() - radius, one.getY() - radius);
	bBox[3] = Point(one.getX() - radius, one.getY() + radius);
}

void Circle::setArea(){
	area = 3.14 * radius * radius;
}

void Circle::setCircumference(){
	circumference = 2 * 3.14 * radius;
}
