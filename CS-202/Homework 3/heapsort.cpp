/*
* Title: Heaps and AVL Tree
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 3
* Description: heapsort.cpp
*/

#include <iostream>
using namespace std;
#include <fstream>
#include "heap.h"

void heapSort( int* arr, int n, int& keyComp);

int main( int argc, char** argv) {

    const int MAX_SIZE = 1000000;
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(argv[1]);
    if( !inputFile.is_open() ) {
        cout << "There is no input file "<< endl;
        return 0;
    }

    int size = 0;
    int number = 0;
    int* arr = new int[ MAX_SIZE ];
    while( inputFile>>number ) {
        arr[size] = number;
        size++;
    }
    cout << "Size is " << size << endl;
    int keyComp = 0;
    inputFile.close();
    heapSort( arr, size, keyComp);
    outputFile.open(argv[2]);
    for( int i = 0 ; i < size; i++ ) {
        outputFile << arr[i] << endl;
    }
    outputFile.close();

    cout << "Total key comparisons are "<< keyComp << endl;
    delete [] arr;

return 0;
}

void heapSort( int* arr, int n, int& keyComp ) {
    Heap* h = new Heap();
    keyComp = 0;
    for( int index = n/2 - 1; index >= 0; index--) {
        h->heapRebuild(arr, index, n, keyComp);
    }

	for( int last = n-1 ; last > 0 ;  last--) {
		int temp = arr[0];
        arr[0] = arr[last];
        arr[last] = temp;
        h->heapRebuild( arr, 0, last, keyComp);
	}

	delete h;
}
