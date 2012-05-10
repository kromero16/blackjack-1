#ifndef game_h
#define game_h

#include <vector>
#include "player.h"
#include "round.h"
#include "dealer.h"

class Game{
    vector<Player> players;
    Dealer dealer;
    bool gameOver;
    House gameDeck;
    float minimBet;
    
public:
    Game(vector<Player>, float);
    int inGameNumber();
    Round* playRound();
    bool over();
};

#endif
