//: E1Question4.cpp

/* 
 Title: E1Question4.cpp
 Description: Exercise #1, Question #4
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #1, Question #4
	(i.e. Create a program that generates a string array of 100 items. To fill the array, have your application 
	open a (text) file and read one line from it into each string until the array is full. Use the syntax 
	"line #: <string>" to display the array, where # is the actual line number and <string> is the stored string.).
 	
 Compile (assuming Cygwin is running): g++ -o E1Question4 E1Question4.cpp
 Execution (assuming Cygwin is running): ./E1Question4.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
 	filein - ifstream - used to read in and contain the file of interest
 	lines - array string - used to contain all the lines (see variable 'byline') from the appropriate file	
 	byline - string - used to capture the lines from the appropriate file
 	i - int - used in 'for loop' to fill array line by line
 	j - int - used in 'for loop' to print out array line by line with line number
*/

/*
 TEST PLAN
 
   Normal case:
 	> Prints out the first 100 lines as referenced by the source file ("Alice in Wonderland.txt")
 
 Discussion:
 	There is no input for this program so a single test plan is sufficient. The program produces
 	what is expected.
 
*/

/*
References:
	http://stackoverflow.com/questions/19337493/reading-one-line-at-a-time-c
		> helpful for reading line by line
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){		
	
	#ifdef DEBUG   
	cout << "Debugging mode on/GDB GNU debugger file created" << endl;  
	#endif
	ifstream filein ("Alice in Wonderland.txt");
	string lines[100]; //array of 100 string objects
	string byline;
	
	for(int i = 0; i < 100; i++) {//fill array line by line
		getline(filein, byline);
		lines[i] = byline;
	}
	for(int j = 0; j < 100; j++) {//print out array line by line with line number
		cout << "line " << j + 1 << ": " << lines[j] << endl;
	}
}