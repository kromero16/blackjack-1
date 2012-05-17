//
//  ui.cpp
//  blackjack
//
//  Created by Pedro Fernandes on 5/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ui.h"

void getPlayers(Game* game){
    
    string name;
    float saldo;
    unsigned int numOfPlayers;
    ifstream playersFileRead;
    ofstream playersFileWrite;

    playersFileRead.open("players.txt");
    
    if (!playersFileRead.is_open()){

		playersFileWrite.open("players.txt");
		playersFileWrite << "Saldo # Nome";

		cout << "How many players will participate?" << endl << PROMPT;

		cin >> numOfPlayers;
		while(cin.fail()) {
			cout << "Invalid number. Please select again." << endl << PROMPT;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numOfPlayers;
		}


		for (unsigned int n = 1; n <= numOfPlayers; n++){
			cout << "What's the name of player number " << n << " ?"<< endl << PROMPT;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cin.clear();

			cout << "How much cash " << name << " will be playing with?" << endl << PROMPT;
			cin >> saldo;
			while(cin.fail() || saldo <= 0) {
				cout << "Invalid amount. Please select again." << endl << PROMPT;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> saldo;

			}
			playersFileWrite << endl << saldo << " " << name;
			game->addPlayer(name, saldo);
		}

		playersFileWrite.close();
		return;
    }
    else {
    	string name;
    	float balance;

    	playersFileRead.ignore(numeric_limits<streamsize>::max(), '\n');

    	while(!playersFileRead.eof()){
    		playersFileRead >> balance;
            playersFileRead.get();
    		getline(playersFileRead, name);
    		game->addPlayer(name,balance);
    	}

    	playersFileRead.close();
    }
}

void setMinimBet(Game* game){
	float bet;
    
	cout << "How much is the minimum bet for this game?" << endl << PROMPT;
	cin >> bet;
    
	while(!cin.good() || bet <= 0){
		cout << "Invalid amount. Please input a positive number." << endl << PROMPT;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> bet;
	}
    
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
	game->setMinimBet(bet);
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
                cout << "Invalid choice." << endl << PROMPT;
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
                cout << "Invalid choice." << endl << PROMPT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
            break;
        case 3:
            //has blackjack
            break;
        default:
            cout << "Error";
            return 0;
            break;
    }
    
    return choice;
}

void drawCards(Hand* h){
    vector<Card> hand = h->getCards();
        
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
        cout << ".---.";
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
        else{
            cout << "|  ";
            switch (suits.at(i) ) {
                case 'S':
                    #ifdef _MSC_VER
                    _setmode(_fileno(stdout), _O_WTEXT);
					wcout << L"\u2660";
                    _setmode(_fileno(stdout), _O_TEXT);
                    #elif _WIN32
                    cout << 'S';  // spades - espadas
                    #else
                    cout << "\u2660";
                    #endif
                    break;
                case 'H':
                    #ifdef _MSC_VER
                    _setmode(_fileno(stdout), _O_WTEXT);
					wcout << L"\u2665";
                    _setmode(_fileno(stdout), _O_TEXT);
                    #elif _WIN32
                    cout << 'H'; // hearts - copas
                    #else
                    cout << "\u2665";
                    #endif
                    break;
                case 'D':
                    #ifdef _MSC_VER
                    _setmode(_fileno(stdout), _O_WTEXT);
					wcout << L"\u2666";
                    _setmode(_fileno(stdout), _O_TEXT);
                    #elif _WIN32
                    cout << 'D';  // diamonds - ouros
                    #else
                    cout << "\u2666";
                    #endif
                    break;
                case 'C':
                    #ifdef _MSC_VER
                    _setmode(_fileno(stdout), _O_WTEXT);
					wcout << L"\u2663";
                    _setmode(_fileno(stdout), _O_TEXT);
                    #elif _WIN32
                    cout << 'C';  // clubs - paus
                    #else
                    cout << "\u2663";
                    #endif
                    break;
                default:
                    break;
            }
            cout << "|";
        }
    }
    
    cout << endl;
    
    for(unsigned int i = 0; i < suits.size(); ++i){
        cout << "`---'";
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
            cout << name << " is bust with " << p->getHand()->getTotal() << " points!" << endl;
            drawCards(p->getHand() );
            wait(2);
            break;
        case 4:
            cout << name << " has doubled and now has " << p->getHand()->getTotal() << " points!" << endl;
            drawCards(p->getHand() );
            wait(2);
            break;
        case 5:
            cout << name << " has a blackjack!" << endl;
            if (p->getHand()->getNumOfCards() != 2) {
                drawCards(p->getHand() );
            }
            wait(2);
            break;
        default:
            break;
    }
}

