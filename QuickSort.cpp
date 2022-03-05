#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
#include <array>
#include "SortLib.h"
using namespace std;

template<typename T>
int partition(T arr[], int left, int right){
    int base = left -1;
    int compare = 0;
    int pivot = arr[right];
    int temp;
    
    for(compare = left; compare < right; compare += 1) {
        if(arr[compare] <= pivot){
            base += 1;
            temp = arr[base];
            arr[base] = arr[compare];
            arr[compare] = temp;   
        }
    }
    base += 1;
    int temp1 = arr[base];
    arr[base] = pivot;
    arr[right] = temp1;
    return base;
    
}
template<typename T>
void QuickSort1(T arr[], int left, int right){
    
    if(left < right){  
        int pivot = partition(arr, left, right);
        QuickSort1(arr, left, pivot-1);
        QuickSort1(arr, pivot+1, right); 
    }
}


template<typename T>
void SortLib::QuickSort(T arr[], int right){
    QuickSort1(arr, 0, right-1);
}



template void SortLib::QuickSort(int*, int);
template void QuickSort1(int*, int, int);
template int partition(int*, int, int);

