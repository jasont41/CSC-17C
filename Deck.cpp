/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.cpp
 * Author: Jason
 * 
 * Created on April 10, 2019, 9:23 PM
 */

#include "Deck.h"
Deck::Deck() {
    makeDeck();
    shufDeck(); 
    vectToStack(); 
    currentDeckCount = 52;
}

void Deck::makeDeck() {
    string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    //put all the suit values in an array as strings
    //string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (int i = 0; i < 52; i++) {
        string temp = faces[i%13];
        deck.push_back(temp); 
    }
}

void Deck::printDeck() {
    for(int i = 0; i < currentDeckCount; i++){
        cout << deck[i] << endl;
    }
}

void Deck::shufDeck() {
    srand(time(0)); 
    for (int i=0; i<52 ;i++) 
    { 
        // Random for remaining positions. 
        int r = i + (rand() % (52 -i)); 
        swap(deck[i], deck[r]); 
    } 
}

string Deck::drawCard() {
    string temp = gameDeck.top();  
    gameDeck.pop(); 
    updateCurrentDeckCount();
    return temp; 
}



void Deck::vectToStack() {
    for(int i = 0; i < deck.size(); i++){
        gameDeck.push(deck[i]); 
    }
    //take out the trash/delete previous vector 
    deck.clear(); 
}

int Deck::getCurrentDeckCount() {
    return currentDeckCount; 
}

void Deck::updateCurrentDeckCount() {
    currentDeckCount = gameDeck.size(); 
}




Deck::Deck(const Deck& orig) {
}

Deck::~Deck() {
}