#include <iostream>

#include "Player.h"
#include "Game.h"
#include "ArrayList.h"

int main() {
    srand(time(NULL));

    List<Player*>* playerList = new ArrayList<Player*>(100);
    for(int i = 0; i < 100; i++) {
        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
    }

    //playerList->getValueAt(0)->setIsPlayer(true);

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

}