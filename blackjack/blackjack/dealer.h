//
//  dealer.h
//
//  Projeto 2 PROG
//
//  Turma 6 Grupo 4 
//
//  Diogo Eiras - ei11087
//  IDE - Eclipse, Visual Studio
//
//  Pedro Fernandes - ei11122
//  IDE - Xcode
//

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