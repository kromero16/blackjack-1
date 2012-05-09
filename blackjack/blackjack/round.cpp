#include "round.h"

Round::Round(vector<Player> vec_players, House* h, Dealer* d){
    this->active_players = vec_players;
    this->current_player = active_players.begin();
    this->roundOver = false;
    gameDeck = h;
    dealer = d;
    
    for (unsigned int i = 0; i < 2; i++) {
        
        for (vector<Player>::iterator player = active_players.begin(); player < active_players.end(); player++ ) {
            player->getHand()->getCard(gameDeck); 
        }
        
        if (i < 1) {
           d->getHand()->getCard(gameDeck);
        }
        else{
            d->getHand()->getCardFlipped(gameDeck);
        }
    }

}


Player* Round::getNextPlayer(){
	current_player++;

	return (Player*)&(*current_player);;
}

Player* Round::getCurrentPlayer(){
    return &(*current_player);
}

bool Round::currentPlayerIsDone(){
    if (this->current_player->getStatus() != 1){
        return true;
    }
    else
        return false;
}


bool Round::over(){
    return roundOver;
}

bool Round::doAction(int choice){
    switch (choice) {
        case 1:
            current_player->stands();
            break;
        case 2:
            current_player->hits(gameDeck);
            break;
        case 3:
            current_player->doubles(gameDeck);
            break;
            
        default:
            return false;
            break;
    }
    
    return true;
}
