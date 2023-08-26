/*
* Title: Balanced Search Trees
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 4
* Description: AVLTree.cpp
*/
#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    deleteTree( root );
}

void AVLTree::generateTree( char* fileName ) {

    ifstream inputFile;
    inputFile.open( fileName );
    if( !inputFile.is_open() ) {
        cout << "There is no input file "<< endl;
        return;
    }
    string str = "";
    string str2 = "";
    while( inputFile >> str ) {
        toLowerCase( str, str.length() );
        for (int i = 0; i < str.length(); i++) {
            if (ispunct(str[i] )) {
                if( str2 != "" && str2 != " " ) {
                    addWord(str2);
                    //cout << str <<"," << str2 << endl;
                    str2 = "";
                }
            }
            else{
                str2 = str2 + str[i];
            }
        }
        if( str2 != "" && str2 != " ") {
            addWord(str2);
            //cout << str <<"," <<str2 << endl;
        }
        str2 = "";
    }
    inputFile.close();

}

void AVLTree::addWord( string wordToAdd ) {
    insertWord( root, wordToAdd );
}

void AVLTree::printHeight() {
    int height = calculateHeight( root );
    cout << "Tree height: " << height << endl;
}

void AVLTree::printHeight( ostream& outFile ) {
    int height = calculateHeight( root );
    outFile << "Tree height: " << height << endl;
}

void AVLTree::printTotalWordCount() {
    int total = totalWordCount( root );
    cout << "Total Word Count: " << total << endl;
}

void AVLTree::printTotalWordCount( ostream& outFile ) {
    int total = totalWordCount( root );
    outFile << "Total Word Count: " << total << endl;
}

void AVLTree::printWordFrequencies( ostream& outFile ) {
    wordFrequencies( root, outFile );
}

void AVLTree::printWordFrequencies() {
    wordFrequencies( root );
}

void AVLTree::printMostFrequent() {
    if( root == NULL ) {
        cout << "There is no word in the tree" << endl;
    }
    else {
        string mostWord = root->word;
        int mostCount = root->count;
        mostFrequent( root, mostWord, mostCount );
        cout<< "Most Frequent: " << mostWord << " " << mostCount << endl;
    }
}

void AVLTree::printMostFrequent( ostream& outFile ) {
    if( root == NULL ) {
        outFile << "There is no word in the tree" << endl;
    }
    else {
        string mostWord = root->word;
        int mostCount = root->count;
        mostFrequent( root, mostWord, mostCount );
        outFile << "Most Frequent: " << mostWord << " " << mostCount << endl;
    }
}

void AVLTree::printLeastFrequent() {
    if( root == NULL ) {
        cout << "There is no word in the tree" << endl;
    }
    else {
        string leastWord = root->word;
        int leastCount = root->count;
        leastFrequent( root, leastWord, leastCount );
        cout<< "Least Frequent: " << leastWord << " " << leastCount << endl;
    }
}

void AVLTree::printLeastFrequent( ostream& outFile ) {
    if( root == NULL ) {
        outFile << "There is no word in the tree" << endl;
    }
    else {
        string leastWord = root->word;
        int leastCount = root->count;
        leastFrequent( root, leastWord, leastCount );
        outFile << "Least Frequent: " << leastWord << " " << leastCount << endl;
    }
}

void AVLTree::printStandartDeviation() {
    int totalWord = totalWordCount( root );
    double arithmeticMean = (double) totalForDeviation( root ) / totalWord;
    int square = squareForDeviation( root );
    double standartDeviation = (double) sqrt( (1/(double) totalWord) * ( square - (totalWord * arithmeticMean * arithmeticMean) ) );
    cout << "Standard Deviation:" << standartDeviation << endl;
}

void AVLTree::printStandartDeviation( ostream& outFile ) {
    int totalWord = totalWordCount( root );
    double arithmeticMean = (double) totalForDeviation( root ) / totalWord;
    int square = squareForDeviation( root );
    double standartDeviation = (double) sqrt( (1/(double) totalWord) * ( square - (totalWord * arithmeticMean * arithmeticMean) ) );
    outFile << "Standard Deviation:" << standartDeviation << endl;
}

//HELPER METHODDS
int AVLTree::calculateHeight( TreeNode* treePtr ) {
    if( treePtr == NULL ) {
        return 0;
    }
    int leftHeight = calculateHeight( treePtr->leftChild ) + 1;
    int rightHeight = calculateHeight( treePtr->rightChild ) + 1;

    if( leftHeight > rightHeight ) {
        return leftHeight;
    }
    else {
        return rightHeight;
    }
}

int AVLTree::balanceHeightFactor( TreeNode* treePtr ) {
    return calculateHeight( treePtr->leftChild ) - calculateHeight( treePtr->rightChild );
}

void AVLTree::LLRotate( TreeNode*& treePtr ) {
    TreeNode* leftPointer = treePtr->leftChild;
    treePtr->leftChild = leftPointer->rightChild;
    leftPointer->rightChild = treePtr;
    treePtr = leftPointer;
}

