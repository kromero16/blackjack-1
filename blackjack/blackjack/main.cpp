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
    
    for (int n = 1; n <= numOfPlayers; n++){
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

int main ()
{
    
    cout << "--------------- Blackjack --------------------" << endl;
    
    Game *game = new Game(getPlayers(), setApostaMinima());
    
    while( !game->over() ) {
        Round *round = game->playRound();
        
        
        
    }
    
    
    
    return 0;
}

