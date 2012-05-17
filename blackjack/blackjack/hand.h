#ifndef hand_h
#define hand_h

#include <vector>
#include <cctype>
#include "hand.h"
#include "house.h"
#include <iostream>

using namespace std;

class Hand {
    vector<Card> vec_hand;
    
    
public:
    Hand ();
    bool getCard(House*);
    bool getCardFlipped(House*);
    vector<Card> getCards();
    void putCards(House*);
    int getTotal();
    int getNumOfCards();
    Card* fetchCard(int);
    
};


#endif
