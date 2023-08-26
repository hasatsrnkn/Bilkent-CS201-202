#include <iostream>
#include "ArrayBasedStack.h"
#include "CharStack.h"
#include "DoublePointerStack.h"
#include "IntPointerStack.h"
using namespace std;
#include <sstream>

/*
    MEHMET HASAT SERINKAN
    21901649
*/

void fantabulous(string list, int length) {
    ArrayBasedStack* listStack = new ArrayBasedStack( length );
    int commaIndex = 0;
    string stringToInt;
    stringstream ss;
    int num;
    int count = 0;
    bool controller = false;
    for( int i = list.length() - 1; i>=0; i = i - 1) {
        count = count + 1;
        if ( i == 0 ) {
            commaIndex = 0;
            stringToInt = list.substr( 0, count );
            controller = true;
        }
        else {
            if( list[i] == ',' ) {
                commaIndex = i;
                stringToInt = list.substr( commaIndex + 1, count - 1 );
                controller = true;
            }
        }
        if( controller ) {
            ss << stringToInt;
            ss >> num;
            listStack->push( num );
            i = commaIndex;
            controller = false;
            count = 0;
            ss.clear();
        }
    }

     ArrayBasedStack* stackOfPrevGreater = new ArrayBasedStack( length );
    IntPointerStack* tempOfPrevGreater = new IntPointerStack();
    ArrayBasedStack* lister = new ArrayBasedStack( length );

    for( int i = 0; i < length; i = i + 1 ) {
        stackOfPrevGreater->push(-1);
        int value, index, value2;
        tempOfPrevGreater->getTop(value, index);
        if ( !(tempOfPrevGreater->isEmpty()) ) {
            tempOfPrevGreater->getTop(value, index);
        }
        listStack->getTop(value2);
        while( !(tempOfPrevGreater->isEmpty()) && value < value2 ) {
            tempOfPrevGreater->pop();
        }

        if( !(tempOfPrevGreater->isEmpty()) ) {
            stackOfPrevGreater->pop();
            tempOfPrevGreater->getTop(value, index);
            stackOfPrevGreater->push(index);
        }
        tempOfPrevGreater->push( value2, i );
        lister->push( value2 );
        listStack->pop();
    }

    delete listStack;
    delete tempOfPrevGreater;

    ArrayBasedStack* stackOfPrevGreater2 = new ArrayBasedStack( length );
    while( !(stackOfPrevGreater->isEmpty()) ) {
        int number;
        stackOfPrevGreater->getTop( number );

        stackOfPrevGreater2->push( number );
        stackOfPrevGreater->pop();
    }
    delete stackOfPrevGreater;

    ArrayBasedStack* stackOfNextGreater = new ArrayBasedStack( length );
    IntPointerStack* tempOfNextGreater = new IntPointerStack();

    for( int i = length - 1; i>= 0; i = i - 1 ) {
        stackOfNextGreater->push(i);
        int value, index, value2;
        tempOfNextGreater->getTop(value, index);
        if( !(tempOfNextGreater->isEmpty()) ) {
            tempOfNextGreater->getTop(value, index);
        }
        lister->getTop(value2);
        while( !(tempOfNextGreater->isEmpty()) && value < value2 ) {
            tempOfNextGreater->pop();
        }

        if( !(tempOfNextGreater->isEmpty()) ) {
            tempOfNextGreater->getTop(value, index);
            stackOfNextGreater->pop();
            stackOfNextGreater->push(index);
        }
        tempOfNextGreater->push( value2, i );
        lister->pop();
    }

    delete tempOfNextGreater;
    delete lister;

    int nextBig;
    int prevBig;
    int* maximum;
    maximum = new int[length];
    for( int i = 0; i < length; i ++ ) {
        maximum[i] = 0;
    }

    for( int i = 0; i < length; i++ ) {
        stackOfNextGreater->getTop(nextBig);

        stackOfPrevGreater2->getTop(prevBig);

        if( nextBig != i ) {
            maximum[ nextBig - i] = max(maximum[nextBig - i ], i - prevBig);
        }
        stackOfNextGreater->pop();
        stackOfPrevGreater2->pop();
    }
    delete stackOfNextGreater;
    delete stackOfPrevGreater2;
    int result = 0;
    for( int i = 0; i < length; i++ ) {
        result = result + maximum[ i ];
    }
    delete [] maximum;

    cout << "The number of Fantabulous subsequences: " << result << endl;





}

