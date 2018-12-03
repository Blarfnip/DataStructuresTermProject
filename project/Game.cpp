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
    if(p1Guess==1 and p2Guess==1){ //1 is rock and 2 is rock
        player1->tie();
        player2->tie();
    }

    else if(p1Guess==1 and p2Guess==2){ //1 is rock and 2 is paper
        player2->won();
        player1->lost();
    }

    else if(p1Guess==1 and p2Guess==3){ //1 is rock and 3 is scissors
        player1->won();
        player2->lost();
    }

    else if(p1Guess==2 and p2Guess==1){//1 is paper and 2 is rock
        player1->won();
        player2->lost();
    }

    else if(p1Guess==2 and p2Guess==2){//1 is paper and 2 is paper
        player1->tie();
        player2->tie();
    }

    else if(p1Guess==2 and p2Guess==3){//1 is paper and 2 is scissors
        player2->won();
        player1->lost();
    }

    else if(p1Guess==3 and p2Guess==1){//1 is scissors and 2 is rock
        player2->won();
        player1->lost();
    }

    else if(p1Guess==3 and p2Guess==2){//1 is scissors and 2 is paper
        player1->won();
        player2->lost();
    }

    else if(p1Guess==3 and p2Guess==3){//1 is scissors and 2 is scissors
        player1->tie();
        player2->tie();
    }

//    int difference1;
//    int difference2;
//
//    //Determines wins based on guesses and solution
//    if (p1Guess > solution) {
//        difference1=p1Guess-solution;
//    }
//    if(p1Guess < solution){
//        difference1=solution-p1Guess;
//    }
//    if(p2Guess > solution) {
//        difference2=p2Guess-solution;
//    }
//    if(p2Guess < solution) {
//        difference2=p2Guess-solution;
//    }
//    if(p1Guess==solution){
//        player1->won();
//        player2->lost();
//    }
//    else if(difference1<difference2){
//        player1->won();
//        player2->lost();
//    }
//
//    else if(difference2<difference1){
//        player2->won();
//        player1->lost();
//
//    }
//    else if(difference1==difference2){
//        player1->tie();
//        player2->tie();
//    }

}


