#ifndef HW3_METROPOLIS_H
#define HW3_METROPOLIS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Junction.h"
#include "Road.h"
#include "Car.h"
#include "LinkedList.h"
#include "Map.h"
#include "FamilyCar.h"
#include "SportsCar.h"
#include "LuxuryCar.h"
#include "MASERATI.h"
using namespace std;

class Metropolis {
public:
    ~Metropolis();
    Metropolis (double** graph, unsigned int size);
    void simulateMetropolis(LinkedList<string>* vehicle_Locations,int number_Of_Time_Pulses);

private:
    int number_Of_Junctions;
    int number_Of_Roads;
    Junction** junction_List;
    LinkedList<Road*>* road_List;
    LinkedList<Car*>* Vehicle_List;
    Map<string,int>* VehiclesLocations;

    void update_Vehicles(LinkedList<string>* vehicle_locations);
    void vehicles_Movement();
    void print_Simulate_Results();
};


#endif //HW3_METROPOLIS_H
