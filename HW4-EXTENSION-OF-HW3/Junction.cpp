#include "Junction.h"

//I used the defaults 'the big three' except destructor.

Junction::Junction(int junction_Number) : junction_Number(junction_Number){
    this->neighboring_Junctions = new LinkedList<int>();
    this->vehicles_In_Junction = new LinkedList<string>();
}

Junction::~Junction() {
    this->vehicles_In_Junction->destroyList();
    this->neighboring_Junctions->destroyList();
    delete(this->vehicles_In_Junction);
    delete(this->neighboring_Junctions);
}

//Function to get the neighboring Junctions linked list
LinkedList<int>* Junction::get_Neighboring_Junctions() const {
    return this->neighboring_Junctions;
}

//Function to insert a new junction to the neighboring Junctions linked list
void Junction::set_Neighboring_Junctions(int x)  {
    this->neighboring_Junctions->insert(x);
}

//Function to set the number of neighbors
void Junction::set_Number_Of_neighbors(int num) {
    this->number_Of_neighbors = num;
}

//Function to get the number of neighbors
int Junction::get_Number_Of_neighbors() const {
    return this->number_Of_neighbors;
}

//Function to get the vehicles linked list in a junction
LinkedList<string> *Junction::get_Vehicles_In_Junction() const {
    return this->vehicles_In_Junction;
}
