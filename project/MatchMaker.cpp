//
// Created by Milo Rue on 12/1/2018.
//

#include "MatchMaker.h"

void runMatches(List<Player*>* playerList ,int numOfMatches, int index){
    for(int k = 0; k < 1000; k++) {
        for(int i = 0; i < 100; i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            //testGame->generateSolution(); *changed game to rock paper scissors format
            testGame->play();
            delete testGame;
        }
    }
}

void playersWon(List<Player>* playerList){
    for(int i = 0; i < 100; i++) {
        std::cout<< playerList->getValueAt(i).getID() << " | " << playerList->getValueAt(i).getWins() <<std::endl;
    }
}
 void createPlayerList(List<Player*>* playerList, int numOfPlayers, int index){
    playerList->insertAtEnd(new Player("Player " + std::to_string(index)));
    if(index<numOfPlayers) {
        return createPlayerList(playerList, numOfPlayers,index++);
    }
}




