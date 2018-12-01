//
// Created by Milo Rue on 11/12/2018.
//

#ifndef TERM_PROJECT_220_PLAYERQUEUE_H
#define TERM_PROJECT_220_PLAYERQUEUE_H

#include "PlayerNode.h"
#include "Player.h"


class PlayerQueue{
private:
    PlayerNode* front; //holds the front of the queue
    PlayerNode* back; //holds the back of the queue
public:

    //constructor
    PlayerQueue();

    //copy constructor
    PlayerQueue(const PlayerQueue& queueToCopy);

    //assignment operator
    PlayerQueue& operator=(const PlayerQueue& queueToCopy);

    //destructor
    ~PlayerQueue();

    //enqueues players with a priority based on rating
    void enqueue(Player* playerIn, float priorityToAdd);

    //removes a player and returns a pointer to that player
    PlayerNode* dequeue();

    //checks if queue is empty
    //true is empty
    //false if not
    bool isEmpty();




};

#endif //TERM_PROJECT_220_PLAYERQUEUE_H
