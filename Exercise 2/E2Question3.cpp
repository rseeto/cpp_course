//: E2Question3.cpp

/* 
 Title: E2Question3.cpp
 Description: Exercise #2, Question #3
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #2, Question #3
	(i.e. Create a program with a Text class that has a string object that hold the text of a file. 
	The Text class should have two constructors: a default constructor and a constructor that accepts
	 a string parameter that is the name of the file to open. Have the second constructor open the 
	 file and read the data into the string member object. Create a member function called contents() 
	 that returns the string so it can be displayed. In main(), have Text open the file and display 
	 the contents.).
 	
 Compile (assuming Cygwin is running): g++ -o E2Question3 E2Question3.cpp Text.cpp
 Execution (assuming Cygwin is running): ./E2Question3.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
 	Text - used to fulfill the requirements of the assignment (i.e. has a string object 
 		with a destructor and a constructor that takes a string argument that is the name
 		of the file to open; opens file and reads contents)
 		 - has member function contents() which returns and displays the string

 Variables:
 	myObj - Text - used to read in and contain the file	
 	readIn - ifstream used by Text class - used by Text class to read in and contain the file of interest
 	temp - string used by Text class - temporarily stores the entire contents of a file in a single string
 	stringObj - string used by Text class - stores the entire contents of a file in a single string; accessed using contents()
*/

/*
 TEST PLAN
 
 Normal case 1 (txt file as argument):
 	> The program reproduced the file line by line. For the OCanada.txt file, the following will be printed on-screen:
 		OCanada.txt
		O Canada!
		Our home and native land!
		True patriot love in all thy sons command.
		With glowing hearts we see thee rise,
		The True North strong and free!
		From far and wide,
		O Canada, we stand on guard for thee.
		God keep our land glorious and free!
		O Canada, we stand on guard for thee.
		O Canada, we stand on guard for thee.

 Normal case 2 (create variable without arguments):
 	> The program prints out the phrase "This is the constructor when no arguments are passed." as expected.
 
 Bad case 1 (empty file):
 	> The program prints the name of the file on-screen with no lines of text.
 	
 Bad case 2 (file not available):
 	> The program will print the file name but will produce a result similar to an empty file.
 	
 Bad case 3 (file name misspelled):
 	> The program will print the file name but will produce a result similar to an empty file.
 	
 Bad case 4 (file name with no extension):
 	> The program will print the file name but will produce a result similar to an empty file.
 	
 Bad case 5 (non-text file (e.g. TMA2Question1.exe)):
 	> The program will produce giberish and will need to be stopped with ctrl+z.
 
 Discussion:
 	The assignment asks to create two constructors. When a file name is used as an argument for a
 	Text class object, the constructor will print the the lines of the file will be on-screen. If 
 	no argument is passed to Text class object, an appropriate phrase will be printed on-screen. Errors
 	arise if the Text class object has an argument of an inappropriate file name.
 
*/

/*
 References:
	http://www.cplusplus.com/forum/general/109435/
		> useful for determining how to store an entire file into a string object
	https://www.youtube.com/watch?v=jTS7JTud1qQ&index=13&list=PLAE85DE8440AA6B83
		> helpful for using variables in classes
*/

#include <iostream>
#include "Text.h"

using namespace std;


int main() {
	Text myObj("OCanada.txt");
	cout << myObj.contents() << endl;

	//Text myObj2; // use to test out constructor when no arguments are passed	
}
