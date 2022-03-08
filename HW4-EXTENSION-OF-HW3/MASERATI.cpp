#include "MASERATI.h"

//I used the defaults 'the big three'.

MASERATI::MASERATI(string vehicle_Number, int junction_Location) : Car(vehicle_Number,junction_Location), SportsCar(vehicle_Number,junction_Location),
                                                                LuxuryCar(vehicle_Number,junction_Location) {
    this->pollution_Constant = 3;
}