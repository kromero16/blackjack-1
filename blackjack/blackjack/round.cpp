#include "round.h"

Round::Round(vector<Player*> vec_players, House* h, Dealer* d, float* b){
    this->active_players = vec_players;
    this->current_player = active_players.begin();
    this->roundOver = false;
    gameDeck = h;
    dealer = d;
    minimBet = b;
    
    for (unsigned int i = 0; i < 2; i++) {
        
        for (vector<Player*>::iterator player = active_players.begin(); player < active_players.end(); player++ ) {
            (*player)->getHand()->getCard(gameDeck); 
        }
        
        if (i < 1) {
           d->getHand()->getCard(gameDeck);
        }
        else{
            d->getHand()->getCardFlipped(gameDeck);
        }
    }
    
    dealer->setStatus(1); // not playing yet

}


Player* Round::getNextPlayer(){
	current_player++;

	return *current_player;
}

Player* Round::getCurrentPlayer(){
    return *current_player;
}

bool Round::allPlayersAreDone(){
    if ((*this->current_player)->getStatus() != 1){
        this->getNextPlayer();
        if (current_player == active_players.end() ){
            
            dealer->getStatus(); // dealer is now playing
            
            return true;
        }
        else
            return false;
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
            (*current_player)->stands();
            break;
        case 2:
            (*current_player)->hits(gameDeck);
            break;
        case 3:
            (*current_player)->doubles(gameDeck);
            break;
            
        default:
            return false;
            break;
    }
    
    return true;
}

Dealer* Round::getDealer(){
    return dealer;
}


float Round::getMinimBet(){
    return *minimBet;
}


bool Round::dealerIsDone(){
    if (dealer->getStatus() == 2 && !dealer->getHand()->fetchCard(2)->isUp() ) // hand under 17 and not flipped 2nd card yet
    {
        dealer->flipCard();
        dealer->setLastAction(1); // flipped 2nd card
        dealer->getStatus();
        return false;
    }
    else if (dealer->getStatus() == 2){
        dealer->hits(gameDeck);
        dealer->setLastAction(2); // dealer hits
        dealer->getStatus();
        return false;
    }
    else{
        dealer->setLastAction(3); // dealer stands
        return true;
    }
}
