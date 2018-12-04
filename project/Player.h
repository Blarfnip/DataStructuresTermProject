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

    //checks for humanity
    bool isPlayer = false;

    //rating determines queue placement and matchmaking
    int rank=0;

    //# of games won
    int wins=0;

    //# of games lost
    int losses=0;

    //# of games won in a row as of current (resets upon loss)
    int winstreak=0;

    //total # of games played
    int games=0;

    //amount of rating gained per win (scales on winstreak)
    int gain=5;

    //amount of rating lost per loss (scales on lossTrend)
    int loss=5;

    //# of losses in a row as of current (resets upon win)
    int lossTrend=0;

    //string Identifier
    std::string playerID;

    //unused password
    std::string password;

    //tie count
    int ties=0;

    //rock count
    int rocks=0;

    //paper count
    int papers=0;

    //scissor count
    int scissors=0;
public:

    //constructor
    Player(std::string playerIDIn);

    //copy constructor
    Player(const Player& playerToCopy);

    //gets the player ID
    std::string getID();

    //initializes a "win" for the player
    void won();

    //initializes a "loss" for the player
    void lost();

    //Sets if player is person or AI
    void setIsPlayer(bool val);

    //Sets rank to val
    void setRank(int val);

    //Adds val to current rank
    void addToRank(int val);

    //returns rating of player (int)
    int getRank();

    //returns an int of games won
    int getWins();

    //returns an int of games played
    int getGames();

    //returns an int of tied games
    int getTies();

    //returns rocks amt
    int getRocks();

    //returns papers amt
    int getPapers();

    //returns scissors amt
    int getScissors();

    //creates a guess for the desired game
    int generateGuess();

    //changes the playerID if a valid password is given
    void changeID(std::string newID, std::string userPassIn);

    //sets the password (unprotected)
    void setPass(std::string userPassIn);

    //returns a string representation of rating
    std::string checkTier();

    //accounts for ties in game and reruns the game till not a tie
    void tie();

    //a way to edit games,wins,and losses for file input of randomized players
    void setPlace(int gamesIn, int winsIn, int lossesIn, int tiesIn);

};


#endif //TERM_PROJECT_220_PLAYER_H
