#include "hand.h"

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
