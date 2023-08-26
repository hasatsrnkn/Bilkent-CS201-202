/*
    NAME: Mehmet Hasat Serinkan
    ID: 21901649
*/

#include "ParkingLot.h"
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
