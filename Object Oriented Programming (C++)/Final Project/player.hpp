/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Player class hpp file
*********************************************************************/

// include guard
#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Player
{
protected:
string playerPouch [6]; //container for the player, to carry “items”.
string playerName;
int pouchCount; //keep track of pouch limit


public:
  Player();
  void insertPlayerPouch (string, int);
  void printPouch ();
  void setPlayerName (string);
  string getPlayerName ();
  int getPouchCount ();
};

#endif /* PLAYER_HPP_ */