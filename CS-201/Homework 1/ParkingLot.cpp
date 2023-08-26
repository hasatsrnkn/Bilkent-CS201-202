/*
    NAME: Mehmet Hasat Serinkan
    ID: 21901649
*/

#include <iostream>
#include "Car.h"
using namespace std;
class ParkingLot{

public:
    ParkingLot(int id = 0, int rows = 0, int columns = 0);
    ~ParkingLot();
    ParkingLot( const ParkingLot& pl );
    ParkingLot& operator= (const ParkingLot& pl);
    int getID();
    int getRows();
    int getColumns();
    int getCarSize();
    int getEmptySlots();
    void setID( const int id );
    void setRows( const int row );
    void setColumns( const int column );
    void setCarSize( const int carsSize );
    void setEmptySlots( const int emptySlots );
    void createArray( const int rows, const int columns);
    void addCar( const int plateNo, const string location, const string type );
    void addCarToLot( const int plateNo, const string location, const string type );
    int locationFinder( const char location);
    bool findCar( const int plateNo );
    bool lookForCar( const int plateNo );
    bool deleteCar( const int index );
    int indexOfCar( const int plateNo );
    void updateData( const string x, string**& data, const int rows, const int columns );
    void listLot();

private:
    int id;
    int row;
    int column;
    string** data;
    Car* cars;
    int carsSize;
    int emptySlots;
};

ParkingLot::ParkingLot( int id, int rows, int columns) {
    this->id = id;
    this->row = rows;
    this->column = columns;
    emptySlots = rows * columns;
    data = NULL;
    cars = NULL;
    carsSize = 0;

    if( rows > 0 && columns > 0 ) {
        createArray( rows, columns);
    }
}

ParkingLot::~ParkingLot() {
    if ( cars ) {
        delete [] cars;
    }

    if( data ) {
        for ( int i = 0; i < row; i++ ) {
            delete [] data[i];
        }
        delete [] data;
    }
}

ParkingLot::ParkingLot( const ParkingLot& pl) {
    id = pl.id;
    row = pl.row;
    column = pl.column;
    carsSize = pl.carsSize;
    emptySlots = pl.emptySlots;

    if ( pl.data ) {
        data = new string*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new string[column];
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                data[i][j] = pl.data[i][j];
            }
        }
    }

    if ( pl.cars ) {
        cars = new Car[carsSize];
        for( int i = 0; i < carsSize; i = i + 1) {
            cars[i] = pl.cars[i];
        }
    }
}

ParkingLot& ParkingLot::operator= (const ParkingLot& pl) {
    id = pl.id;
    row = pl.row;
    column = pl.column;
    carsSize = pl.carsSize;
    emptySlots = pl.emptySlots;

    if ( pl.data ){
        data = new string*[row];

        for (int i = 0; i < row; i++) {
            data[i] = new string[column];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                data[i][j] = pl.data[i][j];
            }
        }
    }

    if ( pl.cars ) {
        cars = new Car[carsSize];
        for( int i = 0; i < carsSize; i = i + 1) {
            cars[i] = pl.cars[i];
        }
    }

    return *this;
}

int ParkingLot::getID() {
    return id;
}

int ParkingLot::getRows() {
    return row;
}

int ParkingLot::getColumns() {
    return column;
}

int ParkingLot::getCarSize() {
    return carsSize;
}

int ParkingLot::getEmptySlots() {
    return emptySlots;
}

void ParkingLot::setID( const int id ) {
    this->id = id;
}

void ParkingLot::setRows( const int row ) {
    this->row = row;
}

void ParkingLot::setColumns( const int column ) {
    this->column = column;
}

void ParkingLot::setCarSize( const int carsSize ) {
    this->carsSize = carsSize;
}

void ParkingLot::setEmptySlots( const int emptySlots ) {
    this->emptySlots = emptySlots;
}

void ParkingLot::createArray( const int rows, const int columns ) {
    data = new string*[ rows ];
    for ( int i = 0; i < rows; i++ ) {
        this->data[ i ] = new string[ columns ];
    }

    for ( int x = 0; x < rows; x = x + 1 ) {
        for( int y = 0; y < columns; y = y + 1) {
            this->data[x][y] = "+";
        }
    }
}

void ParkingLot::addCar( const int plateNo, const string location, const string type ) {
    Car* temp = cars;
    cars = new Car[ carsSize + 1 ];
    for ( int i = 0; i < carsSize; i = i + 1) {
        cars[i] = temp[i];
    }

    cars[carsSize].setPlateNo( plateNo );
    cars[carsSize].setLocation( location );
    cars[carsSize].setType( type );
    carsSize = carsSize + 1;
    delete [] temp;
}

