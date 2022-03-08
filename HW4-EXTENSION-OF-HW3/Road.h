#ifndef HW3_ROAD_H
#define HW3_ROAD_H

class Road {
public:
    Road(double length,int from,int to,int road_Number);
    int get_From() const;
    int get_To() const;
    double get_Air_Pollution_Level() const;
    void updateAir_Pollution_Level(int pollution_Constant);

private:
    double length;
    int from;
    int to;
    int road_Number;
    double air_Pollution_Level;
};


#endif //HW3_ROAD_H
