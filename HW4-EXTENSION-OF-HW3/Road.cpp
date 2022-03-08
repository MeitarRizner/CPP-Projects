#include "Road.h"

//I used the defaults 'the big three'.

Road::Road(double length,int from,int to,int road_Number) : length(length), from(from), to(to) ,road_Number(road_Number), air_Pollution_Level(0){}

//This function returns the junction where the road starts
int Road::get_From() const {
    return this->from;
}

//This function returns the junction where the road ends
int Road::get_To() const {
    return this->to;
}

//This function returns the air pollution level
double Road::get_Air_Pollution_Level() const {
    return this->air_Pollution_Level;
}

//This function updates the air pollution level
void Road::updateAir_Pollution_Level(int pollution_Constant) {
    this->air_Pollution_Level += pollution_Constant / this->length;
}
