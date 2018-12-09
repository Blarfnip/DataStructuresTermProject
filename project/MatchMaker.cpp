//
// Created by Milo Rue on 12/1/2018.
//

#include "MatchMaker.h"
//artificially plays games against next player in list outside of queue
//void MatchMaker::playMatchesList(List<Player*>* playerList ,int numOfMatches){
//    for(int k = 0; k < numOfMatches; k++) {
//        for(int i = 0; i < playerList->itemCount(); i += 2) {
//            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
//            testGame->collectGuesses();
//            //testGame->generateSolution(); *changed game to rock paper scissors format
//            testGame->play();
//            delete testGame;
//        }
//    }
//}

// void createPlayerList(List<Player*>* playerList, int numOfPlayers, int index){
//    playerList->insertAtEnd(new Player("Player " + std::to_string(index)));
//    if(index<numOfPlayers) {
//        return createPlayerList(playerList, numOfPlayers,index++);
//    }
//}

MatchMaker::MatchMaker() {
    playerList = new ArrayList<Player*>(100);
    playerQueues = new ArrayList<PlayerQueue*>(6);



}

void MatchMaker::playMatchesQueue(int numOfMatches, std::string queueName) {
    PlayerQueue* playQueue;
    if(queueName=="Bronze" or "bronze"){
        playQueue=playerQueues->getValueAt(5);
    }
    else if(queueName=="Silver" or "silver"){
        playQueue=playerQueues->getValueAt(4);
    }
    else if(queueName=="Gold" or "gold"){
        playQueue=playerQueues->getValueAt(3);
    }
    else if(queueName=="Platinum" or "platinum"){
        playQueue=playerQueues->getValueAt(2);
    }
    else if(queueName=="Diamond" or "diamond"){
        playQueue=playerQueues->getValueAt(1);
    }
    else if(queueName=="Challenger" or "challenger"){
        playQueue=playerQueues->getValueAt(0);
    }

    else{
        std::cout << "queue name doesnt exist" << std::endl;
    }

    int total=playQueue->getCount();
    bool even;

    if(total % 2 == 0){
        even=true;
        total=total/2;
    }
    else{
        even=false;
        total=total/2;
    }
    if( numOfMatches>total){
        //std::cout << "Entered Match Amount is greater than that of players in " +  queueName + " queue"<< std::endl;
        //std::cout << "Played " + std::to_string(total) + " instead" << std::endl;
        for (int f = 0; f < total; f++) {
            Game *testGame = new Game(playQueue->dequeue()->getPlayer(), playQueue->dequeue()->getPlayer());
            testGame->collectGuesses();
            testGame->play();
            delete testGame;
        }
    }
    else {
        for (int f = 0; f < numOfMatches; f ++) {
            Game *testGame = new Game(playQueue->dequeue()->getPlayer(), playQueue->dequeue()->getPlayer());
            testGame->collectGuesses();
            testGame->play();
            delete testGame;
        }
    }
}

void MatchMaker::dropQueue(std::string queueName) {
    PlayerNode* tempPlayer;
    PlayerNode* helpPtr;
    PlayerQueue* playerQueueToDrop;

    if(queueName=="Bronze" or "bronze"){
        playerQueueToDrop=playerQueues->getValueAt(5);
    }
    else if(queueName=="Silver" or "silver"){
        playerQueueToDrop=playerQueues->getValueAt(4);
    }
    else if(queueName=="Gold" or "gold"){
        playerQueueToDrop=playerQueues->getValueAt(3);
    }
    else if(queueName=="Platinum" or "platinum"){
        playerQueueToDrop=playerQueues->getValueAt(2);
    }
    else if(queueName=="Diamond" or "diamond"){
        playerQueueToDrop=playerQueues->getValueAt(1);
    }
    else if(queueName=="Challenger" or "challenger"){
        playerQueueToDrop=playerQueues->getValueAt(0);
    }

    else{
        std::cout << "queue name doesnt exist" << std::endl;
    }


    while(tempPlayer->getNext()!= nullptr){
        //std::cout << playerQueueToDrop->getCount() << std::endl;
        tempPlayer=playerQueueToDrop->dequeue();
        helpPtr=tempPlayer;
        tempPlayer=tempPlayer->getNext();
        helpPtr= nullptr;
    }
    tempPlayer=playerQueueToDrop->dequeue();
    tempPlayer= nullptr;
    std::cout << "Dropped queue for: " + queueName + " queue" << std::endl;
}

