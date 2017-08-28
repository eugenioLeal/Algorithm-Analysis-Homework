/* This program is part of an Algorithms class homework to measure the execution times of
different sorting algorithms in you're computers hardware and compare it's execution times
using a Raspberry Pi or BeagleBone
Eugenio Leal
*/
#include <iostream>
#include <stdio.h> // printf
#include <cstdlib> // srand, rand, std::atoi
#include <time.h> // time
#include <exception>
#include "SortingAlgorithm.h"
using namespace std;

// function declarations
void argumentsError();
void fillWithRandom(int *arr, int size, int min, int max);
void printArray(int *arr, int size);

int main(int argc, char const *argv[]) {
	// no arguments Error
	if( argc < 2 ) {
		argumentsError();
		exit(1);
	}
	// Initialize variables
	int size = atoi(argv[1]);
	int min = atoi(argv[2]), max = atoi(argv[3]);

	// Generate an array of random integers
	int *array = new int[size];
	fillWithRandom(array, size, min, max);
	//std::cout << "\nInitial Random Integer Array:" << '\n';
	//printArray(array, size);

	// Initialize class SortingAlgorithm
	SortingAlgorithm sort;
	// Calculate time of execution of each algorithm
	sort.timeOfExecution("bubble", sort, array, size);

	delete[] array;
	return 0;
}

void argumentsError() {
	std::cout << "\nERROR: no arguments passed \n\nPlease use the following arguments when runing the executable:" << '\n';
	std::cout << "1) size of the array \n2) minimum value in array range \n3) maximum value in array range" << '\n';
}

void fillWithRandom(int *arr, int size, int min, int max) {
	// initialize random seed
	srand(time(NULL));

	// fill array
	for(int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int *arr, int size) {
	std::cout << "\n[ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << "]\n" << '\n';
}

// try {
// 	int *array = new int[size];
// }
// catch( exception &e ) {
// 	std::cout << "Standard Exception: " << e.what() << '\n';
// }

// clock_t t = clock();
// sort.bubble(array, size);
// t = clock() - t;
// std::cout << "It took " << t << " clicks or (" << ((float)t)/CLOCKS_PER_SEC << ")" << '\n';
// printf ("It took me %ld clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
