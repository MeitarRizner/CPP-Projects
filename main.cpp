#include <iostream>
#include "Game.h"

//The main program creates a game object and starts the game.
int main() {
    Game* game = new Game();
    game->Play();
    return 0;
}