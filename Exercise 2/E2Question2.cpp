//: E2Question2.cpp

/* 
 Title: E2Question2.cpp
 Description: Exercise #2, Question #2
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #2, Question #2
	(i.e. Create a program which contains a Hen class. Inside the Hen class, create a Nest class. 
	Inside the Nest class, create an Egg class. A display() member function should be include in 
	every class. In addition, each class should have a constructor and destructor that prints an 
	appropriate message when called. In main(), create a new instance of each class and call the 
	display() function for each class. Use delete to clear the storage after calling display().).
 	
 Compile (assuming Cygwin is running): g++ -o E2Question2 E2Question2.cpp Hen.cpp
 Execution (assuming Cygwin is running): ./E2Question2.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
 	Hen - used to nest the Nest class; has a display() explicitly displays the class name on screen
 	Nest (Hen::Nest) - nested in the Hen class; used to nest the Egg class; has a display() explicitly displays the class name on screen
 	Egg (Hen::Nest::Egg) - nested in the Nest class (Nest class is nested in the Hen class); has a display() explicitly displays the class name on screen

 Variables:
 	henInstance - Hen - has a constructor, deconstructor, and display() function which displays an appropriate message as per assignment objective
 	nestInstance - Nest (Hen::Nest) - has a constructor, deconstructor, and display() function which displays an appropriate message as per assignment objective
 	eggInstance - Egg (Hen::Nest::Egg) - has a constructor, deconstructor, and display() function which displays an appropriate message as per assignment objective
*/

/*
 TEST PLAN
 
 Normal case:
 	> As expected, the program prints out the following:
 		Initializing the Hen constructor.
		Initializing the Nest constructor.
		Initializing the Egg constructor.
		This is an instance of the display() member function for the Hen class.
		This is an instance of the display() member function for the Nest class.
		This is an instance of the display() member function for the Egg class.
		Initializing the Hen destructor.
		Initializing the Nest destructor.
		Initializing the Egg destructor.
 
 Discussion:
 	There is no input for this program. The program prints to screen the expected lines as per the objective.	
 
*/

/*
 References:
	http://www.icce.rug.nl/documents/cplusplus/cplusplus17.html
		> useful for information about nesting classes
	http://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
		> useful for constructors and destructors
	http://www.cplusplus.com/doc/tutorial/dynamic/
		> useful to determine how to use 'new' and 'delete'
*/

 
#include <iostream>
#include "Hen.h"

using namespace std;
 
int main() {
	Hen * henInstance = new Hen;
	Hen::Nest * nestInstance = new Hen::Nest;
	Hen::Nest::Egg * eggInstance = new Hen::Nest::Egg;

	henInstance->display();
	nestInstance->display();
	eggInstance->display();

	delete henInstance;
	delete nestInstance;
	delete eggInstance;
}