#include "game.h"

Game::Game (){
    this->dealer = Dealer();
    this->gameDeck.populate();
    this->gameDeck.shuffle();
}

bool Game::addPlayer(string name, float balance) {
    Player new_player = Player(name, balance);
    this->players.push_back(new_player);
    
    return true;
}

bool Game::setMinimBet(float bet){
    this->minimBet = bet;
    return true;
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
    else if (inGame == 0){
        winner = NULL;
        return true;
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
    
    this->players_entered_round.clear();
    
    //popular uma ronda com 4 jogadores da lista players
    if (this->active_players.empty() ) {
        unsigned int i = 0;
        for (; i < players.size() && active_players.size() < 4 ; i++) {
            if ( players.at(i).getBalance() >= minimBet ){
                this->active_players.push_back(&players.at(i) );
            }
        }
        if (i < 4) {  // nao existem jogadores a esperar
            nextPlayerWaiting = 0;
        }
        else         // existem jogadores em espera
            nextPlayerWaiting = i;
    }
    else{
        
        for (unsigned int i = 0; i < active_players.size() ; i++) {  //verificar se ha jogadores que perderam e substitui-los
            if ( active_players.at(i)->getStatus() == 7 && nextPlayerWaiting > 0){
                this->active_players.at(i) = (&players.at(nextPlayerWaiting));
                this->players_entered_round.push_back( (&players.at(nextPlayerWaiting)) );
                if (nextPlayerWaiting < players.size()-1) {
                    nextPlayerWaiting++;
                }
                else
                    nextPlayerWaiting = 0; // no more players are waiting
            }
            else if (active_players.at(i)->getStatus() == 7 && nextPlayerWaiting == 0){
                active_players.erase(active_players.begin()+i);
            }
        }
    }
    
    return new Round(active_players, &gameDeck, &dealer, &minimBet);
}

Player* Game::getWinner(){
    return winner;
}

vector<Player*> Game::getPlayersEnteredThisRound(){
    return this->players_entered_round;
}

vector<Player*> Game::getActivePlayers(){
    for (int i = 0; i < active_players.size(); i++ ) {
        if (active_players.at(i)->getStatus() == 7) {
            active_players.erase(active_players.begin()+i);
        }
    }
    return this->active_players;
}


