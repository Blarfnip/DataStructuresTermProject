#include <iostream>

#include "Player.h"
#include "Game.h"

int main() {
    Player* player1 = new Player("1");
    Player* player2 = new Player("2");

    Game* g1 = new Game(*player1, *player2);

    g1->generateSolution();
    g1->collectGuess(2);
    g1->calcGuess();
    g1->play();

    std::cout << player1->getWins() << " " << player2->getWins() << std::endl;

}