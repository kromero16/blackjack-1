//
//  classes.cpp
//  blackjack
//
//  Created by pedro on 4/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "classes.h"


Card::Card(char v, char s, bool f){
    suit = s;
    value = v;
    faceUp = f;
}

Card::Card (char v, char s){
    suit = s;
    value = v;
    faceUp = false;
}

char Card::getValue(){
    return value;
}

char Card::getSuit(){
    return suit;
}

bool Card::isUp(){
    return faceUp;
}

void Card::flip(){
    if (faceUp)
        faceUp = false;
    else
        faceUp = true;
    
    return;
}



House::House(){}

bool House::populate(){
    
    char naipe, valor;
    
    for (unsigned int n = 0; n <= 3; n++) { // os 4 naipes
        
        switch (n) {
            case 0:
                naipe = 'O';  // ouros
                break;
            case 1:
                naipe = 'C';  // copas
                break;
            case 2:
                naipe = 'P';  // paus
                break;
            case 3:
                naipe = 'E';  // espadas
                break;
            default:
                break;
        }
        
        for (unsigned int v = 2; v <= 14; v++) {
            if (v <= 9){
                valor = v + 48;
            }
            else{
                switch (v) {
                    case 10:
                        valor = 'T';  // dez
                        break;
                    case 11:
                        valor = 'V';  // valete
                        break;
                    case 12:
                        valor = 'D';  // dama
                        break;
                    case 13:
                        valor = 'R';  // rei
                        break;
                    case 14:
                        valor = 'A';  // as
                        break;
                    default:
                        break;
                }
            }
            
            deck.push_back( Card (valor, naipe) );
            
        }
        
    }
    
    return true;
}

bool House::shuffle() {

	srand (unsigned(time(NULL)));

	random_shuffle (deck.begin(), deck.end());

	return true;

}

void House::displayDeck(){
    deque<Card>::iterator it;
    it = deck.begin();
    
    while (it != deck.end() ) {
        Card c = *it;
        cout << c.getValue() << " " << c.getSuit() << " | ";
        it++;
    }
    
    return;
}

Card House::putCard() {

	Card c(deck.front().getValue(), deck.front().getSuit(), deck.front().isUp());
	deck.pop_front();
	return c;
}

bool House::getCard(Card c){
    deck.push_back(c);
    return true;
}




Hand::Hand(){}

void Hand::displayHand(){   //debug
    vector<Card>::iterator it;
    
    for (it=vec_hand.begin(); it < vec_hand.end(); it++) {
        Card c = *it;
        cout << c.getValue() << " " << c.getSuit() << " - ";
    }
    
    return;
}

bool Hand::getCard(House* h){
    Card c = h->putCard();
    
    vec_hand.push_back(c); 
    
    return true;
    
}

vector<Card> Hand::getHand(){
    return vec_hand;
}

void Hand::putCards(House* h){
    vector<Card>::iterator it;
    
    for (it = vec_hand.begin(); it < vec_hand.end(); it++) {
        Card c = *it;
        h->getCard(c);
    }
    
    vec_hand.clear();
    
    return;
}


int Hand::getTotal(){
    vector<Card>::iterator it;
    int numOfAces = 0;
    int score = 0;
    
    for (it = vec_hand.begin(); it < vec_hand.end(); it++) {
        Card c = *it;
        char val[1];
        val[0] = c.getValue();
        
        if ( atoi(val) != 0 ) {
            score += atoi(val);
        }
        else{
            switch (val[0]) {
                case 'T':
                    score += 10;
                    break;
                case 'D':
                    score += 10;
                    break;
                case 'V':
                    score += 10;
                    break;
                case 'R':
                    score += 10;
                    break;
                case 'A':
                    score += 11;
                    numOfAces += 1;
                    break;
                default:
                    return -1;
                    break;
            }
        }
    }
    
    if (numOfAces < 1) {
        return score;
    }
    else if (score > 21) {
        do {
            score -= 10;
            numOfAces -= 1;
        } while (numOfAces > 0 || score > 21);
    }
    
    return score;
    
}

Player::Player (string n, int b){
    name = n;
    balance = b;
    hand_ptr = new Hand;
    
}

Hand* Player::getHand(){
    return hand_ptr;
}

