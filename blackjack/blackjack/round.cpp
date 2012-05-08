#include "round.h"

Round::Round(vector<Player> vec_players, House* h, Dealer* d){
    active_players = vec_players;
    current_player = active_players.begin();
    
    for (unsigned int i = 0; i < 2; i++) {
        
        for (vector<Player>::iterator player = active_players.begin(); player < active_players.end(); player++ ) {
            player->getHand()->getCard(h); 
        }
        
        if (i < 1) {
           d->getHand()->getCard(h);
        }
        else{
            d->getHand()->getCardFlipped(h);
        }
    }

    
}


Player* Round::getNextPlayer(){
	current_player++;
	return (Player*)(current_player);
}

Player* Round::getCurrentPlayer(){
    return current_player;
}