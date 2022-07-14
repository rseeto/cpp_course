//: E2Question1.cpp

/* 
 Title: E2Question3.cpp
 Description: Exercise #2, Question #1
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #2, Question #3
	(i.e. Create a program to help a video rental store to organize DVD rentals. As part of the program, 
	represent a DVD using an abstract data. The rental management system must consider all of the data 
	and actions that the DVD type may require in order to function properly. There should be a print() 
	member function which displays the DVD's information. Make an array of ten DVD instances and fill 
	them with data read from a test input file to test the data type. Display the DVD information.).
 	
 Compile (assuming Cygwin is running): g++ -o E2Question1 E2Question1.cpp MovieInfo.cpp
 Execution (assuming Cygwin is running): ./E2Question1.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
 	MovieInfo - contains information about the DVD including title, rank, gross,
 				year, tomatometer rating, available, and associated functions to
 				access the variables. The setAvailable() converts a string to an
 				int. The rnt() and rtrn() change the number of available copies
 				based on a rental or return, respectively.

 Variables:
 	title - string of MovieInfo class - contains the name of the movie
 	rank - string of MovieInfo class - contains the ranking of the movie based on the worldwide gross
 	gross - string of MovieInfo class - contains the amount of money made by the movie 
 	year - string of MovieInfo class - contains the year the movie was released
 	tomatometer - string of MovieInfo class - contains the rating given by Rotten Tomatoes
  	available - int of MovieInfo class - contains the theoretical number of movies available for rent
 	filein - ifstream - used to read in and contain the file
 	lines - vector string - used to contain all the lines (see variable 'byline') from the appropriate file	
 	byline - string - used to capture the lines from the appropriate file
 	numMovie - signed int - stores number of movies in the imported file (assumes there is a header)
 	totalMovie - vector MovieInfo - contains the MovieInfo for all DVDs
 	delimiter - string - indicates what character to split the fields of the input file
 	decision - int - used in the main menu to determine what to print on screen
 	rentDecision - int - used in the rental menu to determine what if the a rental or return should be documented
*/

/*
 TEST PLAN
 
 Normal case 1 (sufficent DVDs):
 	> Please wait while the movie database loads.
	
		The movies in the database are:
		1.      Avatar
		2.      Titanic
		3.      Star Wars: The Force Awakens
		4.      Jurassic World
		5.      The Avengers
		6.      Furious 7
		7.      Avengers: Age of Ultron
		8.      Harry Potter and the Deathly Hallows - Part 2
		9.      Frozen
		10.     Iron Man 3
		
		For more information about a movie, please enter the number corresponding to the movie or '0' to quit. 1
	> Title: Avatar
		Rank (by total Worldwide Gross): 1
		Worldwide Gross (USD): $2,787,965,087
		Year: 2009
		Tomatometer: 83
		Copies Available: 10
		
		Enter '1' to return a DVD, '2' to rent a DVD, or '0' to go to the main menu. 2
	> Rent successful. There are now 9 DVD(s) availalbe to rent.
 	
 Normal case 2 (insufficient DVDs):
 	> Please wait while the movie database loads.
	
		The movies in the database are:
		1.      Avatar
		2.      Titanic
		3.      Star Wars: The Force Awakens
		4.      Jurassic World
		5.      The Avengers
		6.      Furious 7
		7.      Avengers: Age of Ultron
		8.      Harry Potter and the Deathly Hallows - Part 2
		9.      Frozen
		10.     Iron Man 3
		
		For more information about a movie, please enter the number corresponding to the movie or '0' to quit. 1
	> Title: Avatar
		Rank (by total Worldwide Gross): 1
		Worldwide Gross (USD): $2,787,965,087
		Year: 2009
		Tomatometer: 83
		Copies Available: 0
		
		Enter '1' to return a DVD, '2' to rent a DVD, or '0' to go to the main menu. 2
	> There are not enough DVDs to rent.
		Enter '1' to return a DVD, '2' to rent a DVD, or '0' to go to the main menu.
			
 Normal case 3 (incorrect main menu entry):
 	> Please wait while the movie database loads.
	
		The movies in the database are:
		1.      Avatar
		2.      Titanic
		3.      Star Wars: The Force Awakens
		4.      Jurassic World
		5.      The Avengers
		6.      Furious 7
		7.      Avengers: Age of Ultron
		8.      Harry Potter and the Deathly Hallows - Part 2
		9.      Frozen
		10.     Iron Man 3
		
		For more information about a movie, please enter the number corresponding to the movie or '0' to quit. 11
	> That is not an appropriate selection. Please enter a number from '1' to '10' or enter '0' to quit.
	
 Normal case 4 (movielist.txt contains less than 10 movies):
 	> Please wait while the movie database loads.
	
		The movies in the database are:
		1.      Avatar
		2.      Titanic
		3.      Star Wars: The Force Awakens
		4.      Jurassic World
		5.      The Avengers
		6.      Furious 7
		7.      Avengers: Age of Ultron
		8.      Harry Potter and the Deathly Hallows - Part 2
		9.      Frozen
		
		For more information about a movie, please enter the number corresponding to the movie or '0' to quit.
		
 Bad case 1 (file contains no header):
 	> If the file does not contain the header, the program will not provide information about the first DVD.
 	
 Bad case 2 (file contains comma separated values):
 	> If the file is not delimited by vertical bars (e.g. comma separated values), the program will not delimit
 		correctly and the entire information will be stored as the movie title.
 	> If the file reads as: Avatar,1,$2,787,965,087,2009,83,10
 		The title of the movie will be listed as:
 			Avatar,1,$2,787,965,087,2009,83,10
 		The information about the movie will be appear as:
 			Title: Avatar,1,$2,787,965,087,2009,83,10
			Rank (by total Worldwide Gross): Avatar,1,$2,787,965,087,2009,83,10
			Worldwide Gross (USD): Avatar,1,$2,787,965,087,2009,83,10
			Year: Avatar,1,$2,787,965,087,2009,83,10
			Tomatometer: Avatar,1,$2,787,965,087,2009,83,10
			Copies Available: 0

 Bad case 3 (file contains missing field):
 	> If the file contains a missing field, the values will correspond to the next available field
 		and the last field will be filled with the last available field converted to an integer
 	> If the file reads as: Avatar|1|$2,787,965,087|83|10
 		The information about the movie will appear as:
 			Title: Avatar
			Rank (by total Worldwide Gross): 1
			Worldwide Gross (USD): $2,787,965,087
			Year: 83
			Tomatometer: 10
			Copies Available: 10
			
 Bad case 4 (spaces between numerical input):
 	>If a space is put between two numbers (e.g. "1 0"), the program will interpret that as separate inputs
 		instead of a single input (i.e. "10").
 		
 Bad case 5 (empty movielist.txt file):
 	> An empty movielist.txt file will display:
 		Please wait while the movie database loads.
 		
 		Segmentation fault (core dumped)
 		
 Limited case 1 (movielist.txt contains just the header):
 	> The program will load but the only successful option is to quit the program.
 
 Discussion:
 	The assignment asks to create a program used in a DVD rental store. The format of the imported file
 	is strict. It must contain a header, be vertical bar (|) delimited, and must contain all necessary 
 	fields. However, the program can import a movielist.txt with different number of movies. The program 
 	can display information about a particular DVD and it can track the number of available DVDs.
 
*/

