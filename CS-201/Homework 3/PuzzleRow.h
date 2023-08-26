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
    PuzzlePiece* findPiece( int index);
};
