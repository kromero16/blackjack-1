#include "game.h"

Game::Game (vector<Player> vec_players, float bet){
    this->players = vec_players;
    this->dealer = Dealer();
        
    this->gameDeck.populate();
    this->gameDeck.shuffle();
    
    this->minimBet = bet;
}

bool Game::over(){
    vector<Player>::iterator player;
    int inGame = 0;
    
    for (player = players.begin(); player < players.end() ; player++) {
        if ( player->getBalance() >= minimBet ) {
            inGame++;
        }
    }
    
    if (inGame > 1) {
        return false;
    }
    else{
        for (player= players.begin(); player < players.end() ; player++){
            if ( player->getBalance() >= minimBet ){
                winner = &(*player);
            }
        }
    return true;
    }
    
}

Round* Game::playRound(){
    vector<Player*> active_players;
    
    //popular uma ronda com 4 jogadores da lista players
    
    for (unsigned int i = 0; i < players.size() && active_players.size() < 4 ; i++) {
        if ( players.at(i).getBalance() > 0 ){
            active_players.push_back(&players.at(i) );
        }
    }
    
    return new Round(active_players, &gameDeck, &dealer, &minimBet);
}

Player* Game::getWinner(){
    return winner;
}

