//
// Created by Milo Rue on 12/1/2018.
//

#include "MatchMaker.h"
//artificially plays games against next player in list outside of queue
void MatchMaker::playMatchesList(List<Player*>* playerList ,int numOfMatches){
    for(int k = 0; k < numOfMatches; k++) {
        for(int i = 0; i < playerList->itemCount(); i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            //testGame->generateSolution(); *changed game to rock paper scissors format
            testGame->play();
            delete testGame;
        }
    }
}
void MatchMaker::playMatchesQueue(PlayerQueue *playerQueue, int numOfMatches, std::string queueName) {
    int total=playerQueue->getCount();
    bool even;

    if(total % 2 == 0){
        even=true;
        total=total/2;
    }
    else{
        even=false;
        total=total/2;
    }
    if( numOfMatches>total){
        std::cout << "Entered Match Amount is greater than that of players in " +  queueName + " queue"<< std::endl;
        std::cout << "Played " + std::to_string(total) + " instead" << std::endl;
        for (int f = 0; f < total; f++) {
            Game *testGame = new Game(playerQueue->dequeue()->getPlayer(), playerQueue->dequeue()->getPlayer());
            testGame->collectGuesses();
            testGame->play();
            delete testGame;
        }
    }
    else {
        for (int f = 0; f < numOfMatches; f ++) {
            Game *testGame = new Game(playerQueue->dequeue()->getPlayer(), playerQueue->dequeue()->getPlayer());
            testGame->collectGuesses();
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




