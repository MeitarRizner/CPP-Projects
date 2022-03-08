#include "Road.h"

//I used the defaults 'the big three'.

Road::Road(double length,int from,int to,int road_Number) : length(length), from(from), to(to) ,road_Number(road_Number), air_Pollution_Level(0){}

//This function updates the air pollution level by using an operator ++ (postfix)
const Road Road::operator++(int) {
    Road temp = *this;
    this->air_Pollution_Level += this->pollution_Constant / this->length;
    return temp;
}

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

//This function sets the pollution level by an input
void Road::set_Pollution_Constant(double pollution_Constant) {
    this->pollution_Constant = pollution_Constant;
}