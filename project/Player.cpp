//
// Created by Milo Rue on 11/12/2018.
//

#include "Player.h"

Player::Player(std::string playerIDIn) {
    this->playerID=playerIDIn;
}
std::string Player::getID() {
    return playerID;
}
int Player::getRank() {
    return rank;
}
int Player::getWins() {
    return wins;
}
int Player::getGames() {
    return games;
}
void Player::setPass(std::string userPassIn) {
    this->password=userPassIn;
}

void Player::changeID(std::string newID, std::string userPassIn) {
    if(userPassIn==password){
        this->playerID=newID;
    }
    else{
        std::cout << "user pass failed" << std::endl;
    }

}
void Player::won() {
    games+=1;
    wins+=1;
    winstreak+=1;
    if(winstreak>=3 and winstreak < 5){
        rank+=gain*2;
    }
    else if(winstreak >=5 and winstreak <10){
        rank+=gain*3;
    }
    else if(winstreak >=10){
        rank+=gain*4;
    }
    else{
        rank+=gain;
    }
}

void Player::lost() {
    games+=1;
    winstreak=0;
    lossTrend+=1;
    if(lossTrend >=3){
        rank-=10;
    }
    else{
        rank-=5;
    }
}

std::string Player::checkTier() {
    if(rank>=0 and rank<101){
        return "Bronze";
    }
    else if(rank>=101 and rank<200){
        return "Silver";
    }
    else if(rank>=201 and rank<301){
        return "Gold";
    }
    else if(rank>=301 and rank <401){
        return "Platinum";
    }
    else if(rank>=401 and rank <501){
        return "Diamond";
    }
    else if(rank>=501){
        return "NoLifers";
    }
}

int Player::generateGuess() {
    if(!isPlayer) {
        return genRandInt(1,100);
    }
}

