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
