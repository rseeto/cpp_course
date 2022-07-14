//: Point.cpp

#include "Point.h"

using namespace std;


Point::Point(){
}

Point::Point(double pX, double pY){
	x = pX;
	y = pY;
}

double Point::getX(){
	return x;	
}

double Point::getY(){
	return y;	
}

Point Point::operator+(Point pt){
	double pX = getX() + pt.getX();
	double pY = getY() + pt.getY();
	Point brandNew(pX, pY);
	return(brandNew);
}
		
Point Point::operator-(Point pt){
	double pX = getX() - pt.getX();
	double pY = getY() - pt.getY();
	Point brandNew(pX, pY);
	return(brandNew);	
};

ostream &operator << (ostream &output, Point &p){
	output << "(" << p.x << ", " << p.y << ")";
	return output;
};

