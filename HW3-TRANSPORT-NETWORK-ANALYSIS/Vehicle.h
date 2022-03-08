#ifndef HW3_VEHICLE_H
#define HW3_VEHICLE_H

class Vehicle {
public:
    Vehicle(int vehicle_Number, int junction_Location);
    void set_Location(int location);
    int get_Location() const;
    int get_Vehicle_Number() const;

private:
    int vehicle_Number;
    int junction_Location;
};


#endif //HW3_VEHICLE_H
