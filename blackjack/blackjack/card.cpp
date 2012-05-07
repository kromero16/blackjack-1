#include "card.h"

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
