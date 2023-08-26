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
