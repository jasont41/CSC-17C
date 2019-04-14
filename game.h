/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: Jason
 *
 * Created on April 11, 2019, 12:48 PM
 */

#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;
class game {
public:
    game();
    bool gameLoop(); 
    updateTurnCount(); 
    string getWinner(){
        return winner;
    }
    game(const game& orig);
    virtual ~game();
private:
    int turnCount; 
    Player playerOne;
    Player playerTwo; 
    bool turnOver; 
    Deck deck;
    string winner; 
};

#endif /* GAME_H */

