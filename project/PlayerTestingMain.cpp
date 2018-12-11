//
// Created by Saul on 12/11/2018.
//
#include "MatchMakerRevised.h"

int main() {
    MatchMakerRevised* match = new MatchMakerRevised();


    std::string playerName = "Bob";
    Player* newPlayer = new Player(playerName);
    newPlayer->setIsPlayer(true);
    match->addPlayerToList(newPlayer);
    match->populatePlayerList(500);

    match->vsMatch("Bob", "Player1");
    match->vsMatch("Bob", "Player1");
    match->vsMatch("Bob", "Player1");
    match->vsMatch("Bob", "Player1");


    Player *statPlayer = match->getPlayer("Bob");
    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
    std::cout << "-------------------------------" << std::endl;

    statPlayer = match->getPlayer("Player1");
    std::cout << "----------" + statPlayer->getID() + "----------" << std::endl;
    std::cout << "Rank: " + std::to_string(statPlayer->getRank()) << std::endl;
    std::cout << "Wins: " + std::to_string(statPlayer->getWins()) << std::endl;
    std::cout << "Losses: " + std::to_string(statPlayer->getLosses()) << std::endl;
    std::cout << "Ties: " + std::to_string(statPlayer->getTies()) << std::endl;
    std::cout << "Games Played: " + std::to_string(statPlayer->getGames()) << std::endl;
    std::cout << "-------------------------------" << std::endl;

    //match->enqueueAllPlayers();

}