#ifndef HW3_MASERATI_H
#define HW3_MASERATI_H

#include "SportsCar.h"
#include "LuxuryCar.h"

class MASERATI : public SportsCar, public LuxuryCar{
public:
    MASERATI(string vehicle_Number, int junction_Location);
};

#endif //HW3_MASERATI_H