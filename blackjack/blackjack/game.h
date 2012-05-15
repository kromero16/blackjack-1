#ifndef game_h
#define game_h

#include <vector>
#include "player.h"
#include "round.h"
#include "dealer.h"

class Game{
    vector<Player> players;
    int nextPlayerWaiting;
    vector<Player*> active_players;
    Dealer dealer;
    House gameDeck;
    float minimBet;
    Player* winner;
    
public:
    Game();
    Round* playRound();
    bool over();
    Player* getWinner();
    bool addPlayer(string, float);
    bool setMinimBet(float);
};

#endif
