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
#include "game.h"
#include <limits>
#include <fstream>
#include <iostream>

#ifdef WIN32
#include <fcntl.h>
#include <io.h>
#endif

using namespace std;

#define PROMPT "> "

using namespace std;

void getPlayers(Game*);
void setMinimBet(Game*);
int getPlayerOptions(int);
void drawCards(Hand*);
void drawPlayerStatus(Player*);
float getBet(float min, Player*);
void wait(int);
void drawDealerAction(Dealer*);
void drawDealerStatus(Dealer*);
void displayResult(Player*);
void displayWinner(Player* p);
void queryPlayersGiveUp(Game*);
void displayWhoEntered(Game*);

#endif
