//:Hen.cpp

#include <iostream>
#include "Hen.h"

using namespace std;

Hen::Hen() {
	cout << "Initializing the Hen constructor." << endl;
}

Hen::~Hen() {
	cout << "Initializing the Hen destructor." << endl;
}

void Hen::display() {
	cout << "This is an instance of the display() member function for the Hen class." << endl;
}

Hen::Nest::Nest() {
	cout << "Initializing the Nest constructor." << endl;
}

Hen::Nest::~Nest() {
	cout << "Initializing the Nest destructor." << endl;
}

void Hen::Nest::display() {
	cout << "This is an instance of the display() member function for the Nest class." << endl;
}

Hen::Nest::Egg::Egg() {
	cout << "Initializing the Egg constructor." << endl;
}

Hen::Nest::Egg::~Egg() {
	cout << "Initializing the Egg destructor." << endl;
}

void Hen::Nest::Egg::display() {
	cout << "This is an instance of the display() member function for the Egg class." << endl;
}