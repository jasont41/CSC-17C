/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.cpp
 * Author: Jason
 * 
 * Created on April 11, 2019, 12:48 PM
 */

#include "game.h"

game::game() {
    turnCount = 0;
    turnOver = false;
    deck.shufDeck(); 
    gameLoop();
}

int game::updateTurnCount() {
    turnCount++;
}

bool game::gameLoop() {
    for (int i = 0; i < 7; i++) {
        playerOne.drawCard(deck.drawCard());
        playerTwo.drawCard(deck.drawCard());
    }
    do {

        if (playerOne.getSetCount() == 0 || playerTwo.getSetCount() == 0) {
            cout << "There are no completed sets at this time\n";
        } else {
            cout << "The following are the completed sets at this time\n";
            playerOne.displayCompSets();
            playerTwo.displayCompSets();
        }
        do {
            char moveOn;
            vector<string> foundCards;
            bool isFound;
            bool isComp = false;
            updateTurnCount();
            cout << "Turn Number: " << turnCount << endl;
            cout << "Current Cards in the deck: " << deck.getCurrentDeckCount() << endl;
            if (turnCount % 2 != 0) {
                cout << "Player one's turn\n";
                //cout << "This is the comp for testing purposes\n";
                //playerTwo.printHand();
                string temp = playerOne.requestCard();
                cout << "Now searching player two's hand\n";
                playerTwo.searchHand(temp, isFound, foundCards);
                if (isFound == true) {
                    for (int i = 0; i < foundCards.size(); i++) {
                        playerOne.drawCard(foundCards[i]);
                    }
                } else if (isFound == false) {
                    playerOne.drawCard(deck.drawCard());
                }
            } else if (turnCount % 2 == 0) {
                isComp = true;
                cout << "Player Two's Turn\n";
                string temp = playerTwo.requestCard(isComp);
                playerOne.searchHand(temp, isFound, foundCards);
                if (isFound == true) {
                    playerTwo.recieveCard(foundCards);
                } else if (isFound == false) {
                    playerTwo.drawCard(deck.drawCard());
                }
            }


            turnOver = true;
        } while (turnOver == false);
    } while (playerOne.getHandCount() != 0 || playerTwo.getHandCount() != 0);

    if (playerOne.getHandCount() == 0) {
        winner = "PlayerOne"; 
    }
    else if(playerTwo.getHandCount() == 0){
        winner = "PlayerTwo"; 
    }
    if (playerOne.getHandCount() == 0) {
        cout << "Player One wins!" << endl;
        return true;
    } else if (playerTwo.getHandCount() == 0) {
        cout << "Oh well you lost to the computer :/\n";
        return true;
    }
}

game::game(const game & orig) {
}

game::~game() {
}

