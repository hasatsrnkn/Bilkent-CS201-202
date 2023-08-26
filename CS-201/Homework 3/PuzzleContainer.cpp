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

PuzzleContainer::PuzzleContainer( int h, int w ) {
    this->height = h;
    this->width = w;
    rowLists = NULL;
    this->size = 0;
}

PuzzleContainer::~PuzzleContainer() {
    PuzzleRow* cur;
    for( int i = 1; i <= height; i++ ) {
        cur = getRow(i);
        if( cur != NULL ) {
           for( int j = 1; j<= width; j++ ) {
                cur->remove(j);
            }
            removeRow(i);
        }

    }
}

PuzzleRow* PuzzleContainer::getRow( int index ) {
    if( ( index < 1 ) || ( index > height ) ) {
        return NULL;
    }
    else {
        bool controller = rowAcceptance( index );
        if( controller ) {
            return NULL;
        }
        else {
            PuzzleRow* cur = rowLists;
            for( int i = 1; i <= size; i++) {
                if( cur->getRowIndex() == index ) {
                    break;
                }
                else {
                    if( i == size ) {
                        cur = NULL;
                    }
                    else {
                        cur = cur->getNext();
                    }
                }
            }
            return cur;
        }
    }
}

int PuzzleContainer::getHeight() {
    return height;
}

int PuzzleContainer::getWidth() {
    return width;
}

int PuzzleContainer::getSize() {
    return size;
}

bool PuzzleContainer::insertRow( int index ) {
    if( ( index < 1 ) || ( index > height ) ) {
        return false;
    }
    else {
        bool controller = rowAcceptance( index );
        if ( !controller ) {
            return false;
        }
        else {
            PuzzleRow* newPtr = new PuzzleRow( width, index );
            if ( size == 0 ) {
                newPtr->setNext( NULL );
                rowLists = newPtr;
            }
            else {
                PuzzleRow* prev = rowLists;
                if( size != 1 ) {
                    for ( int i = 1; i < size; i++) {
                        prev = prev->getNext();
                    }
                }
                newPtr->setNext( NULL );
                prev->setNext( newPtr );
            }
            size = size + 1;
            return true;
        }
    }
}

bool PuzzleContainer::removeRow( int index ) {
    if( ( index < 1 ) || ( index > height ) ) {
        return false;
    }
    else {
        PuzzleRow* cur = getRow( index );
        if ( cur == NULL ) {
            return false;
        }
        else {
            if( cur == rowLists ) {
                rowLists = rowLists->getNext();
            }
            else {
                PuzzleRow* prev = rowLists;
                int actualIndex;
                for( int i = 1; i <= size; i++) {
                    if ( prev == cur) {
                        actualIndex = i;
                        break;
                    }
                    else {
                        prev = prev->getNext();
                    }
                }
                prev = rowLists;
                for( int i = 1; i < actualIndex - 1; i++) {
                    prev = prev->getNext();
                }
                cur = prev->getNext();
                prev->setNext( cur->getNext() );
            }
            cur->setNext( NULL );
            delete cur;
            cur = NULL;
            size = size - 1;
            return true;
        }
    }
}

bool PuzzleContainer::rowAcceptance( int index ) {
    if( ( index < 1 ) || ( index > height ) ) {
        return false;
    }
    else {
        if ( size == 0 ) {
            return true;
        }
        else {
            PuzzleRow* cur = rowLists;
            for( int i = 1; i <= size; i++ ) {
                if( cur->getRowIndex() == index) {
                    return false;
                }
                else {
                    if( i == size ) {
                        break;
                    }
                    else {
                        cur = cur->getNext();
                    }
                }
            }
            return true;
        }
    }

}

