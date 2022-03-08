#ifndef HW5_SIMULATION_H
#define HW5_SIMULATION_H

#include "Container.h"
#include "WrongInput.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//I used the defaults 'the big three'.
class Simulation {
public:
    Simulation(int argc, char **argv);
    void startSimulation();
    class InputFileError{};
    class OutputFileError{};
    class RegularWrongInput{};

private:
    double** getFiles(int argc , char* argv []);
    Container<double>* setTargetVectors(Container<double>* cont, int numberOfElements) const;
    void printResults() const;
    Container<double>* population;
    int populationSize;
    int n;
    int m;
    int timeSteps;
    string outputFile;
};


#endif //HW5_SIMULATION_H
