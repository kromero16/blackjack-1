#include "house.h"

House::House(){}

bool House::populate(){
    
    char naipe, valor;
    
    for (unsigned int n = 0; n <= 3; n++) { // os 4 naipes
        
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
    
	random_shuffle (deck.begin(), deck.end());
    
	return true;
    
}

void House::displayDeck(){
    deque<Card>::iterator it;
    it = deck.begin();
    
    while (it != deck.end() ) {
        Card c = *it;
        cout << c.getValue() << " " << c.getSuit() << " | ";
        it++;
    }
    
    return;
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
