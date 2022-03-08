#ifndef HW5_WRONGINPUT_H
#define HW5_WRONGINPUT_H

#include <iostream>
#include <string>
#include <cstdlib>

//This class define an exception detailed by the exactly row
class WrongInput{
public:
    WrongInput(int row, string file){
        this->row = row;
        this->fileName = file;
    }
    void PrintError(){
        cerr << "ERROR: population definition in " << this->fileName << " at line " << this->row << " is invalid\n";
    }

private:
    int row;
    string fileName;
};

#endif //HW5_WRONGINPUT_H
