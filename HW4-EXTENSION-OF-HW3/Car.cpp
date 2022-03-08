#include "Car.h"

//I used the defaults 'the big three' except empty destructor to define this class as abstract class

Car::Car(string vehicle_Number, int junction_Location) : vehicle_Number(vehicle_Number), junction_Location(junction_Location), pollution_Constant(0) {}

Car::~Car(){};

//This function sets a new location to the vehicle
void Car::set_Location(int location) {
    this->junction_Location = location;
}

//This function returns the current location
int Car::get_Location() const {
    return this->junction_Location;
}

//This function returns the vehicle number
string Car::get_Vehicle_Number() const {
    return this->vehicle_Number;
}

//This function returns the pollution constant
int Car::getPollution_Constant() const {
    return this->pollution_Constant;
}