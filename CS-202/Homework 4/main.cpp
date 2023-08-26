/*
* Title: Balanced Search Trees
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 4
* Description: main.cpp
*/

#include <iostream>
using namespace std;
#include <fstream>
#include "AVLTree.h"

int main( int argc, char** argv ) {
    AVLTree tree;
    if( argc > 1 ) {
        cout<< "Generating Tree (It may take several minutes because of the size of the file)" << endl;
        tree.generateTree( argv[1] );
        cout << "Tree has been generated." << endl;
        ofstream outputFile1;
        ofstream outputFile2;

        outputFile2.open( "wordfreqs" );
        tree.printWordFrequencies( outputFile2 );
        outputFile2.close();

        outputFile1.open("statistics");
        tree.printTotalWordCount( outputFile1 );
        tree.printHeight( outputFile1 );
        tree.printMostFrequent( outputFile1 );
        tree.printLeastFrequent( outputFile1 );
        tree.printStandartDeviation( outputFile1 );
        outputFile1.close();
        cout << "Output files has been created." << endl;
    }
    else {
        cout << "There is no command" << endl;
    }

return 0;
}
