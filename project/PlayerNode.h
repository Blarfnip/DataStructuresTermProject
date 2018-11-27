//
// Created by Milo Rue on 11/12/2018.
//

#ifndef TERM_PROJECT_220_PLAYERNODE_H
#define TERM_PROJECT_220_PLAYERNODE_H
#include "iostream"
#include "stdlib.h"
#include "Player.h"


class PlayerNode{
private:
    Player* player; //player pointer
    PlayerNode* next; //next Node
    int forceRating; //force rating for admin control
public:
    //constructor
    PlayerNode(Player* player);

    //copy constructor
    PlayerNode(const PlayerNode& nodeToCopy);

    //gets player pointer
    Player* getPlayer();

    //gets next node pointer
    PlayerNode* getNext();

    //sets a new player pointer inside node
    void setPlayer(Player* newPlayer);

    //sets a new next node
    void setNext(PlayerNode* newNext);



};

#endif //TERM_PROJECT_220_PLAYERNODE_H
