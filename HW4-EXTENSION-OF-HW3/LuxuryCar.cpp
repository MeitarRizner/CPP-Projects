#include "LuxuryCar.h"

//I used the defaults 'the big three'.

LuxuryCar::LuxuryCar(string vehicle_Number, int junction_Location) : Car(vehicle_Number,junction_Location) {
    this->pollution_Constant = 3;
}