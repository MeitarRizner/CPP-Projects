#ifndef HEX_GAME_H
#define HEX_GAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Player.h"

using namespace std;

class Game{
public:
    Game();
    void Play();

private:
    char board[11][11];
    Player* playerR;
    Player* playerB;
    char turn;
    void printBoard() const;
    bool checkInput(const string input) const;
    void changeTurn();
};

#endif //HEX_GAME_H