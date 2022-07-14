//: E3Question3.cpp

/* 
 Title: E3Question2.cpp
 Description: Exercise #3, Question #3
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #3, Question #3
	(i.e. Create a program with a class hierarchy for simple geometry.
	
	1. Create a Point class to store a point's x and y values. Overload the << operator so that the operator prints point values. 
	In addition, overload the + and - operators to add and subtract point coordinates.
	
	2. Create a Shape base class that will serve as the foundation for shapes. The Shape class should have functions to determine the 
	shape's area and circumference, as well as the coordinates (Points) of a rectangle that encloses it (a bounding box). These will be 
	overloaded as neded by the derived classes. The class should have a display() function that displays the class name as well as the class's 
	information (including area, circumference, and bounding box).
	
	3. Extend the hierarchy by creating Shape classes of Circle, Square, and Triangle. For these derived classes, have default constructors 
	and constructors whose arguments can correctly initialize the dahpes using the correct number of Points (i.e., Circle requires a Point 
	centre and a radius; Square requires four Point vertices, while Triangle requires three Point vertices).
	
	4. Create one of each of the following in main(): a Circle with a radius of 23, a Square with sides of 25, and a Triangle with sides of 
	10, 20, and 30. Define each one so that the origin (0, 0) is contained within the object. Each object's information should be displayed.).
 	
 Compile (assuming Cygwin is running): g++ -o E3Question3 E3Question3.cpp Point.cpp Shape.cpp Circle.cpp Square.cpp Triangle.cpp
 Execution (assuming Cygwin is running): ./E3Question3.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
	Point - used to store the 2D Cartesian coordinates (x, y) of a point; '<<' is overloaded to print point values; '+'/'-' add and subtract point coordinates
	Shape - contains 'area,' 'circumference,' and 'className' and associated functions; contains bBox, array of 4 points which stores coordinates of a bounding box;
		display() explicitly displays aforementioned information on screen; lineLength function gets the distance between two points
	Circle (Shape::Circle) - constructor calculates 'radius' based on two points and points of the bounding box; area and circumference are calculated using 
		'radius' and associated functions
	Square (Shape::Square) - constructor evaluates if points create a square and calculates the length of one side (sideA); if points create a square, constructor 
		will set bounding box otherwise bounding box points will be set to (0, 0); if points create a square, area and circumference are calculated using 'sideA' 
		and associated functions
	Triangle (Shape::Triangle) - constructor evaluates if points create a triangle; if points create a triangle, constructor will set bounding box otherwise 
		bounding box points will be set to (0, 0); if points create a triangle, area and circumference are calculated using associated functions

 Variables:
 	point1, point2 - Point - values correspond to a circle with a radius of 23 and with origin in the object; point1 is assumed to be the centre of the circle
	circleInstance - Circle (Shape::Circle) - takes point1 and point2 as arguments for the Circle constructor; uses setArea() and setCircumference() and displays 
		results using display()
	point3, point4, point5, point6 - Point - values correspond to a square with sides of 25 and with origin in the object
	squareInstance - Square (Shape::Square) - takes point3, point4, point5, and point6 as arguments for the Square constructor; uses setArea() and 
		setCircumference() and displays results using display()
	point7, point8, point9 - Point - values correspond to a triangle with sides 10, 20, 30 and with origin in the object
	triangleInstance - Triangle (Shape::Triangle) - takes point7, point8, and point9 as arguments for the Square constructor; uses setArea() and 
		setCircumference() and displays results using display()

*/

