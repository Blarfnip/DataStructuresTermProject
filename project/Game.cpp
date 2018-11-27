//
// Created by Milo Rue on 11/12/2018.
//

#include "Game.h"

Game::Game(Player* player1, Player* player2) {
    this->player1 = player1;
    this->player2 = player2;
}

void Game::collectGuesses() {
    p1Guess = player1->generateGuess();
    p2Guess = player2->generateGuess();
}

void Game::generateSolution() {
    solution=genRandInt(1,100);
}



void Game::play() {
    int difference1;
    int difference2;

    if (p1Guess > solution) {
        difference1=p1Guess-solution;
    }
    if(p1Guess < solution){
        difference1=solution-p1Guess;
    }
    if(p2Guess > solution) {
        difference2=p2Guess-solution;
    }
    if(p2Guess < solution) {
        difference2=p2Guess-solution;
    }
    if(p1Guess==solution){
        player1->won();
        player2->lost();
    }
    if(difference1<difference2){
        player1->won();
        player2->lost();
    }

    else if(difference2<difference1){
        player2->won();
        player1->lost();

    }
    else if(difference1==difference2){
        player1->won();
        player2->lost();
    }

}


