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
    ParkingLot( const ParkingLot& pl);
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
