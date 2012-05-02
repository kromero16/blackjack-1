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
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <ctime>


using namespace std;

class Card {
    
    char suit; // 'O' ouros, 'C' copas, 'P' paus, 'E' espadas
    
    char value; // '2', '3' ... 'T' ten, 'V' valete, 'D' dama, 'R' rei, 'A' as
    
    bool faceUp;
    
public:
    Card (char, char, bool);
    Card (char, char);
    char getValue();
    char getSuit();
    bool isUp();
    void flip();
    
};

class House{
    deque<Card> deck;
    
public:
    House();
    void displayDeck(); // debug
    bool populate();
    bool shuffle();
    Card putCard();
    bool getCard(Card);
    
};

class Hand {
    vector<Card> vec_hand;
    
    
public:
    Hand ();
    vector<Card> getHand();
    void displayHand(); // debug
    int getTotal();
    void putCards(House*);
    bool getCard(House*);
    
};

class Player{
    string name;
    float balance;
    float bet;
    Hand* hand_ptr;
    bool inGame;
    
public:
    Player (string, int);
    bool stand();
    bool hit();
    bool doub(); // double
    Hand* getHand();
    bool isPlaying();
    
};

class Dealer{
    Hand* hand;
public:
    
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
