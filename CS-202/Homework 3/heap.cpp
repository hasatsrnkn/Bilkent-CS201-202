/*
* Title: Heaps and AVL Tree
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 3
* Description: heap.cpp
*/
#include <iostream>
using namespace std;
#include "heap.h"

Heap::Heap() {
    size = 0;
}

bool Heap::heapIsEmpty() {
    return ( size == 0);
}

void Heap::insert( const int a ) {
    if( size >= MAX_SIZE ) {
        cout << "Heap is full" << endl;
    }
    else {
        items[ size ] = a;

        int place = size;
        int parent = ( place - 1 ) / 2;

        while ( ( place > 0 ) && ( items[place] > items[parent] ) ) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = ( place - 1 ) / 2;
        }
        ++size;
    }
}

int Heap::maximum() {
    if( size <= 0 ) {
        return -1;
    }
    return items[0];
}

int Heap::popMaximum() {
    if( heapIsEmpty() ) {
        cout << "Heap is empty" << endl;
        return -1;
    }
    else {
        int max = items[0];
        items[0] = items[--size];
        heapRebuild(0);
        return max;
    }
}

void Heap::heapRebuild( int* arr, int index, int n, int& keyComp) {
   int child = 2 * index + 1;
    if( child < n ) {
        int rightChild = child + 1;

        keyComp++;
        if( (rightChild < n) && (arr[rightChild] > arr[child] ) ) {
            child = rightChild;
            keyComp++;
        }

        keyComp++;
        if( arr[index] < arr[child] ) {
            int temp = arr[index];
            arr[index] = arr[child];
            arr[child] = temp;
            heapRebuild( arr, child, n, keyComp );
        }

    }
}


void Heap::heapRebuild( int root ) {
    int child = 2 * root + 1;
    if( child < size ) {
        int rightChild = child + 1;

        if( (rightChild < size) && (items[rightChild] > items[child] ) ) {
            child = rightChild;
        }

        if( items[root] < items[child] ) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild( child );
        }

    }
}

