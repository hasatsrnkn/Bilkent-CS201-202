/*
    NAME: Mehmet Hasat Serinkan
    ID: 21901649
*/

#include <iostream>
using namespace std;
class Car {
public:
    Car( int plateNo = 0, string location = "", string type = "" );
    Car( const Car& car);
    ~Car();
    Car& operator= (const Car& car);
    int getPlateNo();
    string getLocation();
    string getType();
    void setPlateNo( const int plateNo );
    void setLocation( const string location );
    void setType( const string type);

private:
    int plateNo;
    string location;
    string type;
};

Car::Car(int plateNo, string location, string type) {
    this->plateNo = plateNo;
    this->location = location;
    this->type = type;
}

Car::Car( const Car& car) {
    plateNo = car.plateNo;
    location = car.location;
    type = car.type;
}

Car::~Car() {
}

Car& Car::operator= (const Car& car) {
    plateNo = car.plateNo;
    location = car.location;
    type = car.type;

    return *this;
}


int Car::getPlateNo() {
    return plateNo;
}

string Car::getLocation() {
    return location;
}

string Car::getType() {
    return type;
}

void Car::setPlateNo( const int plateNo ) {
    this->plateNo = plateNo;
}

void Car::setLocation( const string location ) {
    this->location = location;
}

void Car::setType( const string type) {
    this->type = type;
}

