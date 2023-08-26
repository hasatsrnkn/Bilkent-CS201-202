/**
* Title : Binary Search Trees
* Author : Mehmet Hasat Serinkan
* ID: 21901649
* Section : 1
* Assignment : 2
* Description : main.cpp
*/

#include "BST.h"
#include <iostream>
using namespace std;

BST* merge(const BST& tree1, const BST& tree2);

int main() {
    BST binaryS1, binaryS2;
    binaryS1.insertItem(8);
    binaryS1.insertItem(4);
    binaryS1.insertItem(3);
    binaryS1.insertItem(1);
    binaryS1.insertItem(2);
    binaryS1.insertItem(6);
    binaryS1.insertItem(5);
    binaryS1.insertItem(13);
    binaryS1.insertItem(12);
    binaryS1.insertItem(10);
    binaryS1.insertItem(15);
    binaryS1.insertItem(14);

    binaryS2.insertItem(16);
    binaryS2.insertItem(9);
    binaryS2.insertItem(17);
    binaryS2.insertItem(7);
    binaryS2.insertItem(11);
    binaryS2.insertItem(18);
    binaryS2.insertItem(19);

    BST* binaryS3 = merge(binaryS1, binaryS2);
    cout << "Merged binaryS1 and binaryS2 " << endl;
    cout << "Inorder of merged tree: ";
    binaryS3->displayBSTinOrder();
    cout << endl;

    int arr1[6] = {1, 2, 3, 4, 5, 6};
    if(  binaryS1.hasSequence( arr1 , 6) ) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }
    cout << endl;

    int arr2[4] = {10, 12, 13, 15};
    if(  binaryS1.hasSequence( arr2 , 4) ) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }
    cout << endl;

    int arr3[3] = {10, 11, 12 };
    if(  binaryS1.hasSequence( arr3 , 3) ) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }
    cout << endl;

    cout << "Number of nodes whose level is greater than or equal to 3 of bst1 is " << binaryS1.countNodesBelowLevel(3) << endl;
    cout << "Number of nodes whose level is greater than or equal to 4 of bst1 is " << binaryS1.countNodesBelowLevel(4) << endl;
    cout << "Number of nodes whose level is greater than or equal to 5 of bst1 is " << binaryS1.countNodesBelowLevel(5) << endl;
    cout << "Number of nodes whose level is greater than or equal to 6 of bst1 is " << binaryS1.countNodesBelowLevel(6) << endl;
    cout << endl;

    BST binaryS4;
    binaryS4.insertItem(8);
    binaryS4.insertItem(15);
    binaryS4.insertItem(10);
    binaryS4.insertItem(4);
    binaryS4.insertItem(9);
    binaryS4.insertItem(6);
    binaryS4.insertItem(16);
    binaryS4.insertItem(5);
    binaryS4.insertItem(13);
    binaryS4.insertItem(14);

    cout << "Inorder of new tree: ";
    binaryS4.displayBSTinOrder();

    binaryS4.deleteItem(5);
    binaryS4.deleteItem(10);
    binaryS4.deleteItem(8);
    binaryS4.deleteItem(9);
    binaryS4.deleteItem(14);
    cout << "Inorder of new tree after deletions: ";
    int* arr4, length;
    arr4 = binaryS4.inorderTraversal(length);
    for( int i = 0; i < length; i++ ) {
        cout << arr4[i] << " ";
    }
    delete [] arr4;
    cout << endl;

    cout << endl;
    cout << "Number of nodes whose level is greater than or equal to 1 of bst4 is " << binaryS4.countNodesBelowLevel(1) << endl;
    cout << "Number of nodes whose level is greater than or equal to 2 of bst4 is " << binaryS4.countNodesBelowLevel(2) << endl;
    cout << "Number of nodes whose level is greater than or equal to 3 of bst4 is " << binaryS4.countNodesBelowLevel(3) << endl;
    cout << "Number of nodes whose level is greater than or equal to 4 of bst4 is " << binaryS4.countNodesBelowLevel(4) << endl;
    cout << endl;

    delete binaryS3;
    BSTNode* BSTNode1 = binaryS4.retrieveItem(6);
    cout << "Address that is holding by BSTNode1 is: " << BSTNode1 << endl;


return 0;
}

BST* merge(const BST& tree1, const BST& tree2) {
    int length1, length2;

    BST treeRef1 = tree1;
    BST treeRef2 = tree2;
    int* treeArr1 = treeRef1.inorderTraversal(length1);
    int* treeArr2 = treeRef2.inorderTraversal(length2);

    int* arr = new int[ length1 + length2 ];
    int first1 = 0;
    int last1 = length1 - 1;
    int first2 = 0;
    int last2 = length2 - 1;
    int index = 0;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {

      if (treeArr1[first1] < treeArr2[first2]) {
         arr[index] = treeArr1[first1];
         ++first1;
      }
      else {
          arr[index] = treeArr2[first2];
          ++first2;
      }
   }

    for (; first1 <= last1; ++first1, ++index){
        arr[index] = treeArr1[first1];
    }

    for (; first2 <= last2; ++first2, ++index) {
        arr[index] = treeArr2[first2];
    }


    BST* newBST = new BST();
    newBST->creatingBSTFromArray(arr,0, (length1 + length2) - 1);
    delete [] treeArr1;
    delete [] treeArr2;
    delete [] arr;

    return newBST;


}
