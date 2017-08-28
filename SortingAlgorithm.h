#ifndef SORTING_ALGORITHM
#define SORTING_ALGORITHM
#include <iostream>
//#include <stdio.h> // printf
#include <string>
//#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
using namespace std;

class SortingAlgorithm {
public:
  void timeOfExecution(string algorithm, SortingAlgorithm sort, int *array, int size) {
    clock_t t;
    if(algorithm == "bubble") {
      t = clock();
    	sort.bubble(array, size);
    	t = clock() - t;
    } else if( algorithm == "cocktail") {
      t = clock();
      sort.cocktail(array, size);
    	t = clock() - t;
    } else if( algorithm == "insertion") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "bucket") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "counting") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "merge") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "binaryTree") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "radix") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "shell") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "selection") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "heap") {
      t = clock();
    	t = clock() - t;
    } else if( algorithm == "quick") {
      t = clock();
    	t = clock() - t;
    }
    std::cout << "It took " << t << " clicks or (" << ((float)t)/CLOCKS_PER_SEC << ")" << '\n';
    printf ("It took me %ld clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  }
  void bubble(int *arr, int n) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(arr[ i ] > arr[ i+1] ) {
                // here swapping of positions is being done.
                temp = arr[ i ];
                arr[ i ] = arr[ i+1 ];
                arr[ i + 1] = temp;
            }
        }
    }
  }
  void cocktail(int a[], int n)
  {
      bool swapped = true;
      int start = 0;
      int end = n-1;

      while (swapped)
      {
          // reset the swapped flag on entering
          // the loop, because it might be true from
          // a previous iteration.
          swapped = false;

          // loop from left to right same as
          // the bubble sort
          for (int i = start; i < end; ++i)
          {
              if (a[i] > a[i + 1])
              {
                  swap(a[i], a[i+1]);
                  swapped = true;
              }
          }

          // if nothing moved, then array is sorted.
          if (!swapped)
              break;

          // otherwise, reset the swapped flag so that it
          // can be used in the next stage
          swapped = false;

          // move the end point back by one, because
          //  item at the end is in its rightful spot
          --end;

          // from right to left, doing the
          // same comparison as in the previous stage
          for (int i = end - 1; i >= start; --i)
          {
              if (a[i] > a[i + 1])
              {
                  swap(a[i], a[i+1]);
                  swapped = true;
              }
          }

          // increase the starting point, because
          // the last stage would have moved the next
          // smallest number to its rightful spot.
          ++start;
      }
  }
  void insertion(int *arr, int n) {

  }
  void bucket(int *arr, int n) {

  }
  void counting(int *arr, int n) {

  }
  void merge(int *arr, int n) {

  }
  void binaryTree(int *arr, int n) {

  }
  void radix(int *arr, int n) {

  }
  void shell(int *arr, int n) {

  }
  void selection(int *arr, int n) {

  }
  void heap(int *arr, int n) {

  }
  void quick(int *arr, int n) {

  }

};
#endif