float getBet(float min, Player* player){
    float bet = 0;
    float player_balance = player->getBalance();
    string name = player->getName();
    
    cout << name << ", how much do you want to bet? (Balance: " << player->getBalance() << " / Minimum bet: " << min << ")" << endl << PROMPT;
    cin >> bet;
    
    while (  (cin.fail() || bet < min ) || bet > player_balance ) {
        cout << "Invalid bet. Please choose a valid number." << endl << PROMPT;
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
    
    // esta funcao foi encontrada em
    // http://www.cplusplus.com/reference/clibrary/ctime/clock/
}


void displayResult(Player* p){
    string name = p->getName(); 
    float winnings = p->getLatestWinnings();
    
    if (winnings < 0 && p->lost() ) {
        cout << name << " lost his bet, " << -winnings << " credits. And lost the game." << endl;
    }
    else if (winnings < 0){
        cout << name << " lost his bet, " << -winnings << " credits." << endl;
    }
    else
        cout << name << " won " << winnings << " credits!" << endl;
    
}

void displayWinner(Player* p){
    if (p == NULL) {
        cout << "No one won the game." << endl;
        return;
    }
    
    string name = p->getName();
    float balance = p->getBalance();
    
    cout << name << " won the game with " << balance << " credits!" << endl << endl;
    
    cout << "Press any key to close...";
    
    cin.get();
    
    return;
}

void displayWhoEntered(Game* game){
    vector<Player*> players_entered_round = game->getPlayersEnteredThisRound();
    if (players_entered_round.size() == 0) {
        return;
    }
    else{
        for (int i = 0; i < players_entered_round.size(); i++) {
            cout << players_entered_round.at(i)->getName() << " has entered the game!" << endl;
        }
    }
    return;
}

void queryPlayersGiveUp(Game* game){
    cout << "Is there a player who wants to give up? (Y/N)" << endl << PROMPT;
    
    char ans;
    
    cin.ignore(numeric_limits<int>::max(),'\n');
    cin.get(ans);
    
    while (toupper(ans) != 'Y' && toupper(ans) != 'N') {
        cout << "Invalid confirmation. Please choose 'y' or 'n' " << endl << PROMPT;
        cin.ignore(numeric_limits<int>::max(),'\n');
        cin.get(ans);
    }
    
    if (toupper(ans) == 'Y'){
        
        while (1) {
            
            int choice;
            
            vector<Player*> players = game->getActivePlayers();
            
            cout << "Who will give up? Choose a number." << endl;
            cout << "0. Cancel" << endl;
            for (int i = 0; i < players.size(); i++) {
                cout << i+1 << ". " << players.at(i)->getName() << endl;
            }
            
            cout << PROMPT;
            
            cin >> choice;
            
            while (  (cin.fail() || choice < 0 ) || choice > players.size() ) {
                cout << "Invalid choice. Choose again." << endl << PROMPT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
            if (choice == 0){
                cout << "No one left the game." << endl;
                return;
            }
            else{
                players.at(choice-1)->giveUp();
                cout << players.at(choice-1)->getName() << " has left the game." << endl;
                cout << "Is there another player who wants to give up? (Y/N)" << endl << PROMPT;
                ans = ' ';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get(ans);
                
                while (toupper(ans) != 'Y' && toupper(ans) != 'N') {
                    cout << "Invalid confirmation. Please choose 'y' or 'n' " << endl << PROMPT;
                    cin.ignore(numeric_limits<int>::max(),'\n');
                    cin.get(ans);
                }
                
                if (toupper(ans) == 'N') {
                    break;
                }
                
            }
            
        }
        
    }
    else if (toupper(ans) == 'N'){
        return;
    }
    
    return;
}

void updatePlayers(Game* game){
    ofstream playersFileWrite;
    
    playersFileWrite.open("players.txt");
    playersFileWrite << "Balance # Name";
    
    vector<Player> players = game->getPlayers();
    
    for (unsigned int n = 0; n < players.size(); n++){
        playersFileWrite << endl << players.at(n).getBalance() << " " << players.at(n).getName();
    }
    
    playersFileWrite.close();
    return;

}

void drawPlayerTurn(Player* current_player, Round* round){
    if (current_player != round->getCurrentPlayer() ) {
        cout << "--------------- " << round->getCurrentPlayer()->getName() << "'s turn -----------------" << endl << endl;
    }
    return;
}
