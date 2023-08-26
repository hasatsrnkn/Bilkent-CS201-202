/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 1
* Description: sorting algorithms, creating arrays, performance analysis
*/
#include "sorting.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int* arr, const int size, int& compCount, int& moveCount) {
    compCount = 0;
    moveCount = 0;
    bool sorted = false;

    for( int pass = 1; ( pass < size ) && !sorted; ++pass ) {
      sorted = true;
      for( int index = 0; index < size - pass; ++index ) {
         int nextIndex = index + 1;
         compCount++;
         if( arr[ index ] > arr[ nextIndex ]) {
            moveCount = moveCount + 3;
            swap( arr[ index ], arr[ nextIndex ] );
            sorted = false; // signal exchange
         }
      }
   }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    merge_sort(arr,0,size-1, size, compCount, moveCount );

}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    quick_sort( arr, 0, size - 1, compCount, moveCount);
}

void quick_sort( int* arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if( first < last ) {
        partition( arr, first, last, pivotIndex, compCount, moveCount );
        quick_sort(arr, first, pivotIndex - 1, compCount, moveCount);
        quick_sort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void partition( int* arr, int first, int last, int& pivotIndex,
               int &compCount, int &moveCount) {

    int pivot = arr[ first ];
    int lastS1 = first;
    int firstUnknown = first + 1;

    for( ; firstUnknown <= last; ++firstUnknown ) {
        compCount++;
        if( arr[firstUnknown] < pivot ) {
            ++lastS1;
            moveCount = moveCount + 3;
            swap( arr[firstUnknown], arr[lastS1] );
        }
    }
    swap( arr[first] , arr[lastS1] );
    moveCount = moveCount + 3;
    pivotIndex = lastS1;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void merge_sort(int *arr, int first, int last, const int size, int &compCount, int &moveCount) {
    if( first < last ) {
        int mid = (first + last) / 2;
        merge_sort( arr, first, mid, size, compCount, moveCount);
        merge_sort( arr, mid+1, last, size, compCount, moveCount);
        merge(arr, first, mid, last, size, compCount, moveCount);
    }
}

void merge( int* arr, int first, int mid, int last, const int size, int &compCount, int &moveCount) {
    int tempArray[ size ];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        moveCount++;
      if (arr[first1] < arr[first2]) {
         tempArray[index] = arr[first1];
         ++first1;
      }
      else {
          tempArray[index] = arr[first2];
          ++first2;
      }
   }

   // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index){
        tempArray[index] = arr[first1];
        moveCount++;
    }

   // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = arr[first2];
        moveCount++;
    }

   // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        moveCount++;
        arr[index] = tempArray[index];
    }
}

void displayArray(const int *arr, const int size) {
    for( int i = 0; i < size; i++ ) {
        cout << arr[ i ] << " ";
    }
    cout << endl;
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    for( int i = 0; i < size; i++ ) {
        int number = rand() % 20000;
        arr1[i] = number;
        arr2[i] = number;
        arr3[i] = number;
    }
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    for( int i = 0; i < size; i++ ) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
    }
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    int x = size;
    for( int i = 0; i < size; i++ ) {
        arr1[i] = x;
        arr2[i] = x;
        arr3[i] = x;
        x--;
    }
}

