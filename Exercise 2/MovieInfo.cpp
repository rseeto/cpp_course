//:MovieInfo.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "MovieInfo.h"

using namespace std;


void MovieInfo::setTitle(string x){
	title = x;
}

void MovieInfo::setRank(string x){
	rank = x;
}

void MovieInfo::setGross(string x){
	gross = x;
}

void MovieInfo::setYear(string x){
	year = x;
}

void MovieInfo::setTomatometer(string x){
	tomatometer = x;
}

void MovieInfo::setAvailable(string x){
 	string str = x;
	stringstream convert(str);
	if(!(convert >> available)){
		available = 0;
	}
}

void MovieInfo::rtrn(){
	available++;
	cout << "Return successful. There are now " << available
	<< " DVD(s) availalbe to rent." << endl << endl;	
}

void MovieInfo::rnt(){
	available--;
	cout << "Rent successful. There are now " << available
	<< " DVD(s) availalbe to rent." << endl << endl;
}

string MovieInfo::getTitle(){
	return title;
}

int MovieInfo::getAvailable(){
	return available;
}

void MovieInfo::print(){
	cout << "Title: " << title << endl;
	cout << "Rank (by total Worldwide Gross): " << rank << endl;
	cout << "Worldwide Gross (USD): " << gross << endl;
	cout << "Year: " << year << endl;
	cout << "Tomatometer: " << tomatometer << endl;
 	cout << "Copies Available: " << available << endl;
}