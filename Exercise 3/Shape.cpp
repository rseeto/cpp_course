//: Shape.cpp

#include <iostream>
#include <cmath>
#include "Point.h"
#include "Shape.h"

using namespace std;


Shape::Shape(){
}

void Shape::setArea(){
	area = 0;
}

void Shape::setCircumference(){
	circumference = 0;
}

void Shape::display(){
	cout << "Class name: " << className << endl;
	cout << "Area (unitless): " << area << endl;
	cout << "Circumference (unitless): " << circumference << endl;
	cout << "Upper right bounding box point (x, y): " << bBox[0] << endl;//operator overload <<
	cout << "Lower right bounding box point (x, y): " << bBox[1] << endl;
	cout << "Lower left bounding box point (x, y): " << bBox[2] << endl;
	cout << "Upper left bounding box point (x, y): " << bBox[3] << endl << endl;
}

void Shape::setClassName(string x){
	className = x;	
}

double Shape::lineLength(Point pOne, Point pTwo){
	double rise = pOne.getX() - pTwo.getX();
	double run = pOne.getY() - pTwo.getY();
	double riseSqr = rise * rise;
	double runSqr = run * run;
	double sumRiseRun = riseSqr + runSqr;
	return sqrt(sumRiseRun);
}
