#ifndef SORTING_ALGORITHM
#define SORTING_ALGORITHM
#include <iostream>
//#include <stdio.h> // printf
#include <string>
#include <vector>
#include <algorithm>
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
      std::cout << "Bubble:\t";
    } else if( algorithm == "cocktail") {
      t = clock();
      sort.cocktail(array, size);
    	t = clock() - t;
      std::cout << "Cocktail:\t";
    } else if( algorithm == "insertion") {
      t = clock();
      sort.insertion(array, size);
    	t = clock() - t;
      std::cout << "Insertion:\t";
    } else if( algorithm == "bucket") {
      t = clock();
      sort.bucket(array, size);
    	t = clock() - t;
      std::cout << "Bucket:\t";
    } else if( algorithm == "counting") {
      t = clock();
    	t = clock() - t;
      std::cout << "Counting:\t";
    } else if( algorithm == "merge") {
      t = clock();
      sort.mergeSort(array, 0, size - 1);
    	t = clock() - t;
      std::cout << "Merge:\t";
    } else if( algorithm == "binaryTree") {
      t = clock();
    	t = clock() - t;
      std::cout << "Binary Tree:\t";
    } else if( algorithm == "radix") {
      t = clock();
    	t = clock() - t;
      std::cout << "Radix:\t";
    } else if( algorithm == "shell") {
      t = clock();
    	t = clock() - t;
      std::cout << "Shell:\t";
    } else if( algorithm == "selection") {
      t = clock();
    	t = clock() - t;
      std::cout << "Selection:\t";
    } else if( algorithm == "heap") {
      t = clock();
    	t = clock() - t;
      std::cout << "Heap:\t";
    } else if( algorithm == "quick") {
      t = clock();
    	t = clock() - t;
      std::cout << "Quick:\t";
    }
    //std::cout << "It took " << t << " clicks or (" << ((float)t)/CLOCKS_PER_SEC << ")" << '\n';
    printf ("%ld clicks or (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
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
    int i, key, j;
    for (i = 1; i < n; i++)
    {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
    }
  }
  void bucket(int *arr, int n) {
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
  }
  void counting(int *arr, int n) {

  }
  void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
  }
  /* l is for left index and r is right index of the
   sub-array of arr to be sorted */
  void mergeSort(int arr[], int l, int r)
  {
      if (l < r)
      {
          // Same as (l+r)/2, but avoids overflow for
          // large l and h
          int m = l+(r-l)/2;

          // Sort first and second halves
          mergeSort(arr, l, m);
          mergeSort(arr, m+1, r);

          merge(arr, l, m, r);
      }
  }
  void binaryTree(int *arr, int n) {

  }
  void radix(int *arr, int n) {
    // Find the maximum number to know number of digits
   int m = getMax(arr, n);

   // Do counting sort for every digit. Note that instead
   // of passing digit number, exp is passed. exp is 10^i
   // where i is current digit number
   for (int exp = 1; m/exp > 0; exp *= 10)
       countSort(arr, n, exp);
  }
  // A function to do counting sort of arr[] according to
  // the digit represented by exp.
  void countSort(int arr[], int n, int exp)
  {
      int output[n]; // output array
      int i, count[10] = {0};

      // Store count of occurrences in count[]
      for (i = 0; i < n; i++)
          count[ (arr[i]/exp)%10 ]++;

      // Change count[i] so that count[i] now contains actual
      //  position of this digit in output[]
      for (i = 1; i < 10; i++)
          count[i] += count[i - 1];

      // Build the output array
      for (i = n - 1; i >= 0; i--)
      {
          output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
          count[ (arr[i]/exp)%10 ]--;
      }

      // Copy the output array to arr[], so that arr[] now
      // contains sorted numbers according to current digit
      for (i = 0; i < n; i++)
          arr[i] = output[i];
  }
  // A utility function to get maximum value in arr[]
  int getMax(int arr[], int n)
  {
      int mx = arr[0];
      for (int i = 1; i < n; i++)
          if (arr[i] > mx)
              mx = arr[i];
      return mx;
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
