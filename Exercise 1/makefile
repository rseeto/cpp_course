#: makefile
 
# Title: makefile
# Description: makefile for E1Question4.cpp
# Author: Ryan Seeto
# Version: 1.0

#References:
#	https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

# the compiler: g++ for C++
CC = g++

# compiler flags:
# -g adds debugging information to the executable file
CFLAGS = -DDEBUG -g

E1Question4: E1Question4.cpp
	$(CC) -o E1Question4 E1Question4.cpp

debug: E1Question4.cpp
	$(CC) $(CFLAGS) -o E1Question4 E1Question4.cpp