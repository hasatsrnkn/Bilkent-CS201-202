/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 1
* Description: main.cpp
*/

#include <iostream>
using namespace std;
#include "sorting.h"


int main() {

    int arr1[16] = {20, 15, 19, 26, 27, 17, 14, 22, 29, 11, 25, 28, 13, 21, 23, 16};
    int arr2[16] = {20, 15, 19, 26, 27, 17, 14, 22, 29, 11, 25, 28, 13, 21, 23, 16};
    int arr3[16] = {20, 15, 19, 26, 27, 17, 14, 22, 29, 11, 25, 28, 13, 21, 23, 16};
    int compCount, moveCount;

    bubbleSort(arr1, 16, compCount, moveCount);
    cout << "CompCount and MoveCounts of bubble sort are " << compCount << " and " << moveCount << endl;
    displayArray(arr1,16);
    cout<< endl;

    mergeSort(arr2, 16, compCount, moveCount);
    cout << "CompCount and MoveCounts of merge sort are " << compCount << " and " << moveCount << endl;
    displayArray(arr1,16);
    cout<< endl;

    quickSort(arr3, 16, compCount, moveCount);
    cout << "CompCount and MoveCounts of quick sort are " << compCount << " and " << moveCount << endl;
    displayArray(arr1,16);
    cout<< endl;

return 0;
}
