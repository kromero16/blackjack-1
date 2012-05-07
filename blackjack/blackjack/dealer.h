#ifndef dealer_h
#define dealer_h

#include "hand.h"

class Dealer{
    Hand* hand;
public:
    Dealer();
    Hand* getHand();
};

#endif