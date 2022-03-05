#include <iostream>
#include "SortLib.h"
using namespace std;
template<typename T>
void SortLib::BubbleSort(T arr[], int size){
    int temp;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size-1-i; ++j){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
template void SortLib::BubbleSort(int*, int);