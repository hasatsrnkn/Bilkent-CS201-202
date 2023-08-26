#include <iostream>
using namespace std;
/*
    MEHMET HASAT SERINKAN
    21901649
*/

class IntPointerStack {
public:
    IntPointerStack();
    ~IntPointerStack();

    bool isEmpty();
    bool push( int value, int value2 );
    bool pop();
    bool getTop( int& value1, int& value2);

private:
    struct StackNode {
      int item;
      int index;
      StackNode* next;
   };

   StackNode *topPtr;
};

IntPointerStack::IntPointerStack() {
    topPtr = NULL;
}

IntPointerStack::~IntPointerStack() {
    while( !isEmpty() ) {
        pop();
    }
}

bool IntPointerStack::isEmpty() {
    return topPtr == NULL;
}

bool IntPointerStack::push( int value1, int value2 ) {
    StackNode *newPtr = new StackNode;
    newPtr->item = value1;
    newPtr->index = value2;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool IntPointerStack::pop() {
    if ( isEmpty() ) {
        return false;
    }
    else {
      StackNode *temp = topPtr;
      topPtr = topPtr->next;
      temp->next = NULL;
      delete temp;
      return true;
   }

}

bool IntPointerStack::getTop( int& value1, int& value2 ) {
    if ( isEmpty() ) {
        return false;
    }
    else {
        value1 = topPtr->item;
        value2 = topPtr->index;
        return true;
    }

}

