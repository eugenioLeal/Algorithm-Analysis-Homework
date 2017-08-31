#include "SortingAlgorithm.h"

void SortingAlgorithm::bubble(int *arr, int n) {
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
void SortingAlgorithm::cocktail(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n-1;

    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
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
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
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

void SortingAlgorithm::insertion(int *arr, int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
     key = arr[i];
     j = i-1;

     /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
     while (j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
     }
     arr[j+1] = key;
  }
}
void SortingAlgorithm::bucket(int *arr, int n) {
    int i, j;
    int count[n];

    for (i = 0; i < n; i++)
      count[i] = 0;

    for (i = 0; i < n; i++)
      (count[arr[i]])++;

    for (i = 0, j = 0; i < n; i++)
      for(; count[i] > 0; (count[i])--)
        arr[j++] = i;
}

void SortingAlgorithm::counting(int *arr, int n, int min, int max) {
  int index = 0;
  int range = max - min + 1;

  int *bucket = new int[range];
  // fill bucket with zeros
  for(int i = 0; i < range; ++i)
    bucket[i] = 0;

  for(int i = 0; i < n; ++i)
    bucket[arr[i] - min]++;

  for(int i = min; i <= max; ++i) {
    for(int j = 0; j < bucket[i-min]; ++j)
      arr[index++] = i;
  }
  delete[] bucket;

}


void SortingAlgorithm::merge(int *arr, int l, int m, int r) {
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
  while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
          arr[k] = L[i];
          i++;
      }
      else {
          arr[k] = R[j];
          j++;
      }
      k++;
  }

  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
  }

  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
  }
}
void SortingAlgorithm::mergeSort(int arr[], int l, int r) {
   /* l is for left index and r is right index of the
   sub-array of arr to be sorted */
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void SortingAlgorithm::storeSorted(Node *root, int arr[], int &i) {
  // Stores inoder traversal of the BST
  // in arr[]
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
void SortingAlgorithm::binaryTree(int *arr, int n) {
  // This function sorts arr[0..n-1] using Tree Sort

  struct Node *root = NULL;

  // Construct the BST
  root = insert(root, arr[0]);
  for (int i=1; i<n; i++)
      insert(root, arr[i]);

  // Store inoder traversal of the BST
  // in arr[]
  int i = 0;
  storeSorted(root, arr, i);

}
int SortingAlgorithm::getMax(int arr[], int n) {
  // A utility function to get maximum value in arr[]
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void SortingAlgorithm::countSort(int arr[], int n, int exp) {
  // A function to do counting sort of arr[] according to
  // the digit represented by exp.
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
    for (i = n - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void SortingAlgorithm::radix(int *arr, int n) {
  // Find the maximum number to know number of digits
 int m = getMax(arr, n);

 // Do counting sort for every digit. Note that instead
 // of passing digit number, exp is passed. exp is 10^i
 // where i is current digit number
 for (int exp = 1; m/exp > 0; exp *= 10)
     countSort(arr, n, exp);
}


void SortingAlgorithm::shell(int *arr, int n) {
  // Start with a big gap, then reduce the gap
  for (int gap = n/2; gap > 0; gap /= 2)
  {
      // Do a gapped insertion sort for this gap size.
      // The first gap elements a[0..gap-1] are already in gapped order
      // keep adding one more element until the entire array is
      // gap sorted
      for (int i = gap; i < n; i += 1)
      {
          // add a[i] to the elements that have been gap sorted
          // save a[i] in temp and make a hole at position i
          int temp = arr[i];

          // shift earlier gap-sorted elements up until the correct
          // location for a[i] is found
          int j;
          for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
              arr[j] = arr[j - gap];

          //  put temp (the original a[i]) in its correct location
          arr[j] = temp;
      }
  }
}
void SortingAlgorithm::selection(int *arr, int n) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n-1; i++) {
      // Find the minimum element in unsorted array
      min_idx = i;
      for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
          min_idx = j;

      // Swap the found minimum element with the first element
      swap(arr[min_idx], arr[i]);
  }
}

void SortingAlgorithm::heapify(int arr[], int n, int i) {
  // To heapify a subtree rooted with node i which is
  // an index in arr[]. n is size of heap
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void SortingAlgorithm::heap(int *arr, int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

  // One by one extract an element from heap
  for (int i=n-1; i>=0; i--)
  {
      // Move current root to end
      swap(arr[0], arr[i]);

      // call max heapify on the reduced heap
      heapify(arr, i, 0);
  }
}
int SortingAlgorithm::partition(int *arr, int low, int high) {
  int pivot = arr[high];    // pivot
  int i = (low - 1);  // Index of smaller element

  for (int j = low; j <= high- 1; j++) {
      // If current element is smaller than or
      // equal to pivot
      if (arr[j] <= pivot) {
          i++;    // increment index of smaller element
          swap(arr[i], arr[j]);
      }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}
void SortingAlgorithm::quick(int *arr, int low, int high) {
  if (low < high) {
      /* pi is partitioning index, arr[p] is now
         at right place */
      int pi = partition(arr, low, high);

      // Separately sort elements before
      // partition and after partition
      quick(arr, low, pi - 1);
      quick(arr, pi + 1, high);
  }
}
