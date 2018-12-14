//
// Created by Milo Rue on 12/1/2018.
//

#include "MatchMakerRevised.h"
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

MatchMakerRevised::MatchMakerRevised() {
    playerList = new ArrayList<Player*>(100);
    playerQueues = new ArrayList<PlayerQueue*>(6);



}

void MatchMakerRevised::playMatchesQueue(int numOfMatches, std::string queueName) {
    PlayerQueue* playQueue;
    if(queueName=="Bronze"){
        playQueue=playerQueues->getValueAt(5);
    }
    if(queueName=="Silver"){
        playQueue=playerQueues->getValueAt(4);
    }
    if(queueName=="Gold"){
        playQueue=playerQueues->getValueAt(3);
    }
    if(queueName=="Platinum"){
        playQueue=playerQueues->getValueAt(2);
    }
    if(queueName=="Diamond"){
        playQueue=playerQueues->getValueAt(1);
    }
    if(queueName=="Challenger"){
        playQueue=playerQueues->getValueAt(0);
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
        for (int f = 0; f < total; f ++) {
            Game *testGame = new Game(playQueue->dequeue()->getPlayer(), playQueue->dequeue()->getPlayer());
            testGame->collectGuesses();
            testGame->play();
            delete testGame;
        }
    }
    if(even==false){
        playQueue->dequeue();
    }
}

