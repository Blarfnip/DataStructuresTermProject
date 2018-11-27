//
// Created by Milo Rue on 11/12/2018.
//

#include "PlayerNode.h"

PlayerNode::PlayerNode(Player* player) {
    next= nullptr;
    this->player=player;
    this->forceRating=10000;
}
PlayerNode::PlayerNode(const PlayerNode &nodeToCopy) {
    next= nullptr;
    this->player=nodeToCopy.player;
}
Player* PlayerNode::getPlayer() {
    return player;
}

PlayerNode* PlayerNode::getNext() {
    return next;
}

void PlayerNode::setNext(PlayerNode* newNext) {
    next=newNext;
}

void PlayerNode::setPlayer(Player* newPlayer) {
    player=newPlayer;
}

