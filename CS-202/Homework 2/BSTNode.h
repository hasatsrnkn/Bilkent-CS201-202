/**
* Title : Binary Search Trees
* Author : Mehmet Hasat Serinkan
* ID: 21901649
* Section : 1
* Assignment : 2
* Description : BSTNode.h
*/

#include <iostream>
using namespace std;

class BSTNode {
public:
    BSTNode();
    BSTNode( const int& item, BSTNode* left = NULL, BSTNode* right = NULL);

private:
    int item;
    BSTNode* leftChildPtr;
    BSTNode* rightChildPtr;
    friend class BST;
};
