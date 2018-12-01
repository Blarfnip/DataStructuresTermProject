#include <iostream>

#include "Player.h"
#include "Game.h"
#include "ArrayList.h"

int main() {
    srand(time(NULL)); //Seeds random numbers

    //Populates list with players
    List<Player*>* playerList = new ArrayList<Player*>(100);
    for(int i = 0; i < 100; i++) {
        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
    }

    //Sets first player to be a user
    //playerList->getValueAt(0)->setIsPlayer(true);

    //Runs 100 matches with each player
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < 100; i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            testGame->generateSolution();
            testGame->play();
            delete testGame;
        }
    }

    //Outputs player wins
    for(int i = 0; i < 100; i++) {
        std::cout<< playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() <<std::endl;
    }

}