/*
 References:
	http://www.cplusplus.com/forum/general/109435/
		> useful for determining how to store an entire file into a string object
	https://www.youtube.com/watch?v=jTS7JTud1qQ&index=13&list=PLAE85DE8440AA6B83
		> helpful for using variables in classes
	http://www.cplusplus.com/articles/D9j2Nwbp/
 		> convert strings to int
 	http://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
 		> helped with parsing strings
*/
 	
#include <iostream>
#include <fstream>
#include <vector>
#include "MovieInfo.h"

using namespace std;

int main(){
 cout << "Please wait while the movie database loads." << endl << endl;
 
	ifstream filein("movieslist.txt");
	
	vector<string> lines;
	string byline;
	
	while(getline(filein, byline)){
	lines.push_back(byline);
	}
	lines.erase(lines.begin()); //deletes header
	signed int numMovie = lines.size();

	MovieInfo totalMovie[numMovie];
	
	string delimiter = "|";
	
	for(int i = 0; i < numMovie; i++){
		totalMovie[i].setTitle(lines[i].substr(0, lines[i].find(delimiter)));
		lines[i].erase(0, lines[i].find(delimiter) + delimiter.length());
		totalMovie[i].setRank(lines[i].substr(0, lines[i].find(delimiter)));
		lines[i].erase(0, lines[i].find(delimiter) + delimiter.length());
		totalMovie[i].setGross(lines[i].substr(0, lines[i].find(delimiter)));
		lines[i].erase(0, lines[i].find(delimiter) + delimiter.length());
		totalMovie[i].setYear(lines[i].substr(0, lines[i].find(delimiter)));
		lines[i].erase(0, lines[i].find(delimiter) + delimiter.length());
		totalMovie[i].setTomatometer(lines[i].substr(0, lines[i].find(delimiter)));
		lines[i].erase(0, lines[i].find(delimiter) + delimiter.length());
		totalMovie[i].setAvailable(lines[i]);
	}

	int decision, rentDecision;	

	while(true){
		cout << "The movies in the database are:" << endl;
		for(int j = 0; j < numMovie; j++){
 			cout << j + 1 << ".\t" <<  totalMovie[j].getTitle() << endl;
 		}
 		cout << endl << "For more information about a movie, please enter the number corresponding to the movie or '0' to quit." << endl;
 		cin >> decision;
 		
 		if(decision == 0){
	 		break;
	 	} 
	 	if(decision >= 1 && decision <= numMovie){
		 	cin.ignore();
		 	cout << endl;
		 	totalMovie[(decision - 1)].print();
			while(true){
				cout << endl << "Enter '1' to return a DVD, '2' to rent a DVD, or '0' to go to the main menu." << endl;
		 		cin >> rentDecision;
				if(rentDecision == 1){
					totalMovie[(decision - 1)].rtrn();
					break;
				} 
				else if(rentDecision == 2 && totalMovie[(decision - 1)].getAvailable() == 0){
					cout << endl <<"There are not enough DVDs to rent.";
				} 
				else if(rentDecision == 2){
					totalMovie[(decision - 1)].rnt();
					break;
				}
				else if(rentDecision == 0){
					break;	
				} 
				else {
					cout << "That is not an appropriate selection.";
				}
			}
		 	continue;
		}
		else{
			cin.ignore();
		 	cout << endl;
		 	cout << "That is not an appropriate selection. Please enter a number from '1' to '" << numMovie 
		 	<< "' or enter '0' to quit." << endl << endl;
			continue;
		}		
	}  
}