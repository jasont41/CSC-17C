/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Jason
 * 
 * Created on April 11, 2019, 10:16 AM
 */

#include <vector>

#include "Player.h"

Player::Player() {
    setCount = 0;
}

void Player::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i] << endl;
    }
}

void Player::drawCard(string temp) {
    hand.push_back(temp);
}

int Player::getSetCount() {
    return setCount;
}

void Player::updateHandCount() {
    handCount = hand.size();
}

string Player::requestCard() {
    cout << "Select what card do you need\n";
    int userInput;
    cout << hand.size() << endl;
    for (int i = 0; i < hand.size(); i++) {
        cout << i + 1 << "   " << hand[i] << endl;
    }
    do {
        cin >> userInput;
    } while (userInput < 1 || userInput > hand.size());
    return (hand[userInput - 1]);

}

int Player::getHandCount() {
    return hand.size();
}

void Player::displayCompSets() {
    for (int i = 0; i < sets.size(); i++) {
        cout << sets[i] << endl;
        cout << sets[i] << endl;
        cout << sets[i] << endl;
        cout << sets[i] << endl;
    }
}

string Player::requestCard(bool isComp) {
    if (isComp == true) {
        int play = rand() % hand.size() + 1;
        return hand[play - 1];
    } else if (isComp == false) {
        requestCard();
    }
}

vector<string> Player::recieveCard(vector<string> cards) {
    cout << "Size of incoming card vector " << cards.size() << endl; 
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i] << endl; 
        hand.push_back(cards[i]); 
    }
}

void Player::searchHand(string card, bool &isFound, vector<string>& foundCards) {
    int cardFreq = 0;
    vector<int>locations;
    getIfSet();
    for (int i = 0; i < hand.size(); i++) {
        string temp = hand[i];
        if (hand[i] == card) {
            cout << "It's a match!\n";
            foundCards.push_back(hand[i]);
            cardFreq++;
            isFound = true;

        } else if (cardFreq > 1) {
            //many cards case
            for (int j = 0; j < hand.size(); j++) {
                if (hand[i] == card) {
                    locations.push_back(i);
                }
            }
        }
    }
    if (cardFreq == 0) {
        //no card case
        cout << "Go Fish!\n";
        isFound = false;
    }
    for (int i = 0; i < locations.size(); i++) {
        hand.erase(hand.begin() + locations[i]);
    }
    if (isFound == true) {
        
    }
}


void Player::getIfSet() {
    /*
     * The idea her is that I will check every card in the hand for duplicates 
     * if there is, I will then increment freqOfCard. If it hits 4, I will then 
     * call storeSet or whatever I called that function arome
     * nd then create another 
     * function to then delete the cards I stored and then increment the 
     * set count variable 
     */
    for (int j = 0; j < hand.size(); j++) {
        string card = hand[j];
        vector<int>location;
        location.push_back(j);
        int freqOfCard = 1;
        for (int i = 0; i < hand.size(); i++) {
            if (card == hand[i] && i == j) {
                freqOfCard++;
                location.push_back(i);
            } else if (freqOfCard == 4) {
                storeSet(card);
                setCount++;
                for (int i = 0; i < 4; i++) {
                    hand.erase(hand.begin() + location[i]);
                }
            }
        }
    }
}

void Player::storeSet(string card) {
    sets.push_back(card);
    setCount++;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}