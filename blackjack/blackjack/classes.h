//
//  classes.h
//  blackjack
//
//  Created by pedro on 4/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef classes_h
#define classes_h

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Card {
    
    char suit; // 'O' ouros, 'C' copas, 'P' paus, 'E' espadas
    
    char value; // '2', '3' ... 'T' ten, 'V' valete, 'D' dama, 'R' rei, 'A' as
    
    bool faceUp;
    
public:
    Card (char suit, char value, bool faceUp);
    Card (char suit, char value);
    char getValue();
    char getSuit();
    bool isUp();
    void flip();
    
};

class Hand {
    vector<Card> hand;
    
public:
    Hand ();
    int getTotal();
    void clear();
    bool addCard(Card card);
    
};

class Player{
    string name;
    float balance;
    float bet;
    Hand* hand;
    bool inGame;
    
public:
    Player (string name, int balance);
    bool stand();
    bool hit();
    bool doub(); // double
    Hand getHand();
    bool isPlaying();
    
};

class Dealer{
    Hand* hand;
public:
    
};

class House{
    queue<Card> deck;
    
public:
    bool populate();
    bool shuffle();  // check function random_shuffle() !;
    bool giveCard();
    bool getCard();
    
};

class Round{
	vector<Player> active_players;

public:
	Player* getNextPlayer();
	int getPlay(Player*);

};

class Game{
    vector<Player> players;
    bool gameOver;

public:
    Game();
    int inGameNumber();
    Round* playRound();
    bool addPlayers();
};


#endif
