//: E1Question1.cpp

/* 
 Title: E1Question1.cpp
 Description: Exercise #1, Question #1
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #1, Question #1
	(i.e. Create a program that will read the contents of a file and counts the whitespace-separated 
	words in the file.).
 	
 Compile (assuming Cygwin is running): g++ -o E1Question1 E1Question1.cpp
 Execution (assuming Cygwin is running): ./E1Question1.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
 	words - vector string - used to contain all the words (see variable 'word') from the appropriate file	
 	in - ifstream - read file
 	word - string - used to capture the number of words from the appropriate file	
*/

/*
 TEST PLAN
 
 Normal case:
 	> The program will produce "There are 217 whitespace-separated words in the 'E1Question1.cpp' file."
 
 Discussion:
 	There is no input for this program so a single test plan is sufficient. The program prints out the expected phrase.	
 
*/

/*
References:
	Based on GetWords.cpp by Bruce Eckel, Chapter 2
		> largely provided framework for program
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  vector<string> words;
  ifstream in("E1Question1.cpp");
  string word;
  while(in >> word) {
    words.push_back(word); 
  }
  cout << "There are " << words.size() <<" whitespace-separated words in the 'E1Question1.cpp' file." << endl;
}
