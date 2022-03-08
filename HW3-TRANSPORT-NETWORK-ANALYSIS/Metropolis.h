#ifndef HW3_METROPOLIS_H
#define HW3_METROPOLIS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Junction.h"
#include "Road.h"
#include "Vehicle.h"
#include "LinkedList.h"
using namespace std;

class Metropolis {
public:
    ~Metropolis();
    Metropolis (double** graph, unsigned int size);
    void set_C(double c);
    void simulateMetropolis(LinkedList<int>* vehicle_Locations,int number_Of_Time_Pulses);

private:
    int number_Of_Junctions;
    int number_Of_Roads;
    Junction** junction_List;
    LinkedList<Road*>* road_List;
    LinkedList<Vehicle*>* Vehicle_List;

    void update_Vehicles(LinkedList<int>* vehicle_locations);
    void print_Simulate_Results();
    void vehicles_Movement();
};


#endif //HW3_METROPOLIS_H
