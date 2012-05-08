#include "player.h"

Player::Player (string n, int b){
    name = n;
    balance = b;
    hand_ptr = new Hand;
    
    
}

Hand* Player::getHand(){
    return hand_ptr;
}

float Player::getBalance(){
    return balance;
}

bool Player::wantsStand(){
    
    return true;
}

bool Player::wantsHit(){
    
    return true;
}

bool Player::wantsDouble(){
    
    return true;
}

