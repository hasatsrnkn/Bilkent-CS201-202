/**
* Title : Binary Search Trees
* Author : Mehmet Hasat Serinkan
* ID: 21901649
* Section : 1
* Assignment : 2
* Description : BST.cpp
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

BST::BST() {
    root = NULL;
}

BST::~BST() {
    deleteTree(root);
}

BST::BST(const BST &tree) {
    root = copyTree(tree.root);
}

void BST::insertItem( int key ) {
    searchTreeInsert( root, key );
}

BSTNode* BST::retrieveItem( int key ) {
    return binarySearch( root, key );
}

int* BST::inorderTraversal( int& length ) {
    length = totalNodes( root );
    int* arr = new int[ length ];
    int index = 0;
    intoTheArray(root,arr,index);
    return arr;
}

void BST::deleteItem( int key ) {
    searchTreeDelete( root, key );
}

int BST::countNodesBelowLevel( int level ) {
    int maxLevel = getLevelNo( root );
    int nodesNo = 0;
    for( int i = level; i<= maxLevel; i++ ) {
        nodesNo = nodesNo + numberOfNodesInLevel(root, 1, i);
    }
    return nodesNo;
}

bool BST::hasSequence(int* seq, int length) {
    if( length == 0 ) {
        return true;
    }
    else {
        bool controller = true;
        int index = 0;
        sequenceController(root,seq,length,index,controller);
        if( controller && index == length ) {
            return true;
        }
        return false;
    }
}

int BST::totalNodes( BSTNode* treePtr ) {
    if( treePtr == NULL ) {
        return 0;
    }
    else {
        return 1 + totalNodes( treePtr->leftChildPtr ) + totalNodes( treePtr->rightChildPtr );
    }
}

BSTNode* BST::creatingBSTFromArray(int* arr, int startP, int endP ) {
    if( startP > endP ) {
        return NULL;
    }

    int mid = (startP + endP)/2;

    root = new BSTNode( arr[mid], creatingBSTFromArray(arr, startP, mid - 1), creatingBSTFromArray(arr, mid + 1, endP) );
    return root;
}

void BST::displayBSTinOrder() {
    int length;
    int* arr;
    arr = inorderTraversal( length );

    for( int i = 0; i < length; i++ ) {
        cout << arr[i] << " ";
    }

    cout << endl;
    delete[] arr;
}

//HELPER METHODS

void BST::intoTheArray( BSTNode* treePtr,int* arr, int&index) {
    if( treePtr == NULL ) {
        return;
    }
    intoTheArray(treePtr->leftChildPtr, arr, index );
    arr[index++] = treePtr->item;
    intoTheArray(treePtr->rightChildPtr, arr, index);
}

void BST::searchTreeInsert( BSTNode*& treePtr, const int newItem) {

    if( treePtr == NULL ) {
        treePtr = new BSTNode( newItem, NULL, NULL);
    }

    else if( newItem < treePtr->item ) {
        searchTreeInsert( treePtr->leftChildPtr, newItem );
    }

    else {
        searchTreeInsert( treePtr->rightChildPtr, newItem );
    }

}

void BST::searchTreeDelete( BSTNode*& treePtr, const int newItem ) {
    if( treePtr == NULL ) {
        cout << "Delete failed " << endl;
    }
    else if( newItem == treePtr->item ) {
        deleteNodeItem( treePtr );
    }
    else if( newItem < treePtr->item ) {
        searchTreeDelete( treePtr->leftChildPtr, newItem );
    }
    else {
        searchTreeDelete( treePtr->rightChildPtr, newItem );
    }
}

void BST::deleteNodeItem( BSTNode*& treePtr ) {
    BSTNode* delPtr;
    int replacementItem;

    if( (treePtr->leftChildPtr == NULL) && (treePtr->rightChildPtr == NULL) ) {
        delete treePtr;
        treePtr = NULL;
    }
    else if( treePtr->leftChildPtr == NULL ) {
        delPtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else if( treePtr->rightChildPtr == NULL ) {
        delPtr = treePtr;
        treePtr = treePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    else {
        processLeftMost( treePtr->rightChildPtr, replacementItem );
        treePtr->item = replacementItem;
    }
}

void BST::processLeftMost( BSTNode*& treePtr, int& treeItem ) {
    if( treePtr->leftChildPtr == NULL ) {
        treeItem = treePtr->item;
        BSTNode* delPtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else {
        processLeftMost( treePtr->leftChildPtr, treeItem);
    }

}

BSTNode* BST::binarySearch( BSTNode*& treePtr, const int newItem ) {
    if( treePtr == NULL ) {
        return NULL;
    }
    else if( treePtr->item == newItem ) {
        return treePtr;
    }
    else if( newItem < treePtr->item ) {
        return binarySearch( treePtr->leftChildPtr, newItem );
    }
    else {
        return binarySearch( treePtr->rightChildPtr, newItem );
    }
}

int BST::getLevelNo( BSTNode* treePtr ) {
    if( treePtr == NULL ) {
        return 0;
    }
    else {
        int left = getLevelNo( treePtr->leftChildPtr );
        int right = getLevelNo( treePtr-> rightChildPtr );

        if( left > right ) {
            return 1 + left;
        }
        else {
            return 1 + right;
        }
    }
}

int BST::numberOfNodesInLevel( BSTNode* treePtr, int curLevel, int desiredLevel ) {
    if( treePtr == NULL ) {
        return 0;
    }
    if( curLevel == desiredLevel ) {
        return 1;
    }
    return numberOfNodesInLevel( treePtr->leftChildPtr, curLevel+1, desiredLevel) + numberOfNodesInLevel( treePtr->rightChildPtr, curLevel+1, desiredLevel );
}

void BST::deleteTree( BSTNode* treePtr ) {
    if(treePtr != NULL) {
        deleteTree(treePtr->leftChildPtr);
        deleteTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
	}


}

BSTNode* BST::copyTree(const BSTNode *treePtr) {
    BSTNode* newTreePtr = NULL;
    if (treePtr != NULL){
        newTreePtr = new BSTNode(treePtr->item, NULL, NULL);
        newTreePtr->leftChildPtr = copyTree(treePtr->leftChildPtr);
        newTreePtr->rightChildPtr = copyTree(treePtr->rightChildPtr);
    }

    return newTreePtr;
}

void BST::sequenceController( BSTNode* treePtr, int* arr, int length, int& index, bool& controller ) {

    if(treePtr != NULL && controller ) {
        if(treePtr->item > arr[0] ) {
            sequenceController(treePtr->leftChildPtr, arr, length, index, controller );
        }

        cout << "Visited node value: " << treePtr->item << endl;

        if( treePtr->item >= arr[0] && treePtr->item <= arr[length-1] ) {
            if( treePtr->item == arr[index++] ) {
                controller = true;
            }
            else {
                controller = false;
            }
        }

        if( treePtr->item < arr[length - 1] ) {
            sequenceController(treePtr->rightChildPtr,arr,length,index,controller);
        }

    }
}


