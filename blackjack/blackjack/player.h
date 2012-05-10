#ifndef player_h
#define player_h

#include "hand.h"
#include "string.h"
#include "house.h"

class Player{
    string name;
    int bet;
    int balance;
    Hand* hand_ptr;
    int status;
    
public:
    Player (string, int);
    bool stands();
    bool hits(House*);
    bool doubles(House*);
    Hand* getHand();
    float getBalance();
    bool changeStatus(int);
    int getStatus();
    int getOptions();
    string getName();
    bool makeBet(float);
    
};

#endif