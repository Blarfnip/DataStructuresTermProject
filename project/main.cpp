#include <iostream>
#include <sstream>
#include <fstream>


#include "Player.h"
#include "Game.h"
#include "ArrayList.h"
#include "PlayerQueue.h"
#include "PlayerNode.h"
#include "MatchMaker.h"

/**
 * FileIO implementation
 * Writes existing player list to a file
 * Can read new player list from a text file as well as a string
 */

Player* createPlayerFromString(const std::string playerString){
    std::stringstream splitter (playerString);
    std::string playerID, rank;

    getline(splitter, playerID, ',');
    getline(splitter, rank, ',');
//    getline(splitter, games, ',');
//    getline(splitter, wins, ',');
//    getline(splitter, losses, ',');
//    getline(splitter, ties, ',');

    Player* newPlayer = new Player(playerID);
    newPlayer->setRank(std::stoi(rank));
    return newPlayer;
}

void addHardCodedPlayers(List<Player*>* playerListToChange){
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player, 100"));
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player1, 200"));
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player2, 300"));
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player3, 400"));
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player4, 500"));
    playerListToChange->insertAtEnd(createPlayerFromString("Dummy_Player5, 600"));
}

void printPlayerListToFile(List<Player*>* pList, std::string filename){
    std::ofstream outf(filename);
    if(outf){
        for(int f=0; f<pList->itemCount(); f++){
            outf << pList->getValueAt(f)->getID() + ", "  + std::to_string(pList->getValueAt(f)->getRank()) << std::endl;
        }
        outf.close();
    }
}

void addPlayersFromFile(List<Player*>* playerListToChange, const std::string& filename){


    Player* inPlayer;
    std::ifstream infile(filename);

    if(infile){
        while(infile){
            std::string line;
            getline(infile, line);
            if(line==""){

            }
            else if(line!="") {
                inPlayer = createPlayerFromString(line);
                playerListToChange->insertAtEnd(inPlayer);
            }
        }

    }

    infile.close();

}

int main() {
    srand(time(NULL)); //Seeds random numbers

    //TODO Tested Main:



    //Populates list with players
    List<Player*>* playerList = new ArrayList<Player*>(100);
    for(int i = 0; i < 100; i++) {
        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
    }

    if(playerList->isEmpty()==true){
        std::cout << "Failed to fill list" << std::endl;
    }
    else{
        std::cout << "Passed fill list test" << std::endl;
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

    std::cout << "=====================================================================" << std::endl;

    List<Player*>* ioTest = new ArrayList<Player*>(120);
    List<Player*>* testList = new ArrayList<Player*>(100);
    addHardCodedPlayers(ioTest);
    std::cout << ioTest->getValueAt(0)->getID() + " " + std::to_string(ioTest->getValueAt(0)->getRank())<< std::endl;
    std::cout << ioTest->getValueAt(1)->getID() + " " + std::to_string(ioTest->getValueAt(1)->getRank())<< std::endl;
    std::cout << ioTest->getValueAt(2)->getID() + " " + std::to_string(ioTest->getValueAt(2)->getRank())<< std::endl;
    std::cout << ioTest->getValueAt(3)->getID() + " " + std::to_string(ioTest->getValueAt(3)->getRank())<< std::endl;
    std::cout << ioTest->getValueAt(4)->getID() + " " + std::to_string(ioTest->getValueAt(4)->getRank())<< std::endl;
    std::cout << ioTest->getValueAt(5)->getID() + " " + std::to_string(ioTest->getValueAt(5)->getRank())<< std::endl;

    std::cout << "========================" << std::endl;
    printPlayerListToFile(playerList, "playerOutput.csv");
    addPlayersFromFile(ioTest, "playerOutput.csv");

    for(int s = 0; s<playerList->itemCount(); s++){
        std::cout << ioTest->getValueAt(s)->getID() + " " + std::to_string(ioTest->getValueAt(s)->getRank()) << std::endl;
    }
    std::cout << "=====================================================================" << std::endl;

    //creates queues for ratings
    //change to list of queues?
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

    MatchMaker* match=new MatchMaker();
    match->playMatchesQueue(bronzeQueue,4, "bronze");
    match->playMatchesQueue(silverQueue,4, "silver");
    match->playMatchesQueue(goldQueue,100, "gold"); //tests overloaded games amount for queue size

    std::string testQueueStrB = "Bronze Queue: ";
    std::string testQueueStrS = "Silver Queue: ";
    std::string testQueueStrG = "Gold Queue: ";

    testQueueStrB += bronzeQueue->toString();
    testQueueStrS += silverQueue->toString();
    testQueueStrG += goldQueue->toString();
    std::cout << testQueueStrB << std::endl;
    std::cout << testQueueStrS << std::endl;
    std::cout << testQueueStrG << std::endl;


    std::cout << bronzeQueue->getCount() << std::endl;\



    match->dropQueue(bronzeQueue, "bronze"); //drops the queue and doesnt play remaining games

    std::cout << silverQueue->getCount() << std::endl;
    match->clearQueue(silverQueue, "silver"); //clears the queue by playing all the games and accounts for odd numbers of players in queues
    std::string testQ="Bronze: " + bronzeQueue->toString();
    std::string testK="Silver: " + silverQueue->toString();
    std::cout << testQ << std::endl;
    std::cout << testK << std::endl;

    std::cout << std::to_string(bronzeQueue->getCount()) << std::endl;
    std::cout << std::to_string(silverQueue->getCount()) << std::endl;







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