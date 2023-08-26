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
