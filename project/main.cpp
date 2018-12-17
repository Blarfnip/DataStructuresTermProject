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

    MatchMakerRevised *system = new MatchMakerRevised();

    MatchMakerRevised *ranmatch = new MatchMakerRevised();

    bool play = true;
    int choice;
    std::string strChoice;
    int utilityChoice = 0;
    int playerNums = 0;
    int playerNumsIn = 0;
    std::string playerName;

    std::cout << "How would you like to use this piece of software?: " << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "(1) Debugger UI" << std::endl;
    std::cout << "(2) Competitive Rock-Paper Scissors" << std::endl;
    std::cout << "(3) Tests" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "Enter an action: " << std::endl;
    std::cin >> utilityChoice;

    if (utilityChoice == 1) {

        std::cout << "" << std::endl;
        std::cout << "Welcome to the Competitive Rock-Paper-Scissors Simulator" << std::endl;
        std::cout << "========================================================" << std::endl;


        //initializes the queues list
        ranmatch->initialQueue();

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
            std::cin >> strChoice;
            std::cout << "--------------------------------------------------------" << std::endl;

            choice = std::stoi(strChoice);

            if (choice == 1) {
                std::cout << "What is the id of your new player?: " << std::endl;
                std::cin >> playerName;
                while (ranmatch->isInList(playerName) == true) {
                    std::cout << "Name already exists please choose another: " << std::endl;
                    std::cin >> playerName;
                }

                ranmatch->addUserIDFromString(playerName);

            } else if (choice == 2) {
                std::cout << "How many players would you like to add?: " << std::endl;
                std::cin >> playerNums;
                ranmatch->populatePlayerList(playerNums);
                std::cout << "Added " + std::to_string(playerNums) + " players to the database" << std::endl;
            } else if (choice == 3) {
                int gameCount;
                std::cout << "How many matches would you like to run?: " << std::endl;
                std::cin >> gameCount;
                ranmatch->runMatches(gameCount);
            } else if (choice == 4) {
                std::string filename;
                std::cout << "What file would you like to read a player-base from?: (make sure its a .csv)"
                          << std::endl;
                std::cin >> filename;
                readPlayersFromFile(ranmatch->getPlayerList(), filename);
                std::cout << "Read file into database from: " + filename << std::endl;
            } else if (choice == 5) {
                std::string filename;
                std::cout << "What file would you like to create?: (make sure its a .csv)" << std::endl;
                std::cin >> filename;
                writePlayersToFile(ranmatch->getPlayerList(), filename);
                std::cout << "Wrote database into filename: " + filename << std::endl;
            } else if (choice == 6) {
                int outChoice = 0;
                std::cout << "Would you like to print the whole list or only a specific number of players?: "
                          << std::endl;
                std::cout << "(1) Whole list" << std::endl;
                std::cout << "(2) Specific number" << std::endl;
                std::cin >> outChoice;
                if (outChoice == 1) {
                    ranmatch->outputWholeListWins();
                } else if (outChoice == 2) {
                    int pTotal;
                    std::cout << "Enter an amount of players: " << std::endl;
                    std::cin >> pTotal;
                    while (pTotal > ranmatch->getPlayerList()->itemCount()) {
                        std::cout << "Amount is greater than player-base size please enter a new amount: " << std::endl;
                        std::cin >> pTotal;
                    }
                    ranmatch->outputListWins(pTotal);
                } else {
                    std::cout << "Invalid choice" << std::endl;
                }
            } else if (choice == 7) {
                int enqueueChoice;
                std::cout << "What would you like to enqueue?: " << std::endl;
                std::cout << "(1) A single player" << std::endl;
                std::cout << "(2) An amount of players" << std::endl;
                std::cout << "(3) The entire player-base" << std::endl;
                std::cin >> enqueueChoice;
                if (enqueueChoice == 1) {
                    std::string playerIn;
                    std::cout << "Which player would you like to enqueue?: " << std::endl;
                    std::cin >> playerIn;
                    if (ranmatch->isInList(playerIn)) {
                        ranmatch->enqueuePlayer(playerIn);
                    } else {
                        std::cout << "Player doesnt exist" << std::endl;
                    }
                } else if (enqueueChoice == 2) {
                    int queueAmt;
                    std::cout << "How many player would you like to enqueue?: " << std::endl;
                    std::cin >> queueAmt;
                    ranmatch->enqueueSelection(queueAmt);
                } else if (enqueueChoice == 3) {
                    ranmatch->enqueueAllPlayers();
                    std::cout << std::to_string(ranmatch->getPlayerList()->itemCount()) << std::endl;
                    std::cout << "Enqueued all: " + std::to_string(ranmatch->getPlayerList()->itemCount()) + " players"
                              << std::endl;
                } else {
                    std::cout << "Invalid choice" << std::endl;
                }
            } else if (choice == 8) {
                int numMatches;
                std::string queueType;
                std::cout << "How many matches would you like to play?: " << std::endl;
                std::cin >> numMatches;
                std::cout << "On which queue?: " << std::endl;
                std::cin >> queueType;
                ranmatch->playMatchesQueue(numMatches, queueType);
            } else if (choice == 9) {
                ranmatch->queuesToString();
            } else if (choice == 10) {
                int clearChoice;
                std::cout << "Which would you like to clear?: " << std::endl;
                std::cout << "(1) A specific one" << std::endl;
                std::cout << "(2) All queues" << std::endl;
                std::cin >> clearChoice;

                if (clearChoice == 1) {
                    std::string qChoice;
                    std::cout << "Which queue?: " << std::endl;
                    std::cin >> qChoice;
                    ranmatch->dropQueue(qChoice);
                } else if (clearChoice == 2) {
                    if (ranmatch->getQueueList()->getValueAt(5)->isEmpty() == false) {
                        ranmatch->dropQueue("Bronze");
                    }
                    if (ranmatch->getQueueList()->getValueAt(4)->isEmpty() == false) {
                        ranmatch->dropQueue("Silver");
                    }
                    if (ranmatch->getQueueList()->getValueAt(3)->isEmpty() == false) {
                        ranmatch->dropQueue("Gold");
                    }
                    if (ranmatch->getQueueList()->getValueAt(2)->isEmpty() == false) {
                        ranmatch->dropQueue("Platinum");
                    }
                    if (ranmatch->getQueueList()->getValueAt(1)->isEmpty() == false) {
                        ranmatch->dropQueue("Diamond");
                    }
                    if (ranmatch->getQueueList()->getValueAt(0)->isEmpty() == false) {
                        ranmatch->dropQueue("Challenger");
                    }
                    std::cout << "Cleared all queues" << std::endl;
                } else {
                    std::cout << "Invalid choice" << std::endl;
                }

            } else if (choice == 11) {
                std::string delPlay;
                std::cout << "Which player would you like to delete?: " << std::endl;
                std::cin >> delPlay;
                if (ranmatch->isInList(delPlay) == true) {
                    ranmatch->removePlayer(delPlay);
                } else {
                    std::cout << "Player doesn't exist in list" << std::endl;
                }
            } else if (choice == 12) {
                std::string playerStat;
                std::cout << "Which player would like stats on?: " << std::endl;
                std::cin >> playerStat;
                if (ranmatch->isInList(playerStat) == true) {
                    Player *statPlayer = ranmatch->getPlayer(playerStat);
                    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
                    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
                    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
                    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
                    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
                    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
                    std::cout << "-------------------------------" << std::endl;
                } else {
                    std::cout << "Player isn't in list" << std::endl;
                }
            } else if (choice == 13) {
                std::cout << "The total amount of players is: " + std::to_string(ranmatch->getPlayerList()->itemCount())
                          << std::endl;
            } else if (choice == 14) {
                std::cout << "The counts for queues are: " << std::endl;
                std::cout << "Bronze: " + std::to_string(ranmatch->getQueueList()->getValueAt(5)->getCount()) << std::endl;
                std::cout << "Silver: " + std::to_string(ranmatch->getQueueList()->getValueAt(4)->getCount()) << std::endl;
                std::cout << "Gold: " + std::to_string(ranmatch->getQueueList()->getValueAt(3)->getCount()) << std::endl;
                std::cout << "Platinum: " + std::to_string(ranmatch->getQueueList()->getValueAt(2)->getCount())
                          << std::endl;
                std::cout << "Diamond: " + std::to_string(ranmatch->getQueueList()->getValueAt(1)->getCount())
                          << std::endl;
                std::cout << "Challenger: " + std::to_string(ranmatch->getQueueList()->getValueAt(0)->getCount())
                          << std::endl;

            } else if (choice == 15) {
                std::string p1;
                std::string p2;
                std::cout << "Which two players would you like to play:" << std::endl;
                std::cout << "Player 1: " << std::endl;
                std::cin >> p1;
                std::cout << "Player 2: " << std::endl;
                std::cin >> p2;
                if (ranmatch->isInList(p1) and ranmatch->isInList(p2) == true) {
                    ranmatch->vsMatch(p1, p2);
                } else {
                    std::cout << "One or more of the players doesn't exist" << std::endl;
                }
            } else {
                std::cout << "Program Ended" << std::endl;
                play = false;
            }


        }
    } else if (utilityChoice == 2) {
        int playerNums = 250;

        //Initialize

        std::cout << "" << std::endl;
        std::cout << "Welcome to the Competitive Rock-Paper-Scissors Simulator" << std::endl;

        //initializes the queues list
        MatchMakerRevised *ranMatch= new MatchMakerRevised();
        ranmatch->initialQueue();

        std::cout << "========================================================" << std::endl;
        std::cout << "Its time to create your player, what is your name: " << std::endl;
        std::cin >> playerName;

        while (ranmatch->isInList(playerName) == true) {
            std::cout << "Name already exists please choose another: " << std::endl;
            std::cin >> playerName;
        }

        Player *newPlayer = new Player(playerName);
        newPlayer->setIsPlayer(true);
        ranmatch->populatePlayerList(playerNums);
        readPlayersFromFile(ranmatch->getPlayerList(), "playerOutput");
        for (int i = 0; i < 1000; i++) {
            ranmatch->enqueueAllPlayers();
            ranmatch->playMatchesQueue(playerNums, "Bronze");
            ranmatch->playMatchesQueue(playerNums, "Silver");
            ranmatch->playMatchesQueue(playerNums, "Gold");
            ranmatch->playMatchesQueue(playerNums, "Platinum");
            ranmatch->playMatchesQueue(playerNums, "Diamond");
            ranmatch->playMatchesQueue(playerNums, "Challenger");

        }

        ranmatch->addPlayerToList(newPlayer);
        if (ranmatch->getQueueList()->getValueAt(5)->isEmpty() == false) {
            ranmatch->dropQueue("Bronze");
        }
        if (ranmatch->getQueueList()->getValueAt(4)->isEmpty() == false) {
            ranmatch->dropQueue("Silver");
        }
        if (ranmatch->getQueueList()->getValueAt(3)->isEmpty() == false) {
            ranmatch->dropQueue("Gold");
        }
        if (ranmatch->getQueueList()->getValueAt(2)->isEmpty() == false) {
            ranmatch->dropQueue("Platinum");
        }
        if (ranmatch->getQueueList()->getValueAt(1)->isEmpty() == false) {
            ranmatch->dropQueue("Diamond");
        }
        if (ranmatch->getQueueList()->getValueAt(0)->isEmpty() == false) {
            ranmatch->dropQueue("Challenger");
        }

        //Stuff

        bool play = true;

        while (play == true) {
            int choice = 0;
            std::cout << "-------------------Rock Paper Scissors------------------" << std::endl;
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


            if (choice == 1) {
                std::string playerStat;
                std::cout << "Which player would like stats on?: " << std::endl;
                std::cin >> playerStat;
                if (ranmatch->isInList(playerStat) == true) {
                    Player *statPlayer = ranmatch->getPlayer(playerStat);
                    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
                    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
                    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
                    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
                    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
                    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
                    std::cout << "-------------------------------" << std::endl;
                } else {
                    std::cout << "Player isn't in list" << std::endl;
                }
            } else if (choice == 2) {
                std::cout << "The total amount of players is: " + std::to_string(ranmatch->getPlayerList()->itemCount())
                          << std::endl;
            } else if (choice == 3) {
                std::cout << "The counts for queues are: " << std::endl;
                std::cout << "Bronze: " + std::to_string(ranmatch->getQueueList()->getValueAt(5)->getCount()) << std::endl;
                std::cout << "Silver: " + std::to_string(ranmatch->getQueueList()->getValueAt(4)->getCount()) << std::endl;
                std::cout << "Gold: " + std::to_string(ranmatch->getQueueList()->getValueAt(3)->getCount()) << std::endl;
                std::cout << "Platinum: " + std::to_string(ranmatch->getQueueList()->getValueAt(2)->getCount())
                          << std::endl;
                std::cout << "Diamond: " + std::to_string(ranmatch->getQueueList()->getValueAt(1)->getCount())
                          << std::endl;
                std::cout << "Challenger: " + std::to_string(ranmatch->getQueueList()->getValueAt(0)->getCount())
                          << std::endl;

            } else if (choice == 4) {
                int remainingMatches = 1;
                std::cout << "How many matches would you like to play?: " << std::endl;
                std::cin >> remainingMatches;
                std::cout << "Playing " << remainingMatches << " matches..." << std::endl;
                for (int i = 0; i < remainingMatches; i++) {
                    std::cout << "Queueing..." << std::endl;
                    ranmatch->enqueueAllPlayers();
                    std::cout << "Queue Found" << std::endl;
                    ranmatch->playMatchesQueue(1000000, "Bronze");
                    ranmatch->playMatchesQueue(1000000, "Silver");
                    ranmatch->playMatchesQueue(1000000, "Gold");
                    ranmatch->playMatchesQueue(1000000, "Platinum");
                    ranmatch->playMatchesQueue(1000000, "Diamond");
                    ranmatch->playMatchesQueue(1000000, "Challenger");
                }


            } else if (choice == 5) {
                int outChoice = 0;
                std::cout << "Would you like to print the whole list or only a specific number of players?: "
                          << std::endl;
                std::cout << "(1) Whole list" << std::endl;
                std::cout << "(2) Specific number" << std::endl;
                std::cin >> outChoice;
                if (outChoice == 1) {
                    ranmatch->outputWholeListWins();
                } else if (outChoice == 2) {
                    int pTotal;
                    std::cout << "Enter an amount of players: " << std::endl;
                    std::cin >> pTotal;
                    while (pTotal > ranmatch->getPlayerList()->itemCount()) {
                        std::cout << "Amount is greater than player-base size please enter a new amount: " << std::endl;
                        std::cin >> pTotal;
                    }
                    ranmatch->outputListWins(pTotal);
                } else {
                    std::cout << "Invalid choice" << std::endl;
                }
            } else {
                std::cout << "Program Ended" << std::endl;
                play = false;
            }


        }


    } else if(utilityChoice==3){
        std::cout << "Testing MatchMaker Object: " << std::endl;
        MatchMakerRevised *testMatch = new MatchMakerRevised();

        testMatch->populatePlayerList(100);
        std::cout << "==============" << std::endl;

        //populated list test
        std::cout << "Populate List Test:" << std::endl;
        if(testMatch->getPlayerList()->itemCount()!=100){
            std::cout << "failed: expected 100 got: " + std::to_string(testMatch->getPlayerList()->itemCount()) + " instead" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }
        std::cout << "==============" << std::endl;

        //add players to list test
        std::cout << "Add Players Test:" << std::endl;
        testMatch->addUserIDFromString("Milo");
        if(testMatch->isInList("Milo")==false){
            std::cout << "failed: expected true for Milo in list got: false" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }
        std::cout << "==============" << std::endl;

        //running matches tests
        std::cout << "Run Matches On List Test:" << std::endl;
        std::cout << "Positive num of matches:" << std::endl;
        testMatch->runMatches(100);
        if(testMatch->getPlayer("Player1")->getGames()!=100){
            std::cout << "failed: expected 100 games played got: "+ std::to_string(testMatch->getPlayer("Player1")->getGames()) + " instead" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }
        std::cout << "==============" << std::endl;
        std::cout << "Negative num of matches:" << std::endl;
        testMatch->runMatches(-100);
        if(testMatch->getPlayer("Player1")->getGames()==200){
            std::cout << "failed: expected 0 games and error message got: "+ std::to_string(testMatch->getPlayer("Player1")->getGames()) + " instead" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }
        std::cout << "==============" << std::endl;
        //File IO tests
        std::cout << "File IO Tests: " << std::endl;
        std::cout << "Read-Write test to test.csv" << std::endl;
        writePlayersToFile(testMatch->getPlayerList(), "test.csv");
        readPlayersFromFile(testMatch->getPlayerList(), "test.csv");
        testMatch->outputWholeListWins();
        std::cout << "Check your cmake file for .csv and it was read into the list that is printed" << std::endl;
        std::cout << "==============" << std::endl;
        std::cout << "List printed and passed" << std::endl;
        std::cout << "Tested printing list" << std::endl;

        std::cout << "==============" << std::endl;

        std::cout << "Player enqueue test: " << std::endl;
        testMatch->initialQueue();
        testMatch->enqueueAllPlayers();
        if(testMatch->getQueueList()->getValueAt(5)->isEmpty()==true){
            std::cout << "failed: expected queues to be filled" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }
        std::cout << "==============" << std::endl;
        std::cout << "Queued Matches Run test: " << std::endl;
        testMatch->playMatchesQueue(200,"Bronze");
        if(testMatch->getQueueList()->getValueAt(5)->isEmpty()==false){
            std::cout << "failed the queue isn't empty because not enough matches were played" << std::endl;
        }
        else{
            std::cout << "passed" << std::endl;
        }


        std::cout << "==============" << std::endl;

        //checks if stats print
//        std::cout << "Stat check test print:" << std::endl;
//        Player *statPlayer = match->getPlayer("Player1");
//        std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
//        std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
//        std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
//        std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
//        std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
//        std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
//        std::cout << "-------------------------------" << std::endl;
//
//        std::cout << "==============" << std::endl;
//
//        //queue count tests prints
//        std::cout << "Player counts for queues test print:" << std::endl;
//        testMatch->enqueueAllPlayers();
//        std::cout << "The counts for queues are: " << std::endl;
//        std::cout << "Bronze: " + std::to_string(match->getQueueList()->getValueAt(5)->getCount()) << std::endl;
//        std::cout << "Silver: " + std::to_string(match->getQueueList()->getValueAt(4)->getCount()) << std::endl;
//        std::cout << "Gold: " + std::to_string(match->getQueueList()->getValueAt(3)->getCount()) << std::endl;
//        std::cout << "Platinum: " + std::to_string(match->getQueueList()->getValueAt(2)->getCount()) << std::endl;
//        std::cout << "Diamond: " + std::to_string(match->getQueueList()->getValueAt(1)->getCount()) << std::endl;
//        std::cout << "Challenger: " + std::to_string(match->getQueueList()->getValueAt(0)->getCount()) << std::endl;
//
//        std::cout << "==============" << std::endl;







    } else{
        std::cout << "bad input" << std::endl;
    }


}

