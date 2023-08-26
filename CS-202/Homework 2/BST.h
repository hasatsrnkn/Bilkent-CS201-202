/**
* Title : Binary Search Trees
* Author : Mehmet Hasat Serinkan
* ID: 21901649
* Section : 1
* Assignment : 2
* Description : BST.h
*/

#include <iostream>
using namespace std;
#include "BSTNode.h"

class BST{
public:
    BST();
    ~BST();
    BST(const BST &tree);
    void insertItem(int key);
    void deleteItem(int key);
    BSTNode* retrieveItem(int key);
    int* inorderTraversal(int& length);
    bool hasSequence(int* seq, int length);
    int countNodesBelowLevel(int level);
    BSTNode* creatingBSTFromArray(int* arr, int startP, int endP );
    void displayBSTinOrder();

private:
    BSTNode* root;

    BSTNode* binarySearch( BSTNode*& treePtr, const int newItem);
    void searchTreeInsert( BSTNode*& treePtr, const int newItem);
    void searchTreeDelete( BSTNode*& treePtr, const int newItem);
    void intoTheArray( BSTNode* treePtr,int* arr, int& index);
    int getLevelNo( BSTNode* treePtr );
    void deleteNodeItem( BSTNode*& treePtr );
    void processLeftMost( BSTNode*& treePtr, int& treeItem );
    int numberOfNodesInLevel(BSTNode* treePtr, int curLevel, int desiredLevel);
    void deleteTree( BSTNode* treePtr);
    BSTNode* copyTree(const BSTNode *treePtr);
    void sequenceController( BSTNode* treePtr, int* arr, int length, int& index, bool& controller );
    int totalNodes(BSTNode* treePtr);
};

