#include <iostream>

#include "Player.h"
#include "Game.h"
#include "ArrayList.h"

int main() {
    srand(time(NULL));
    Player* player1 = new Player("1");
    Player* player2 = new Player("2");

    ArrayList<Player*>* playerList = new ArrayList<Player*>(100);
    for(int i = 0; i < 100; i++) {
        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
    }

    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < 100; i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            testGame->generateSolution();
            testGame->play();
            delete testGame;
        }
    }

    for(int i = 0; i < 100; i++) {
        std::cout<< playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() <<std::endl;
    }


//
//    Game* g1 = new Game();
//
//    g1->generateSolution();
//    g1->collectGuess(50);
//    g1->calcGuess();
//    g1->play(*player1,*player2);

    //std::cout << player1->getWins() << " " << player2->getWins() << std::endl;
>>>>>>> c6f091f035dc4647204bceba803f585f2ba6d159

}