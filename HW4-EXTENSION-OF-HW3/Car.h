#ifndef HW3_CAR_H
#define HW3_CAR_H

#include <string>
using namespace std;

class Car {
public:
    Car(string vehicle_Number, int junction_Location);
    virtual ~Car() = 0;
    void set_Location(int location);
    int get_Location() const;
    string get_Vehicle_Number() const;
    int getPollution_Constant() const;

protected:
    string vehicle_Number;
    int junction_Location;
    int pollution_Constant;
};

#endif //HW3_CAR_H