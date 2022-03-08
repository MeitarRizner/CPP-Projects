#include "Player.h"
//I used the default 'the big three'.
//I didn't use dynamic memory assignments

//This class represents a players. Any player have a unique board for him.
Player::Player() {
    for (int i=0 ; i<11 ; i++){
        for (int j=0 ; j<11 ; j++){
            this->playerData[i][j] = false;
        }
    }
}

//This method updates the value of an (i,j) element in the player board.
void Player::updatePlayer(int i,int j){
    this->playerData[i][j] = true;
}

//This method checks if the player has a valid sequence.
bool Player::checkWin(char turn) const{
    if (turn == 'B'){
        int nextElementColumn = 1;
        int prevElementRow = 1;
        bool hasNeighbor = false;
        int firstElementRow = 0;
        while (firstElementRow < 11){
            while (!this->playerData[firstElementRow][0]){
                firstElementRow++;
                if (firstElementRow > 10){
                    return false;
                }
            }
            while (true){
                for (int i=0 ; i<11 ; i++){
                    if (this->playerData[i][nextElementColumn]){
                        if (nextElementColumn == 1){
                            if (checkNeighbor(firstElementRow+1,nextElementColumn,i+1,nextElementColumn+1)){
                                prevElementRow = i;
                                nextElementColumn++;
                                hasNeighbor = true;
                                break;
                            }
                        }
                        else{
                            if (checkNeighbor(prevElementRow+1,nextElementColumn,i+1,nextElementColumn+1)){
                                prevElementRow = i;
                                nextElementColumn++;
                                hasNeighbor = true;
                                break;
                            }
                        }
                    }
                }
                if (!hasNeighbor){
                    firstElementRow++;
                    break;
                }
                if (nextElementColumn == 11){
                    return true;
                }
                hasNeighbor = false;
            }
        }
        return false;
    }
    else if (turn == 'R'){
        int nextElementRow = 1;
        int prevElementColumn = 1;
        bool hasNeighbor = false;
        int firstElementColumn = 0;
        while (firstElementColumn < 11){
            while (!this->playerData[0][firstElementColumn]){
                firstElementColumn++;
                if (firstElementColumn > 10){
                    return false;
                }
            }
            while (true){
                for (int i=0 ; i<11 ; i++){
                    if (this->playerData[nextElementRow][i]){
                        if (nextElementRow == 1){
                            if (checkNeighbor(nextElementRow,firstElementColumn+1,nextElementRow+1,i+1)){
                                prevElementColumn = i;
                                nextElementRow++;
                                hasNeighbor = true;
                                break;
                            }
                        }
                        else{
                            if (checkNeighbor(nextElementRow,prevElementColumn+1,nextElementRow+1,i+1)){
                                prevElementColumn = i;
                                nextElementRow++;
                                hasNeighbor = true;
                                break;
                            }
                        }
                    }
                }
                if (!hasNeighbor){
                    firstElementColumn++;
                    break;
                }
                if (nextElementRow == 11){
                    return true;
                }
                hasNeighbor = false;
            }
        }
        return false;
    }
    else return false;
}

//This method check if the (n,m) element is a valid neighbor of the (i,j) element.
bool Player::checkNeighbor(int i, int j, int n, int m) const{
    //corners
    if (i==11 && j==1){
        if((n==10 && m==1) || (n==10 && m==2) || (n==11 && m==2))
            return true;
    }
    if (i==1 && j==11){
        if((n==1 && m==10) || (n==2 && m==10) || (n==2 && m==11))
            return true;
    }
    if (i==11 && j==11){
        if((n==11 && m==10) || (n==10 && m==11))
            return true;
    }
    if (i==1 && j==1){
        if((n==2 && m==1) || (n==1 && m==2))
            return true;
    }
    //frames
    if (i>1 && i<11 && j==1){
        if((n==i-1 && m==1) || (n==i+1 && m==1) || (n==i-1 && m==2) || (n==i && m==2))
            return true;
    }
    if (i>1 && i<11 && j==11){
        if((n==i-1 && m==11) || (n==i+1 && m==11) || (n==i+1 && m==10) || (n==i && m==10))
            return true;
    }
    if (j>1 && j<11 && i==1){
        if((n==1 && m==j-1) || (n==1 && m==j+1) || (n==i+1 && m==j-1) || (n==i+1 && m==j))
            return true;
    }
    if (j>1 && j<11 && i==11){
        if((n==11 && m==j-1) || (n==11 && m==j+1) || (n==10 && m==j) || (n==10 && m==j+1))
            return true;
    }
    //inner
    if (j>1 && j<11 && i>1 && i<11){
        if((n==i-1 && m==j) || (n==i+1 && m==j) || (n==i && m==j+1) || (n==i && m==j-1) || (n==i-1 && m==j+1) || (n==i+1 && m==j-1))
            return true;
    }
    return false;
}