bool PuzzleContainer::addPiece( int row, int col, char shape ) {
    if( ( row < 1 ) || ( row > height ) || ( col < 1 ) || ( col > width ) ) {
        cout << "(" << row << "," << col << ") is out of frame, it cannot be added" << endl;
        return false;
    }
    else{
        PuzzleRow* cur = getRow( row );
        PuzzleRow* bottom = getRow( row + 1 );
        PuzzleRow* top = getRow( row - 1 );
        int down, up, right, left;
        shapeConverter( shape, down, up, right, left );
        if( cur == NULL ) {
            if( row == 1 ) {
                if( (up != 2) || (down == 2) ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                bool controller = edgeController( col, left, right);
                if( !controller ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                if( bottom == NULL ){
                    insertRow(row);
                    cur = getRow( row );
                    cur->insert(col,shape);
                    cout << "A piece is added to (" << row << "," << col << ")" << endl;
                    return true;
                }
                else {
                    char shape2 = bottom->getPiece( col );
                    int down2, up2, right2, left2;
                    shapeConverter( shape2, down2, up2, right2, left2);
                    bool controller = shapeSuitability( down, up2);
                    if( controller ) {
                        insertRow(row);
                        cur = getRow( row );
                        cur->insert(col,shape);
                        cout << "A piece is added to (" << row << "," << col << ")" << endl;
                        return true;
                    }
                    else {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }
                }
            }

            else if( row == height ) {
                if( (down != 2) || (up == 2) ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                bool controller = edgeController( col, left, right);
                if( !controller ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                if( top == NULL ){
                    insertRow(row);
                    cur = getRow( row );
                    cur->insert(col,shape);
                    cout << "A piece is added to (" << row << "," << col << ")" << endl;
                    return true;
                }
                else {
                    char shape2 = top->getPiece( col );
                    int down2, up2, right2, left2;
                    shapeConverter( shape2, down2, up2, right2, left2);
                    bool controller = shapeSuitability( up, down2 );
                    if( controller ) {
                        insertRow(row);
                        cur = getRow( row );
                        cur->insert(col,shape);
                        cout << "A piece is added to (" << row << "," << col << ")" << endl;
                        return true;
                    }
                    else {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }
                }
            }
            else {
                if( (up == 2) || (down == 2) ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                bool controller = edgeController( col, left, right);
                if( !controller ) {
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }

                int down2, down3, up2, up3, right2, right3, left2, left3;
                char shape2;
                char shape3;

                if ( top != NULL ) {
                    shape2 = top->getPiece( col );
                }
                else {
                    shape2 = 255;
                }
                if( bottom != NULL ) {
                    shape3 = bottom->getPiece( col );
                }
                else {
                    shape3 = 255;
                }

                shapeConverter( shape2, down2, up2, right2, left2 );
                shapeConverter( shape3, down3, up3, right3, left3 );
                bool condition1 = shapeSuitability( up, down2 );
                bool condition2 = shapeSuitability( down, up3 );
                if( condition1 && condition2 ){
                    insertRow(row);
                    cur = getRow( row );
                    cur->insert(col,shape);
                    cout << "A piece is added to (" << row << "," << col << ")" << endl;
                    return true;
                }
                else{
                    cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                    return false;
                }
            }
        }
        else {

            if( cur->findPiece(col) != NULL ) {
                cout << "(" << row << "," << col << ") has been already occupied, it cannot be added" << endl;
                return false;
            }
            else {
                if( row == 1 ) {
                    if( (up != 2) || (down == 2) ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    bool controller = edgeController( col, left, right);
                    if( !controller ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    int down2, down3, down4, up2, up3, up4, right2, right3, right4, left2, left3, left4;
                    char shapeLeft = cur->getPiece( col - 1);
                    char shapeRight = cur->getPiece( col + 1);
                    char shapeBottom;

                    if( bottom != NULL ) {
                        shapeBottom = bottom->getPiece( col );
                    }
                    else {
                        shapeBottom = 255;
                    }

                    shapeConverter( shapeLeft, down2, up2, right2, left2 );
                    shapeConverter( shapeRight, down3, up3, right3, left3 );
                    shapeConverter( shapeBottom, down4, up4, right4, left4 );
                    bool condition1 = shapeSuitability(left, right2 );
                    bool condition2 = shapeSuitability(right, left3 );
                    bool condition3 = shapeSuitability(down, up4);

                    if ( condition1 && condition2 && condition3 ) {
                        cur->insert(col,shape);
                        cout << "A piece is added to (" << row << "," << col << ")" << endl;
                        return true;
                    }
                    else {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }
                }
                else if( row == height ) {

                    if( (down != 2) || (up == 2) ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    bool controller = edgeController( col, left, right );
                    if( !controller ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    int down2, down3, down4, up2, up3, up4, right2, right3, right4, left2, left3, left4;
                    char shapeLeft = cur->getPiece( col - 1);
                    char shapeRight = cur->getPiece( col + 1);
                    char shapeTop;

                    if( top != NULL ) {
                        shapeTop = top->getPiece( col );
                    }
                    else {
                        shapeTop = 255;
                    }

                    shapeConverter( shapeLeft, down2, up2, right2, left2 );
                    shapeConverter( shapeRight, down3, up3, right3, left3 );
                    shapeConverter( shapeTop, down4, up4, right4, left4 );
                    bool condition1 = shapeSuitability(left, right2 );
                    bool condition2 = shapeSuitability(right, left3 );
                    bool condition3 = shapeSuitability(up, down4);

                    if ( condition1 && condition2 && condition3 ) {
                        cur->insert(col,shape);
                        cout << "A piece is added to (" << row << "," << col << ")" << endl;
                        return true;
                    }
                    else {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }
                }
                else {
                    if( (up == 2) || (down == 2) ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    bool controller = edgeController( col, left, right);
                    if( !controller ) {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }

                    int down2, down3, down4, down5, up2, up3, up4, up5,
                    right2, right3, right4, right5, left2, left3, left4, left5;
                    char shapeLeft = cur->getPiece( col - 1 );
                    char shapeRight = cur->getPiece( col + 1 );
                    char shapeTop;
                    char shapeBottom;

                    if( top != NULL ) {
                        shapeTop = top->getPiece( col );
                    }
                    else {
                        shapeTop = 255;
                    }
                    if( bottom != NULL ) {
                        shapeBottom = bottom->getPiece( col );
                    }
                    else {
                        shapeBottom = 255;
                    }

                    shapeConverter( shapeLeft, down2, up2, right2, left2 );
                    shapeConverter( shapeRight, down3, up3, right3, left3 );
                    shapeConverter( shapeTop, down4, up4, right4, left4 );
                    shapeConverter( shapeBottom, down5, up5, right5, left5 );
                    bool condition1 = shapeSuitability(left, right2 );
                    bool condition2 = shapeSuitability(right, left3 );
                    bool condition3 = shapeSuitability(up, down4 );
                    bool condition4 = shapeSuitability(down, up5 );

                    if ( condition1 && condition2 && condition3 && condition4 ) {
                        cur->insert(col,shape);
                        cout << "A piece is added to (" << row << "," << col << ")" << endl;
                        return true;
                    }
                    else {
                        cout << "Shape does not fit into ("<< row << "," << col << "), it cannot be added" << endl;
                        return false;
                    }
                }
            }
        }
    }
}

bool PuzzleContainer::removePiece( int row, int col ) {
    if( ( row < 1 ) || ( row > height ) || ( col < 1 ) || ( col > width ) ) {
        cout << "(" << row << "," << col << ") is out of frame, it cannot be removed" << endl;
        return false;
    }
    else {
        PuzzleRow* cur = getRow( row );
        if( cur == NULL ) {
            cout << "There is no piece on (" << row << "," << col << "), it cannot be removed" << endl;
            return false;
        }
        else {
            if( cur->findPiece( col ) == NULL ) {
                cout << "There is no piece on (" << row << "," << col << "), it cannot be removed" << endl;
                return false;
            }
            else{
                cout << "The piece on (" << row << "," << col << ") is removed" << endl;
                cur->remove( col );
                int length = cur->getLength();
                int indexToRemove = cur->getRowIndex();
                if( length == 0 ) {
                    removeRow( indexToRemove );
                }
                return true;
            }
        }
    }

}

void PuzzleContainer::shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape%4;
    up = (shape/4)%4;
    right= (shape/16)%4;
    left= shape/64;
}

bool PuzzleContainer::shapeSuitability( int side1, int side2 ) {
    if( side1 == 0 ) {
        if( (side2 == 1) || (side2 == 3) ) {
            return true;
        }
        else {
            return false;
        }
    }

    if( side1 == 1 ) {
        if( (side2 == 0) || (side2 == 3) ) {
            return true;
        }
        else {
            return false;
        }
    }

    if( side1 == 2 ) {
        if( (side2 == 2) || (side2 == 3) ) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

bool PuzzleContainer::edgeController( int col, int left, int right ) {

    if( col == 1) {
        if( left != 2 ) {
            return false;
        }
    }
    else if( col == width ) {
        if( right != 2 ) {
            return false;
        }
    }
    else {
        if( (left == 2) || (right == 2) ) {
            return false;
        }
    }
    return true;
}

void PuzzleContainer::showRow( int row ) {
    if( ( row < 1 ) || ( row > height ) ) {
        cout << "Row " << row << " is out of border" << endl;
    }
    else {
        cout << "Row " << row << ":" << endl;
        PuzzleRow* cur = getRow( row );
        if( cur == NULL ) {
            for( int i = 1; i <= width; i++ ) {
                cout << "O ";
            }
            cout << endl;
        }
        else{
            cur->printRow();
            cout << endl;
        }
    }

}

void PuzzleContainer::displayContainer() {
    cout << "Container " << height << "x" << width << ":" << endl;
    cout << "  ";
    for( int i = 1; i <= width; i++ ) {
        cout << i << " ";
    }
    cout << endl;
    PuzzleRow* cur;
    for( int i = 1; i <= height; i++ ) {
        cout << i << " ";
        cur=getRow( i );
        if( cur == NULL ) {
            for( int i = 1; i <= width; i++ ) {
                cout << "O ";
            }
        }
        else {
            cur->printRow();
        }
        cout << endl;
    }
}

void PuzzleContainer::showColumn( int col ) {
    if( ( col < 1 ) || ( col > width ) ) {
        cout << "Column " << col << " is out of border" << endl;
    }
    else {
        cout << "Column " << col << ":" << endl;
        PuzzleRow* cur;
        for( int i = 1; i <= height; i++ ) {
            cur = getRow(i);
            if( cur == NULL ) {
                cout << "O" << endl;
            }
            else {
                if( cur->findPiece(col) == NULL ) {
                    cout << "O" << endl;
                }
                else {
                    cout << "X" << endl;
                }
            }
        }
    }

}

void PuzzleContainer::showPiece( int row, int col ) {
    if( (col < 1) || (col > width) || (row < 1) || (row > height) ) {
        cout << "(" << row << "," << col << ") is out of frame, it cannot be shown" << endl;
    }
    else {
        PuzzleRow* cur = getRow( row );
        if( cur == NULL ) {
            cout << "There is no piece on (" << row << "," << col << "), it cannot be shown" << endl;
        }
        else {
            if( cur->findPiece( col ) == NULL ) {
                cout << "There is no piece on (" << row << "," << col << "), it cannot be shown" << endl;
            }
            else {
                cout << "Piece on (" << row << "," << col << ") as following:" << endl;
                char shape = cur->getPiece( col );
                int down, up, right, left;
                shapeConverter( shape, down, up, right, left );

                if( down == 0 ) {
                    cout << "Down: Hole" << endl;
                }
                if( down == 1 ) {
                    cout << "Down: Knob" << endl;
                }
                if( down == 2 ) {
                    cout << "Down: Border" << endl;
                }
                if( up == 0 ) {
                    cout << "Up: Hole" << endl;
                }
                if( up == 1 ) {
                    cout << "Up: Knob" << endl;
                }
                if( up == 2 ) {
                    cout << "Up: Border" << endl;
                }
                if( right == 0 ) {
                    cout << "Right: Hole" << endl;
                }
                if( right == 1 ) {
                    cout << "Right: Knob" << endl;
                }
                if( right == 2 ) {
                    cout << "Right: Border" << endl;
                }
                if( left == 0 ) {
                    cout << "Left: Hole" << endl;
                }
                if( left == 1 ) {
                    cout << "Left: Knob" << endl;
                }
                if( left == 2 ) {
                    cout << "Left: Border" << endl;
                }


            }
        }
    }
}

void PuzzleContainer::findPiece( char shape ) {
    PuzzleRow* cur;
    int count = 0;
    for( int i = 1; i <= height; i++) {
        cur = getRow(i);
        if( cur != NULL ) {
            for(int j = 1; j <= width; j++ ) {
                if( cur->getPiece(j) == shape ) {
                    if ( count == 0 ) {
                        cout << "(" << i << "," << j << ")";
                        count = count + 1;
                    }
                    else {
                        cout << ", (" << i << "," << j << ")";
                    }
                }
            }
        }
    }
    if( count == 0 ) {
        cout << "There is no piece that has shape" << endl;
    }
    else {
        cout << " contain the piece that has shape" << endl;
    }

    int down, up, right, left;
    shapeConverter( shape, down, up, right, left );

    if( down == 0 ) {
        cout << "Down: Hole" << endl;
    }
    if( down == 1 ) {
        cout << "Down: Knob" << endl;
    }
    if( down == 2 ) {
        cout << "Down: Border" << endl;
    }
    if( up == 0 ) {
        cout << "Up: Hole" << endl;
    }
    if( up == 1 ) {
        cout << "Up: Knob" << endl;
    }
    if( up == 2 ) {
        cout << "Up: Border" << endl;
    }
    if( right == 0 ) {
        cout << "Right: Hole" << endl;
    }
    if( right == 1 ) {
        cout << "Right: Knob" << endl;
    }
    if( right == 2 ) {
        cout << "Right: Border" << endl;
    }
    if( left == 0 ) {
        cout << "Left: Hole" << endl;
    }
    if( left == 1 ) {
        cout << "Left: Knob" << endl;
    }
    if( left == 2 ) {
        cout << "Left: Border" << endl;
    }

}








