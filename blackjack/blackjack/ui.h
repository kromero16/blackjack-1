//
//  ui.h
//  blackjack
//
//  Created by Pedro Fernandes on 5/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ui_h
#define ui_h

#include "hand.h"
#include "dealer.h"
#include "player.h"

#define PROMPT "> "

using namespace std;

vector<Player> getPlayers();
float setMinimBet();
int getPlayerOptions(int);
void drawCards(Hand*);
void drawPlayerStatus(Player*);
float getBet(float min, Player*);
void wait(int);
void drawDealerAction(Dealer*);
void drawDealerStatus(Dealer*);
void displayResult(Player*);
void displayWinner(Player* p);

#endif
