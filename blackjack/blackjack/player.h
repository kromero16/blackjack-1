#ifndef player_h
#define player_h

#include "hand.h"
#include "string.h"


class Player{
    string name;
    float balance;
    float bet;
    Hand* hand_ptr;
    int status;
    
public:
    Player (string, int);
    bool stands();
    bool hits();
    bool doubles();
    Hand* getHand();
    float getBalance();
    bool changeStatus(int);
    int getStatus();
    int getOptions();
    
};

#endif