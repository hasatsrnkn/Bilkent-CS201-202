/**
* Title : Binary Search Trees
* Author : Mehmet Hasat Serinkan
* ID: 21901649
* Section : 1
* Assignment : 2
* Description : BSTNode.cpp
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

BSTNode::BSTNode() {
    item = -1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

BSTNode::BSTNode( const int& item, BSTNode* left, BSTNode* right ) {
    this->item = item;
    this->leftChildPtr = left;
    this->rightChildPtr = right;
}