void subset( string intervals, int length ) {
    ArrayBasedStack* firstStack = new ArrayBasedStack( length );
    int commaIndex = 0;
    string stringToInt;
    stringstream ss;
    int num;
    int count = 0;
    bool controller = false;
    for( int i = intervals.size() - 1; i >= 0; i = i - 1 ) {
        count = count + 1;
        if ( i == 0 ) {
            commaIndex = 0;
            stringToInt = intervals.substr( 0, count );
            controller = true;
        }
        else {
            if( intervals[i] == ',' ) {
                commaIndex = i;
                stringToInt = intervals.substr( commaIndex + 1, count - 1 );
                controller = true;
            }
        }
        if( controller ) {
            ss << stringToInt;
            ss >> num;
            firstStack->push( num );
            i = commaIndex;
            controller = false;
            count = 0;
            ss.clear();
        }

    } //stack is created

    ArrayBasedStack* intervalStack = new ArrayBasedStack( length );
    int number1;
    int number2;

    firstStack->getTop( number1 );
    intervalStack->push( number1 );
    firstStack->pop();
    firstStack->getTop( number1 );
    intervalStack->push( number1 );
    firstStack->pop();
    bool controller2 = true;

    while( controller2 ) {
        if( !(firstStack->isEmpty()) ) {
            firstStack->getTop( number1 );
            intervalStack->getTop( number2 );
            if( number2 < number1 ) {
                intervalStack->push( number1 );
                firstStack->pop();
                firstStack->getTop( number1 );
                intervalStack->push( number1 );
                firstStack->pop();
            }
            else {
                firstStack->pop();
                firstStack->getTop( number1 );
                if( number1 >= number2) {
                    intervalStack->pop();
                    intervalStack->push( number1);
                }
                firstStack->pop();
            }
        }
        else {
            controller2 = false;
        }
    }
    delete firstStack;

    ArrayBasedStack* indicatorStack = new ArrayBasedStack( length );
    controller2 = true;
    while( controller2 ) {
        if( !(intervalStack->isEmpty()) ) {
            intervalStack->getTop(number1 );
            indicatorStack->push( number1 );
            intervalStack->pop();

        }
        else {
            controller2 = false;
        }
    }
    delete intervalStack;
    controller2 = true;

    cout << "Joined subsets:";
    while( controller2 ) {
        if( !(indicatorStack->isEmpty()) ) {
            cout << " (";
            for( int i = 0; i < 2; i++ ) {
                indicatorStack->getTop(number1);
                cout << number1;
                if( i == 0 ) {
                    cout << ":";
                }
                indicatorStack->pop();
            }
            cout << ")";
            if( !(indicatorStack->isEmpty()) ) {
                cout << ",";
            }
        }
        else {
            controller2 = false;
        }

    }
    delete indicatorStack;
    cout << endl;
}

