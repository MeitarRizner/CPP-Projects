#ifndef HW3_SIMULATION_H
#define HW3_SIMULATION_H

#include "Metropolis.h"
#include "LinkedList.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

#define MAX_JUNCTIONS 500
#define MAX_VEHICLES 10000

using namespace std;


class Simulation{
public:
    Simulation(int argc, char **argv);
    ~Simulation();
private:
    unsigned int number_Of_Time_Pulses;
    Metropolis* metropolis;
    double** metropolis_Graph;
    LinkedList<string>* vehicle_Locations;
    int number_Of_Junctions;
    bool getFiles(int argc , char* argv []);
};


#endif //HW3_SIMULATION_H
