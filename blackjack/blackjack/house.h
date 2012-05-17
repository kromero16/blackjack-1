//
//  house.h
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