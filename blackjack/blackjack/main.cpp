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
    cout << "--------------- Blackjack --------------------" << endl;
    
    Game* game = new Game();
    
    getPlayers(game);
    setMinimBet(game);
    
    while( !game->over() ) {
        Round *round = game->playRound();
        displayWhoEntered(game);
        
        while (!round->over() ) {
            
            Dealer* dealer = round->getDealer();
            
            while (!round->allPlayersHaveBetted()) {
                Player* current_player = round->getCurrentPlayer();
                
                if (!current_player->hasBetted() ) {
                    current_player->makeBet( getBet(round->getMinimBet(), current_player) );
                }
            }
            
            while (!round->allPlayersAreDone() ) {
                
                Player* current_player = round->getCurrentPlayer();
                
                cout << "Dealer has " << dealer->getHand()->getTotal() << " points." << endl;
                
                drawCards(dealer->getHand() );
                cout << endl;
                
                cout << current_player->getName() << " has " << current_player->getHand()->getTotal() << " points." << endl;
                
                drawCards(current_player->getHand() );
                
                round->doAction( getPlayerOptions(current_player->getOptions() )   );
                
                drawPlayerStatus(current_player);
                cout << endl;
                wait(1);
                
            }
            
            while (!round->dealerIsDone()) {
                drawDealerAction(dealer);
                drawCards(dealer->getHand() );
                cout << "Dealer has " << dealer->getHand()->getTotal() << " points." << endl;
                drawDealerStatus(dealer);
                wait(3);
            }
            
            while (!round->moneyIsDistributed() ) {
                Player* current_player = round->getCurrentPlayer();
                displayResult(current_player);
            }
            
        }
        
        delete round;
        
        queryPlayersGiveUp(game);
        updatePlayers(game);
    }
    
    displayWinner(game->getWinner() );
    
    return 0;
}

