#include <iostream>
using namespace std;
/*
    MEHMET HASAT SERINKAN
    21901649
*/
class ArrayBasedStack {
public:
    ArrayBasedStack( int length );
    ~ArrayBasedStack();
    bool isEmpty();
    bool push( int item );
    bool pop();
    bool getTop( int& item );

private:
    int* arr;
    int top;
    int size;
};

ArrayBasedStack::ArrayBasedStack( int length ) {
    this->top = -1;
    this->size = length;
    this->arr = new int[length];
}

ArrayBasedStack::~ArrayBasedStack() {
    delete []arr;
}

bool ArrayBasedStack::isEmpty() {
    if( top == -1 ) {
        return true;
    }
    else {
        return false;
    }
}

bool ArrayBasedStack::push( int item ) {
    if( top >= size ) {
        return false;
    }
    else {
        top = top + 1;
        arr[ top ] = item;
        return true;
    }
}

bool ArrayBasedStack::pop() {
    if( isEmpty() ) {
        return false;
    }
    else {
        top = top - 1;
        return true;
    }
}

bool ArrayBasedStack::getTop( int& item ) {
    if( isEmpty() ) {
        return false;
    }
    else {
        item = arr[top];
        return true;
    }
}
