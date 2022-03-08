#include "Metropolis.h"

//I used the defaults 'the big three' except destructor.

//The constructor creates an empty metropolis without a vehicles, only roads and junctions
Metropolis::Metropolis(double **graph, unsigned int size) {
    this->number_Of_Junctions = int(size);
    this->number_Of_Roads = 0;
    int counter = 0; //number of neighboring junctions
    this->Vehicle_List = new LinkedList<Vehicle*>();
    this->junction_List = new Junction*[this->number_Of_Junctions];
    this->road_List = new LinkedList<Road*>();
    for (int i=0; i<this->number_Of_Junctions; i++){
        this->junction_List[i] = new Junction(i);
        for(int j=0; j<this->number_Of_Junctions; j++){
            if (graph[i][j] != 0){
                this->junction_List[i]->set_Neighboring_Junctions(j);
                this->road_List->insert(new Road(graph[i][j],i,j,number_Of_Roads));
                this->number_Of_Roads++;
                counter++;
            }
        }
        this->junction_List[i]->set_Number_Of_neighbors(counter);
        counter = 0;
    }
}

Metropolis::~Metropolis() {
    this->road_List->destroyList();
    delete(this->road_List);
    for (int i=0; i<this->number_Of_Junctions; i++){
        delete(this->junction_List[i]);
    }
    delete(this->junction_List);
    this->Vehicle_List->destroyList();
    delete(this->Vehicle_List);
}

//This function sets the pollution constant for all the vehicles
void Metropolis::set_C(double c) {
    LinkedList<Road*>* temp = new LinkedList<Road*>();
    temp->head = this->road_List->head;
    while (this->road_List->head != NULL){
        this->road_List->head->data->set_Pollution_Constant(c);
        this->road_List->head = this->road_List->head->next;
    }
    this->road_List = temp;
}

//This functions gets a vehicles locations linked list and creates all the vehicles
void Metropolis::update_Vehicles(LinkedList<int>* vehicle_locations) {
    for (int i=0; i<this->number_Of_Junctions; i++) {
        while (vehicle_locations[i].head != NULL) {
            Vehicle_List->insert(new Vehicle(vehicle_locations[i].head->data,i));
            this->junction_List[i]->get_Vehicles_In_Junction()->insert(vehicle_locations[i].head->data);
            vehicle_locations[i].head = vehicle_locations[i].head->next;
        }
    }
}

//This function activates the moving of the vehicles by the amount of times inserted
void Metropolis::simulateMetropolis(LinkedList<int>* vehicle_Locations, int number_Of_Time_Pulses) {
    update_Vehicles(vehicle_Locations);
    int counter =0;
    while (counter < number_Of_Time_Pulses){
        vehicles_Movement();
        counter ++;
    }
    print_Simulate_Results();
}

//This function prints all the required details
void Metropolis::print_Simulate_Results() {
    bool flag = false;
    for (int i=0; i<this->number_Of_Junctions; i++){
        for (int j=0; j<this->number_Of_Junctions; j++){
            if (i==j){
                cout << "0";
            }
            else{
                LinkedList<Road*>* temp = new LinkedList<Road*>();
                temp->head = road_List->head;
                while (this->road_List->head != NULL){
                    if(this->road_List->head->data->get_From() == i && this->road_List->head->data->get_To() == j){
                        cout << setprecision (2) << this->road_List->head->data->get_Air_Pollution_Level();
                        flag = true;
                        break;
                    }
                    this->road_List->head = this->road_List->head->next;
                }
                this->road_List = temp;
                if (!flag){
                    cout << "0";
                }
                else flag = false;
            }
            if (j != this->number_Of_Junctions-1){
                cout << " ";
            }
        }
        cout << "\n";
    }

    for (int i=0; i<this->number_Of_Junctions; i++){
        cout << i+1 << ": ";
        while (this->junction_List[i]->get_Vehicles_In_Junction()->head != NULL){
            cout << this->junction_List[i]->get_Vehicles_In_Junction()->head->data;
            if (this->junction_List[i]->get_Vehicles_In_Junction()->head->next != NULL){
                cout << " ";
            }
            this->junction_List[i]->get_Vehicles_In_Junction()->head = this->junction_List[i]->get_Vehicles_In_Junction()->head->next;
        }
        cout << "\n";
    }
}

//This function moves the vehicles by raffling a junction for each vehicle
void Metropolis::vehicles_Movement() {
    int location, new_Location;
    LinkedList<Vehicle*>* temp_Vehicle_List = new LinkedList<Vehicle*>();
    temp_Vehicle_List->head = this->Vehicle_List->head;
    while (this->Vehicle_List->head != NULL){
        location = this->Vehicle_List->head->data->get_Location();
        LinkedList<int>* Neighboring_Junctions = new LinkedList<int>(this->junction_List[location]->get_Neighboring_Junctions()->head);
        srand(time(NULL));
        int raffle = rand() % (this->junction_List[location]->get_Number_Of_neighbors()+1) + 0;
        if (raffle != 0){ // 0 = Doesn't move to another junction
            new_Location = Neighboring_Junctions->getData(raffle-1);
            this->junction_List[new_Location]->get_Vehicles_In_Junction()->insert(this->Vehicle_List->head->data->get_Vehicle_Number());
            this->junction_List[location]->get_Vehicles_In_Junction()->Delete(this->Vehicle_List->head->data->get_Vehicle_Number());
            this->Vehicle_List->head->data->set_Location(new_Location);
            LinkedList<Road*>* temp_Road_List = new LinkedList<Road*>();
            temp_Road_List->head = this->road_List->head;
            while (this->road_List->head != NULL){
                if (this->road_List->head->data->get_From() == location && this->road_List->head->data->get_To() == new_Location){
                    this->road_List->head->data->operator++(0);
                    break;
                }
                this->road_List->head = this->road_List->head->next;
            }
            this->road_List = temp_Road_List;
        }
        this->Vehicle_List->head = this->Vehicle_List->head->next;
        delete(Neighboring_Junctions);
    }
    delete(this->Vehicle_List);
    this->Vehicle_List = temp_Vehicle_List;
}