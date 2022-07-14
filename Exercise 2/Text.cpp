//:Text.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

Text::Text(){
	cout << "This is the constructor when no arguments are passed." << endl;
}

Text::Text(string x){
	cout << x << endl << endl; //insert name of the file
	ifstream readIn(x.c_str()); //converts string to character to be accepted by ifstream
	string temp((istreambuf_iterator<char>(readIn)), istreambuf_iterator<char>());
	stringObj = temp;
}

string Text::contents(){
	return stringObj;
}