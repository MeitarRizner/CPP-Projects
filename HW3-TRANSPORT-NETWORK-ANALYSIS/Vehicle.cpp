#include "Vehicle.h"

//I used the defaults 'the big three'.

Vehicle::Vehicle(int vehicle_Number, int junction_Location) : vehicle_Number(vehicle_Number), junction_Location(junction_Location) {}

//This function sets a new location to the vehicle
void Vehicle::set_Location(int location) {
    this->junction_Location = location;
}

//This function returns the current location
int Vehicle::get_Location() const {
    return this->junction_Location;
}

//This function returns the vehicle number
int Vehicle::get_Vehicle_Number() const {
    return this->vehicle_Number;
}
