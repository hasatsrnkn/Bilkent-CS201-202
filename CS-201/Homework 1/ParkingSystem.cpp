/*
    NAME: Mehmet Hasat Serinkan
    ID: 21901649
*/

#include <iostream>
#include "ParkingLot.h"
using namespace std;
class ParkingSystem{
public:
    ParkingSystem();
    ~ParkingSystem();
    void createLot(int id, int rows, int columns);
    void addParkingLotToSystem( const int id, const int rows, const int columns);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar( int plateNumber);
    void listLots();
    void lotContents(int id);
    void removeLot(int id);

private:
    ParkingLot* lots;
    int size;
};

ParkingSystem::ParkingSystem() {
    size = 0;
    lots = NULL;
}

ParkingSystem::~ParkingSystem() {
    if ( lots ) {
        delete [] lots;
    }
}

void ParkingSystem::createLot(int id, int rows, int columns) {
    bool controlForID = true;
    for( int i = 0; i < size; i = i + 1  ) {
        if( id == lots[i].getID()) {
            cout << "Cannot create the parking lot " << id << ", a lot with this ID already exists" << endl;
            controlForID = false;
            break;
        }
    }

    if( controlForID ) {

        if( rows > 12 || columns > 12) {
            cout << "Cannot create the parking lot " << id << ", dimensions exceed acceptable bounds" << endl;
        }
        else {
            addParkingLotToSystem( id, rows, columns );
            cout << "Parking lot with ID " << id << " and dimensions ("<< rows << "," << columns<< ") has been added to the system" << endl;
        }
    }
}

void ParkingSystem::addParkingLotToSystem( const int id, const int rows, const int columns) {
    ParkingLot* temp = lots;
    lots = new ParkingLot[ size + 1 ];
    for ( int i = 0; i < size; i = i + 1) {
        lots[i] = temp[i];
    }

    lots[size].setID(id);
    lots[size].setRows(rows);
    lots[size].setColumns(columns);
    lots[size].setCarSize( 0 );
    lots[size].setEmptySlots( rows * columns);
    lots[size].createArray(rows,columns);
    size = size + 1;
    delete [] temp;
}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber) {

     bool controlForID = false;
     bool controlForCar = false;
     int index;
     for( int i = 0; i < size; i = i + 1  ) {
        if( lotId == lots[i].getID()  ) {
            controlForID = true;
            index = i;
            break;
        }
    }

    if( !controlForID ) {
        cout << "Lot " << lotId << " is not in the system" << endl;
    }
    else {
        for ( int i = 0 ; i < size; i = i + 1) {
            controlForCar = lots[i].lookForCar( plateNumber );
            if( controlForCar ){
                break;
            }
        }

        if( !controlForCar ) {
            lots[index].addCarToLot( plateNumber, location, carType);
        }
        else {
            cout << "Cannot create the car with " << plateNumber << ", a car with this plate no " << plateNumber << " already exists" << endl;
        }
    }

}


void ParkingSystem::findCar( int plateNumber ) {
    bool controller;
    for( int i = 0; i < size; i = i + 1  ) {
        controller = lots[i].findCar( plateNumber );
        if( controller || i == size - 1 ) {
            break;
        }
    }
    if ( !controller ) {
        cout << "The car with number plate " << plateNumber <<  " is not in the system" << endl;
    }
}


void ParkingSystem::removeCar( int plateNumber ) {
    bool controller;
    int indexToRemove;
    for( int i = 0; i < size; i = i + 1) {
        controller = lots[i].lookForCar( plateNumber );
        if( controller ) {
            indexToRemove = i;
            break;
        }
    }

    if ( !controller ) {
        cout << "The car with number plate " << plateNumber <<  " is not in the system" << endl;
    }
    else {
        int carToRemove = lots[ indexToRemove ].indexOfCar( plateNumber );
        lots[ indexToRemove ].deleteCar( carToRemove );
    }
}

void ParkingSystem::listLots() {
    if( size == 0) {
        cout << "No lots to list" << endl;
    }
    else {
        for( int i = 0; i < size; i = i + 1 ) {
            cout << "ID: " << lots[i].getID() << ", Dim: (" << lots[i].getRows() << "," << lots[i].getColumns() <<
            "), number of empty parking spaces: " << lots[i].getEmptySlots() << endl;
        }
    }
}

void ParkingSystem::lotContents( int id ) {
    bool controller = false;
    for( int i = 0; i < size; i = i + 1 ) {
        if( lots[i].getID() == id ) {
            controller = true;
            lots[i].listLot();
            break;
        }
    }
    if ( !controller ) {
       cout << "Lot " << id << " is not in the system" << endl;
    }
}

void ParkingSystem::removeLot( int id ) {
    bool controller = false;
    int index;
    int carSize;
    for( int i = 0; i < size; i = i + 1 ) {
        if( lots[i].getID() == id ) {
            index = i;
            controller = true;
            carSize = lots[index].getCarSize();
            for( int j = carSize - 1; j >= 0; j = j - 1) {
                lots[index].deleteCar(j);
            }

            ParkingLot* temp = lots;
            if ( size == 1) {
                lots = NULL;
            }
            else {
                lots = new ParkingLot[ size - 1];
                for( int x = 0; x < index; x = x + 1) {
                    lots[x] = temp[x];
                }
                for( int y = index + 1; y < size; y = y + 1) {
                    lots[y - 1] = temp[ y ];
                }
            }
        size = size - 1;
        delete [] temp;
        cout << "Lot " << id << " has been successfully removed from the system" << endl;
        break;
        }
    }
    if( !controller ) {
        cout << "Lot " << id << " is not in the system" << endl;
    }
}