void MatchMakerRevised::dropQueue(std::string queueName) {
    PlayerNode* tempPlayer;
    PlayerNode* helpPtr;
    PlayerQueue* playerQueueToDrop;

    if(queueName=="Bronze"){
        playerQueueToDrop=playerQueues->getValueAt(5);
    }
    if(queueName=="Silver"){
        playerQueueToDrop=playerQueues->getValueAt(4);
    }
    if(queueName=="Gold"){
        playerQueueToDrop=playerQueues->getValueAt(3);
    }
    if(queueName=="Platinum"){
        playerQueueToDrop=playerQueues->getValueAt(2);
    }
    if(queueName=="Diamond"){
        playerQueueToDrop=playerQueues->getValueAt(1);
    }
    if(queueName=="Challenger"){
        playerQueueToDrop=playerQueues->getValueAt(0);
    }

    tempPlayer=playerQueueToDrop->getFront();


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
void MatchMakerRevised::clearQueue(std::string queueName){
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

List<Player*>* MatchMakerRevised::getPlayerList() {
    return playerList;
}

List<PlayerQueue*>* MatchMakerRevised::getQueueList() {
    return playerQueues;
}

void MatchMakerRevised::addPlayerFromString(const std::string playerString) {
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

void MatchMakerRevised::addUserIDFromString(const std::string playerString) {
    Player* newPlayer = new Player(playerString);
    playerList->insertAtEnd(newPlayer);
}

void MatchMakerRevised::addPlayerToList(Player* newPlayer) {
    playerList->insertAtEnd(newPlayer);
}

void MatchMakerRevised::writePlayerListToFile(std::string filename) {
    std::ofstream outf(filename);
    if(outf){
        for(int f=0; f<playerList->itemCount(); f++){
            outf << playerList->getValueAt(f)->getID() + ", "  + std::to_string(playerList->getValueAt(f)->getRank()) << std::endl;
        }
        outf.close();
    }
}

void MatchMakerRevised::readPlayersFromFile(const std::string &filename) {
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

void MatchMakerRevised::populatePlayerList(int numOfPlayers) {
    for(int i = 0; i < numOfPlayers; i++) {
        playerList->insertAtEnd(new Player("Player" + std::to_string(playerCount)));
        playerCount++;
    }
}

void MatchMakerRevised::runMatches(int numOfMatches) {
    //Runs x matches with each player

    for (int k = 0; k < numOfMatches; k++) {
        if ((playerList->itemCount() % 2) == 0) {
            for (int i = 0; i < playerList->itemCount(); i += 2) {
                Game *testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));

                testGame->generateSolution();
                testGame->collectGuesses();

                //testGame->generateSolution(); *changed game to rock paper scissors format
                testGame->play();
                delete testGame;


//          else {
//                for (int i = 0; i < playerList->itemCount() - 1; i += 2) {
//                    if (playerList->itemCount() % 2) {
//                        Game *testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));
//
//                        testGame->generateSolution();
//                        testGame->collectGuesses();
//
//                        //testGame->generateSolution(); *changed game to rock paper scissors format
//                        testGame->play();
//                        delete testGame;
//
//                    }
//                }
//            }
            }
        } else {
            for (int i = 0; i < playerList->itemCount() - 1; i += 2) {
                Game *testGame = new Game(playerList->getValueAt(i), playerList->getValueAt(i + 1));

                testGame->generateSolution();
                testGame->collectGuesses();

                //testGame->generateSolution(); *changed game to rock paper scissors format
                testGame->play();
                delete testGame;
            }
        }
    }
}

void MatchMakerRevised::headToHead(std::string player1, std::string player2, std::string winner) {
    Player* play1;
    Player* play2;
    play1=getPlayer(player1);
    play2=getPlayer(player2);
    if(winner == player1){
        play1->won();
        play2->lost();
    }
    else if(winner==player2){
        play2->won();
        play1->lost();
    }
}

void MatchMakerRevised::vsMatch(std::string player1, std::string player2) {
    Player* play1;
    Player* play2;
    play1=getPlayer(player1);
    play2=getPlayer(player2);
    Game* vsGame = new Game(play1,play2);
    vsGame->generateSolution();
    vsGame->collectGuesses();
    vsGame->play();
    delete vsGame;
}

int MatchMakerRevised::getPlayerWins(std::string playerIdIn) {
    for(int i=0; i <playerList->itemCount(); i++){
        if(playerList->getValueAt(i)->getID()==playerIdIn){
            return playerList->getValueAt(i)->getWins();
        }
        else{

        }
    }
    return -1;
}

void MatchMakerRevised::outputListWins(int numOfPlayers) {
    for (int i = 0; i < numOfPlayers; i++) {
        std::cout << playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() << std::endl;
    }
}

void MatchMakerRevised::outputWholeListWins(){
    for (int i = 0; i < playerList->itemCount(); i++) {
        std::cout << playerList->getValueAt(i)->getID() << " | " << playerList->getValueAt(i)->getWins() << std::endl;
    }
}

void MatchMakerRevised::initialQueue() {
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

void MatchMakerRevised::enqueueAllPlayers() {

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
        else{

        }
    }
    tempPlayer= nullptr;
}

void MatchMakerRevised::enqueueSelection(int numOfPlayers) {

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
        else{

        }
    }
    tempPlayer= nullptr;
}

void MatchMakerRevised::enqueuePlayer(std::string idIn) {
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

void MatchMakerRevised::queuesToString() {
    std::cout << "Bronze Queued Players: " + playerQueues->getValueAt(5)->toString() << std::endl;
    std::cout << "Silver Queued Players: " + playerQueues->getValueAt(4)->toString() << std::endl;
    std::cout << "Gold Queued Players: " + playerQueues->getValueAt(3)->toString() << std::endl;
    std::cout << "Platinum Queued Players: " + playerQueues->getValueAt(2)->toString() << std::endl;
    std::cout << "Diamond Queued Players: " + playerQueues->getValueAt(1)->toString() << std::endl;
    std::cout << "Challenger Queued Players: " + playerQueues->getValueAt(0)->toString() << std::endl;
}

Player* MatchMakerRevised::getPlayer(std::string idIn) {
    Player* tempPlayer;
    for(int f=0; f<playerList->itemCount(); f++){
        if(playerList->getValueAt(f)->getID()==idIn){
            tempPlayer=playerList->getValueAt(f);
            return tempPlayer;
        }
        else{

        }
    }
    return tempPlayer;
}

bool MatchMakerRevised::isInList(std::string idIn) {
    for(int i=0; i<playerList->itemCount(); i++){
        if(playerList->getValueAt(i)->getID()==idIn){
            return true;
        }
        else{

        }
    }
    return false;
}

void MatchMakerRevised::removePlayer(std::string idIn) {
    for(int i=0; i<playerList->itemCount(); i++){
        if(playerList->getValueAt(i)->getID()==idIn){
            playerList->removeValueAt(i);
        }
        else{

        }
    }
}

void MatchMakerRevised::balanceList() {
    if(playerList->itemCount() % 2 == 0){
        addUserIDFromString("BPlayer" + std::to_string(playerCount));
    }
    else{

    }
}







