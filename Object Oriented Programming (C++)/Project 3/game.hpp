/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Game class hpp file
*********************************************************************/

// include guard
#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include "menu.hpp"
//#include "character.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Game
{
private:
  int round,
      playChoice,
      characterChoice1,
      characterChoice2,
      damage1,
      damage2,
      attackRoll1,
      defenderRoll1,
      defenderArmor1,
      attackRoll2,
      defenderRoll2,
      defenderArmor2;
  Character *character1;
  Character *character2;

public:
  Game();
  void runGame();
  void createCharacter(int, int);
  void runRound();
  bool processDamage(int, int);
  void printResult(int);
  void deallocatePointers();
  
};

#endif /* GAME_HPP_ */

/*

Zoo Tycoon

Game Flow:

The player begins with a specific amount of money in the bank, e.g. 100,000 dollars. At the start, the user needs to buy three types of animals (tigers, penguins, turtles) to start the business. Each type should have a quantity of either 1 or 2. For each animal bought, the cost is subtracted from the bank. All newly bought animals are 1 day old.

Each turn is a “day”. At the beginning of the day, all animals increase age by 1 day, and the user needs to pay the feeding cost of each animal. Feeding is required so the animals don’t die. After the feeding cost is subtracted from the bank, one randomized event takes place during the day.  You can determine how to implement the random functions by yourself.  The random function will pick one random event from the following list:

*/