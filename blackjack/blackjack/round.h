#ifndef round_h
#define round_h

#include <vector>
#include "player.h"
#include "house.h"
#include "hand.h"
#include "dealer.h"
#include "card.h"


class Round{
	vector<Player*> active_players;
    vector<Player*>::iterator current_player;
    bool roundOver;
    House* gameDeck;
    Dealer* dealer;
    float* minimBet;
    
public:
    Round(vector<Player*>, House*, Dealer*, float*);
	Player* getNextPlayer();
    bool allPlayersAreDone();
	Player* getCurrentPlayer();
    bool allPlayersHaveBetted();
    bool over();
    bool doAction(int);
    Dealer* getDealer();
    float getMinimBet();
    bool dealerIsDone();
    bool moneyIsDistributed();
    ~Round();

    
};

#endif