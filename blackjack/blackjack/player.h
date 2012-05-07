#ifndef player_h
#define player_h

#include "hand.h"
#include "string.h"


class Player{
    string name;
    float balance;
    float bet;
    Hand* hand_ptr;
    bool isStanding;
    
public:
    Player (string, int);
    bool stand();
    bool hit();
    bool doub(); // double
    Hand* getHand();
    float getBalance();
    
};

#endif