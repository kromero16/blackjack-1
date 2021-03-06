//
//  player.cpp
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

#include "player.h"

Player::Player (string n, float b){
    this->name = n;
    this->balance = b;
    this->hand_ptr = new Hand;
    this->status = 1;  // is playing
    this->bet = 0;
    this->latest_winnings = 0;
    
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
    
    this->balance = this->balance - this->bet;
    this->bet = this->bet*2;
        
    int current_score = this->getHand()->getTotal();
    
    if (current_score > 21){
        this->changeStatus(3); //is bust
    }
    else if (current_score == 21) {
        this->changeStatus(6); //has doubled and blackjack
    }
    else {
        this->changeStatus(4); //has doubled
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
     6 - has doubled and blackjack
     7 - lost (no more money to bet) or gave up
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
    
    bool hasMoneyToDouble = false;
    
    if (this->balance - this->bet > 0)
        hasMoneyToDouble = true;
    
    if ( (( player_points >= 9 && player_points <= 11 ) && this->getHand()->getNumOfCards() == 2) && hasMoneyToDouble ){
        return 2;
    }
    else if (player_points == 21){
        this->changeStatus(5);
        return 3;
    }
    else
        return 1;
    
}

bool Player::makeBet(float amount_betted){
    this->balance -= amount_betted;
    this->bet += amount_betted;
    
    return true;
}

bool Player::hasBetted(){
    if (this->bet > 0) {
        return true;
    }
    else
        return false;
}



float Player::getBet(){
    return bet;
}

bool Player::updateBalance(float winnings){
    if (winnings == 0) {
        this->latest_winnings = -bet;
        this->bet = 0;
        return true;
    }
    else{
        this->balance += winnings;
        this->bet = 0;
        this->latest_winnings = winnings;
        return true;
    }
    
    return true;
}

float Player::getLatestWinnings(){
    return this->latest_winnings;
}

bool Player::lost(){
    if (this->status == 7)
        return true;
    else
        return false;
}
bool Player::giveUp(){
    this->changeStatus(7);
    this->balance = 0;
    
    return true;
}

