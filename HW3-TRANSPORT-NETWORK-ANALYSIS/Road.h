#ifndef HW3_ROAD_H
#define HW3_ROAD_H

class Road {
public:
    Road(double length,int from,int to,int road_Number);
    const Road operator++(int);
    int get_From() const;
    int get_To() const;
    void set_Pollution_Constant(double pollution_Constant);
    double get_Air_Pollution_Level() const;

private:
    double length;
    int from;
    int to;
    int road_Number;
    double air_Pollution_Level;
    double pollution_Constant;
};


#endif //HW3_ROAD_H
