/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 1
* Description: header file of sorting.cpp
*/
#include <iostream>
using namespace std;

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void swap(int& x, int& y);
void merge_sort(int *arr, int first, int last, const int size, int &compCount, int &moveCount);
void merge( int* arr, int first, int mid, int last, const int size, int &compCount, int &moveCount);
void quick_sort( int* arr, int first, int last, int &compCount, int &moveCount);
void partition( int* arr, int first, int last, int& pivotIndex, int &compCount, int &moveCount);
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3,const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void performanceAnalysis();
