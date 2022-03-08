#include "Game.h"
/*I used the defaults 'the big three'.
I didn't use dynamic memory assignments*/

//This class represents a game. The class has a game board and objects of 2 players.
Game::Game(){
    for (int i=0 ; i<11 ; i++){
        for (int j=0 ; j<11 ; j++){
            this->board[i][j] = 'O';
        }
    }
    this->turn = 'B';
    this->playerB = new Player();
    this->playerR = new Player();
}

//This method prints the game board
void Game::printBoard() const{
    for (int r=0 ; r<11 ; r++){
        for (int c=0; c<r ; c++)
            cout << ' ';
        for (int c=0 ; c<11 ; c++){
            cout << this->board[r][c];
            if (c != 10){
                cout << " ";
            }
        }
        cout << "\n";
    }
}

//This method starts the game until one of the players is winning or quitting.
void Game::Play(){
    printBoard();
    int i,j;
    string input;
    while (true){
        cout << this->turn << ":\n";
        cin >> input;
        if (input == "QUIT"){
            break;
        }
        while (!checkInput(input)){
            cerr << "Invalid move; the game awaits a valid move.\n";
            cin >> input;
        }
        j = input[0] - 65;
        i = input[1] - 49;
        if (input.size() == 3){
            if (input[2] == '1')
                i+= 10;
            if (input[2] == '0')
                i+= 9;
        }
        this->board[i][j] = this->turn;
        printBoard();
        if (this->turn == 'B'){
            this->playerB->updatePlayer(i,j);
            if (playerB->checkWin(this->turn)){
                cout  << "B wins the game.\n";
                break;
            }
        }
        else{
            this->playerR->updatePlayer(i,j);
            if (playerR->checkWin(this->turn)){
                cout  << "R wins the game.\n";
                break;
            }
        }
        changeTurn();
    }
    if (input == "QUIT"){
        cout << this->turn << ": QUIT\n";
        printBoard();
        changeTurn();
        cout << this->turn << " wins the game.\n";
    }
}

//This method checks if the input value is valid.
bool Game::checkInput(const string input) const{
    if (input == "QUIT"){
        return true;
    }
    if (input.size() == 3){
        if (!isalpha(input[0]))
            return false;
        if('K' < input[0] || !isupper(input[0]))
            return false;
        if (input[1] != '1')
            return false;
        if (!isdigit(input[2]))
            return false;
        if (input[2] != '0' && input[2] != '1')
            return false;
    }
    else if (input.size() == 2){
        if (!isalpha(input[0]))
            return false;
        if('K' < input[0] || !isupper(input[0]))
            return false;
        if (!isdigit(input[1]))
            return false;
        if('1' > input[1] || '9' < input[1])
            return false;
    }
    else return false;
    int j = input[0] - 65;
    int i = input[1] - 49;
    if (input.size() == 3){
        if (input[2] == '1')
            i+= 10;
        if (input[2] == '0')
            i+= 9;
    }
    if (this->board[i][j] != 'O')
        return false;
    return true;
}

//This method changes the turn value to the second player.
void Game::changeTurn(){
    if(this->turn == 'B')
        this->turn = 'R';
    else
        this->turn = 'B';
}