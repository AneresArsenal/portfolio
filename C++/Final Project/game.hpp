/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Game class hpp file
*********************************************************************/

// include guard
#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include "menu.hpp"
#include "player.hpp"
#include "bruinen.hpp"
#include "rohan.hpp"
#include "gondor.hpp"
#include "mordor.hpp"
#include "rivendell.hpp"
#include "shire.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Game
{
private:
  int stepCount,  //keep track of limit of steps a player can take
      playChoice; // user inputs choice
  //pointers to all 6 spaces and current space and player
  Space *shireSpace;
  Space *bruinenSpace;
  Space *rivendellSpace;
  Space *rohanSpace;
  Space *gondorSpace;
  Space *mordorSpace;
  Space *currentSpace;
  Player *player;

public:
  Game(); //constructor
  // ~Game();
  void runGame(); //run game in sequence
  void createCharacter(int); //dynamically create player
  bool runAdventure(); //run adventure in 6 spaces
  void createSpaces(); //dynamically create spaces
  void deallocatePointers(); //release memory and set pointers to null
  void updatePouch(int); //add prize into pouch
};

#endif /* GAME_HPP_ */