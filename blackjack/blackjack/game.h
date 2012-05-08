#ifndef game_h
#define game_h

#include <vector>
#include "player.h"
#include "round.h"
#include "dealer.h"

class Game{
    vector<Player> players;
    Dealer* dealer;
    bool gameOver;
    House casa;
    int apostaMinima;
    
public:
    Game(vector<Player>, int);
    int inGameNumber();
    Round* playRound();
    bool over();
};

#endif
