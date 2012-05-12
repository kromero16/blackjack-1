#ifndef game_h
#define game_h

#include <vector>
#include "player.h"
#include "round.h"
#include "dealer.h"

class Game{
    vector<Player> players;
    Dealer dealer;
    House gameDeck;
    float minimBet;
    Player* winner;
    
public:
    Game(vector<Player>, float);
    Round* playRound();
    bool over();
    Player* getWinner();
};

#endif
