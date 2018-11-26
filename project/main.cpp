#include <iostream>

#include "Player.h"
#include "Game.h"

int main() {
    srand(time(NULL));
    Player* player1 = new Player("1");
    Player* player2 = new Player("2");

    Game* g1 = new Game();
    Game* g2 = new Game();
    Game* g3 = new Game();

    g1->generateSolution();
    g1->collectGuess(76);
    g1->calcGuess();
    g1->play(*player1,*player2);

    g2->generateSolution();
    g2->collectGuess(76);
    g2->calcGuess();
    g2->play(*player1,*player2);

    g3->generateSolution();
    g3->collectGuess(76);
    g3->calcGuess();
    g3->play(*player1,*player2);

    std::cout << player1->getWins() << " " << player2->getWins() << std::endl;

}