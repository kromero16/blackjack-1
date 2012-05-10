#ifndef dealer_h
#define dealer_h

#include "hand.h"

class Dealer{
    Hand* hand;
    int status;
    int lastAction;
    
public:
    Dealer();
    Hand* getHand();
    int getStatus();
    bool setStatus(int);
    bool hits(House*);
    bool flipCard();
    int getLastAction();
    bool setLastAction(int);
};

#endif