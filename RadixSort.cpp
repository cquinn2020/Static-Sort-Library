#include <iostream>
#include "SortLib.h"
using namespace std;
/* Credit to Pedro who wrote a good amount of this code for the lab.
We had permission to use this though. */

// helper function to get the maximum number in an array
template<typename T>
unsigned getMax(T arr[], unsigned n)
{
    unsigned mx = arr[0];
    for (unsigned i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Helper function for radix sort which computes the maxium number
// of digits of in a number in an array.
template<typename T>
unsigned getMaxNDigit(T arr[], unsigned n){
    unsigned int max1 = getMax(arr, n);
    int count = 0;
    while(max1 != 0){
        max1 = max1 / 10;
        count++;
    }
    return count;
}

// Retrieves digit of value at specific digit index [0, nDigits-1]
unsigned getDigitAt(unsigned value, unsigned digit){
    int place = 0; 
    for(int i = 0; i <= digit; ++i){
        place = value % 10;
        value = value / 10; 
    }
    return place;
}

// Counting sort is used as a subroutine for radix sort.
template<typename T>
void countSort(T arr[], unsigned n, unsigned range, unsigned digit)
{
    unsigned output[n];
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[getDigitAt(arr[i], digit)]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < range; i++)
        count[i] += count[i - 1];
 
    
    // Build the output array by reordering elements according to count
    for(int i = n -1; i >= 0; i--){
        output[count[getDigitAt(arr[i], digit)]-1] = arr[i];
        count[getDigitAt(arr[i], digit)]--;

    }
    // copy the sorted array back into the original
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
template<typename T>
void SortLib::RadixSort(T arr[], int n)
{
    // Find the maximum number of digits
    unsigned m = getMaxNDigit(arr, n);
 
    // Do counting sort for every digit.
    for (unsigned i = 0; i < m; i++)
        countSort(arr, n, 10, i);
}

template void SortLib::RadixSort(int*, int);
template unsigned getMax(unsigned*, unsigned int);
template unsigned getMaxNDigit(unsigned*, unsigned n);