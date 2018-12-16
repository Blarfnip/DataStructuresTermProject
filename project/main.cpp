#include <iostream>
#include <sstream>
#include <fstream>


#include "Player.h"
#include "Game.h"
#include "ArrayList.h"
#include "PlayerQueue.h"
#include "PlayerNode.h"
#include "MatchMaker.h"
#include "MatchMakerRevised.h"

/**
 * FileIO implementation
 * Writes existing player list to a file
 * Can read new player list from a text file as well as a string
 */

Player* createPlayerFromString(const std::string playerString){
    std::stringstream splitter (playerString);
    std::string playerID, rank, games, wins, losses, ties;

    getline(splitter, playerID, ',');
    getline(splitter, rank, ',');
    getline(splitter, games, ',');
    getline(splitter, wins, ',');
    getline(splitter, losses, ',');
    getline(splitter, ties, ',');

    Player* newPlayer = new Player(playerID);
    newPlayer->setRank(std::stoi(rank));
    newPlayer->setPlace(std::stoi(games), std::stoi(wins), std::stoi(losses), std::stoi(ties));
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

void writePlayersToFile(List<Player*>* pList, std::string filename){
    std::ofstream outf(filename);
    if(outf){
        for(int f=0; f<pList->itemCount(); f++){
            outf << pList->getValueAt(f)->getID() + ", "  + std::to_string(pList->getValueAt(f)->getRank()) + ", " +std::to_string(pList->getValueAt(f)->getGames()) + ", " +  std::to_string(pList->getValueAt(f)->getWins()) + ", "  + std::to_string(pList->getValueAt(f)->getLosses()) + ", " + std::to_string(pList->getValueAt(f)->getTies())<< std::endl;
        }
        outf.close();
    }
}

void readPlayersFromFile(List<Player*>* playerListToChange, const std::string& filename){


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

    MatchMakerRevised* system = new MatchMakerRevised();

    MatchMakerRevised* match = new MatchMakerRevised();

    bool play=true;
    int choice;
    int utilityChoice=0;
    int playerNums=0;
    int playerNumsIn=0;
    std::string playerName;

    std::cout << "How would you like to use this piece of software?: " << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "(1) Debugger UI" << std::endl;
    std::cout << "(2) Competitive Rock-Paper Scissors" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "Enter an action: " << std::endl;
    std::cin >> utilityChoice;

    if(utilityChoice==1) {

        std::cout << "" << std::endl;
        std::cout << "Welcome to the Competitive Rock-Paper-Scissors Simulator" << std::endl;
        std::cout << "========================================================" << std::endl;


        //initializes the queues list
        match->initialQueue();

//        std::cout << "========================================================" << std::endl;
//        std::cout << "Its time to create your player, what is your name: " << std::endl;
//        std::cin >> playerName;
//
//        while (match->isInList(playerName) == true) {
//            std::cout << "Name already exists please choose another: " << std::endl;
//            std::cin >> playerName;
//        }

//        Player* newPlayer = new Player(playerName);
//        newPlayer->setIsPlayer(true);
//        match->addPlayerToList(newPlayer);
        //match->addUserIDFromString(playerName);

        std::cout << "========================================================" << std::endl;
        while (play == true) {
            std::cout << "" << std::endl;
            std::cout << "--------------------Matchmaking Hub---------------------" << std::endl;
            std::cout << "    Enter a number for each of the following commands   " << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << "(1) Create a new player" << std::endl;
            std::cout << "(2) Add a set number of AI players to the player base" << std::endl;
            std::cout << "(3) Run a set number of matches on the player base" << std::endl;
            std::cout << "(4) Read a player-base from a file" << std::endl;
            std::cout << "(5) Write a player-base to a file" << std::endl;
            std::cout << "(6) Print player list" << std::endl;
            std::cout << "(7) Enqueue some players" << std::endl;
            std::cout << "(8) Play a set number of matches on queues" << std::endl;
            std::cout << "(9) Print queues" << std::endl;
            std::cout << "(10) Empty queue" << std::endl;
            std::cout << "(11) Remove a player" << std::endl;
            std::cout << "(12) Get a player's statistics" << std::endl;
            std::cout << "(13) Get player-base counts" << std::endl;
            std::cout << "(14) Get player counts for queues" << std::endl;
            std::cout << "(15) Play specific player" << std::endl;
            std::cout << "(17) Exit" << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << "                     Enter an action:                   " << std::endl;
            std::cin >> choice;
            std::cout << "--------------------------------------------------------" << std::endl;

            if (choice == 1) {
                std::cout << "What is the id of your new player?: " << std::endl;
                std::cin >> playerName;
                while (match->isInList(playerName) == true) {
                    std::cout << "Name already exists please choose another: " << std::endl;
                    std::cin >> playerName;
                }

                match->addUserIDFromString(playerName);

            } else if (choice == 2) {
                std::cout << "How many players would you like to add?: " << std::endl;
                std::cin >> playerNums;
                match->populatePlayerList(playerNums);
                std::cout << "Added " + std::to_string(playerNums) + " players to the database" << std::endl;
            } else if (choice == 3) {
                int gameCount;
                std::cout << "How many matches would you like to run?: " << std::endl;
                std::cin >> gameCount;
                match->runMatches(gameCount);
            } else if (choice == 4) {
                std::string filename;
                std::cout << "What file would you like to read a player-base from?: (make sure its a .csv)" << std::endl;
                std::cin >> filename;
                readPlayersFromFile(match->getPlayerList(),filename);
                std::cout << "Read file into database from: " + filename << std::endl;
            } else if (choice == 5) {
                std::string filename;
                std::cout << "What file would you like to create?: (make sure its a .csv)" << std::endl;
                std::cin >> filename;
                writePlayersToFile(match->getPlayerList(),filename);
                std::cout << "Wrote database into filename: " + filename << std::endl;
            } else if (choice == 6) {
                int outChoice=0;
                std::cout << "Would you like to print the whole list or only a specific number of players?: " << std::endl;
                std::cout << "(1) Whole list" << std::endl;
                std::cout << "(2) Specific number" << std::endl;
                std::cin >> outChoice;
                if(outChoice==1){
                    match->outputWholeListWins();
                } else if(outChoice==2){
                    int pTotal;
                    std::cout << "Enter an amount of players: " << std::endl;
                    std::cin >> pTotal;
                    while(pTotal>match->getPlayerList()->itemCount()){
                        std::cout << "Amount is greater than player-base size please enter a new amount: " << std::endl;
                        std::cin >> pTotal;
                    }
                    match->outputListWins(pTotal);
                } else{
                    std::cout << "Invalid choice" << std::endl;
                }
            } else if (choice == 7) {
                int enqueueChoice;
                std::cout << "What would you like to enqueue?: " << std::endl;
                std::cout << "(1) A single player" << std::endl;
                std::cout << "(2) An amount of players" << std::endl;
                std::cout << "(3) The entire player-base" << std::endl;
                std::cin >> enqueueChoice;
                if(enqueueChoice==1){
                    std::string playerIn;
                    std::cout << "Which player would you like to enqueue?: " << std::endl;
                    std::cin >> playerIn;
                    if(match->isInList(playerIn)){
                        match->enqueuePlayer(playerIn);
                    }
                    else{
                        std::cout << "Player doesnt exist" << std::endl;
                    }
                } else if(enqueueChoice==2){
                    int queueAmt;
                    std::cout << "How many player would you like to enqueue?: " << std::endl;
                    std::cin >> queueAmt;
                    match->enqueueSelection(queueAmt);
                } else if(enqueueChoice==3){
                    match->enqueueAllPlayers();
                    std::cout << std::to_string(match->getPlayerList()->itemCount()) << std::endl;
                    std::cout << "Enqueued all: " + std::to_string(match->getPlayerList()->itemCount()) + " players" << std::endl;
                } else{
                    std::cout << "Invalid choice" << std::endl;
                }
            } else if (choice == 8) {
                int numMatches;
                std::string queueType;
                std::cout << "How many matches would you like to play?: " << std::endl;
                std::cin >> numMatches;
                std::cout << "On which queue?: " << std::endl;
                std::cin >> queueType;
                match->playMatchesQueue(numMatches,queueType);
            } else if(choice == 9) {
                match->queuesToString();
            } else if(choice == 10) {
                int clearChoice;
                std::cout << "Which would you like to clear?: " << std::endl;
                std::cout << "(1) A specific one" << std::endl;
                std::cout << "(2) All queues" << std::endl;
                std::cin >> clearChoice;

                if(clearChoice==1){
                    std::string qChoice;
                    std::cout << "Which queue?: " << std::endl;
                    std::cin >> qChoice;
                    match->dropQueue(qChoice);
                } else if(clearChoice==2){
                    if(match->getQueueList()->getValueAt(5)->isEmpty()==false){
                        match->dropQueue("Bronze");
                    }
                    if(match->getQueueList()->getValueAt(4)->isEmpty()==false){
                        match->dropQueue("Silver");
                    }
                    if(match->getQueueList()->getValueAt(3)->isEmpty()==false){
                        match->dropQueue("Gold");
                    }
                    if(match->getQueueList()->getValueAt(2)->isEmpty()==false){
                        match->dropQueue("Platinum");
                    }
                    if(match->getQueueList()->getValueAt(1)->isEmpty()==false){
                        match->dropQueue("Diamond");
                    }
                    if(match->getQueueList()->getValueAt(1)->isEmpty()==false){
                        match->dropQueue("Challenger");
                    }
                    std::cout << "Cleared all queues" << std::endl;
                } else{
                    std::cout << "Invalid choice" << std::endl;
                }

            } else if(choice == 11){
                std::string delPlay;
                std::cout << "Which player would you like to delete?: " << std::endl;
                std::cin >> delPlay;
                if(match->isInList(delPlay)==true){
                    match->removePlayer(delPlay);
                }
                else{
                    std::cout << "Player doesn't exist in list" << std::endl;
                }
            } else if(choice == 12){
                std::string playerStat;
                std::cout << "Which player would like stats on?: " << std::endl;
                std::cin >> playerStat;
                if(match->isInList(playerStat)==true) {
                    Player *statPlayer = match->getPlayer(playerStat);
                    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
                    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
                    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
                    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
                    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
                    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
                    std::cout << "-------------------------------" << std::endl;
                }
                else{
                    std::cout << "Player isn't in list" << std::endl;
                }
            } else if(choice == 13){
                std::cout << "The total amount of players is: " + std::to_string(match->getPlayerList()->itemCount()) << std::endl;
            } else if(choice == 14){
                std::cout << "The counts for queues are: " << std::endl;
                std::cout << "Bronze: " + std::to_string(match->getQueueList()->getValueAt(5)->getCount()) << std::endl;
                std::cout << "Silver: " + std::to_string(match->getQueueList()->getValueAt(4)->getCount()) << std::endl;
                std::cout << "Gold: " + std::to_string(match->getQueueList()->getValueAt(3)->getCount()) << std::endl;
                std::cout << "Platinum: " + std::to_string(match->getQueueList()->getValueAt(2)->getCount()) << std::endl;
                std::cout << "Diamond: " + std::to_string(match->getQueueList()->getValueAt(1)->getCount()) << std::endl;
                std::cout << "Challenger: " + std::to_string(match->getQueueList()->getValueAt(0)->getCount()) << std::endl;

            } else if(choice == 15){
                std::string p1;
                std::string p2;
                std::cout << "Which two players would you like to play:" << std::endl;
                std::cout << "Player 1: " << std::endl;
                std::cin >> p1;
                std::cout << "Player 2: " << std::endl;
                std::cin >> p2;
                if(match->isInList(p1) and match->isInList(p2)==true) {
                    match->vsMatch(p1, p2);
                }
                else{
                    std::cout << "One or more of the players doesn't exist" << std::endl;
                }
            }

            else{
                std::cout << "Program Ended" << std::endl;
                play=false;
            }



        }
    }

    else if(utilityChoice==2){
        int playerNums = 250;

        //Initialize

        std::cout << "" << std::endl;
        std::cout << "Welcome to the Competitive Rock-Paper-Scissors Simulator" << std::endl;

        //initializes the queues list
        match->initialQueue();

        std::cout << "========================================================" << std::endl;
        std::cout << "Its time to create your player, what is your name: " << std::endl;
        std::cin >> playerName;

        while (match->isInList(playerName) == true) {
            std::cout << "Name already exists please choose another: " << std::endl;
            std::cin >> playerName;
        }

        Player* newPlayer = new Player(playerName);
        newPlayer->setIsPlayer(true);
        match->populatePlayerList(playerNums);
        readPlayersFromFile(match->getPlayerList(),"playerOutput");
        for(int i = 0; i < 1000; i++) {
            match->enqueueAllPlayers();
            match->playMatchesQueue(playerNums, "Bronze");
            match->playMatchesQueue(playerNums, "Silver");
            match->playMatchesQueue(playerNums, "Gold");
            match->playMatchesQueue(playerNums, "Platinum");
            match->playMatchesQueue(playerNums, "Diamond");
            match->playMatchesQueue(playerNums, "Challenger");

        }

        match->addPlayerToList(newPlayer);
        //Stuff

        bool play = true;

        while(play == true) {
            int choice = 0;
            std::cout << "-------------------Rock Paper Scissors------------------" <<std::endl;
            std::cout << "    Enter a number for each of the following commands   " << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << "(1) Get Player Stats" << std::endl;
            std::cout << "(2) Get Total Player Count" << std::endl;
            std::cout << "(3) Get Queued Player Count" << std::endl;
            std::cout << "(4) Play Match" << std::endl;
            std::cout << "(5) Print Player Ranks" << std::endl;
            std::cout << "(7) Quit" << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << "                     Enter an action:                   " << std::endl;
            std::cin >> choice;
            std::cout << "--------------------------------------------------------" << std::endl;


            if(choice == 1){
                std::string playerStat;
                std::cout << "Which player would like stats on?: " << std::endl;
                std::cin >> playerStat;
                if(match->isInList(playerStat)==true) {
                    Player *statPlayer = match->getPlayer(playerStat);
                    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
                    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
                    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
                    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
                    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
                    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
                    std::cout << "-------------------------------" << std::endl;
                }
                else{
                    std::cout << "Player isn't in list" << std::endl;
                }
            } else if(choice == 2){
                std::cout << "The total amount of players is: " + std::to_string(match->getPlayerList()->itemCount()) << std::endl;
            } else if(choice == 3){
                std::cout << "The counts for queues are: " << std::endl;
                std::cout << "Bronze: " + std::to_string(match->getQueueList()->getValueAt(5)->getCount()) << std::endl;
                std::cout << "Silver: " + std::to_string(match->getQueueList()->getValueAt(4)->getCount()) << std::endl;
                std::cout << "Gold: " + std::to_string(match->getQueueList()->getValueAt(3)->getCount()) << std::endl;
                std::cout << "Platinum: " + std::to_string(match->getQueueList()->getValueAt(2)->getCount()) << std::endl;
                std::cout << "Diamond: " + std::to_string(match->getQueueList()->getValueAt(1)->getCount()) << std::endl;
                std::cout << "Challenger: " + std::to_string(match->getQueueList()->getValueAt(0)->getCount()) << std::endl;

            } else if(choice == 4) {
                int remainingMatches = 1;
                std::cout << "How many matches would you like to play?: " << std::endl;
                std::cin >> remainingMatches;
                std::cout << "Playing " << remainingMatches << " matches..." << std::endl;
                for(int i = 0; i < remainingMatches; i++ ) {
                    std::cout << "Queueing..." << std::endl;
                    match->enqueueAllPlayers();
                    std::cout << "Queue Found" << std::endl;
                    match->playMatchesQueue(1000000,"Bronze");
                    match->playMatchesQueue(1000000,"Silver");
                    match->playMatchesQueue(1000000,"Gold");
                    match->playMatchesQueue(1000000,"Platinum");
                    match->playMatchesQueue(1000000,"Diamond");
                    match->playMatchesQueue(1000000,"Challenger");
                }


            }
            else if (choice == 5) {
                int outChoice=0;
                std::cout << "Would you like to print the whole list or only a specific number of players?: " << std::endl;
                std::cout << "(1) Whole list" << std::endl;
                std::cout << "(2) Specific number" << std::endl;
                std::cin >> outChoice;
                if(outChoice==1){
                    match->outputWholeListWins();
                } else if(outChoice==2){
                    int pTotal;
                    std::cout << "Enter an amount of players: " << std::endl;
                    std::cin >> pTotal;
                    while(pTotal>match->getPlayerList()->itemCount()){
                        std::cout << "Amount is greater than player-base size please enter a new amount: " << std::endl;
                        std::cin >> pTotal;
                    }
                    match->outputListWins(pTotal);
                } else{
                    std::cout << "Invalid choice" << std::endl;
                }
            }
            else{
                std::cout << "Program Ended" << std::endl;
                play=false;
            }


        }


    }






//    //Populates list with players
//    List<Player*>* playerList = new ArrayList<Player*>(100);
//    for(int i = 0; i < 100; i++) {
//        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
//    }
//
//    if(playerList->isEmpty()==true){
//        std::cout << "Failed to fill list" << std::endl;
//    }
//    else{
//        std::cout << "Passed fill list test" << std::endl;
//    }
//
//    //Sets first player to be a user
//    //playerList->getValueAt(0)->setIsPlayer(true);
//
//    //Runs 100 matches with each player
//    for(int k = 0; k < 1000; k++) {
//        for(int i = 0; i < 100; i += 2) {
//            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
//            testGame->collectGuesses();
//            //testGame->generateSolution(); *changed game to rock paper scissors format
//            testGame->play();
//            delete testGame;
//        }
//    }
//
//    //Outputs player wins
//    for(int i = 0; i < 100; i++) {
//        std::cout<< playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() <<std::endl;
//    }
//
//    std::cout << "=====================================================================" << std::endl;
//
//    List<Player*>* ioTest = new ArrayList<Player*>(120);
//    List<Player*>* testList = new ArrayList<Player*>(100);
//    addHardCodedPlayers(ioTest);
//    std::cout << ioTest->getValueAt(0)->getID() + " " + std::to_string(ioTest->getValueAt(0)->getRank())<< std::endl;
//    std::cout << ioTest->getValueAt(1)->getID() + " " + std::to_string(ioTest->getValueAt(1)->getRank())<< std::endl;
//    std::cout << ioTest->getValueAt(2)->getID() + " " + std::to_string(ioTest->getValueAt(2)->getRank())<< std::endl;
//    std::cout << ioTest->getValueAt(3)->getID() + " " + std::to_string(ioTest->getValueAt(3)->getRank())<< std::endl;
//    std::cout << ioTest->getValueAt(4)->getID() + " " + std::to_string(ioTest->getValueAt(4)->getRank())<< std::endl;
//    std::cout << ioTest->getValueAt(5)->getID() + " " + std::to_string(ioTest->getValueAt(5)->getRank())<< std::endl;
//
//    std::cout << "========================" << std::endl;
//    printPlayerListToFile(playerList, "playerOutput.csv");
//    addPlayersFromFile(ioTest, "playerOutput.csv");
//
//    for(int s = 0; s<playerList->itemCount(); s++){
//        std::cout << ioTest->getValueAt(s)->getID() + " " + std::to_string(ioTest->getValueAt(s)->getRank()) << std::endl;
//    }
//    std::cout << "=====================================================================" << std::endl;
//
//    //creates queues for ratings
//    //change to list of queues?
//    PlayerQueue* bronzeQueue= new PlayerQueue();
//    PlayerQueue* silverQueue= new PlayerQueue();
//    PlayerQueue* goldQueue= new PlayerQueue();
//    PlayerQueue* platinumQueue= new PlayerQueue();
//    PlayerQueue* diamondQueue= new PlayerQueue();
//    PlayerQueue* challengerQueue=new PlayerQueue();
//
//    Player* tempPlayer;
//    for(int i = 0; i<100; i++){
//        tempPlayer=playerList->removeValueAtFront();
//        if(tempPlayer->checkTier()=="Bronze"){
//            bronzeQueue->enqueue(tempPlayer);
//        }
//        else if(tempPlayer->checkTier()=="Silver"){
//            silverQueue->enqueue(tempPlayer);
//        }
//        else if(tempPlayer->checkTier()=="Gold"){
//            goldQueue->enqueue(tempPlayer);
//        }
//        else if(tempPlayer->checkTier()=="Platinum"){
//            platinumQueue->enqueue(tempPlayer);
//        }
//        else if(tempPlayer->checkTier()=="Diamond"){
//            diamondQueue->enqueue(tempPlayer);
//        }
//        else if(tempPlayer->checkTier()=="Challenger"){
//            challengerQueue->enqueue(tempPlayer);
//        }
//    }
//    std::string outStringB="Bronze Queued Players: ";
//    std::string outStringS="Silver Queued Players: ";
//    std::string outStringG="Gold Queued Players: ";
//    std::string outStringP="Platinum Queued Players: ";
//    std::string outStringD="Diamond Queued Players: ";
//    std::string outStringC="Challenger Queued Players: ";
//    outStringB += bronzeQueue->toString();
//    outStringS += silverQueue->toString();
//    outStringG += goldQueue->toString();
//    outStringP += platinumQueue->toString();
//    outStringD += diamondQueue->toString();
//    outStringC += challengerQueue->toString();
//    std::cout << "=====================================================================" << std::endl;
//    std::cout << outStringB << std::endl;
//    std::cout << outStringS << std::endl;
//    std::cout << outStringG << std::endl;
//    std::cout << outStringP << std::endl;
//    std::cout << outStringD << std::endl;
//    std::cout << outStringC << std::endl;
//
//
//    std::string playerCountB="Bronze Player Counts: "+ std::to_string(bronzeQueue->getCount());
//    std::string playerCountS="Silver Player Counts: "+ std::to_string(silverQueue->getCount());
//    std::string playerCountG="Gold Player Counts: "+ std::to_string(goldQueue->getCount());
//    std::string playerCountP="Platinum Player Counts: "+ std::to_string(platinumQueue->getCount());
//    std::string playerCountD="Diamond Player Counts: "+ std::to_string(diamondQueue->getCount());
//    std::string playerCountC="Challenger Player Counts: "+ std::to_string(challengerQueue->getCount());
//    std::cout << "=====================================================================" << std::endl;
//    std::cout << playerCountB << std::endl;
//    std::cout << playerCountS << std::endl;
//    std::cout << playerCountG << std::endl;
//    std::cout << playerCountP << std::endl;
//    std::cout << playerCountD << std::endl;
//    std::cout << playerCountC << std::endl;
//    std::cout << "=====================================================================" << std::endl;
//
//
//
//    //spaces
//    std::cout << "BETA MATCHMAKER" << std::endl;
//    std::cout << " " << std::endl;
//    std::cout << " " << std::endl;
//    std::cout << " " << std::endl;
//    std::cout << " " << std::endl;
//    std::cout << " " << std::endl;
//
//    MatchMakerRevised* match=new MatchMakerRevised();
//
//    std::cout << "Test match is created" << std::endl;
//
//    match->populatePlayerList(100);
//
//    std::cout << "Test player list is populated" << std::endl;
//
//    match->runMatches(1000);
//
//    match->outputListWins(50);
//    std::cout << "Tested 50 players print" << std::endl;
//
//    match->outputWholeListWins();
//    std::cout << "Tested whole list print" << std::endl;
//
//    match->initialQueue();
//    std::cout << "Tested intializing queues" << std::endl;
//
//    match->enqueueAllPlayers();
//    std::cout << "Tested enqueue all players" << std::endl;
//
//    match->queuesToString();
//    std::cout << "Tested queue to String" << std::endl;
//
//
//
//    std::string testQueueStrB = "Bronze Queue: ";
//    std::string testQueueStrS = "Silver Queue: ";
//    std::string testQueueStrG = "Gold Queue: ";
//
////    testQueueStrB += bronzeQueue->toString();
////    testQueueStrS += silverQueue->toString();
////    testQueueStrG += goldQueue->toString();
////    std::cout << testQueueStrB << std::endl;
////    std::cout << testQueueStrS << std::endl;
////    std::cout << testQueueStrG << std::endl;
//
//
//    std::cout << match->getQueueList()->getValueAt(5)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(4)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(3)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(2)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(1)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(0)->getCount() << std::endl;
//
//    std::cout << "Tested counts of queues" << std::endl;
//
//    match->playMatchesQueue(10, "bronze");
//    match->queuesToString();
//    std::cout << match->getQueueList()->getValueAt(5)->getCount() << std::endl;
//
//    match->dropQueue("bronze"); //drops the queue and doesnt play remaining games
//    //TODO clear is broken atm (STILL BROKEN)
//    match->clearQueue("silver"); //clears the queue by playing all the games and accounts for odd numbers of players in queues
//
//    match->queuesToString();
//    std::cout << match->getQueueList()->getValueAt(5)->getCount() << std::endl;
//    std::cout << match->getQueueList()->getValueAt(4)->getCount() << std::endl;
//
////    match->writePlayerListToFile("playerOutput.csv");
////    match->readPlayersFromFile("matchMaker.csv");
////
////    match->outputWholeListWins();
//
//    //TODO weird bug with no ranks (FIXED)
//
//    printPlayerListToFile(match->getPlayerList(),"playerOutput.csv");
//    addPlayersFromFile(match->getPlayerList(),"test.csv");
//
//    match->runMatches(20);
//
//    match->outputWholeListWins();
//
//    Player* player100;
//    player100=match->getPlayer("Player 100");
//    std::cout << player100->getRank() << std::endl;
//
//
//
//
//
//
//
//
//
//
//
//
//
////    Player* temp1Player;
////
////    for(int i = 0; i<100; i++){
////        temp1Player=playerList->removeValueAtFront();
////        rockCountsTotal+=temp1Player->getRocks();
////        paperCountsTotal+=temp1Player->getPapers();
////        scissorsCountTotal+=temp1Player->getScissors();
////    }
////
////    std::cout << "Rocks thrown: " + std::to_string(rockCountsTotal) << std::endl;
////    std::cout << "Papers crumpled: " + std::to_string(paperCountsTotal) << std::endl;
////    std::cout << "Scissors sliced: " + std::to_string(scissorsCountTotal) << std::endl;
//
////    std::string leaderTest = bronzeQueue->toLeaderboard();
////    std::cout << leaderTest << std::endl;
//
////    Player* testPlayer = new Player("testPlayer");
////    for(int l=0;l<=100; l++) {
////        int guess = testPlayer->generateGuess();
////        std::cout << guess << std::endl;
////    }
//
}