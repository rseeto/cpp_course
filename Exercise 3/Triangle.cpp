//: Triangle.cpp

#include <iostream>
#include <cmath>
#include "Triangle.h"

using namespace std;


Triangle::Triangle(){
}

Triangle::Triangle(Point one, Point two, Point three){
	Shape::setClassName("Triangle");
	sideA = lineLength(one, two);
	sideB = lineLength(one, three);
	sideC = lineLength(two, three);
	
	//validate if points create a triangle
	if((sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA)){ // triangle inequality theorem
		isTriangle = true;
	} else {
		cout << "The three points do not create a triangle according to the triangle inequality theorem." 
		<< " The bounding box points, area, and circumference will be set to 0." << endl;
		isTriangle = false;
	}
	
	if(isTriangle == true){
		double maxX = max(max(one.getX(), two.getX()), three.getX()); //set bounding box parameters
		double minX = min(min(one.getX(), two.getX()), three.getX());
		double maxY = max(max(one.getY(), two.getY()), three.getY());
		double minY = min(min(one.getY(), two.getY()), three.getY());
		bBox[0] = Point(maxX, maxY);
		bBox[1] = Point(minX, maxY);
		bBox[2] = Point(minX, minY);
		bBox[3] = Point(maxX, minY);
	} else {
		bBox[0] = Point(0, 0);
		bBox[1] = Point(0, 0);
		bBox[2] = Point(0, 0);
		bBox[3] = Point(0, 0);
	}
	
	
}

void Triangle::setArea(){
	if(isTriangle == true){
		double semiperimeter = (sideA + sideB + sideC)/2; //area of a triangle calculated using Heron's formula
		area = sqrt(semiperimeter * (semiperimeter - sideA) * (semiperimeter - sideB) * (semiperimeter - sideC));
	} else {
		area = 0;
	}		
}

void Triangle::setCircumference(){
	if(isTriangle == true){
		circumference = sideA + sideB + sideC;
	} else {
		circumference = 0;
	}
}

