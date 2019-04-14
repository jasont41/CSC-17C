/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: Jason
 *
 * Created on April 10, 2019, 9:23 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <stack>
#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

class Deck {
public:
    Deck();
    void makeDeck();
    void printDeck();
    void shufDeck(); 
    string drawCard();  
    void updateCurrentDeckCount(); 
    int getCurrentDeckCount(); 
    void vectToStack(); 
    Deck(const Deck& orig);
    virtual ~Deck();
private:
    int currentDeckCount;
    vector <string> deck;
    stack <string> gameDeck; 
    
};

#endif /* DECK_H */

