//
//  main.cpp
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

#include "main.h"


int main ()
{
    cout << "--------------- Blackjack --------------------" << endl << endl;
    
    Game* game = new Game();
    
    getPlayers(game);
    setMinimBet(game);
    
    while( !game->over() ) {
        Round *round = game->playRound();
        displayWhoEntered(game);
        
        while (!round->over() ) {
            
            Dealer* dealer = round->getDealer();
            
            cout << endl << "--------------- Betting Round ----------------" << endl << endl;
            
            while (!round->allPlayersHaveBetted()) {
                Player* current_player = round->getCurrentPlayer();
                
                if (!current_player->hasBetted() ) {
                    current_player->makeBet( getBet(round->getMinimBet(), current_player) );
                }
            }
            
            cout << "--------------- Round Start ------------------" << endl << endl;
            
            wait(1);
            
            while (!round->allPlayersAreDone() ) {
                
                Player* current_player;
                
                drawPlayerTurn(current_player, round);
                
                current_player = round->getCurrentPlayer();
                            
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
            
            cout << "------------- Dealer's turn ---------------" << endl << endl;
            
            while (!round->dealerIsDone()) {
                drawDealerAction(dealer);
                drawCards(dealer->getHand() );
                cout << "Dealer has " << dealer->getHand()->getTotal() << " points." << endl;
                drawDealerStatus(dealer);
                wait(3);
            }
            
            cout << endl << "--------------- Winnings ------------------" << endl << endl;
            
            while (!round->moneyIsDistributed() ) {
                Player* current_player = round->getCurrentPlayer();
                displayResult(current_player);
            }
            
        }
        
        delete round;
        
        queryPlayersGiveUp(game);
        updatePlayers(game);
    }
    
    cout << endl << "--------------- Game Over -----------------" << endl << endl;
    
    displayWinner(game->getWinner() );
    
    return 0;
}

