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
    unsigned int numOfPlayers;
    
    cout << "Quantos jogadores vão participar?" << endl << PROMPT;
    
    cin >> numOfPlayers;
    while(cin.fail()) {
        cout << "Numero invalido. Introduza novamente." << endl << PROMPT;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numOfPlayers;
    }

    
    for (unsigned int n = 1; n <= numOfPlayers; n++){
        cout << "Indique o nome do " << n << "o jogador: "<< endl << PROMPT;
        cin >> name;
        while(cin.fail()) {
            cout << "Nome invalido. Introduza novamente." << endl << PROMPT;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> name;
        }
        cout << "Saldo desse jogador?" << endl << PROMPT;
        cin >> saldo;
        while(cin.fail()) {
            cout << "Saldo invalido. Introduza novamente." << endl << PROMPT;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> saldo;
           
        }
        
        vec_players.push_back(Player(name, saldo));
    }
    
    return vec_players;
}

int setMinimBet(){
	int bet;

	cout << "Defina aposta minima (valor inteiro positivo)" << endl << PROMPT;
	cin >> bet;

	while(!cin.good() || bet <= 0){
		cout << "Por favor, atribua um valor plausivel (inteiro positivo) para a aposta minima" << endl << PROMPT;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> bet;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return bet;
}

int getPlayerOptions(int options){
    unsigned int choice = 0;
    
    switch (options) {
        case 1:
            cout << "1. Stand" << endl;
            cout << "2. Hit" << endl;
            cout << PROMPT;
            cin >> choice;
            while( (cin.fail() || choice > 2) || choice < 1 ) {
                cout << "Escolha invalida." << endl << PROMPT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
            break;
        case 2:
            cout << "1. Stand" << endl;
            cout << "2. Hit" << endl;
            cout << "3. Double" << endl;
            cout << PROMPT;
            cin >> choice;
            while( (cin.fail() || choice > 3) || choice < 1 ) {
                cout << "Escolha invalida." << endl << PROMPT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
            break;
        case 3:
            //has blackjack
            break;
        default:
            cout << "Erro";
            return 0;
            break;
    }
    
    return choice;
}

void drawCards(Hand* h){
    vector<Card> hand = h->getCards();
    
    //vector<Card>::iterator card_iterator = hand.begin();
    
    char s, v;
    bool faceUp;
    
    vector<char> suits, values;
    vector<bool> visible;
    

    for (vector<Card>::iterator card_iterator = hand.begin(); card_iterator < hand.end(); card_iterator++) {
        s = card_iterator->getSuit();
        v = card_iterator->getValue();
        faceUp = card_iterator->isUp();
        
        suits.push_back(s);
        values.push_back(v);
        visible.push_back(faceUp);
    }

    for(unsigned int i = 0; i < suits.size(); ++i){
    	   	cout << ",---,";
    }

    cout << endl;

    for(unsigned int i = 0; i < suits.size(); ++i){
        if (visible.at(i) == false) {
            cout << "| //|";
        }
        else if(values.at(i) == 'T'){
       	   	cout << "|10 |";
        }
        else 
            cout << "|" << (char) values.at(i) << "  |";
    }

    cout << endl;

    for(unsigned int i = 0; i < suits.size(); ++i){
        if (visible.at(i) == false) {
            cout << "|// |"; 
        }
        else
            cout << "|  " << (char) suits.at(i) << "|";
    }
    
    cout << endl;

    for(unsigned int i = 0; i < suits.size(); ++i){
         cout << "'---'";
    }

    cout << endl;
}

void drawPlayerStatus(Player* p){
    int status = p->getStatus();
    string name = p->getName();
    
    
    switch (status) {
        case 1:
            cout << name << " hits!" << endl;
            break;
        case 2:
            cout << name << " is standing!" << endl;
            break;
        case 3:
            cout << name << " has busted with " << p->getHand()->getTotal() << " points!" << endl;
            drawCards(p->getHand() );
            break;
        case 4:
            cout << name << " has doubled and now has " << p->getHand()->getTotal() << " points!" << endl;
            drawCards(p->getHand() );
            break;
        case 5:
            cout << name << " has a blackjack!" << endl;
            if (p->getHand()->getNumOfCards() != 2) {
                drawCards(p->getHand() );
            }
            break;
        default:
            break;
    }
}

float getBet(float min, Player* player){
    float bet = 0;
    float player_balance = player->getBalance();
    string name = player->getName();
    
    cout << name << ", quanto queres apostar? (Saldo: " << player->getBalance() << " / Aposta minima: " << min << ")" << endl << PROMPT;
    cin >> bet;
    
    while (  (cin.fail() || bet < min ) || bet > player_balance ) {
        cout << "Aposta invalida. Introduza novamente:" << endl << PROMPT;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> bet;
    }
    
    return bet;
}

void drawDealerAction(Dealer* d){
    int action = d->getLastAction();
    
    switch (action) {
        case 1:
            cout << "The dealer flips his card!" << endl;
            break;
        case 2:
            cout << "The dealer hits!" << endl;
            break;
        case 3:
            cout << "The dealer stands!" << endl;
            break;
        default:
            break;
    }
    
    return;
}

void drawDealerStatus(Dealer* d){
    int status = d->getStatus();
    
    switch (status) {
        case 4:
            cout << "The Dealer has blackjack!" << endl;
            break;
        case 5:
            cout << "The Dealer is bust!" << endl;
            break;
        default:
            break;
    }
}

void wait ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait){}
}

void displayResult(Player* p){
    string name = p->getName(); 
    float winnings = p->getLatestWinnings();
    
    if (winnings < 0) {
        cout << name << " lost his bet, " << -winnings << " credits." << endl;
    }
    else
        cout << name << " has won " << winnings << " credits!" << endl;

}

void displayWinner(Player* p){
    string name = p->getName();
    float balance = p->getBalance();
    
    cout << name << " has won the game with " << balance << " credits!";
    
    return;
}

int main ()
{
    
    cout << "--------------- Blackjack --------------------" << endl;
    
    //Game *game = new Game(getPlayers(), setApostaMinima());
    
       // para testar rapidamente sem escolher players
    vector<Player> teste;
    teste.push_back(Player("Pedro", 10));
    teste.push_back(Player("Diogo", 10));
    Game *game = new Game(teste, 5);
    
    while( !game->over() ) {
        Round *round = game->playRound();
        
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
            
            round->over();

        }
        
        delete round;
    }
    
    displayWinner(game->getWinner() );
    
    return 0;
}