void performanceAnalysis() { //This function works very slowly on Dijkstra server. However, it gives correct results on a personal computer
    int*randomArr1, *randomArr2, *randomArr3, *randomArr4, *randomArr5, *randomArr6, *randomArr7, *randomArr8, *randomArr9, *randomArr10, *randomArr11, *randomArr12, *randomArr13,
    *randomArr14, *randomArr15, *randomArr16, *randomArr17, *randomArr18, *randomArr19, *randomArr20, *randomArr21, *randomArr22, *randomArr23, *randomArr24, *randomArr25,
    *randomArr26, *randomArr27, *randomArr28, *randomArr29, *randomArr30;

    createRandomArrays( randomArr1, randomArr2, randomArr3, 4000);
    createRandomArrays( randomArr4, randomArr5, randomArr6, 8000);
    createRandomArrays( randomArr7, randomArr8, randomArr9, 12000);
    createRandomArrays( randomArr10, randomArr11, randomArr12, 16000);
    createRandomArrays( randomArr13, randomArr14, randomArr15, 20000);
    createRandomArrays( randomArr16, randomArr17, randomArr18, 24000);
    createRandomArrays( randomArr19, randomArr20, randomArr21, 28000);
    createRandomArrays( randomArr22, randomArr23, randomArr24, 32000);
    createRandomArrays( randomArr25, randomArr26, randomArr27, 36000);
    createRandomArrays( randomArr28, randomArr29, randomArr30, 40000);

    cout << "RANDOM ARRAYS" << endl;
    cout << "----------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    int compCount, moveCount;
    double duration;
    clock_t startTime = clock();
    bubbleSort( randomArr1, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms        " << compCount << "         " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr4, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms       " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr7, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr10, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr13, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr16, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr19, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr22, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr25, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr28, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    //MERGE SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    startTime = clock();
    mergeSort( randomArr2, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr5, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr8, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr11, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr14, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr17, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr20, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr23, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr26, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr29, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "        " << moveCount << endl;


    //QUICK SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    startTime = clock();
    quickSort( randomArr3, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "           " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr6, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr9, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr12, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr15, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr18, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr21, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr24, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr27, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr30, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    delete[] randomArr1;
    delete[] randomArr2;
    delete[] randomArr3;
    delete[] randomArr4;
    delete[] randomArr5;
    delete[] randomArr6;
    delete[] randomArr7;
    delete[] randomArr8;
    delete[] randomArr9;
    delete[] randomArr10;
    delete[] randomArr11;
    delete[] randomArr12;
    delete[] randomArr13;
    delete[] randomArr14;
    delete[] randomArr15;
    delete[] randomArr16;
    delete[] randomArr17;
    delete[] randomArr18;
    delete[] randomArr19;
    delete[] randomArr20;
    delete[] randomArr21;
    delete[] randomArr22;
    delete[] randomArr23;
    delete[] randomArr24;
    delete[] randomArr25;
    delete[] randomArr26;
    delete[] randomArr27;
    delete[] randomArr28;
    delete[] randomArr29;
    delete[] randomArr30;

    cout << endl;

    createAscendingArrays( randomArr1, randomArr2, randomArr3, 4000);
    createAscendingArrays( randomArr4, randomArr5, randomArr6, 8000);
    createAscendingArrays( randomArr7, randomArr8, randomArr9, 12000);
    createAscendingArrays( randomArr10, randomArr11, randomArr12, 16000);
    createAscendingArrays( randomArr13, randomArr14, randomArr15, 20000);
    createAscendingArrays( randomArr16, randomArr17, randomArr18, 24000);
    createAscendingArrays( randomArr19, randomArr20, randomArr21, 28000);
    createAscendingArrays( randomArr22, randomArr23, randomArr24, 32000);
    createAscendingArrays( randomArr25, randomArr26, randomArr27, 36000);
    createAscendingArrays( randomArr28, randomArr29, randomArr30, 40000);

    cout << "ASCENDING ARRAYS" << endl;
    cout << "----------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    startTime = clock();
    bubbleSort( randomArr1, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "               " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr4, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms        " << compCount << "                " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr7, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr10, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr13, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr16, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr19, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr22, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms        " << compCount << "             " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr25, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms       " << compCount << "            " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr28, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms       " << compCount << "            " << moveCount << endl;

    //MERGE SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    startTime = clock();
    mergeSort( randomArr2, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr5, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr8, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr11, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr14, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr17, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr20, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr23, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr26, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr29, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "        " << moveCount << endl;


    //QUICK SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array SizeElapsed   timecompCount  moveCount" << endl;

    startTime = clock();
    quickSort( randomArr3, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr6, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr9, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr12, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr15, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr18, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr21, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr24, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr27, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr30, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    delete[] randomArr1;
    delete[] randomArr2;
    delete[] randomArr3;
    delete[] randomArr4;
    delete[] randomArr5;
    delete[] randomArr6;
    delete[] randomArr7;
    delete[] randomArr8;
    delete[] randomArr9;
    delete[] randomArr10;
    delete[] randomArr11;
    delete[] randomArr12;
    delete[] randomArr13;
    delete[] randomArr14;
    delete[] randomArr15;
    delete[] randomArr16;
    delete[] randomArr17;
    delete[] randomArr18;
    delete[] randomArr19;
    delete[] randomArr20;
    delete[] randomArr21;
    delete[] randomArr22;
    delete[] randomArr23;
    delete[] randomArr24;
    delete[] randomArr25;
    delete[] randomArr26;
    delete[] randomArr27;
    delete[] randomArr28;
    delete[] randomArr29;
    delete[] randomArr30;

    cout << endl;

    createDescendingArrays( randomArr1, randomArr2, randomArr3, 4000);
    createDescendingArrays( randomArr4, randomArr5, randomArr6, 8000);
    createDescendingArrays( randomArr7, randomArr8, randomArr9, 12000);
    createDescendingArrays( randomArr10, randomArr11, randomArr12, 16000);
    createDescendingArrays( randomArr13, randomArr14, randomArr15, 20000);
    createDescendingArrays( randomArr16, randomArr17, randomArr18, 24000);
    createDescendingArrays( randomArr19, randomArr20, randomArr21, 28000);
    createDescendingArrays( randomArr22, randomArr23, randomArr24, 32000);
    createDescendingArrays( randomArr25, randomArr26, randomArr27, 36000);
    createDescendingArrays( randomArr28, randomArr29, randomArr30, 40000);

    cout << "DESCENDING ARRAYS" << endl;
    cout << "----------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array SizeElapsed   timecompCount moveCount" << endl;

    startTime = clock();
    bubbleSort( randomArr1, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms        " << compCount << "         " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr4, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms       " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr7, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr10, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr13, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr16, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr19, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr22, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr25, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms      " << compCount << "        " << moveCount << endl;

    startTime = clock();
    bubbleSort( randomArr28, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    unsigned int x = moveCount;
    cout << "40000   " << duration << " ms      " << compCount << "        " << x << endl;

    //MERGE SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array SizeElapsed   timecompCount   moveCount" << endl;

    startTime = clock();
    mergeSort( randomArr2, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr5, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr8, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr11, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr14, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr17, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr20, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr23, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr26, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    mergeSort( randomArr29, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "        " << moveCount << endl;


    //QUICK SORT
    cout << "----------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array SizeElapsed   timecompCount     moveCount" << endl;

    startTime = clock();
    quickSort( randomArr3, 4000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "4000   " << duration << " ms         " << compCount << "           " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr6, 8000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "8000   " << duration << " ms         " << compCount << "          " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr9, 12000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "12000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr12, 16000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "16000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr15, 20000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "20000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr18, 24000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "24000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr21, 28000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "28000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr24, 32000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "32000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr27, 36000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "36000   " << duration << " ms         " << compCount << "         " << moveCount << endl;

    startTime = clock();
    quickSort( randomArr30, 40000, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "40000   " << duration << " ms         " << compCount << "        " << moveCount << endl;

    delete[] randomArr1;
    delete[] randomArr2;
    delete[] randomArr3;
    delete[] randomArr4;
    delete[] randomArr5;
    delete[] randomArr6;
    delete[] randomArr7;
    delete[] randomArr8;
    delete[] randomArr9;
    delete[] randomArr10;
    delete[] randomArr11;
    delete[] randomArr12;
    delete[] randomArr13;
    delete[] randomArr14;
    delete[] randomArr15;
    delete[] randomArr16;
    delete[] randomArr17;
    delete[] randomArr18;
    delete[] randomArr19;
    delete[] randomArr20;
    delete[] randomArr21;
    delete[] randomArr22;
    delete[] randomArr23;
    delete[] randomArr24;
    delete[] randomArr25;
    delete[] randomArr26;
    delete[] randomArr27;
    delete[] randomArr28;
    delete[] randomArr29;
    delete[] randomArr30;

}


