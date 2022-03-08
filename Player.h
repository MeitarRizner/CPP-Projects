#ifndef HEX_PLAYER_H
#define HEX_PLAYER_H

#include <cmath>
#include <iostream>

class Player {
public:
    Player();
    void updatePlayer(int i, int j);
    bool checkWin(char turn) const;

private:
    bool playerData[11][11];
    bool checkNeighbor(int i, int j, int n, int m) const;
};

#endif //HEX_PLAYER_H