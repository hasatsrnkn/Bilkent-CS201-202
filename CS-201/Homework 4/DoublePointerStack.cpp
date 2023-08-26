#include <iostream>
using namespace std;
/*
    MEHMET HASAT SERINKAN
    21901649
*/

class DoublePointerStack {
public:
    DoublePointerStack();
    ~DoublePointerStack();

    bool isEmpty();
    bool push( double value );
    bool pop();
    bool getTop( double& value );

private:
    struct StackNode {
      double item;
      StackNode* next;
   };

   StackNode *topPtr;
};

DoublePointerStack::DoublePointerStack() {
    topPtr = NULL;
}

DoublePointerStack::~DoublePointerStack() {
    while( !isEmpty() ) {
        pop();
    }
}

bool DoublePointerStack::isEmpty() {
    return topPtr == NULL;
}

bool DoublePointerStack::push( double value ) {
    StackNode *newPtr = new StackNode;
    newPtr->item = value;

    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool DoublePointerStack::pop() {
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

bool DoublePointerStack::getTop( double& value ) {
    if ( isEmpty() ) {
        return false;
    }
    else {
        value = topPtr->item;
        return true;
    }

}
