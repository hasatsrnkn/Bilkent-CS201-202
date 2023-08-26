/*
    Mehmet Hasat Serinkan
    21901649
*/
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int algorithm1(const int a, unsigned long long n, const int p);
int algorithm2(const int a, unsigned long long n, const int p);
int algorithm3(const int a, unsigned long long n, const int p);

int main() {
    double duration;
    clock_t startTime = clock();
    int x;

    x = algorithm1(3,4000000000,10007);

    cout << x << endl;

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;


return 0;
}

//ALGORITHMS
int algorithm1(const int a, unsigned long long n, const int p) {
    int result = 0;
    unsigned long long value = 1;
    for( unsigned long long i = 0; i < n; i = i + 1 ) {
        value = value * a;
        result = value % p;
    }

    return result;
}

int algorithm2(const int a, unsigned long long n, const int p) {
    int result = 0;
    unsigned long long value = 1;
    for( unsigned long long i = 0; i < n; i = i + 1) {
        if ( result != 1) {
            value = value * a;
            result = value % p;
        }
        else {
            int newResult = 1;
            unsigned long long forLoop = n % i;
            unsigned long newValue = 1;
            for( unsigned long long j = 0; j < forLoop; j = j + 1 ) {
                newValue = newValue * a;
                newResult = newValue % p;
            }

            return newResult;
        }
    }
    return result;
}

int algorithm3(const int a, unsigned long long n, const int p) {

    if( n == 1) {
        return a % p;
    }
    if( n % 2 == 0) {
        unsigned long long  value = algorithm3( a , (n/2) , p) ;
        return (value * value) % p;
    }
    else {
        unsigned long long  value = algorithm3(a , (n - 1) / 2 , p);
        return (a * value * value) % p;
    }
}


