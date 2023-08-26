/**
    MEHMET HASAT SERINKAN
    21901649
    CS-201/2
*/

#include <iostream>
using namespace std;
#include "PuzzleRow.h"
class PuzzleContainer{
private:
    PuzzleRow* rowLists;
    int height;
    int width;
    int size;

public:
    PuzzleContainer( int h, int w);
    ~PuzzleContainer();
    PuzzleRow* getRow( int index );
    bool insertRow( int index );
    bool removeRow( int index );
    bool addPiece( int row, int col , char shape );
    bool removePiece(int row, int col);
    bool rowAcceptance( int index );
    int getHeight();
    int getWidth();
    int getSize();
    void showPiece(int row, int col);
    void displayContainer();
    void showColumn(int col);
    void showRow(int row);
    void findPiece(char shape);
    void shapeConverter( unsigned char shape, int& down, int& up, int& right, int& left);
    bool shapeSuitability( int side1, int side2 );
    bool edgeController( int col, int left, int right );
};
