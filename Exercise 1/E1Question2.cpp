//: E1Question2.cpp

/* 
 Title: E1Question2.cpp
 Description: Exercise #1, Question #2
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #1, Question #2
	(i.e. Create a program that read the contents of a text file and display the lines of the file one at a time. 
	The program will wait for the user to press the enter key before displaying the subsequent line in the file.).
 	
 Compile (assuming Cygwin is running): g++ -o E1Question2 E1Question2.cpp
 Execution (assuming Cygwin is running): ./E1Question2.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
 	filein - ifstream - used to read in and contain the file
 	lines - vector string - used to contain all the lines (see variable 'byline') from the appropriate file	
 	byline - string - used to capture the lines from the appropriate file	
*/

/*
 TEST PLAN
 
 Normal case:
 	> The program reproduced the file line by line with the preamble and conclusion.
 
 Discussion:
 	There is no input for this program so a single test plan is sufficient. The program prints out the expected lines.	
 
*/

/*
References:
	http://stackoverflow.com/questions/19337493/reading-one-line-at-a-time-c
		> helpful for reading line by line
	http://stackoverflow.com/questions/903221/press-enter-to-continue
		> helpful for 'pressing enter to continue'
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	cout << "This program will print each line of the program used to create it." << endl;
	cout << "You will be required to press 'enter' to see the proceeding line:" << endl;
	
	ifstream filein("TMA1Question2.cpp");
	
	vector<string> lines;
	string byline;
	
	while(getline(filein, byline)){
	lines.push_back(byline);
	}
	cin.ignore();
	
	for(int i = 0; i < lines.size(); i++){
		cout << lines[i] << endl;
		cin.ignore();
	}
	cout << "You have reached the end of the program. Good-bye!" << endl;	
}