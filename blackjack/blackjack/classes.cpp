//
//  classes.cpp
//  blackjack
//
//  Created by pedro on 4/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "classes.h"


Card::Card(char v, char s, bool f){
    suit = s;
    value = v;
    faceUp = f;
}

Card::Card (char v, char s){
    suit = s;
    value = v;
    faceUp = false;
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



House::House(){}

bool House::populate(){
    
    char naipe, valor;
    
    for (unsigned int n = 0; n <= 4; n++) { // os 4 naipes
        
        switch (n) {
            case 0:
                naipe = 'O';  // ouros
                break;
            case 1:
                naipe = 'C';  // copas
                break;
            case 2:
                naipe = 'P';  // paus
                break;
            case 3:
                naipe = 'E';  // espadas
                break;
                
            default:
                break;
        }
        
        for (unsigned int v = 2; v <= 14; v++) {
            if (v <= 9){
                valor = v + 48;
            }
            else{
                switch (v) {
                    case 10:
                        valor = 'T';  // dez
                        break;
                    case 11:
                        valor = 'V';  // valete
                        break;
                    case 12:
                        valor = 'D';  // dama
                        break;
                    case 13:
                        valor = 'R';  // rei
                        break;
                    case 14:
                        valor = 'A';  // as
                    default:
                        break;
                }
            }
            
            deck.push ( Card (valor, naipe) );
            
        }
        
    }
    
    return true;
}