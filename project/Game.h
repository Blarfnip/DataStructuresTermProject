//
// Created by Milo Rue on 11/12/2018.
//

#ifndef TERM_PROJECT_220_GAME_H
#define TERM_PROJECT_220_GAME_H
#include "Player.h"
#include "string"
#include "iostream"
#include "stdlib.h"
#include "time.h"
#include "ArrayLib.h"



class Game{
private:
    int solution; //Game Solution
    int p1Guess; //Player 1 guess
    int p2Guess; //Player 2 Guess
    Player* player1; //Player 1 pointer
    Player* player2; //Player 2 pointer

public:
    Game(Player* player1, Player* player2);
    void collectGuesses(); //Calls generateGuess on each player and stores values

    void generateSolution(); //Generates game solution
    void play(); //Evaluates guesses and solution to determine wins
};

#endif //TERM_PROJECT_220_GAME_H
