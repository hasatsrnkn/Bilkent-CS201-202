/*
* Title: Balanced Search Trees
* Author: Mehmet Hasat Serinkan
* ID: 21901649
* Section: 1
* Assignment: 4
* Description: AVLTree.h
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

class AVLTree {
private:
    struct TreeNode {
        string word;
        int count;
        TreeNode* leftChild;
        TreeNode* rightChild;
    };
    TreeNode* root;

public:
    AVLTree();
    ~AVLTree();
    void addWord( string wordToAdd );
    void printHeight();
    void printTotalWordCount();
    void printWordFrequencies();
    void printMostFrequent();
    void printLeastFrequent();
    void printStandartDeviation();
    void generateTree( char* fileName );

    //METHODS FOR OUTPUT FILE
    void printHeight(ostream& outFile);
    void printTotalWordCount(ostream& outFile);
    void printWordFrequencies(ostream& outFile);
    void printMostFrequent(ostream& outFile);
    void printLeastFrequent(ostream& outFile);
    void printStandartDeviation(ostream& outFile);

protected:
    int calculateHeight( TreeNode* treePtr );
    int balanceHeightFactor( TreeNode* treePtr );
    void LLRotate( TreeNode*& treePtr );
    void LRRotate( TreeNode*& treePtr );
    void RRRotate( TreeNode*& treePtr );
    void RLRotate( TreeNode*& treePtr );
    void insertWord( TreeNode*& treePtr, string wordToAdd );
    int totalWordCount( TreeNode* treePtr );
    void deleteTree( TreeNode* treePtr );
    void wordFrequencies( TreeNode* treePtr );
    void wordFrequencies( TreeNode* treePtr, ostream& outFile );
    void mostFrequent( TreeNode* treePtr, string& str, int& wordCount );
    void leastFrequent( TreeNode* treePtr, string& str, int& wordCount );
    int totalForDeviation( TreeNode* treePtr );
    int squareForDeviation( TreeNode* treePtr );
    void toLowerCase( string& str, int length );
};
