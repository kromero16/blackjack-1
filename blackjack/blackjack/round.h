#ifndef round_h
#define round_h

#include <vector>
#include "player.h"


class Round{
	vector<Player> active_players;
    vector<Player>::iterator current_player;
    
public:
    Round(vector<Player>);
	Player* getNextPlayer();
	bool play(Player*, int);
    
};

#endif