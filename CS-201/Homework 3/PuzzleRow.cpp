/**
    MEHMET HASAT SERINKAN
    21901649
    CS-201/2
*/

#include <iostream>
using namespace std;
class PuzzleRow{
private:
    struct PuzzlePiece{
        char shape;
        int rowindex;
        int colindex;
        PuzzlePiece* next;
    };

    PuzzlePiece* head;
    PuzzleRow* next;
    int rowindex;
    int maxSize; //equals to puzzleContainer width
    int size;

public:
    PuzzleRow( int size, int rowindex);
    ~PuzzleRow();
    int getRowIndex();
    int getLength();
    void setNext( PuzzleRow* next );
    PuzzleRow* getNext();
    bool insert( int index, char shape );
    bool remove( int index );
    bool isEmpty();
    char getPiece(int index );
    void printRow();
    PuzzlePiece* findPiece( int index );
};

PuzzleRow::PuzzleRow( int size, int rowindex ) {
    this->rowindex = rowindex;
    this->maxSize = size;
    this->size = 0;
    head = NULL;
    next = NULL;
}

PuzzleRow::~PuzzleRow() {
    for( int i = 1; i <= maxSize; i++) {
        remove(i);
    }
}

int PuzzleRow::getRowIndex(){
    return rowindex;
}

int PuzzleRow::getLength() {
    return size;
}

void PuzzleRow::setNext( PuzzleRow* next ) {
    this->next = next;
}

PuzzleRow* PuzzleRow::getNext() {
    return next;
}

bool PuzzleRow::isEmpty() {
    if( head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool PuzzleRow::insert( int index, char shape ) {
    if( (index < 1) || (index > maxSize) ) {
        return false;
    }
    else {
        PuzzlePiece* newPtr = new PuzzlePiece;
        newPtr->shape = shape;
        newPtr->rowindex = rowindex;
        newPtr->colindex = index;
        if ( size == 0 ) {
            newPtr->next = head;
            head = newPtr;
        }
        else {
            PuzzlePiece* prev = head;
            for ( int i = 1; i < size; i++) {
                prev = prev->next;
            }
            newPtr->next = NULL;
            prev->next = newPtr;
        }
        size = size + 1;
        return true;
    }
}

char PuzzleRow::getPiece( int index ) {
     if( (index < 1) || (index > maxSize) ) {
        return 255;
    }
    else {
        PuzzlePiece* cur = findPiece(index);
        if( cur == NULL ) {
            return 255;
        }
        else {
            return cur->shape;
        }
    }

}

PuzzleRow::PuzzlePiece* PuzzleRow::findPiece( int index ) {
    if( (index < 1) || (index > maxSize) ) {
        return NULL;
    }
    else {
        if( size == 0 ) {
            return NULL;
        }
        else {
            PuzzlePiece* cur = head;
            for( int i = 1; i <= size; i++) {
                if( cur->colindex == index ) {
                    break;
                }
                else {
                    if( i == size ) {
                        cur = NULL;
                    }
                    else {
                        cur = cur->next;
                    }
                }
            }
            return cur;
        }
    }
}

bool PuzzleRow::remove( int index ) {
    if( (index < 1) || (index > maxSize) ) {
        return false;
    }
    else {
        PuzzlePiece* cur = findPiece(index);
        if( cur == NULL ) {
            return false;
        }
        else {
            if( cur == head ) {
                head = head->next;
            }
            else {
                PuzzlePiece* prev = head;
                int actualIndex;
                for( int i = 1; i <= size; i++) {
                    if ( prev == cur) {
                        actualIndex = i;
                        break;
                    }
                    else {
                        prev = prev->next;
                    }
                }
                prev = head;
                for( int i = 1; i < actualIndex; i++) {
                    prev = prev->next;
                }
                if ( actualIndex == size ) {
                    prev->next = NULL;
                }
                else {
                    prev->next = cur->next;
                }
            }
            cur->next = NULL;
            delete cur;
            cur = NULL;
            size = size - 1;
            return true;
        }
    }
}

void PuzzleRow::printRow() {
    PuzzlePiece* cur;
    for( int i = 1; i <= maxSize; i++) {
        cur = findPiece(i);
        if( cur == NULL ) {
            cout << "O ";
        }
        else {
            cout << "X ";
        }
    }
}

