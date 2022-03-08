#ifndef HW3_LUXURYCAR_H
#define HW3_LUXURYCAR_H

#include "Car.h"

class LuxuryCar : virtual public Car{
public:
    LuxuryCar(string vehicle_Number, int junction_Location);
};

#endif //HW3_LUXURYCAR_H