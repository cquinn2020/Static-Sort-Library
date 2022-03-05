#include "SortLib.h"
#include <iostream>
using std::endl; using std::cout;

void merge(int arr[], int inputSize, int leftHalf[], int leftSize, int rightHalf[], int rightSize) {
    // Need 3 iterator variables.
    int i = 0, j = 0, k = 0;

    // Iterate thru the left and right arrays and add to merged
    while (i < leftSize && j < rightSize)
    {
        // If the left subarrays current element is <= 
        // to the current in right, add to the merged array
        if (leftHalf[i] <= rightHalf[j])
        {
            arr[k] = leftHalf[i];
            i++;
        } else { // else the jth element is smaller
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }
    // Could still be elements left in the left or right array so need 
    // to do clean up. (could be either one)
    while (i < leftSize)
    {   // Cover left array
        arr[k] = leftHalf[i];
        i++; 
        k++;
    }
    while (j < rightSize)
    {   // Cover right array
        arr[k] = rightHalf[j];
        k++;
        j++;
    }
        
}


// Merge Sort
template <typename T>
void SortLib::MergeSort(T arr[], int size) {
    // Condition for empty array or array with one element.
    if (size < 2) { return; }
    // Get midpoint and create two subarrays.
    int mid = size/2;
    int* leftArray = new int[mid];
    int* rightArray = new int[size-mid];
    // Populate the left and right arrays based on their parent.
    for (int i = 0; i < mid; i++)
    {
        leftArray[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {   // If mid is 5, i starts at 5 so (5-5=0)
        rightArray[i - mid] = arr[i];
    }
    // Recursive call on each half.
    MergeSort(leftArray, mid);
    MergeSort(rightArray, size-mid);
    
    // Call merge method
    merge(arr, size, leftArray, mid, rightArray, size-mid);
    delete[] leftArray; delete[] rightArray;
}


template void SortLib::MergeSort(int*, int);

