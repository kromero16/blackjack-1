//
//  card.h
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

#ifndef card_h
#define card_h

class Card {
    
    char suit; // 'O' ouros, 'C' copas, 'P' paus, 'E' espadas
    
    char value; // '2', '3' ... 'T' (ten) dez, 'J' valete, 'Q' dama, 'K' rei, 'A' as
    
    bool faceUp;
    
public:
    Card (char, char, bool);
    Card (char, char);
    char getValue();
    char getSuit();
    bool isUp();
    void flip();
    
};

#endif