#include "player.h"

Player::Player (string n, int b){
    name = n;
    balance = b;
    hand_ptr = new Hand;
    isStanding = false;
    
}

Hand* Player::getHand(){
    return hand_ptr;
}

float Player::getBalance(){
    return balance;
}

bool Player::stand(){
    isStanding = true;
    return true;
}

bool Player::hit(){
    
    return true;
}

bool Player::doub(){
    
    return true;
}

