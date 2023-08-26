/*
* Title: Heaps and AVL Tree
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 3
* Description: heap.h
*/
#include <iostream>
using namespace std;
const int MAX_SIZE = 1000000;
class Heap{
public:
    Heap();
    bool heapIsEmpty();
    void insert( const int a );
    int maximum();
    int popMaximum();
    void heapRebuild( int* arr, int index, int n, int& keyComp);

protected:
    void heapRebuild( int root );

private:
    int size;
    int items[ MAX_SIZE ];

};

