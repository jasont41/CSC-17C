/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on April 10, 2019, 1:45 PM
 */

#include <cstdlib>
#include <iostream> // i/o
#include <ctime> // raindom seed
#include <utility> // pairs 
#include <vector>
#include <iomanip> // setw
#include <fstream>
#include <cassert>
#include <map>
#include "Deck.h"
#include "game.h"

using namespace std;
void intro();
int askNumGames();

/*
 * 
 */
int main(int argc, char** argv) {
    intro();
    ofstream outfile;
    string winner;
    outfile.open("output.txt");
    assert(outfile.is_open());
    int numGames = askNumGames();
    game gameArr[numGames];
    int gameCounter = 0;
    int p1WinCount = 0, p2WinCount = 0;
    bool gameOver = false, allGamesOver = false;
    do {
        do {
            gameArr[gameCounter];

            outfile << "The winner of game " << gameCounter + 1 << " is ";
            winner = gameArr[gameOver].getWinner();
            if (winner == "PlayerOne") {
                p1WinCount++;
                outfile << "Player One ";
            } else if (winner == "PlayerTwo") {
                p2WinCount++;
                outfile << "Player Two ";
            }
            outfile << endl;
            outfile << "The current win count for each player is: " << endl;
            outfile << "Player One: " << p1WinCount << setw(6) << "Player Two: "
                    << p2WinCount << endl;
            gameCounter++;
            gameOver = true;
        } while (gameOver == false);
    } while (allGamesOver == false);
    outfile.close();
    return 0;
}

void intro() {
    cout << "Welcome to a Go-Fish game\nThis game is really simple, you will be"
            " dealt a hand of seven cards and you will ask the computer if there\n"
            "is a card you need in is hand. Your objective here is to get a many "
            "pairs as possible.\nWe will playing with a standard 52 card deck\n" << endl;
}

int askNumGames() {
    int temp;
    cout << "How many games would you like to play?\n";
    do {
        cin >> temp;
    } while (temp < 1 || temp > 10);
    return temp;
}