void ParkingLot::addCarToLot( const int plateNo, const string location, const string type ) {
    char rowLetter = location[0];
    int rowNo = locationFinder( rowLetter );
    int columnNo = (int)(location[1]) - 49;
    if ( location.length() == 3) {
        columnNo = (int)(location[2]) - 39;
    }

    if( type == "a" ) {

        if( data[rowNo][columnNo] == "+" ) {
            addCar( plateNo, location, type);
            updateData("a",data,rowNo,columnNo);
            emptySlots = emptySlots - 1;
            cout << "Light-duty car with number plate " << plateNo << " has been parked at location " << location << ", lot " << id << endl;;
        }
        else {
            cout << "Cannot park light-duty car with number plate " << plateNo << " at location " <<
            location << ", already occupied" << endl;
        }
    }
    else {

        if( (data[rowNo][columnNo] == "+" )&& rowNo != 0 && (data[rowNo - 1][columnNo] == "+") ) {
            addCar( plateNo, location, type);
            updateData("b",data,rowNo,columnNo);
            updateData("b",data,rowNo - 1,columnNo);
            emptySlots = emptySlots - 2;
            cout << "Heavy-duty car with number plate " << plateNo << " has been parked at location " << location << ", lot " << id << endl;
        }
        else {

            if( rowNo == 0) {
                cout << "Cannot park heavy-duty car with number plate " << plateNo << " at location " <<
                location <<", not enough space" << endl;
            }
            else {
                cout << "Cannot park heavy-duty car with number plate " << plateNo << " at location " <<
                location <<", already occupied" << endl;
            }
        }
    }
}

int ParkingLot::locationFinder( const char location ) {
    string letters = "ABCDEFGHIJKL";
    for(int i = 0; i < 12; i = i + 1) {
        if ( letters[i] == location) {
            return i;
        }
    }
    return -1;
}

bool ParkingLot::findCar( const int plateNo ) {
    for( int i = 0; i < carsSize; i = i + 1) {
        if( plateNo == cars[i].getPlateNo()  ) {
            if( cars[i].getType() == "a") {
                cout << "Light-duty car with number plate " << cars[i].getPlateNo() << " is at location " <<
                cars[i].getLocation() << ", lot " << id << endl;
            }

            else {
                cout << "Heavy-duty car with number plate " << cars[i].getPlateNo() << " is at location " <<
                cars[i].getLocation() << ", lot " << id << endl;
            }
            return true;
        }
    }
    return false;
}

bool ParkingLot::lookForCar( const int plateNo ) {
    for( int i = 0; i < carsSize; i = i + 1) {
        if ( plateNo == cars[i].getPlateNo() ) {
            return true;
        }
    }
    return false;
}

bool ParkingLot::deleteCar( const int index ) {
    if ( index < 0 || index > carsSize ) {
        return false;
    }
    Car* temp = cars;
    string location = cars[ index ].getLocation();
    char rowLetter = location[0];
    int rowNo = locationFinder( rowLetter );
    int columnNo = (int)(location[1]) - 49;

    if ( location.length() == 3) {
            columnNo = (int)(location[2]) - 39;
    }

    if( cars[ index ].getType() == "a" ) {
        updateData("+",data,rowNo,columnNo);
        cout << "Light-duty car with number plate " << cars[ index ].getPlateNo() <<  " car has been removed from slot " <<
        location << ", lot " << id << endl;
        emptySlots = emptySlots + 1;
    }
    else {
        updateData("+",data,rowNo,columnNo);
        updateData("+",data,rowNo - 1,columnNo);
        emptySlots = emptySlots + 2;
        cout << "Heavy-duty car with number plate " << cars[ index ].getPlateNo() <<  " car has been removed from slot " <<
        location << ", lot " << id << endl;
    }

    if ( carsSize == 1) {
        cars = NULL;
    }
    else {
        cars = new Car[ carsSize - 1];
        for( int i = 0; i < index; i = i + 1) {
            cars[i] = temp[i];
        }
        for( int j = index + 1; j < carsSize; j = j + 1) {
            cars[j - 1] = temp[ j ];
        }
    }
    carsSize = carsSize - 1;
    delete [] temp;
    return true;
}

int ParkingLot::indexOfCar( const int plateNo ) {
    for( int i = 0; i < carsSize; i = i + 1) {
        if( cars[i].getPlateNo() == plateNo ) {
            return i;
        }
    }
    return -1;
}

void ParkingLot::updateData( const string x, string**& data, const int rows, const int columns ) {
    data[rows][columns] = x;
}


void ParkingLot::listLot() {
    cout << "ID: " << id << ", (" << row << "," << column << "), empty slot: " << emptySlots << ", parked cars: ";

    if ( carsSize == 0 ) {
        cout << "no cars yet ";
    }
    else {
        for(int i = 0; i < carsSize; i = i + 1) {
            cout << cars[ i ].getPlateNo() << " ";
        }
    }

    cout << endl;
    cout << endl;
    cout << "  ";

    for( int i = 1; i <= column; i = i + 1) {
        cout << i << " ";
    }
    cout << endl;

    string letters = "ABCDEFHIGJKL";
    for( int i = 0; i < row; i = i + 1) {
        cout << letters[i] << " ";
        for( int j = 0; j < column; j = j + 1) {

            if ( j < 9 ) {
                cout << data[i][j] << " ";
            }
            else {
                cout << data[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}





