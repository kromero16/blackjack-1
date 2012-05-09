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

int setApostaMinima(){
	int aposta;

	cout << "Defina aposta minima (valor inteiro positivo)" << endl << PROMPT;
	cin >> aposta;

	while(!cin.good() || aposta <= 0){
		cout << "Por favor, atribua um valor plausivel (inteiro positivo) para a aposta minima" << endl << PROMPT;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> aposta;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return aposta;
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

void drawCards(Player* p){
    vector<Card> hand = p->getHand()->getCards();
    
    vector<Card>::iterator card_iterator = hand.begin();
    
    char s, v;
    string suit, value;
    
    vector<char> suits, values;
    

    for (vector<Card>::iterator card_iterator = hand.begin(); card_iterator < hand.end(); card_iterator++) {
        s = card_iterator->getSuit();
        v = card_iterator->getValue();
        
        suits.push_back(s);
        values.push_back(v);


        /*switch (s) {
            case 'E':
                suit = "Espadas";
                break;
            case 'O':
                suit = "Ouros";
                break;
            case 'C':
                suit = "Copas";
                break;
            case 'P':
                suit = "Paus";
                break;
            default:
                break;
        }
        
        switch (v) {
            case '2':
                value = "Dois";
                break;
            case '3':
                value = "Tres";
                break;
            case '4':
                value = "Quatro";
                break;
            case '5':
                value = "Cinco";
                break;
            case '6':
                value = "Seis";
                break;
            case '7':
                value = "Sete";
                break;
            case '8':
                value = "Oito";
                break;
            case '9':
                value = "Nove";
                break;
            case 'T':
                value = "Dez";
                break;
            case 'V':
                value = "Valete";
                break;
            case 'D':
                value = "Dama";
                break;
            case 'R':
                value = "Rei";
                break;
            case 'A':
                value = "As";
                break;
            default:
                break;
        }*/


    }

    for(unsigned int i = 0; i < suits.size(); ++i){
    	   	cout << ",---,";
    }

    cout << endl;

    for(unsigned int i = 0; i < suits.size(); ++i){
       	 if(values.at(i) == 'T'){
       	   	cout << "|10 |";
       	 }
       	 else cout << "|" << (char) values.at(i) <<"  |";
    }

    cout << endl;

    for(unsigned int i = 0; i < suits.size(); ++i){
         cout << "|  " << (char) suits.at(i) <<"|";
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
            drawCards(p);
            break;
        case 4:
            cout << name << " has doubled and now has " << p->getHand()->getTotal() << " points!" << endl;
            drawCards(p);
            break;
        case 5:
            cout << name << " has a blackjack!" << endl;
            if (p->getHand()->getNumOfCards() != 2) {
                drawCards(p);
            }
            break;
        default:
            break;
    }
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
            
            while (!round->currentPlayerIsDone()) {
                
                Player* current_player = round->getCurrentPlayer();
                
                drawCards(current_player);
                
                cout << current_player->getHand()->getTotal() << " pontos" << endl;
                
                round->doAction( getPlayerOptions(current_player->getOptions() )   );
                
                drawPlayerStatus(current_player);
                
            }
           
            break;
        }
        
        break;
    }
    
    
    
    return 0;
}

