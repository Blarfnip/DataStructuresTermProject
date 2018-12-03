#include <iostream>

#include "Player.h"
#include "Game.h"
#include "ArrayList.h"
#include "PlayerQueue.h"
#include "PlayerNode.h"

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
    for(int k = 0; k < 1000; k++) {
        for(int i = 0; i < 100; i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            //testGame->generateSolution(); *changed game to rock paper scissors format
            testGame->play();
            delete testGame;
        }
    }

    //Outputs player wins
    for(int i = 0; i < 100; i++) {
        std::cout<< playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() <<std::endl;
    }

    //creates queues for ratings
    PlayerQueue* bronzeQueue= new PlayerQueue();
    PlayerQueue* silverQueue= new PlayerQueue();
    PlayerQueue* goldQueue= new PlayerQueue();
    PlayerQueue* platinumQueue= new PlayerQueue();
    PlayerQueue* diamondQueue= new PlayerQueue();
    PlayerQueue* challengerQueue=new PlayerQueue();

    Player* tempPlayer;
    for(int i = 0; i<100; i++){
        tempPlayer=playerList->removeValueAtFront();
        if(tempPlayer->checkTier()=="Bronze"){
            bronzeQueue->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Silver"){
            silverQueue->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Gold"){
            goldQueue->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Platinum"){
            platinumQueue->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Diamond"){
            diamondQueue->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Challenger"){
            challengerQueue->enqueue(tempPlayer);
        }
    }
    std::string outStringB="Bronze Queued Players: ";
    std::string outStringS="Silver Queued Players: ";
    std::string outStringG="Gold Queued Players: ";
    std::string outStringP="Platinum Queued Players: ";
    std::string outStringD="Diamond Queued Players: ";
    std::string outStringC="Challenger Queued Players: ";
    outStringB += bronzeQueue->toString();
    outStringS += silverQueue->toString();
    outStringG += goldQueue->toString();
    outStringP += platinumQueue->toString();
    outStringD += diamondQueue->toString();
    outStringC += challengerQueue->toString();
    std::cout << "=====================================================================" << std::endl;
    std::cout << outStringB << std::endl;
    std::cout << outStringS << std::endl;
    std::cout << outStringG << std::endl;
    std::cout << outStringP << std::endl;
    std::cout << outStringD << std::endl;
    std::cout << outStringC << std::endl;


    std::string playerCountB="Bronze Player Counts: "+ std::to_string(bronzeQueue->getCount());
    std::string playerCountS="Silver Player Counts: "+ std::to_string(silverQueue->getCount());
    std::string playerCountG="Gold Player Counts: "+ std::to_string(goldQueue->getCount());
    std::string playerCountP="Platinum Player Counts: "+ std::to_string(platinumQueue->getCount());
    std::string playerCountD="Diamond Player Counts: "+ std::to_string(diamondQueue->getCount());
    std::string playerCountC="Challenger Player Counts: "+ std::to_string(challengerQueue->getCount());
    std::cout << "=====================================================================" << std::endl;
    std::cout << playerCountB << std::endl;
    std::cout << playerCountS << std::endl;
    std::cout << playerCountG << std::endl;
    std::cout << playerCountP << std::endl;
    std::cout << playerCountD << std::endl;
    std::cout << playerCountC << std::endl;
    std::cout << "=====================================================================" << std::endl;
    int rockCountsTotal=0;
    int paperCountsTotal=0;
    int scissorsCountTotal=0;

//    Player* temp1Player;
//
//    for(int i = 0; i<100; i++){
//        temp1Player=playerList->removeValueAtFront();
//        rockCountsTotal+=temp1Player->getRocks();
//        paperCountsTotal+=temp1Player->getPapers();
//        scissorsCountTotal+=temp1Player->getScissors();
//    }
//
//    std::cout << "Rocks thrown: " + std::to_string(rockCountsTotal) << std::endl;
//    std::cout << "Papers crumpled: " + std::to_string(paperCountsTotal) << std::endl;
//    std::cout << "Scissors sliced: " + std::to_string(scissorsCountTotal) << std::endl;





//    std::string leaderTest = bronzeQueue->toLeaderboard();
//    std::cout << leaderTest << std::endl;

//    Player* testPlayer = new Player("testPlayer");
//    for(int l=0;l<=100; l++) {
//        int guess = testPlayer->generateGuess();
//        std::cout << guess << std::endl;
//    }

}