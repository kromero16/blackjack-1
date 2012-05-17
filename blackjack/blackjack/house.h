
#ifndef house_h
#define house_h

#include <queue>
#include <algorithm>
#include <iostream>
#include <ctime>

#include "card.h"

using namespace std;


class House{
    deque<Card> deck;
    
public:
    House();
    bool populate();
    bool shuffle();
    Card putCard();
    bool getCard(Card);
    
};

#endif