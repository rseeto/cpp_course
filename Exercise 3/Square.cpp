//: Square.cpp

#include <iostream>
#include <cmath>
#include "Square.h"

using namespace std;


Square::Square(){
}

Square::Square(Point one, Point two, Point three, Point four){
	Shape::setClassName("Square");
	
	//validate if points create a square
	if(lineLength(one, two) == lineLength(one, three)){
		if(lineLength(four, three) == lineLength(four, two) && lineLength(four, three) == lineLength(one, two) ){ //length of sides are equal
			double cathetus = pow(lineLength(one, two), 2) + pow(lineLength(one, three), 2);
			double hypotenuse = pow(lineLength(two, three), 2);
			if(cathetus == hypotenuse){ //Pythagorean theorem to check for right angle
				sideA = lineLength(one, two);
				isSquare = true;
			} else {
				cout << "A right angle cannot be at one of the corners. This is a rhombus, not a square. " << 
				"The bounding box points, area, and circumference will be set to 0." << endl;
				isSquare = false;	
			}
		} else {
			cout << "Four equal sides cannot be created using the points given. This is not a square. " << 
			"The bounding box points, area, and circumference will be set to 0." << endl;
			isSquare = false; 
		}	
	} else if(lineLength(one, two) == lineLength(one, four)){
		if(lineLength(three, two) == lineLength(three, four) && lineLength(three, two) == lineLength(one, two) ){
			double cathetus = pow(lineLength(one, two), 2) + pow(lineLength(one, four), 2); 
			double hypotenuse = pow(lineLength(two, four), 2);
			if(cathetus == hypotenuse){
				sideA = lineLength(one, two);
				isSquare = true;
			} else {
				cout << "A right angle cannot be at one of the corners. This is a rhombus, not a square. " << 
				"The bounding box points, area, and circumference will be set to 0." << endl;
				isSquare = false;	
			}
		} else {
			cout << "Four equal sides cannot be created using the points given. This is not a square. " << 
			"The bounding box points, area, and circumference will be set to 0." << endl;
			isSquare = false;
		}
	} else if(lineLength(one, three) == lineLength(one, four)){
		if(lineLength(two, three) == lineLength(two, four) && lineLength(two, three) && lineLength(one, three) ){ 
			double cathetus = pow(lineLength(one, three), 2) + pow(lineLength(one, four), 2);
			double hypotenuse = pow(lineLength(three, four), 2);
			if(cathetus == hypotenuse){
				sideA = lineLength(one, three);
				isSquare = true;
			} else {
				cout << "A right angle cannot be at one of the corners. This is a rhombus, not a square. " << 
				"The bounding box points, area, and circumference will be set to 0." << endl;
				isSquare = false;	
			}
		} else {
			cout << "Four equal sides cannot be created using the points given. This is not a square. " << 
			"The bounding box points, area, and circumference will be set to 0." << endl;
			isSquare = false;
		}
	} else { 
		cout << "Four equal sides cannot be created using the points given. This not a square. " << 
		"The bounding box points, area, and circumference will be set to 0." << endl;
		isSquare = false;
	}

	if(isSquare == true){
		double maxX = max(max(one.getX(), two.getX()), max(three.getX(), four.getX())); //set bounding box parameters
		double minX = min(min(one.getX(), two.getX()), min(three.getX(), four.getX()));
		double maxY = max(max(one.getY(), two.getY()), max(three.getY(), four.getY()));
		double minY = min(min(one.getY(), two.getY()), min(three.getY(), four.getY()));
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

void Square::setArea(){
	if(isSquare == true){
		area = sideA * sideA;
	} else {
		area = 0;
	}
}

void Square::setCircumference(){
	if(isSquare == true){
		circumference = sideA * 4;
	} else {
		circumference = 0;
	}
}
