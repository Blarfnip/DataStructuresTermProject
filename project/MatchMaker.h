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


class MatchMaker {
private:
    ;
public:
    void playMatchesList(List<Player*>* playerList,int numOfMatches);

    void playMatchesQueue(PlayerQueue* playerQueue, int numOfMatches, std::string queueName);

    void playersWon(List<Player*>* playerList);

    void dropQueue(PlayerQueue* playerQueueToDrop, std::string queueName);

    void clearQueue(PlayerQueue* playerQueueToClear, std::string queueName);

    List<Player*>* createPlayerList(List<Player*>* playerList,int numOfPlayers,int index);
};


#endif //PROJECT_MATCHMAKER_H
