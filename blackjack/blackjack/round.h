#ifndef round_h
#define round_h

#include <vector>
#include "player.h"
#include "house.h"
#include "hand.h"
#include "dealer.h"
#include "card.h"


class Round{
	vector<Player> active_players;
    vector<Player>::iterator current_player;
    
public:
    Round(vector<Player>, House*, Dealer*);
	Player* getNextPlayer();
	Player* getCurrentPlayer();
    
};

#endif