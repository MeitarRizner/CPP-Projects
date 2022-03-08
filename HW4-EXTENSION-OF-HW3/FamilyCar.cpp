#include "FamilyCar.h"

//I used the defaults 'the big three'.

FamilyCar::FamilyCar(string vehicle_Number, int junction_Location) : Car(vehicle_Number,junction_Location){
    this->pollution_Constant = 2;
}