//TODO not currently working
void MatchMaker::clearQueue(std::string queueName){
    Player* tempPlayer;
    PlayerQueue* playerQueueToClear;

    if(queueName=="Bronze" or "bronze"){
        playerQueueToClear=playerQueues->getValueAt(5);
    }
    else if(queueName=="Silver" or "silver"){
        playerQueueToClear=playerQueues->getValueAt(4);
    }
    else if(queueName=="Gold" or "gold"){
        playerQueueToClear=playerQueues->getValueAt(3);
    }
    else if(queueName=="Platinum" or "platinum"){
        playerQueueToClear=playerQueues->getValueAt(2);
    }
    else if(queueName=="Diamond" or "diamond"){
        playerQueueToClear=playerQueues->getValueAt(1);
    }
    else if(queueName=="Challenger" or "challenger"){
        playerQueueToClear=playerQueues->getValueAt(0);
    }

    else{
        playerQueueToClear=playerQueues->getValueAt(4);
    }
    playMatchesQueue(playerQueueToClear->getCount()/2-1, queueName);

    }

List<Player*>* MatchMaker::getPlayerList() {
    return playerList;
}

List<PlayerQueue*>* MatchMaker::getQueueList() {
    return playerQueues;
}

void MatchMaker::addPlayerFromString(const std::string playerString) {
    std::stringstream splitter (playerString);
    std::string playerID, rank;

    getline(splitter, playerID, ',');
    getline(splitter, rank, ',');
//    getline(splitter, games, ',');
//    getline(splitter, wins, ',');
//    getline(splitter, losses, ',');
//    getline(splitter, ties, ',');

    Player* newPlayer = new Player(playerID);
    newPlayer->setRank(std::stoi(rank));
    playerList->insertAtEnd(newPlayer);
}

void MatchMaker::writePlayerListToFile(std::string filename) {
    std::ofstream outf(filename);
    if(outf){
        for(int f=0; f<playerList->itemCount(); f++){
            outf << playerList->getValueAt(f)->getID() + ", "  + std::to_string(playerList->getValueAt(f)->getRank()) << std::endl;
        }
        outf.close();
    }
}

void MatchMaker::readPlayersFromFile(const std::string &filename) {
    Player* inPlayer;
    std::ifstream infile(filename);

    if(infile){
        while(infile){
            std::string line;
            getline(infile, line);
            if(line==""){

            }
            else if(line!="") {
                addPlayerFromString(line);
            }
        }

    }

    infile.close();


}

void MatchMaker::populatePlayerList(int numOfPlayers) {
    for(int i = 0; i < numOfPlayers; i++) {
        playerList->insertAtEnd(new Player("Player " + std::to_string(i)));
    }
}

void MatchMaker::runMatches(int numOfMatches) {
    //Runs x matches with each player
    for(int k = 0; k < numOfMatches; k++) {
        for(int i = 0; i < playerList->itemCount(); i += 2) {
            Game* testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
            testGame->collectGuesses();
            //testGame->generateSolution(); *changed game to rock paper scissors format
            testGame->play();
            delete testGame;
        }
    }
}

int MatchMaker::getPlayerWins(std::string playerIdIn) {
    for(int i=0; i <playerList->itemCount(); i++){
        if(playerList->getValueAt(i)->getID()==playerIdIn){
            return playerList->getValueAt(i)->getWins();
        }
        else{

        }
    }
    return -1;
}

void MatchMaker::outputListWins(int numOfPlayers) {
    for (int i = 0; i < numOfPlayers; i++) {
        std::cout << playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() << std::endl;
    }
}

void MatchMaker::outputWholeListWins(){
    for (int i = 0; i < playerList->itemCount(); i++) {
        std::cout << playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() << std::endl;
    }
}

