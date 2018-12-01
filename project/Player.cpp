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
    this->password=userPassIn; //sets new pass
}

void Player::changeID(std::string newID, std::string userPassIn) {
    if(userPassIn==password){ //if the password is correct it allows changes
        this->playerID=newID;
    }
    else{
        std::cout << "user pass failed" << std::endl;
    }

}
void Player::won() {
    games+=1; //adds 1 to game count
    wins+=1; //adds 1 to win count
    winstreak+=1; //increments winstreak counter
    lossTrend=0; //resets lossTrend
    if(winstreak>=3 and winstreak < 5){
        rank+=gain*2; //if winstreak is 3 to 4 than the rating gain is doubled
    }
    else if(winstreak >=5 and winstreak <10){
        rank+=gain*3; //if winstreak is 5 to 9 than rating gain is tripled
    }
    else if(winstreak >=10){
        rank+=gain*4; //any winstreak larger than 10 is rating gain x4
    }
    else{
        rank+=gain; //if winstreak less than 3 than gain is normal
    }
}

void Player::lost() {
    games+=1; //adds 1 to game count
    winstreak=0; //resets winstreak
    lossTrend+=1; //adds 1 to lossTrend
    if(lossTrend >=5){
        rank-=loss*2;
    }
    else{
        rank-=loss;
    }
}

std::string Player::checkTier() {
    if(rank>=0 and rank<101){ //checks for bronze
        return "Bronze";
    }
    else if(rank>=101 and rank<200){ //checks for silver
        return "Silver";
    }
    else if(rank>=201 and rank<301){ //checks for gold
        return "Gold";
    }
    else if(rank>=301 and rank <401){ //checks for plat
        return "Platinum";
    }
    else if(rank>=401 and rank <501){ //checks for diamond
        return "Diamond";
    }
    else if(rank>=501){ //checks for NoLifers rank
        return "NoLifers";
    }
}

//Sets player to user or AI
void Player::setIsPlayer(bool val) {
    isPlayer = val;
}

int Player::generateGuess() { //creates a random guess between 1-100
    if(!isPlayer) { //If player is AI
        return genRandInt(1,100);
    } else { //If Player is User
        //TODO: Separate this to another data structure
        std::cout << "Please give me your guess (1-100): ";
        std::string guess = "0";
        std::getline(std::cin, guess);// >> guess;
        std::cout << std::endl;
        return std::stoi(guess);
    }
}


void Player::setRank(int val) {
    rank = val; //overrides rank
}
void Player::addToRank(int val) {
    rank += val; //adds to rank
}

