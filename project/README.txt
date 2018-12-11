MatchMakerRevised

MatchMakerRevised::MatchMakerRevised()

class constructor

void MatchMakerRevised::playMatchesQueue(int numOfMatches, std::string queueName) 

plays matches in queue, if the number of Matches is greater than the total number of players, matchmaker plays the maximum number of matches it can play 

void MatchMakerRevised::dropQueue(std::string queueName) 

drops a specific player from queue

void MatchMakerRevised::addPlayerFromString(const std::string playerString)

adds a new player on the playerList

void MatchMakerRevised::writePlayerListToFile(std::string filename)

writes players in playerList into a file

void MatchMakerRevised::readPlayersFromFile(const std::string &filename)

reads a file and inherits players from the file into the playerList

void MatchMakerRevised::populatePlayerList(int numOfPlayers)

populates initial playerList with a for loop for each numOfPlayers

void MatchMakerRevised::runMatches(int numOfMatches)

runs a number of matches(depends how much numOfMatches is)

void MatchMakerRevised::headToHead(std::string player1, std::string player2, std::string winner)???

checks which player won and which player lost

void MatchMakerRevised::vsMatch(std::string player1, std::string player2)

runs a match between player1 and player2

int MatchMakerRevised::getPlayerWins(std::string playerIdIn)

