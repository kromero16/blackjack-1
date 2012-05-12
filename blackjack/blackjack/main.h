//
//  main.h
//  blackjack
//
//  Created by pedro on 4/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef main_h
#define main_h

#include <iostream>
#include <limits>
#include <ctime>

#include "player.h"
#include "round.h"
#include "card.h"
#include "dealer.h"
#include "game.h"
#include "hand.h"
#include "house.h"

#define PROMPT "> "

using namespace std;

vector<Player> getPlayers();
int setMinimBet();
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
