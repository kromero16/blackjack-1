//
//  dealer.cpp
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

#include "dealer.h"

Dealer::Dealer(){
    hand = new Hand;
}

Hand* Dealer::getHand(){
    return hand;
}

int Dealer::getStatus(){
    /*
     dealer's status
     1 - isnt playing yet
     2 - has under 17
     3 - has over 17 and under 21
     4 - has blackjack
     5 - has busted
     */
    
    int points = this->getHand()->getTotal();
    
    if (points < 17) {
        status = 2;
    }
    else if (points >= 17 && points < 21){
        status = 3;
    }
    else if (points == 21){
        status = 4;
    }
    else if (points > 21){
        status = 5;
    }
    
    return this->status;
}

bool Dealer::setStatus(int status){
    this->status = status;
    
    return true;
}

bool Dealer::hits(House* h){
    this->getHand()->getCard(h);
    
    return true;
}

bool Dealer::flipCard(){
    this->getHand()->fetchCard(2)->flip();
    
    return true;
}


int Dealer::getLastAction(){
    /*
     dealer's last actions
     1 - flipped 2nd card
     2 - hitted
     3 - standed
    */
    return this->lastAction;
}

bool Dealer::setLastAction(int action){
    this->lastAction = action;
    
    return true;
}
