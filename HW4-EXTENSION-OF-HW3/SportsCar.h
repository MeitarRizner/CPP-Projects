#ifndef HW3_SPORTSCAR_H
#define HW3_SPORTSCAR_H

#include "Car.h"

class SportsCar : virtual public Car {
public:
    SportsCar(string vehicle_Number, int junction_Location);
};


#endif //HW3_SPORTSCAR_H