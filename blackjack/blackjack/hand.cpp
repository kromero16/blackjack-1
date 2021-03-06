//
//  hand.cpp
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

#include "hand.h"

Hand::Hand(){}


bool Hand::getCard(House* h){
    Card c = h->putCard();
    
    vec_hand.push_back(c); 
    
    return true;
    
}

bool Hand::getCardFlipped(House* h){
    Card c = h->putCard();
    
    c.flip();
    
    vec_hand.push_back(c);
    
    return true;
}

vector<Card> Hand::getCards(){
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
    vector<Card>::iterator card_iterator;
    int numOfAces = 0;
    int score = 0;
    
    for (card_iterator = vec_hand.begin(); card_iterator < vec_hand.end(); card_iterator++) {
        Card c = *card_iterator;
        char val[1];
        val[0] = c.getValue();
        
        if (c.isUp() ){
            
            if ( !isalpha(val[0]) ) {
                score += atoi(val);
            }
            else{
                switch (val[0]) {
                    case 'T':
                        score += 10;
                        break;
                    case 'Q':
                        score += 10;
                        break;
                    case 'J':
                        score += 10;
                        break;
                    case 'K':
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
    }
    
    if (numOfAces < 1) {
        return score;
    }
    else if (score > 21) {
        while (numOfAces > 0 && score > 21) {
            score -= 10;
            numOfAces -= 1;
        }
    }
    
    return score;
    
}

int Hand::getNumOfCards(){
    vector<Card>::iterator cards = this->vec_hand.begin();
    
    int numOfCards = 0;
    
    while (cards < vec_hand.end() ) {
        numOfCards++;
        cards++;
    }
    
    return numOfCards;
}

Card* Hand::fetchCard(int card_number){
    //warning example -> card number 2 == position 1 in vec_hand
    for (int number = 0; number <= card_number-1; number++) {
        if (number == card_number-1)
            return &vec_hand.at(number);
    }
    
    return &vec_hand.at(0);
}
