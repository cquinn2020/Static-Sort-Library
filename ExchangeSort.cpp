#include "SortLib.h"

/* Exchange Sort:
 - Simple sort in which every element in the list will be compared
  to all other elements in the list. If the element on the left is greater
  than the element on the right, they are swapped. 
*/

template <typename T>
void SortLib::ExchangeSort(T arr[], int size) {
    // Iterate a total of n times on the outer loop (cover every element)
    for (int i = 0; i < size; i++)
    {
        // Compare each ith element to every other element (j) and swap
        // if i > j.
        for (int j = i; j < size; j++)
        {
            // Conditional for swap:
            if (arr[i] > arr[j])
            {   // Create temporary var.
                T temp = arr[i];
                // Swap!
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }
}





// Function instantiation to generate a pattern for the compiler.
template void SortLib::ExchangeSort(int*, int);