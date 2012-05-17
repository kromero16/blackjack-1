//
//  ui.h
//
//  Projeto 2 PROG
//
//  Turma 6 Grupo 4 
//
//  Diogo Eiras - ei11087
//  IDE - Eclipse, Visual Studio
//
//  Pedro Fernandes - ei11122
//  IDE - Xcode
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
#include <string>

#ifdef _WIN32
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
void updatePlayers(Game*);
void drawPlayerTurn(Player*, Round*);

#endif
