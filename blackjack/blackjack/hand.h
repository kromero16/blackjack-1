#ifndef hand_h
#define hand_h

#include <vector>
#include "hand.h"
#include "house.h"
#include <iostream>

using namespace std;

class Hand {
    vector<Card> vec_hand;
    
    
public:
    Hand ();
    vector<Card> getHand();
    void displayHand(); // debug
    int getTotal();
    void putCards(House*);
    bool getCard(House*);
    
};


#endif