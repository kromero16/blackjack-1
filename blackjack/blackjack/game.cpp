#include "game.h"

Game::Game (vector<Player> vec_players, int aposta){
    players = vec_players;
    dealer = Dealer();
    minimBet = aposta;
    
    gameDeck.populate();
    gameDeck.shuffle();
}

bool Game::over(){
    return gameOver;
}

Round* Game::playRound(){
    vector<Player*> active_players;
    
    //popular uma ronda com 4 jogadores da lista players
    
    for (unsigned int i = 0; i < players.size() && active_players.size() <= 4 ; i++) {
        if ( players.at(i).getBalance() > 0 ){
            active_players.push_back(&players.at(i) );
        }
    }
    
    return new Round(active_players, &gameDeck, &dealer);
}
