#include "house.h"

House::House(){}

bool House::populate(){
    
    char naipe, valor;
    
    for (unsigned int n = 0; n <= 3; n++) { // os 4 naipes
        
        switch (n) {
            case 0:
                naipe = 'D';  // ouros - diamonds
                break;
            case 1:
                naipe = 'H';  // copas - hearts
                break;
            case 2:
                naipe = 'C';  // paus - clubs
                break;
            case 3:
                naipe = 'S';  // espadas - spades
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
                        valor = 'J';  // valete
                        break;
                    case 12:
                        valor = 'Q';  // dama
                        break;
                    case 13:
                        valor = 'K';  // rei
                        break;
                    case 14:
                        valor = 'A';  // as
                        break;
                    default:
                        break;
                }
            }
            
            deck.push_back( Card (valor, naipe) );
            
        }
        
    }
    
    return true;
}

bool House::shuffle() {
    
    srand (unsigned(time(NULL)));
    
	random_shuffle (deck.begin(), deck.end());
    
	return true;
    
}

Card House::putCard() {
    
	Card c(deck.front().getValue(), deck.front().getSuit(), deck.front().isUp());
	deck.pop_front();
	return c;
}

bool House::getCard(Card c){
    deck.push_back(c);
    return true;
}
