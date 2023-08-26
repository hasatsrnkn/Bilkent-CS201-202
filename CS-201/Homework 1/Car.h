/*
    NAME: Mehmet Hasat Serinkan
    ID: 21901649
*/

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
