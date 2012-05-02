//
//  main.cpp
//  blackjack
//
//  Created by pedro on 4/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "main.h"

vector<Player> getPlayers(){
   
    vector<Player> vec_players;
    
    string name;
    float saldo;
    
    cout << "Defina jogadores. CTRL-Z (windows) ou CTRL-D (mac/linux) para sair." << endl;
    
    while (1) {
        cout << "Indique o nome do jogador:" << endl << PROMPT;
        cin >> name;
        if (cin.eof()) {
            break;
        }
        cout << "Saldo desse jogador?" << endl << PROMPT;
        cin >> saldo;
        if (cin.eof()) {
            break;
        }
        
        vec_players.push_back(Player(name, saldo));
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "players returned!";
    
    return vec_players;
}

int main ()
{
    
    cout << "--------------- Blackjack --------------------" << endl;
    
    Game* game = new Game( getPlayers() );
    
    if ( !game->over() ) {
        game->playRound();
    }
    
    // DEBUG
    
    /* House casa;
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
     
    */
    
    
    return 0;
}

