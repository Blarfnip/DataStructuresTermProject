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

returns the number of player wins

void outputListWins(int numOfPlayers);

prints out how many wins a specific player has

void outputWholeListWins();

prints out the whole list of players and how many wins they all have

void initialQueue();

creates queues for each player tier and then

void enqueueAllPlayers();

puts all players onto a queue

void enqueuePlayer(std::string idIn);

enqueues player from playerlist with the player ID

void enqueueSelection(int numOfPlayers);

enqueues player from playerlist with the player number

void queuesToString();

converts player queues into string

Player* getPlayer(std::string idIn);

gets player* with the ID as an input

bool isInList(std::string idIn);

checks if a certain player is in playerlist with by using the player ID

void MatchMakerRevised::removePlayer(std::string idIn)

removes player from playerList

void MatchMakerRevised::balanceList()

checks if the list is even and if it is even, adds a user ID

PlayerQueue

void PlayerQueue::enqueue(Player *playerIn)

adds player onto the queue
//priority only allows for low_priority queueing for players with penalty's and allows
    //allows line cutting if priority for a certain player is higher than 1 (default priority is 1)

PlayerNode* PlayerQueue::dequeue()

removes a player from the queue

bool PlayerQueue::isEmpty()

std::string PlayerQueue::toLeaderboard()

converts list leaderboard into a string

//TODO:void PlayerQueue::clear()

GAME

void Game::collectGuesses()

collects player guesses by running generate guess for both players

void Game::play()

plays the game-checks who won and who lost by using integers
1=rock
2=paper
3=scissors

Player

void Player::won()

adds to wincount and games played to player, also checks if player has a winstreak. If it does it modifies the rank depending on how high the win streak is.

void Player::lost()

adds to lostcount and games played to player, also checks if player has a losstreak. If it does it modifies the rank depending on how high the loss streak is

void Player::tie()

adds to tiecount and games played to player

int generateGuess();

generates a random number from 1-3, each number represents rock, paper, or scissors respectively. Also adds to the scissors, paper, or rock count

std::string checkTier()

returns a string representation of rating

void setPlace(int gamesIn, int winsIn, int lossesIn, int tiesIn);

a way to edit games,wins,and losses for file input of randomized players


