#ifndef player_h
#define player_h

#include "hand.h"
#include "string.h"
#include "house.h"

class Player{
    string name;
    float bet;
    float balance;
    Hand* hand_ptr;
    int status;
    float latest_winnings;
    
public:
    Player (string, float);
    Hand* getHand();
    float getBalance();
    string getName();
    bool stands();
    bool hits(House*);
    bool doubles(House*);
    bool changeStatus(int);
    int getStatus();
    int getOptions();
    bool makeBet(float);
    bool hasBetted();
    float getBet();
    bool updateBalance(float);
    float getLatestWinnings();
    bool lost();
    bool giveUp();
    
};

#endif