#include <iostream>
using namespace std;
/*
    MEHMET HASAT SERINKAN
    21901649
*/
class CharStack {
public:
    CharStack();
    ~CharStack();

    bool isEmpty();
    bool push( char value );
    bool pop();
    bool getTop( char& value );

private:
    struct StackNode {
      char item;
      StackNode* next;
   };

   StackNode *topPtr;
};

CharStack::CharStack() {
    topPtr = NULL;
}

CharStack::~CharStack() {
    while( !isEmpty() ) {
        pop();
    }
}

bool CharStack::isEmpty() {
    return topPtr == NULL;
}

bool CharStack::push( char value ) {
    StackNode *newPtr = new StackNode;
    newPtr->item = value;

    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool CharStack::pop() {
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

bool CharStack::getTop( char& value ) {
    if ( isEmpty() ) {
        return false;
    }
    else {
        value = topPtr->item;
        return true;
    }

}



