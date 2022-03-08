#ifndef HW3_JUNCTION_H
#define HW3_JUNCTION_H
#include "LinkedList.h"


class Junction {
public:
    Junction(int junction_Number);
    ~Junction();
    void set_Number_Of_neighbors(int num);
    int get_Number_Of_neighbors() const;
    void set_Neighboring_Junctions(int x);
    LinkedList<int>* get_Neighboring_Junctions() const;
    LinkedList<string>* get_Vehicles_In_Junction() const;

private:
    int junction_Number;
    int number_Of_neighbors;
    LinkedList<int>* neighboring_Junctions;
    LinkedList<string>* vehicles_In_Junction;
};


#endif //HW3_JUNCTION_H
