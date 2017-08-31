#ifndef SORTING_ALGORITHM
#define SORTING_ALGORITHM
#include <iostream>
#include <stdio.h> // printf
#include <string>
#include <vector>
#include <algorithm> // swap
//#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

class SortingAlgorithm {
public:

  struct Node {
    int key;
    struct Node *left, *right;
  };
  struct Node *newNode(int item) {
    // A utility function to create a new BST Node
      struct Node *temp = new Node;
      temp->key = item;
      temp->left = temp->right = NULL;
      return temp;
  }
  Node* insert(Node* node, int key) {
    /* A utility function to insert a new
       Node with given key in BST */

      /* If the tree is empty, return a new Node */
      if (node == NULL) return newNode(key);

      /* Otherwise, recur down the tree */
      if (key < node->key)
          node->left  = insert(node->left, key);
      else if (key > node->key)
          node->right = insert(node->right, key);

      /* return the (unchanged) Node pointer */
      return node;
  }
  void bubble(int *arr, int n);
  void cocktail(int a[], int n);
  void insertion(int *arr, int n);
  void bucket(int *arr, int n);
  void counting(int *arr, int n, int min, int max);
  void merge(int *arr, int l, int m, int r); // helper to mergeSort
  void mergeSort(int arr[], int l, int r);
  void storeSorted(Node *root, int arr[], int &i); // helper to binaryTree
  void binaryTree(int *arr, int n);
  int getMax(int arr[], int n); // helper to radix
  void countSort(int arr[], int n, int exp); // helper to radix
  void radix(int *arr, int n);
  void shell(int *arr, int n);
  void selection(int *arr, int n);
  void heapify(int arr[], int n, int i); // helper to heap
  void heap(int *arr, int n);
  int partition(int *arr, int low, int high); // helper to quick
  void quick(int *arr, int low, int high);
};
#endif





// void timeOfExecution(string algorithm, SortingAlgorithm sort, int *array, int size) {
//   clock_t t;
//   if(algorithm == "bubble") {
//     t = clock();
//   	sort.bubble(array, size);
//   	t = clock() - t;
//     std::cout << "Bubble:\t";
//   } else if( algorithm == "cocktail") {
//     t = clock();
//     sort.cocktail(array, size);
//   	t = clock() - t;
//     std::cout << "Cocktail:\t";
//   } else if( algorithm == "insertion") {
//     t = clock();
//     sort.insertion(array, size);
//   	t = clock() - t;
//     std::cout << "Insertion:\t";
//   } else if( algorithm == "bucket") {
//     t = clock();
//     sort.bucket(array, size);
//   	t = clock() - t;
//     std::cout << "Bucket:\t";
//   } else if( algorithm == "counting") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Counting:\t";
//   } else if( algorithm == "merge") {
//     t = clock();
//     sort.mergeSort(array, 0, size - 1);
//   	t = clock() - t;
//     std::cout << "Merge:\t";
//   } else if( algorithm == "binaryTree") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Binary Tree:\t";
//   } else if( algorithm == "radix") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Radix:\t";
//   } else if( algorithm == "shell") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Shell:\t";
//   } else if( algorithm == "selection") {
//     t = clock();
//     sort.selection(array, size);
//   	t = clock() - t;
//     std::cout << "Selection:\t";
//   } else if( algorithm == "heap") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Heap:\t";
//   } else if( algorithm == "quick") {
//     t = clock();
//   	t = clock() - t;
//     std::cout << "Quick:\t";
//   }
//   //std::cout << "It took " << t << " clicks or (" << ((float)t)/CLOCKS_PER_SEC << ")" << '\n';
//   printf ("%ld clicks or (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
// }
