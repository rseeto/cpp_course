//: E1Question3.cpp

/* 
 Title: E1Question3.cpp
 Description: Exercise #1, Question #3
 Author: Ryan Seeto
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Complete the requirements as per Exercise #1, Question #3
	(i.e. Create a program that displays all prime numbers from 1 to 10,000. The program should use 
	two nested for loops and the modulus operator (%) to complete the task. Display all primes found.).
 	
 Compile (assuming Cygwin is running): g++ -o E1Question3 E1Question3.cpp
 Execution (assuming Cygwin is running): ./E1Question3.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
 	i - int - used in a 'for loop' to interate through all numbers up to 10000	
 	j - int - used in a 'for loop' to see if 'i' is divisible by preceeding numbers
*/

/*
 TEST PLAN
 
  Normal case:
 	> The first 10 prime numbers match Wikipedia's List of Prime Numbers 
 	(https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers)
 
 Discussion:
 	There is no input for this program so a single test plan is sufficient. The program produces
 	what is expected.
 
*/

/*
References:
	http://www.tutorialspoint.com/cplusplus/cpp_nested_loops.htm
		> helpful for nested loops
*/


#include <iostream>
using namespace std;
 
int main ()
{
   int i, j;
   
   for(i=2; i<10000; i++) { // looks at numbers 2 through 10000
      for(j=2; j <= (i/j); j++) {//checks to see if divisible by preceeding numbers
	      if(!(i%j)){ // if factor found, not prime
		      break;
		  }  
  	  }    
  	  if(j > (i/j)) { // print out prime number
	  	  cout << i << " is a prime number" << endl;
	  }		      
   }
   return 0;
}