//
//  card.cpp
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


#include "card.h"

Card::Card(char v, char s, bool f){
    suit = s;
    value = v;
    faceUp = f;
}

Card::Card(char v, char s){
    suit = s;
    value = v;
    faceUp = true;
}

char Card::getValue(){
    return value;
}

char Card::getSuit(){
    return suit;
}

bool Card::isUp(){
    return faceUp;
}

void Card::flip(){
    if (faceUp)
        faceUp = false;
    else
        faceUp = true;
    
    return;
}
