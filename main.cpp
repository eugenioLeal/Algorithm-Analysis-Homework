/* This program is part of an Algorithms class homework to measure the execution times of
different sorting algorithms in you're computers hardware and compare it's execution times
using a Raspberry Pi or BeagleBone
Eugenio Leal
*/
#include <iostream>
#include <stdio.h> // printf
#include <cstdlib> // srand, rand, std::atoi, exit
#include <time.h> // time
#include <fstream>
#include "SortingAlgorithm.h"
using namespace std;

// function declarations
void argumentsError();
void fillWithRandom(int *arr, int size, int min, int max, std::ofstream& write);
void readWithRandom(int *arr, int size, std::ifstream& read);
void menu(int *arr, int size, int min, int max, SortingAlgorithm sort);
void printArray(int *arr, int size);

// struct Node
// {
//     int key;
//     struct Node *left, *right;
// };
//
// // A utility function to create a new BST Node
// struct Node *newNode(int item)
// {
//     struct Node *temp = new Node;
//     temp->key = item;
//     temp->left = temp->right = NULL;
//     return temp;
// }
//
// // Stores inoder traversal of the BST
// // in arr[]
// void storeSorted(Node *root, int arr[], int &i)
// {
//     if (root != NULL)
//     {
//         storeSorted(root->left, arr, i);
//         arr[i++] = root->key;
//         storeSorted(root->right, arr, i);
//     }
// }
//
// /* A utility function to insert a new
//    Node with given key in BST */
// Node* insert(Node* node, int key)
// {
//     /* If the tree is empty, return a new Node */
//     if (node == NULL) return newNode(key);
//
//     /* Otherwise, recur down the tree */
//     if (key < node->key)
//         node->left  = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);
//
//     /* return the (unchanged) Node pointer */
//     return node;
// }
//
// // This function sorts arr[0..n-1] using Tree Sort
// void binaryTree(int arr[], int n)
// {
//     struct Node *root = NULL;
//
//     // Construct the BST
//     root = insert(root, arr[0]);
//     for (int i=1; i<n; i++)
//         insert(root, arr[i]);
//
//     // Store inoder traversal of the BST
//     // in arr[]
//     int i = 0;
//     storeSorted(root, arr, i);
// }

int main(int argc, char const *argv[]) {

	// Initialize variables
	int size;
	int min, max;
	int *array;
	int *arrayCopy;

	// Check for existing file containing the random integer array
	ifstream read("randomIntArray.txt");
	if( ! read ) {
		// Generate a new file and write the values of a newly generated random integer array.

		// no arguments Error
		if( argc < 2 ) {
			argumentsError();
			exit(1);
		}

		// filling variables with arguments
		size = atoi(argv[1]);
		min = atoi(argv[2]);
		max = atoi(argv[3]);

		// creating space in memory
		array = new int[size];

		ofstream write("randomIntArray.txt");
		if( !write ) {
			std::cout << "Error" << '\n';
		}
		// Generate an array of random integers
		fillWithRandom(array, size, min, max, write);
		std::cout << "\nInitial Random Integer Array:" << '\n';
		printArray(array, size);

	} else
	{ // If a randomIntArray was previously generated read the values and assign them to an array of corresponding size.
		read >> size;
		read >> min;
		read >> max;
		// creating space in memory
		array = new int[size];

		readWithRandom(array, size, read);
		std::cout << "\nInitial Random Integer Array:" << '\n';
		printArray(array, size);
	}

	// Initialize class SortingAlgorithm
	SortingAlgorithm sort;

	menu(array, size, min, max, sort);

	delete[] array;
	return 0;
}

void argumentsError() {
	std::cout << "\nERROR: no arguments passed \n\nPlease use the following arguments when runing the executable:" << '\n';
	std::cout << "1) size of the array \n2) minimum value in array range \n3) maximum value in array range" << '\n';
}

void fillWithRandom(int *arr, int size, int min, int max, std::ofstream& write) {
	// initialize random seed
	srand(time(NULL));

	// writing the size of the array, the minimum and maximum range values. used for capturing if you run the main program again.
	write << size << endl;
	write << min << endl;
	write << max << endl;

	// fill array
	for(int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
		write << arr[i] << endl; // writing the new random array to the file
	}
}

void readWithRandom(int *arr, int size, std::ifstream& read) {
	// capturing the array from the file
	int randNum;
	for(int i = 0; i < size; i++) {
		read >> randNum;
		arr[i] = randNum;
	}
	cout << "\nCaptured the random integer array from an existing file!" << endl;
}

void menu(int *arr, int size, int min, int max, SortingAlgorithm sort) {
	// Reset the array to it's original state with it's backup.
	int userInput;
	clock_t t;
	std::cout << "\n Choose an algorithm:" << '\n';
	cout << "1) Bubble\n2) Cocktail \n3) Insertion\n4) Bucket\n5) Counting\n6) Merge\n7) Binary Tree\n8) Radix\n9) Shell\n10) Selection\n11) Heap\n12) Quick\n13) Exit\n\n";
	cin >> userInput;
	switch (userInput) {
		case 1:
			t = clock();
			sort.bubble(arr, size);
			t = clock() - t;
			std::cout << "Bubble:\t";
			break;
		case 2:
			t = clock();
			sort.cocktail(arr, size);
			t = clock() - t;
			std::cout << "Cocktail:\t";
			break;
		case 3:
			t = clock();
			sort.insertion(arr, size);
			t = clock() - t;
			std::cout << "Insertion:\t";
			break;
		case 4:
			t = clock();
			sort.bucket(arr, size);
			t = clock() - t;
			std::cout << "Bucket:\t";
			break;
		case 5:
			t = clock();
			sort.counting(arr, size, min, max);
			t = clock() - t;
			std::cout << "Counting:\t";
			break;
		case 6:
			t = clock();
			sort.mergeSort(arr, 0, size - 1);
			t = clock() - t;
			std::cout << "Merge:\t";
			break;
		case 7:
			t = clock();
			sort.binaryTree(arr, size);
			t = clock() - t;
			std::cout << "Binary Tree:\t";
			break;
		case 8:
			t = clock();
			sort.radix(arr, size);
			t = clock() - t;
			std::cout << "Radix:\t";
			break;
		case 9:
			t = clock();
			sort.shell(arr, size);
			t = clock() - t;
			std::cout << "Shell:\t";
			break;
		case 10:
			t = clock();
			sort.selection(arr, size);
			t = clock() - t;
			std::cout << "Selection:\t";
			break;
		case 11:
			t = clock();
			sort.heap(arr, size);
			t = clock() - t;
			std::cout << "Heap:\t";
			break;
		case 12:
			t = clock();
			sort.quick(arr, 0, size - 1);
			t = clock() - t;
			std::cout << "Quick:\t";
			break;
		case 13:
			delete[] arr;
			exit(1);
		default :
			break;
	}
	printArray(arr, size);
	//printf ("%ld clicks or (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	std::cout << "It took " << t << " clicks or (" << (((float)t)*1000)/CLOCKS_PER_SEC << " milliseconds)" << '\n';
}

void printArray(int *arr, int size) {
	std::cout << "\n[ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << "]\n" << '\n';
}

// Calculate time of execution of each algorithm
// sort.timeOfExecution("bubble", sort, array, size);
// printArray(array, size);
//sort.timeOfExecution("cocktail", sort, array, size);
// sort.timeOfExecution("insertion", sort, array, size);
// printArray(array, size);
// //sort.timeOfExecution("bucket", sort, array, size);// segmentation fault
// sort.timeOfExecution("merge", sort, array, size);
// sort.timeOfExecution("selection", sort, array, size);

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
