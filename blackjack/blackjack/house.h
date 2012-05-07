
#ifndef house_h
#define house_h

#include <queue>
#include <algorithm>
#include "card.h"
#include <iostream>
#include <ctime>

using namespace std;


class House{
    deque<Card> deck;
    
public:
    House();
    void displayDeck(); // debug
    bool populate();
    bool shuffle();
    Card putCard();
    bool getCard(Card);
    
};

#endif