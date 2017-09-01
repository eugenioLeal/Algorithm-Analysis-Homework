# Algorithm-Analysis-Homework
This program is part of an Algorithms class homework to measure the execution times of different sorting algorithms in you're computers hardware and compare it's execution times using a Raspberry Pi or BeagleBone Eugenio Leal

User manual:
This program can create random integer arrays by passing arguments while running the executable file, this creates a new file with the values; it can also read from an existing file with existing values.

To create an random integer array you must remove a file called randomIntArray.txt from the directory the main.cpp is located; then run the program.

Example:
./exe-main 100 0 10
this creates a new randomIntArray.txt file with your newly created array where the first argument: n elements, second argument: lowest number in array range, third number: highest number in array range.

If the program detects that you allready have a "randomIntArray.txt" in your directory then it reads the array you allready have, thus, creating a way for you to test different algorithms with the same values of the array.
Example:
./exe-main
if you had the existing test file in you're directory, it would just read the values.

In "randomIntArray.txt", the first line: "n elements"(the size of the array) the second line: the lowest number in the range of possible random numbers in the array, third line: the highest range of possible random numbers in the array; followed by all the n random elements of the array.
