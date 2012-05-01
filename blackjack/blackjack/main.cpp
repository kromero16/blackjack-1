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
    
    Hand mao;
    mao.getCard(&casa);
    mao.getCard(&casa);
    mao.getCard(&casa);
    mao.displayHand();
    
    cout << endl << endl;
    
    cout << "Valor da mao: " << mao.getTotal();
    mao.putCards(&casa);
    
    cout << endl << endl;
    
    casa.displayDeck();
    
    
    return 0;
}

