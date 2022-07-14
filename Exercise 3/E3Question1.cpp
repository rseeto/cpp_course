//: E3Question1.cpp

/* 
 Title: E3Question1.cpp
 Description: Exercise #3, Question #1
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #3, Question #1
	(i.e. Create a program where a const whose value is determined at runtime by reading the program's 
	start time (hint: use the <ctime> standard header). Have the program construct two arrays of 10,000 
	doubles in a separate function. For the first array, initialize it with sequential integral values 
	starting with 100, and for the second array, initialize with the same number in reverse order 
	(i.e., the first array would contain 100, 101, 102... while the second array contains 10,099, 10,098, 
	10,097...). In a single loop, iterate through both arrays and multiply the corresponding array elements 
	from each array together and display the result. Calculate and display the function's elapsed time. 
	For this program, do no use inline functions.).
 	
 Compile (assuming Cygwin is running): g++ -o E3Question1 E3Question1.cpp
 Execution (assuming Cygwin is running): ./E3Question1.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
	NONE

 Variables:
 	start - const clock_t - used to store the start time of the function
	increase - double - array used to store the increasing values starting with 100
	decrease - double - array used to store the decreasing values starting with 10099
	end - const clock_t - used to store the end time of the function
*/

/*
 TEST PLAN
 
 Normal case:
 	> As expected, the program prints out the following:
		1.04988e+06
		1.03989e+06
		1.02989e+06
		1.0199e+06
		1.0099e+06
		Average time for one iteration (ms): 184.54
	> Only the last 5 values are shown; manual calculations confirmed the value of the last 5 values

 Discussion:
 	There is no input for this program. The program prints to screen the expected lines as per the objective.	
*/

/*
 References:
	http://www.cplusplus.com/forum/beginner/146620/
		> useful for calculating execution time
*/


#include <iostream>
#include <ctime>

using namespace std;

int main(){
	
	const clock_t start = clock();
	double increase[10000];
	double decrease[10000];
	
	for(int j = 0; j < 100; j++){
		for(int i = 0; i < 10000; i++){
			increase[i] = 100 + i;
			decrease[i] = 10099 - i;
			cout << increase[i] * decrease[i] << endl;
		}	
	}
	
	const clock_t end = clock();
	cout << "Average time for one iteration (ms): " << ((end - start)/double(CLOCKS_PER_SEC)*1000)/100 << endl;
	
}