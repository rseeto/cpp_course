//: E3Question2.cpp

/* 
 Title: E3Question2.cpp
 Description: Exercise #3, Question #2
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #3, Question #2
	(i.e. Recreate the program in Exercise 2, Question 2 (Create a program where a const whose value 
	is determined at runtime by reading the program's start time (hint: use the <ctime> standard header). 
	Have the program construct two arrays of 10,000 doubles in a separate function. For the first array, 
	initialize it with sequential integral values starting with 100, and for the second array, initialize 
	with the same number in reverse order (i.e., the first array would contain 100, 101, 102... while the 
	second array contains 10,099, 10,098, 10,097...). In a single loop, iterate through both arrays and 
	multiply the corresponding array elements from each array together and display the result. Calculate 
	and display the function's elapsed time.) but use an inline function for the calculation. Compare the 
	processing time for Exercise 2, Question 2 (non-inline program) to this program (inline).).
 	
 Compile (assuming Cygwin is running): g++ -o E3Question2 E2Question2.cpp
 Execution (assuming Cygwin is running): ./E3Question2.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
 	MyClass - contains 'increase' and 'decrease'; has myFunction() which is an inline function which initializes and prints values

 Variables:
 	start - const clock_t - used to store the start time of the function
	myTest - MyClass - used to access myFunction()
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
		Average time for one iteration (ms): 183.61
	> Only the last 5 values are shown; manual calculations confirmed the value of the last 5 values

 Discussion:
 	There is no input for this program. The program prints to screen the expected lines as per the objective.

 Results:
	It was noticed that the time it took to execute the program varied significantly between trials. The execution time of a program can be affected by factors 
	such as other programs running on the computer. To mitigate the differences in performance, a 'for' loop was constructed for question 1 and question 2 
	that would run the program 100 times. An average of the trials could then be calculated giving a better representation of how long the program takes to 
	execute. While the non-inline program took an average time of 184.54 ms to execute, the inline program was not significantly faster and took an average 
	time of 183.61 ms to execute.

	While the use of 'inline' resulted in faster execution, it was not by much. According to the Standard C++ Foundation, the use of 'inline' functions may make 
	the code execution faster but if using 'inline' in code could also increase execution time (https://isocpp.org/wiki/faq/inline-functions#inline-and-perf). 
	There are various reasons why no significant difference was observed when explicitly declaring the function as 'inline' versus a non-inline program. The 
	compiler may choose to ignore the request to make a designated function 'inline.' Alternatively, the C++ Standard Foundation has also noted that most systems 
	are not CPU-bound. In order for the execution speed to decrease, the CPU needs to be the bottleneck and most often it is not the limiting factor. Explicitly, 
	this means that the CPU needs to be running at near to 100%. Even in cases where the CPU is the limiting factor, the code that is the limiting factor needs to 
	be specified as 'inline' and the function specified as 'inline' is most often not the limiting factor.
*/

/*
 References:
	https://isocpp.org/wiki/faq/inline-functions#inline-member-fns
		> useful for creating 'inline' function
	http://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header
		> useful for creating 'inline' function
	http://www.cplusplus.com/forum/beginner/146620/
		> useful for calculating execution time
	https://isocpp.org/wiki/faq/inline-functions#inline-and-perf
		> discussion on why 'inline' functions may not decrease execution time
*/



#include <iostream>
#include <ctime>
#include "MyClass.h"

using namespace std;	


int main(){
	
	const clock_t start = clock();
	MyClass myTest;
	
	for(int j = 0; j < 100; j++){
		myTest.myFunction();
	}
	
	const clock_t end = clock();
	cout << "Average time for one iteration (ms): " << ((end - start)/double(CLOCKS_PER_SEC)*1000)/100 << endl;
	
}