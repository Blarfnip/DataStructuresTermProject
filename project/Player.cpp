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

int Player::getLosses() {
    return losses;
}
int Player::getGames() {
    return games;
}

int Player::getTies() {
    return ties;
}

int Player::getRocks() {
    return rocks;
}

int Player::getPapers() {
    return papers;
}

int Player::getScissors() {
    return scissors;
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
    losses++; //adds 1 to loss count
    winstreak=0; //resets winstreak
    lossTrend+=1; //adds 1 to lossTrend
    if(lossTrend >=3 and lossTrend < 5){
        if(rank-loss*2<0){
            rank=0;
        }
        else {
            rank -= loss * 2;
        }
    }
    else if(lossTrend >=5 and lossTrend <10){
        if(rank-loss*3<0){
            rank=0;
        }
        else {
            rank -= loss * 3;
        }
    }
    else if(lossTrend >=10){
        if(rank-loss*4<0){
            rank=0;
        }
        else{
            rank -=loss * 4;
        }
    }
    else{
        if(rank-loss<0){
            rank=0;
        }
        else{
            rank-=loss;
        }
    }
}
void Player::tie(){
    games+=1;
    ties+=1;
}

std::string Player::checkTier() {
    std::string tempStr="";
    if(rank<101){ //checks for bronze
        return tempStr+="Bronze";
    }
    if(rank>=101 and rank<201){ //checks for silver
        return tempStr+="Silver";
    }
    if(rank>=201 and rank<301){ //checks for gold
        return tempStr+="Gold";
    }
    if(rank>=301 and rank <401){ //checks for plat
        return tempStr+="Platinum";
    }
    if(rank>=401 and rank <501){ //checks for diamond
        return tempStr+="Diamond";
    }
    if(rank>=501){ //checks for NoLifers rank
        return tempStr+="Challenger";
    }
    else{
        return tempStr+="Bronze";
    }
}

//Sets player to user or AI
void Player::setIsPlayer(bool val) {
    isPlayer = val;
}

int Player::generateGuess() { //creates a random guess between 1-100
    if(!isPlayer) { //If player is AI
        int num=genRandInt(1,3);
        if(num==1){
            rocks++;
        }
        else if(num==2){
            papers++;
        }
        else if(num==3){
            scissors++;
        }
        return num;
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

//careful as this artificially inflates games played stats and doesnt change rank based on the stats inputted for games played
void Player::setPlace(int gamesIn, int winsIn, int lossesIn, int tiesIn) {
    games+=gamesIn;
    wins+=winsIn;
    losses+=lossesIn;
    ties+=tiesIn;
}

//TODO: Possibility of setPlace for creating artificial players that runs games based
//TODO: on what you put to create more accurate ranking stats, wouldn't allow for rank input though

