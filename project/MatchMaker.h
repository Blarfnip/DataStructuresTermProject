//
// Created by Milo Rue on 12/1/2018.
//

#ifndef PROJECT_MATCHMAKER_H
#define PROJECT_MATCHMAKER_H
#include "Player.h"
#include "Game.h"
#include "ArrayList.h"
#include "PlayerQueue.h"
#include "PlayerNode.h"

#include <iostream>
#include <sstream>
#include <fstream>


class MatchMaker {
private:
    List<PlayerQueue*>* playerQueues;
    List<Player*>* playerList;
    int playerCount=0;
public:

    MatchMaker();

    void playMatchesQueue(int numOfMatches, std::string queueName);

    void dropQueue(std::string queueName);

    void clearQueue(std::string queueName);

    List<Player*>* getPlayerList();

    List<PlayerQueue*>* getQueueList();

    void addPlayerFromString(const std::string playerString);

    void addPlayerToList(Player* newPlayer);

    void writePlayerListToFile(std::string filename);

    void readPlayersFromFile(const std::string& filename);

    void populatePlayerList(int numOfPlayers);

    void runMatches(int numOfMatches);

    int getPlayerWins(std::string playerIdIn);

    //prints a certain given num
    void outputListWins(int numOfPlayers);

    //prints the whole list
    void outputWholeListWins();

    void initialQueue();

    void enqueueAllPlayers();

    void enqueuePlayer(std::string idIn);

    void enqueueSelection(int numOfPlayers);

    void queuesToString();

    Player* getPlayer(std::string idIn);

    bool isInList(std::string idIn);



};


#endif //PROJECT_MATCHMAKER_H