void AVLTree::RRRotate( TreeNode*& treePtr ) {
    TreeNode* rightPointer = treePtr->rightChild;
    treePtr->rightChild = rightPointer->leftChild;
    rightPointer->leftChild = treePtr;
    treePtr = rightPointer;
}

void AVLTree::LRRotate( TreeNode*& treePtr ) {
    TreeNode* leftPointer = treePtr->leftChild;
    TreeNode* leftRightPointer = leftPointer->rightChild;
    leftPointer->rightChild = leftRightPointer->leftChild;
    treePtr->leftChild = leftRightPointer->rightChild;
    leftRightPointer->leftChild = leftPointer;
    leftRightPointer->rightChild = treePtr;
    treePtr = leftRightPointer;
}

void AVLTree::RLRotate( TreeNode*& treePtr ) {
    TreeNode* rightPointer = treePtr->rightChild;
    TreeNode* rightLeftPointer = rightPointer->leftChild;
    rightPointer->leftChild = rightLeftPointer->rightChild;
    treePtr->rightChild = rightLeftPointer->leftChild;
    rightLeftPointer->leftChild = treePtr;
    rightLeftPointer->rightChild = rightPointer;
    treePtr = rightLeftPointer;
}

void AVLTree::insertWord( TreeNode*& treePtr, string wordToAdd ) {
    if( treePtr == NULL ) {
        treePtr = new TreeNode;
        treePtr->leftChild = NULL;
        treePtr->rightChild = NULL;
        treePtr->count = 1;
        treePtr->word = wordToAdd;
    }
    else if( treePtr->word == wordToAdd ) {
        treePtr->count = treePtr->count + 1;
        return;
    }
    else if( wordToAdd < treePtr->word ) {
        insertWord( treePtr->leftChild, wordToAdd );
    }
    else {
        insertWord( treePtr->rightChild, wordToAdd );
    }

    int balanceFactor = balanceHeightFactor( treePtr );

    if( balanceFactor == 2 && balanceHeightFactor( treePtr->leftChild ) == 1 ) {
        LLRotate( treePtr );
    }
    else if( balanceFactor == 2 && balanceHeightFactor( treePtr->leftChild ) == -1 ) {
        LRRotate( treePtr );
    }
    else if( balanceFactor == -2 && balanceHeightFactor( treePtr->rightChild ) == -1 ) {
        RRRotate( treePtr );
    }
    else if( balanceFactor == -2 && balanceHeightFactor( treePtr->rightChild ) == 1 ) {
        RLRotate( treePtr );
    }

}

int AVLTree::totalWordCount( TreeNode* treePtr ) {
    if( treePtr == NULL ) {
        return 0;
    }
    else {
        return 1 + totalWordCount( treePtr->leftChild ) + totalWordCount( treePtr->rightChild );
    }
}

void AVLTree::deleteTree( TreeNode* treePtr ) {
    if(treePtr != NULL) {
        deleteTree( treePtr->leftChild );
        deleteTree( treePtr->rightChild );
        delete treePtr;
        treePtr = NULL;
	}
}

void AVLTree::wordFrequencies( TreeNode* treePtr  ) {
    if( treePtr == NULL ) {
        return;
    }
    wordFrequencies( treePtr->leftChild );
    cout << treePtr->word << " " << treePtr->count << endl;
    wordFrequencies( treePtr->rightChild );

}

void AVLTree::wordFrequencies( TreeNode* treePtr, ostream& outFile ) {
    if( treePtr == NULL ) {
        return;
    }
    wordFrequencies( treePtr->leftChild, outFile );
    outFile << treePtr->word << " " << treePtr->count << endl;
    wordFrequencies( treePtr->rightChild, outFile );
}

void AVLTree::mostFrequent( TreeNode* treePtr, string& str, int& wordCount ) {
    if( treePtr == NULL ){
        return;
    }
    mostFrequent( treePtr->leftChild, str, wordCount );
    if( treePtr->count > wordCount ) {
        wordCount = treePtr->count;
        str = treePtr->word;
    }
    mostFrequent( treePtr->rightChild, str, wordCount );
}

void AVLTree::leastFrequent( TreeNode* treePtr, string& str, int& wordCount ) {
    if( treePtr == NULL ){
        return;
    }
    leastFrequent( treePtr->leftChild, str, wordCount );
    if( treePtr->count < wordCount ) {
        wordCount = treePtr->count;
        str = treePtr->word;
    }
    leastFrequent( treePtr->rightChild, str, wordCount );
}

int AVLTree::totalForDeviation( TreeNode* treePtr ) {
    if( treePtr == NULL ){
        return 0;
    }
    return treePtr->count + totalForDeviation( treePtr->leftChild ) + totalForDeviation ( treePtr->rightChild );
}

int AVLTree::squareForDeviation( TreeNode* treePtr ) {
    if( treePtr == NULL ){
        return 0;
    }
    return treePtr->count * treePtr->count + squareForDeviation( treePtr->leftChild ) + squareForDeviation( treePtr->rightChild );
}

void AVLTree::toLowerCase( string& str, int length ) {

    for(int i = 0; i < length; i++ ) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }


}
