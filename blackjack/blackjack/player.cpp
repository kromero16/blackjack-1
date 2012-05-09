#include "player.h"

Player::Player (string n, int b){
    name = n;
    balance = b;
    hand_ptr = new Hand;
    status = 1;
    
}

Hand* Player::getHand(){
    return hand_ptr;
}

float Player::getBalance(){
    return balance;
}

string Player::getName(){
    return this->name;
}


bool Player::stands(){
    this->changeStatus(2);
    
    return true;
}

bool Player::hits(House* h){
    this->getHand()->getCard(h);
    
    int current_score = this->getHand()->getTotal();
    
    if (current_score > 21) {
        this->changeStatus(3); //is bust
    }
    else if (current_score == 21) {
        this->changeStatus(5); //has blackjack
    }
    
    return true;
}

bool Player::doubles(House* h){
    this->getHand()->getCard(h);
    
    int current_score = this->getHand()->getTotal();
    
    if (current_score > 21){
        this->changeStatus(3); //is bust
    }
    else if (current_score == 21) {
        this->changeStatus(5); //has blackjack
    }
    else {
        this->changeStatus(5); //has doubled
    }
    
    return true;
}

bool Player::changeStatus(int new_status){
    this->status = new_status;
    
    /*
     status details
     1 - playing
     2 - is standing
     3 - is bust
     4 - has doubled
     5 - has blackjack
     ...
    */
    
    return true;
}

int Player::getStatus(){
    return this->status;
}

int Player::getOptions(){
    /*
     1 - stand, hit
     2 - stand, hit, double
     3 - has blackjack
    */
    
    int player_points = this->getHand()->getTotal();
    
    if ( ( player_points >= 9 && player_points <= 11 ) && this->getHand()->getNumOfCards() == 2 ){
        return 2;
    }
    else if (player_points == 21){
        this->changeStatus(5);
        return 3;
    }
    else
        return 1;
    
}

