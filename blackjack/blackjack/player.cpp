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

bool Player::stands(){
    
    return true;
}

bool Player::hits(){
    
    return true;
}

bool Player::doubles(){
    
    return true;
}

bool Player::changeStatus(int new_status){
    this->status = new_status;
    
    return true;
    
    /*
     status details
     1 - playing
     2 - is standing
     3 - is bust
     4 - has doubled
     ...
    */
}

int Player::getStatus(){
    return this->status;
}

int Player::getOptions(){
    /*
     1 - stand, hit
     2 - stand, hit, double
    */
    
    int player_points = this->getHand()->getTotal();
    
    if ( ( player_points >= 9 && player_points <= 11 ) && this->getHand()->getNumOfCards() == 2 ){
        return 2;
    }
    else
        return 1;
    
}
