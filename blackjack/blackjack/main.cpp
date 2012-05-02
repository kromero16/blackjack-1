//
//  main.cpp
//  blackjack
//
//  Created by pedro on 4/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "main.h"

int main ()
{
    House casa;
    casa.populate();
    casa.shuffle();
    
    casa.displayDeck();

    cout << endl << endl;
    
    Player p1 ("Pedro", 50);
    p1.getHand()->getCard(&casa);
    p1.getHand()->getCard(&casa);
    p1.getHand()->getCard(&casa);
    p1.getHand()->displayHand();
    
    cout << endl << endl;
    
    cout << "Valor da mao: " << p1.getHand()->getTotal();
    p1.getHand()->putCards(&casa);
    
    cout << endl << endl;
    
    casa.displayDeck();
    
    
    return 0;
}

