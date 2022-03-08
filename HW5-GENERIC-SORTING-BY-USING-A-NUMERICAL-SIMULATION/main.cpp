#include <iostream>
using namespace std;
#include "Simulation.h"

//The main program starts a simulation.
int main(int argc,char** argv) {
    Simulation* sm = new Simulation(argc, argv);
    sm->startSimulation();
    return 0;
}