string infix2prefix(string expression) {
    CharStack* stack1 = new CharStack();
    string reversed;
    string out;
    int number;
    for( int i = expression.length() - 1; i>= 0; i-- ) {
        reversed = reversed + expression[i];
    }
    for( int i = 0; i < reversed.length(); i = i + 1 ) {
        if( reversed[i] == '(' ) {
            reversed[i] = ')';
        }
        else if( reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    for( int i = 0; i < reversed.length(); i++ ) {
        if( (reversed[i] == '+') || (reversed[i] == '-') ) {
            number = 1;
        }
        else if( (reversed[i] == '*' ) || (reversed[i] == '/') ) {
            number = 2;
        }
        else {
            number = -1;
        }

        if( (reversed[i] >= 'a' && reversed[i] <= 'z') || (reversed[i] >= 'A' && reversed[i] <= 'Z')
           || (reversed[i] >= '0' && reversed[i] <= '9') ) {
            out = out + reversed[i];
        }

        else if( reversed[i] == '(') {
            stack1->push( reversed[i] );
        }

        else if( reversed[i] == ')') {
            char charOfTop;
            stack1->getTop(charOfTop);
            while( !(stack1->isEmpty()) && (charOfTop != '(') ) {
                char temp;
                stack1->getTop(temp);
                out = out + temp;
                stack1->pop();
                if( !(stack1->isEmpty()) ) {
                    stack1->getTop(charOfTop);
                }
            }
            if( !(stack1->isEmpty()) ) {
                stack1->getTop(charOfTop);
            }
            if( charOfTop == '(' ) {
                stack1->pop();
            }
        }
        else if( (number == 1) || (number == 2) ) {
            if( stack1->isEmpty() ) {
                stack1->push(reversed[i]);
            }
            else {
                int number2;
                char temp2;
                stack1->getTop(temp2);
                if( (temp2 == '+') || (temp2 == '-') ) {
                    number2 = 1;
                }
                else if( (temp2 == '*' ) || (temp2 == '/') ) {
                    number2 = 2;
                }
                else {
                    number2 = -1;
                }
                if(number > number2 ) {
                    stack1->push(reversed[i]);
                }

                else if( number == number2 ) {
                    stack1->push(reversed[i]);
                }
                else {
                    if( !(stack1->isEmpty() ) ) {
                        char temp3;
                        stack1->getTop(temp3);
                        if( (temp3 == '+') || (temp3 == '-') ) {
                            number2 = 1;
                        }
                        else if( (temp3 == '*' ) || (temp3 == '/') ) {
                            number2 = 2;
                        }
                        else {
                            number2 = -1;
                        }
                    }

                    while( !(stack1->isEmpty()) && number < number2) {
                        char temp4;
                        stack1->getTop(temp4);
                        out = out + temp4;
                        stack1->pop();
                        if( !(stack1->isEmpty()) ) {
                            stack1->getTop(temp4);
                            if( (temp4 == '+') || (temp4 == '-') ) {
                                number2 = 1;
                            }
                            else if( (temp4 == '*' ) || (temp4 == '/') ) {
                                number2 = 2;
                            }
                            else {
                                number2 = -1;
                            }
                        }
                    }
                    stack1->push(reversed[i]);
                }

            }
        }

    } // end of for
    char temp5;
    while( !stack1->isEmpty() ) {


        stack1->getTop(temp5);
        out = out + temp5;
        stack1->pop();


    }
    string out2;
    for( int i = out.length() - 1; i>= 0; i-- ) {
        out2 = out2 + out[i];
    }
    delete stack1;
    string out3 = "Preix form of " + expression +  " is " + out2;
    return out3;
}

void evaluatePrefix(string expression) {
    DoublePointerStack* stack1 = new DoublePointerStack();
    char character;
    double number1;
    double number2;
    double result;
    for( int i = expression.length(); i >= 0; i-- ) {
        character = expression[i];
        if( isdigit(character) ) {
            number1 = character - '0';
            stack1->push( number1 );
        }
        else {
            stack1->getTop(number1);
            stack1->pop();
            stack1->getTop(number2);
            stack1->pop();
            if( character == '+' ) {
                result = number1 + number2;
            }
            else if( character == '-' ) {
                result = number1 - number2;
            }
            else if ( character == '*' ) {
                result = number1 * number2;
            }
            else if( character == '/' ) {
                result = number1 / number2;
            }
            stack1->push( result );
        }
    }
    stack1->getTop(result);
    delete stack1;
    cout << "Result of " << expression << " is: " << result << endl;
}


