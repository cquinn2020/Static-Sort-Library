#include <iostream>
#include "SortLib.h"
#include <algorithm>
using std::endl;
using std::cout;
// https://www.techiedelight.com/find-minimum-maximum-value-array-cpp/

template <typename T>
T getMaximum(T arr[], int size) {
    T maximum = arr[0]; 
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > maximum)
            {
                maximum = arr[i];
            }
        }
        return maximum;
}


template <typename T>
	void SortLib::CountingSort(T arr[], int size) {
        // Take input array and find min/max to get range for count array
        T maximum = getMaximum(arr, size);
        
        // Create the output array. 
        T* out = new int[size];
        
        // Create the count array and initialize values to zero. 
        int sizeCountArray = maximum+1;
        T* countArr = new T[sizeCountArray] { 0 };

        // Count each element in the input array and place the count at the appropriate 
        // index of the count array. Range is from max-min but indice will be element-minimum
        for (int i = 0; i < size; i++)
        {
            countArr[arr[i]]++;
        }
        
        
        // Modify the count array by adding the previous counts (cummulative)
        // - modified count array indicates the position of each element in out array.
        for (int i = 1; i < sizeCountArray; i++)
        {
            countArr[i] += countArr[i-1];
        }
        
        // Output each element from the input array to the sorted output array by 
        // decreasing its count by 1. 
        for (int i = size - 1;  i >= 0; i--)
        {
            T key = arr[i];
            int pos = --countArr[key];
            out[pos] = key;
        }

        // Copy over into the original and make it sorted.
        for (int i = 0; i < size; i++)
        {
            arr[i] = out[i];
        }
        
        // Delete the created arrays for count and out.
        delete[] out;
        delete[] countArr;

    }

// Function instantiation to generate a pattern for the compiler.
template void SortLib::CountingSort(int*, int);