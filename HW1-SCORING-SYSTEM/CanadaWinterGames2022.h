#ifndef EX1_CANADAWINTERGAMES2022_H
#define EX1_CANADAWINTERGAMES2022_H
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <iomanip>

class CanadaWinterGames2022{
public:
    CanadaWinterGames2022(int referees, int competitors);
    void setScore();
    void getScore() const;
    void getAverage() const;
    void getSummary() const;
    void getMean();
    void getVariance();

private:
    typedef struct Competitor
    {
        float* refereesScores;
        std::string competitorName;
    }Competitor;
    int competitorsAmount;
    int competitorsCurrentAmount;
    int refereesAmount;
    Competitor* competitorsList;
    void updateMeanArray();
    float* MeanArray;
    bool meanFlag;
};













#endif //EX1_CANADAWINTERGAMES2022_H
