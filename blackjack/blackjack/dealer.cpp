#include "dealer.h"

Dealer::Dealer(){
    hand = new Hand;
}

Hand* Dealer::getHand(){
    return hand;
}