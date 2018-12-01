//
// Created by Milo Rue on 11/12/2018.
//
#include "PlayerQueue.h"

PlayerQueue::PlayerQueue() {
    front= nullptr; //empty ptr
    back= nullptr; //empty ptr
}

//TODO
//All of it
PlayerQueue::PlayerQueue(const PlayerQueue &queueToCopy) {
    PlayerNode* helpPtr=queueToCopy.front;
    PlayerNode* helpNode= new PlayerNode(queueToCopy.front->getPlayer(), queueToCopy.front->getPriority());
    PlayerNode* helpPtr2=helpNode;

    this->front=helpNode;

    while(helpPtr->getNext() != nullptr) {
        PlayerNode *whileNode = new PlayerNode(helpPtr->getNext()->getPlayer(), helpPtr->getNext()->getPriority());
        helpPtr2->setNext(whileNode);
        helpPtr = helpPtr->getNext();
        helpPtr2 = helpPtr2->getNext();
    }

    back = helpPtr2;
    back->setNext(nullptr);

}

PlayerQueue& PlayerQueue::operator=(const PlayerQueue &queueToCopy) {
    if(this!=&queueToCopy){
        PlayerNode *helpPtr=queueToCopy.front;
        PlayerNode *helpNode= new PlayerNode(queueToCopy.front->getPlayer(), queueToCopy.front->getPriority());
        PlayerNode *helpPtr2=helpNode;

        this->front=helpNode;

        while (helpPtr->getNext() != nullptr) {
            PlayerNode* whileNode=new PlayerNode(helpPtr->getNext()->getPlayer(), queueToCopy.front->getPriority());
            helpPtr2->setNext(whileNode);
            helpPtr=helpPtr->getNext();
            helpPtr2=helpPtr2->getNext();

        }
        back = helpPtr2;
        back->setNext(nullptr);
    }
}

PlayerQueue::~PlayerQueue() {
    while(front!= nullptr){
        PlayerNode *helpPtr= front->getNext();
        delete front;
        front=helpPtr;
    }
    delete front;
    front= nullptr;
    back = nullptr;
}

void PlayerQueue::enqueue(Player *playerIn) { //priority only allows for low_priority queueing for players with penalty's and allows
    //allows line cutting if priority for a certain player is higher than 1 (default priority is 1)
    PlayerNode* newNode= new PlayerNode(playerIn,1);
    if(front== nullptr){
        front=newNode;
        back=newNode;
    }
    else{
        back->setNext(newNode);
        back= newNode;
    }
//    else{
//        if(front->getPriority()==newNode->getPriority()){ //when priorities are the same it just acts like a normal queue
//            front->setNext(newNode);
//            back=newNode;
//        }
//        else if(front->getPriority() < newNode->getPriority()){ //when front has lower priority than new node than it will set a new front
//            PlayerNode* helpPtr=front;
//            front=newNode;
//            front->setNext(helpPtr);
//            helpPtr= nullptr;
//        }
//        else if(front->getPriority() > newNode->getPriority()){
//            PlayerNode* helpPtr=front->getNext();
//            if(helpPtr== nullptr){
//                front->setNext(newNode); //sets front's next node to the new node when the next node after front is a nullptr
//            }
//            else{
//                while (newNode->getPriority() < helpPtr->getPriority() or helpPtr->getNext()== nullptr) {
//                        helpPtr = helpPtr->getNext(); //increments helpPtr
//                    }
//                    if(helpPtr->getNext()== nullptr){
//                        back=newNode;
//                        helpPtr->setNext(newNode);
//                    }
//                    else {
//                        PlayerNode* helpNext=helpPtr->getNext(); //holds the old next in queue before new node is added in
//                        helpPtr->setNext(newNode);
//                        newNode->setNext(helpNext);
//                    }
//                }
//            }
//    }
}

PlayerNode* PlayerQueue::dequeue() {
    if(isEmpty()){
        throw std::out_of_range("Queue is empty");
    }
    else {
        PlayerNode *dequeuedPlayer = front;
        front = front->getNext();
        return dequeuedPlayer;
    }
}

bool PlayerQueue::isEmpty() {
    if(front== nullptr){
        return true;
    }
    else{
        return false;
    }
}

std::string PlayerQueue::toString() {
    PlayerNode* helpPtr=front;
    std::string outStr="";
    while(helpPtr!= nullptr){
        outStr+=helpPtr->getPlayer()->getID()+ " Rating: "+ std::to_string(helpPtr->getPlayer()->getRank())+" || ";
        helpPtr=helpPtr->getNext();
    }
    return outStr;
}

