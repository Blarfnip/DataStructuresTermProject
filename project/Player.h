//
// Created by Milo Rue on 11/12/2018.
//

#ifndef TERM_PROJECT_220_PLAYER_H
#define TERM_PROJECT_220_PLAYER_H
#include "string"
#include "iostream"
#include "ArrayLib.h"

class Player{
private:
    bool isPlayer = false;
    int rank=0;
    int wins=0;
    int winstreak=0;
    int games=0;
    int gain=5;
    int loss=5;
    int lossTrend=0;
    std::string playerID;
    std::string password;
public:
    Player(std::string playerIDIn);
    Player(const Player& playerToCopy);
    std::string getID();
    void won();
    void lost();
    void setIsPlayer(bool val);
    void setRank(int val);
    void addToRank(int val);
    int getRank();
    int getWins();
    int getGames();
    int generateGuess();
    void changeID(std::string newID, std::string userPassIn);
    void setPass(std::string userPassIn);
    std::string checkTier();


};


#endif //TERM_PROJECT_220_PLAYER_H
