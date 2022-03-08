#include "Simulation.h"

//I used the defaults 'the big three' except destructor.

//This constructor create a new metropolis and gets all the require inputs.
Simulation::Simulation(int argc, char **argv){
    if (getFiles(argc, argv)){
        this->metropolis = new Metropolis(this->metropolis_Graph,this->number_Of_Junctions);
    }
    else{
        exit(1);
    }
    double pollution_Constant;
    cin >> pollution_Constant;
    cin >> this->number_Of_Time_Pulses;
    this->metropolis->set_C(pollution_Constant);
    this->metropolis->simulateMetropolis(this->vehicle_Locations,this->number_Of_Time_Pulses);
}

Simulation::~Simulation() {
    this->vehicle_Locations->destroyList();
    delete(this->vehicle_Locations);
    delete(metropolis);
}

//This function encodes the data into lists
bool Simulation::getFiles(int argc , char* argv []) {
    if(argc != 3){
        cerr << "error: invalid input.\n";
        return false;
    }
    ifstream met_graph (argv[1]);
    if (!met_graph){
        cerr << "error: invalid input.\n";
        return false;
    }
    ifstream vehicle_locations (argv[2]);
    if (!vehicle_locations)
    {
        cerr << "error: invalid input.\n";
        return false;
    }
    string line, num;
    bool flag = false;
    int j=0 , i=0;

    // Encodes metropolis graph
    while (getline (met_graph, line)){
        if (!flag){
            if (line.size() > 3) {
                cerr << "error: invalid input.\n";
                return false;
            }
            else if (atoi(line.c_str()) > MAX_JUNCTIONS){
                cerr << "error: invalid input.\n";
                return false;
            }
            else{
                this->number_Of_Junctions = atoi(line.c_str());
                flag = true;
            }
            this->metropolis_Graph = new double*[this->number_Of_Junctions];
            continue;
        }
        else{
            this->metropolis_Graph[i] = new double[this->number_Of_Junctions];
            for (unsigned int n=0; n<line.size(); n++){
                if (line[n] != ' '){
                    num += line[n];
                    if (n == line.size()-1){
                        this->metropolis_Graph[i][j] = atof(num.c_str());
                        num = "";
                    }
                }
                else{
                    this->metropolis_Graph[i][j] = atof(num.c_str());
                    num = "";
                    j++;
                }
            }
        }
        if (j != number_Of_Junctions-1){
            cerr << "error: invalid input.\n";
            return false;
        }
        j = 0;
        i++;
    }

    // Encodes vehicles locations
    i=0;
    int number_Of_Vehicles = 0;
    num = "";
    this->vehicle_Locations = new LinkedList<int>[this->number_Of_Junctions];
    while (getline (vehicle_locations, line)){
        for (unsigned int n=3; n<line.size(); n++){
            if (line[n] != ' '){
                num += line[n];
                if (n == line.size()-1) {
                    this->vehicle_Locations[i].insert(atoi(num.c_str()));
                    num = "";
                }
            }
            else{
                this->vehicle_Locations[i].insert(atoi(num.c_str()));
                number_Of_Vehicles ++;
                num = "";
            }
        }
        if (number_Of_Vehicles > MAX_VEHICLES){
            cerr << "error: invalid input.\n";
            return false;
        }
        i++;
    }
    return true;
}