void MatchMaker::initialQueue() {
    PlayerQueue* bronzeQueue= new PlayerQueue();
    PlayerQueue* silverQueue= new PlayerQueue();
    PlayerQueue* goldQueue= new PlayerQueue();
    PlayerQueue* platinumQueue= new PlayerQueue();
    PlayerQueue* diamondQueue= new PlayerQueue();
    PlayerQueue* challengerQueue=new PlayerQueue();


    playerQueues->insertAtFront(bronzeQueue);
    playerQueues->insertAtFront(silverQueue);
    playerQueues->insertAtFront(goldQueue);
    playerQueues->insertAtFront(platinumQueue);
    playerQueues->insertAtFront(diamondQueue);
    playerQueues->insertAtFront(challengerQueue);

}

void MatchMaker::enqueueAllPlayers() {

    Player* tempPlayer;
    int count=playerList->itemCount();
    for(int i = 0; i<count; i++){
        tempPlayer=playerList->getValueAt(i);
        if(tempPlayer->checkTier()=="Bronze"){
            playerQueues->getValueAt(5)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Silver"){
            playerQueues->getValueAt(4)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Gold"){
            playerQueues->getValueAt(3)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Platinum"){
            playerQueues->getValueAt(2)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Diamond"){
            playerQueues->getValueAt(1)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Challenger"){
            playerQueues->getValueAt(0)->enqueue(tempPlayer);
        }
    }
    tempPlayer= nullptr;
}

void MatchMaker::enqueueSelection(int numOfPlayers) {

    Player* tempPlayer;
    for(int i = 0; i<numOfPlayers; i++){
        tempPlayer=playerList->getValueAt(i);
        if(tempPlayer->checkTier()=="Bronze"){
            playerQueues->getValueAt(5)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Silver"){
            playerQueues->getValueAt(4)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Gold"){
            playerQueues->getValueAt(3)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Platinum"){
            playerQueues->getValueAt(2)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Diamond"){
            playerQueues->getValueAt(1)->enqueue(tempPlayer);
        }
        else if(tempPlayer->checkTier()=="Challenger"){
            playerQueues->getValueAt(0)->enqueue(tempPlayer);
        }
    }
    tempPlayer= nullptr;
}

void MatchMaker::enqueuePlayer(std::string idIn) {
    Player* tempPlayer;

    for(int i=0; i <playerList->itemCount(); i++){
        if(playerList->getValueAt(i)->getID()==idIn){
            tempPlayer=playerList->getValueAt(i);
        }
        else{

        }
    }


    if(tempPlayer->checkTier()=="Bronze"){
        playerQueues->getValueAt(5)->enqueue(tempPlayer);
    }
    else if(tempPlayer->checkTier()=="Silver"){
        playerQueues->getValueAt(4)->enqueue(tempPlayer);
    }
    else if(tempPlayer->checkTier()=="Gold"){
        playerQueues->getValueAt(3)->enqueue(tempPlayer);
    }
    else if(tempPlayer->checkTier()=="Platinum"){
        playerQueues->getValueAt(2)->enqueue(tempPlayer);
    }
    else if(tempPlayer->checkTier()=="Diamond"){
        playerQueues->getValueAt(1)->enqueue(tempPlayer);
    }
    else if(tempPlayer->checkTier()=="Challenger"){
        playerQueues->getValueAt(0)->enqueue(tempPlayer);
    }

    tempPlayer= nullptr;
}

void MatchMaker::queuesToString() {
    std::cout << "Bronze Queued Players: " + playerQueues->getValueAt(5)->toString() << std::endl;
    std::cout << "Silver Queued Players: " + playerQueues->getValueAt(4)->toString() << std::endl;
    std::cout << "Gold Queued Players: " + playerQueues->getValueAt(3)->toString() << std::endl;
    std::cout << "Platinum Queued Players: " + playerQueues->getValueAt(2)->toString() << std::endl;
    std::cout << "Diamond Queued Players: " + playerQueues->getValueAt(1)->toString() << std::endl;
    std::cout << "Challenger Queued Players: " + playerQueues->getValueAt(0)->toString() << std::endl;
}






