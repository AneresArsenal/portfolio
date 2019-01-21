/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Player class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "player.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Player::Player()
{
    playerName = " ";
    pouchCount = 0;
}

void Player::insertPlayerPouch(string prize, int count)
{
    playerPouch[pouchCount] = prize;
    printPouch();
    pouchCount += 1;
}

void Player::printPouch()
{
    cout << playerName << " currently has " << endl;
    for (int i = 0; i <= pouchCount; i++)
    {
        cout << "Item " << (i + 1) << ": " << playerPouch[i] << " ";
    }
    cout << endl;
}

void Player::setPlayerName(string name)
{
    playerName = name;
}

string Player::getPlayerName()
{
    return playerName;
}

int Player::getPouchCount()
{
    return pouchCount;
}