/*
 TEST PLAN
 
 Normal case (as per the assignment requirements):
 	> As expected, the program prints out the following:
 		Class name: Circle
		Area (unitless): 1661.06
		Circumference (unitless): 144.44
		Upper right bounding box point (x, y): (23, 23)
		Lower right bounding box point (x, y): (23, -23)
		Lower left bounding box point (x, y): (-23, -23)
		Upper left bounding box point (x, y): (-23, 23)
		
		Class name: Square
		Area (unitless): 625
		Circumference (unitless): 100
		Upper right bounding box point (x, y): (25, 25)
		Lower right bounding box point (x, y): (0, 25)
		Lower left bounding box point (x, y): (0, 0)
		Upper left bounding box point (x, y): (25, 0)
		
		The three points do not create a triangle according to the triangle inequality theorem. The bounding box points, area, and circumference will be set to 0.
		Class name: Triangle
		Area (unitless): 0
		Circumference (unitless): 0
		Upper right bounding box point (x, y): (0, 0)
		Lower right bounding box point (x, y): (0, 0)
		Lower left bounding box point (x, y): (0, 0)
		Upper left bounding box point (x, y): (0, 0)

 Normal case ('Point' arguments do not make four equal sides):
 	> 'point6' changed from (25, 0) to (26, 0)
 	> As expected, the program prints out the following:
		Four equal sides cannot be created using the points given. This not a square.
		Class name: Square
		Area (unitless): 0
		Circumference (unitless): 0
		Upper right bounding box point (x, y): (0, 0)
		Lower right bounding box point (x, y): (0, 0)
		Lower left bounding box point (x, y): (0, 0)
		Upper left bounding box point (x, y): (0, 0)
		
 Normal case ('Point' arguments make a rhomboid):
 	> 'point4' changed from (0, 25) to (5, 0)
 	> 'point5' changed from (25, 25) to (8, 4)
 	> 'point6' changed from (25, 0) to (3, 4)
 	> As expected, the program prints out the following:
 		A right angle cannot be at one of the corners. This is a rhombus, not a square. The bounding box points, area, and circumference will be set to 0.
		Class name: Square
		Area (unitless): 0
		Circumference (unitless): 0
		Upper right bounding box point (x, y): (0, 0)
		Lower right bounding box point (x, y): (0, 0)
		Lower left bounding box point (x, y): (0, 0)
		Upper left bounding box point (x, y): (0, 0)

 Normal case ('Point' arguments make a triangle):		
	> 'point9' changed from (0, 20) to (30, 40)
	> As expected, the program prints out the following:
		Class name: Triangle
		Area (unitless): 600
		Circumference (unitless): 120
		Upper right bounding box point (x, y): (30, 40)
		Lower right bounding box point (x, y): (0, 40)
		Lower left bounding box point (x, y): (0, 0)
		Upper left bounding box point (x, y): (30, 0)
		
 Normal case (test use of operator overloading):
 	> only used operator overloading to fulfill assignment requirements
 	> added the following code to end of main() to test operator:
 		Point c = point4 - point5;
		cout << c << endl;
	> as expected, the program prints out the following:
		(-25, 0)

 Bad case (incorrect number of 'Point' arguments for circle):
 	> does not compile
 	
 Bad case ('Point' arguments are characters instead of numeric):
 	> does not compile
 
 Discussion:
 	There is no explicit input for this program. As directed by the program objectives, a 'Point' class is created to hold information Caretesian information 
 	about a point. A 'Shape' class is created which stores area and circumference information about the object. There is also a display() function to print 
 	out this information. The lineLength() function finds the length of a line given two points. 'Shape' as a base class for the derived classes 'Circle', 
 	'Square', and 'Triangle'. The derived classes takes 2, 4, and 3 points respectively. The 'Square' and 'Triangle' class evaulate if the points can create the
 	expected shape. Because there only two points are necessary for 'Circle', no such validation is necessary; however, it cannot be determined which point 
 	represents the centre). The program objectives explicitly ask for separate functions to set the area and circumference. I would have prefered to integrate 
 	this into the constructor. The program prints to screen the expected lines as per the objective.
*/

/*
 References:
	http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
		> useful for operator overloading
	http://www.purplemath.com/modules/distform.htm
		> distance formula
	http://hotmath.com/hotmath_help/topics/triangle-inequality-theorem.html
		> triangle inequality theorem
	https://en.wikipedia.org/wiki/Heron%27s_formula
		> Heron's formula
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;


int main(){
	
	Point point1(0, 0);
	Point point2(0, 23);
	Circle circleInstance(point1, point2);
	circleInstance.setArea();
	circleInstance.setCircumference();
	circleInstance.display();
		
	Point point3(0, 0);
	Point point4(0, 25);
	Point point5(25, 25);
	Point point6(25, 0);
	Square squareInstance(point3, point4, point5, point6);
	squareInstance.setArea();
	squareInstance.setCircumference();
	squareInstance.display();
	
	Point point7(0, 0);
	Point point8(30, 0);
	Point point9(20, 0);
	Triangle triangleInstance(point7, point8, point9);
	triangleInstance.setArea();
	triangleInstance.setCircumference();
	triangleInstance.display();
	
}