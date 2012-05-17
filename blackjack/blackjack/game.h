//
//  game.h
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
    vector<Player*> players_entered_round;
    Dealer dealer;
    House gameDeck;
    float minimBet;
    Player* winner;
    
public:
    Game();
    bool addPlayer(string, float);
    bool setMinimBet(float);
    bool over();
    Round* playRound();
    Player* getWinner();
    vector<Player*> getPlayersEnteredThisRound();
    vector<Player*> getActivePlayers();
    vector<Player> getPlayers();
};

#endif
