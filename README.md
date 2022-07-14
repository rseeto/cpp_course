# C++ course
## Description
This repository contains exercises associated with a course on C++. The 
exercise descriptions are as follows:

### Exercise 1
1. Create a program that will read the contents of a file and counts the  
whitespace-separated words in the file.
2. Create a program that read the contents of a text file and display the lines  
of the file one at a time. The program will wait for the user to press the 
enter key before displaying the subsequent line in the file.
3. Create a program that displays all prime numbers from 1 to 10,000. The  
program should use two nested for loops and the modulus operator (%) to  
complete the task.
4. Create a program that generates a string array of 100 items. To fill the  
array, have your application open a (text) file and read one line from it into  
each string until the array is full. Use the syntax "line #: <string>" to  
display the array, where # is the actual line number and <string> is the stored  
string.

### Exercise 2
1. Create a program to help a video rental store to organize DVD rentals. As  
part of the program, represent a DVD using an abstract data. The rental  
management system must consider all of the data and actions that the DVD type  
may require in order to function properly. There should be a print() member  
function which displays the DVD's information. Make an array of ten DVD  
instances and fill them with data read from a test input file to test the data  
type. Display the DVD information.
2. Create a program which contains a Hen class. Inside the Hen class, create a  
Nest class. Inside the Nest class, create an Egg class. A display() member  
function should be include in every class. In addition, each class should have 
a constructor and destructor that prints an appropriate message when called. 
In main(), create a new instance of each class and call the display() function 
for each class. Use delete to clear the storage after calling display().
3. Create a program with a Text class that has a string object that hold the  
text of a file. The text class should have two constructors: a default  
constructor and a constructor that accepts a string parameter that is the name  
of the file to open. Have the second constructor open the file and read the 
data into the string member object. Create a member function called contents()
that returns the string so it can be displayed. In main(), have Text open the
file and display the contents.

### Exercise 3
1. Create a program where a const whose value is determined at runtime by  
reading the program's start time (hint: use the <ctime> standard header). Have  
the program construct two arrays of 10,000 doubles in a separate function. For  
the first array, initialize it with sequential integral values starting with  
100, and for the second array, initialize with the same number in reverse order  
(i.e., the first array would contain 100, 101, 102... while the second array  
contains 10,099, 10,098, 10,097...). In a single loop, iterate through both  
arrays and multiply the corresponding array elements from each array together  
and display the result. Calculate and display the function's elapsed time. For  
this program, do no use inline functions.
2. Recreate the program in Exercise 2, Question 2 (Create a program where a  
const whose value is determined at runtime by reading the program's start time  
(hint: use the <ctime> standard header). Have the program construct two arrays  
of 10,000 doubles in a separate function. For the first array, initialize it  
with sequential integral values starting with 100, and for the second array,  
initialize with the same number in reverse order (i.e., the first array would  
contain 100, 101, 102... while the second array contains 10,099, 10,098,  
10,097...). In a single loop, iterate through both arrays and multiply the  
corresponding array elements from each array together and display the result.  
Calculate and display the function's elapsed time.) but use an inline function  
for the calculation. Compare the processing time for Exercise 2, Question 2  
(non-inline program) to this program (inline).
3. Create a program with a class hierarchy for simple geometry.
	1. Create a Point class to store a point's x and y values. Overload the  
	<< operator so that the operator prints point values. In addition, overload  
	the + and - operators to add and subtract point coordinates.
	2. Create a Shape base class that will serve as the foundation for shapes.  
	The Shape class should have functions to determine the shape's area and  
	circumference, as well as the coordinates (Points) of a rectangle that  
	encloses it (a bounding box). These will be overloaded as neded by the  
	derived classes. The class should have a display() function that displays  
	the class name as well as the class's information (including area,  
	circumference, and bounding box).
	3. Extend the hierarchy by creating Shape classes of Circle, Square, and  
	Triangle. For these derived classes, have default constructors and  
	constructors whose arguments can correctly initialize the dahpes using the  
	correct number of Points (i.e., Circle requires a Point centre and a 
	radius; Square requires four Point vertices, while Triangle requires three
	Point vertices).
	4. Create one of each of the following in main(): a Circle with a radius of  
	23, a Square with sides of 25, and a Triangle with sides of 10, 20, and 30.  
	Define each one so that the origin (0, 0) is contained within the object.  
	Each object's information should be displayed.

## Installation
Compiliation and execution instructions are inside the associated file (as per  
the assignment instructions). An example is below:

Compile (assuming Cygwin is running and in the working directory):
```bash
g++ -o E1Question1 E1Question1.cpp
```
 Execution (assuming Cygwin is running and in the working directory):
```bash
./E1Question1.exe
```

## Notes
- A testing plan is included in the program files (as per the assignment  
instructions).
- The exercise description has been slightly altered to prevent plagurism  
issues.