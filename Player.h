/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Jason
 *
 * Created on April 11, 2019, 10:16 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iterator>
#include <iostream>
using namespace std; 

class Player {
public:
    Player();
    void printHand(); 
    void drawCard(string); 
    void storeSet(string); 
    void displayCompSets(); 
    int getSetCount(); 
    vector<string> recieveCard(vector<string>);  
    int getHandCount(); 
    void updateHandCount(); 
    void getIfSet(); 
    void searchHand(string,bool&,vector<string>&); 
    // ^ returning a pointer / many cases
    string requestCard();
    string requestCard(bool);
    Player(const Player& orig);
    virtual ~Player();
private:
    vector<string> hand;
    vector<string> sets;
    int handCount; 
    int setCount; 
};

#endif /* PLAYER_H */

