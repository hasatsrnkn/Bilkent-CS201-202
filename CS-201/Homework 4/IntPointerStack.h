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
