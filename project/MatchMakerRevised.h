//
// Created by Milo Rue and Desmond Lee on 12/1/2018.
//

#ifndef PROJECT_MATCHMAKERREVISED_H
#define PROJECT_MATCHMAKERREVISED_H
#include "Player.h"
#include "Game.h"
#include "ArrayList.h"
#include "PlayerQueue.h"
#include "PlayerNode.h"

#include <iostream>
#include <sstream>
#include <fstream>


class MatchMakerRevised {
private:
    List<PlayerQueue*>* playerQueues;
    List<Player*>* playerList;
    int playerCount=0;
public:

    MatchMakerRevised();

    void playMatchesQueue(int numOfMatches, std::string queueName);

    void dropQueue(std::string queueName);

    void clearQueue(std::string queueName);

    List<Player*>* getPlayerList();

    List<PlayerQueue*>* getQueueList();

    void addPlayerFromString(const std::string playerString);

    void addUserIDFromString(const std::string playerString);

    void addPlayerToList(Player* newPlayer);

    void writePlayerListToFile(std::string filename);

    void readPlayersFromFile(const std::string& filename);

    void populatePlayerList(int numOfPlayers);

    void runMatches(int numOfMatches);

    void headToHead(std::string player1, std::string player2, std::string winner);

    void vsMatch(std::string player1, std::string player2);

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

    void removePlayer(std::string idIn);

    void balanceList();


};


#endif //PROJECT_MATCHMAKERREVISED_H
