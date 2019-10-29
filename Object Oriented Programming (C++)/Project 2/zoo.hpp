/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Zoo class hpp file
*********************************************************************/

// include guard
#ifndef ZOO_HPP_
#define ZOO_HPP_

#include <iostream>
//#include "animal.hpp"
#include "game.hpp"
#include "menu.hpp"

#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Zoo
{
private:
  // three dynamic arrays to store objects of each animal type
  Penguin *penguinArray;
  Tiger *tigerArray;
  Turtle *turtleArray;
  int bankBalance,
      //counter to keep track of each animal type counts
      penguinCount,
      tigerCount,
      turtleCount,
      //used to check capacity to determine if resizing is needed
      penguinCapacity,
      tigerCapacity,
      turtleCapacity;
  

public:
  //data of each animals are created so game class can access them but not change them
  static const int costPenguin = 1000;
  static const int costTiger = 10000;
  static const int costTurtle = 100;
  static const int baseFoodCost = 10;
  static const int foodCostPenguin = baseFoodCost;
  static const int foodCostTiger = 5 * baseFoodCost;
  static const int foodCostTurtle = (baseFoodCost / 2);

  Zoo();

  int bonusPayoff();

  void updateAnimalCount(int, int);
  void createAnimal(int, int, int);
  void removeSickAnimal(int);
  int getAnimalCount(int);
  int getAnimalAge(int);
  void updateAge();
  bool checkAdult(int);

  void updateBankBalance(int);
  void payFoodCost();
  void printDailyReport(int);
  bool checkBankBalance();

  void resizeArray(int, int);
  void increaseCapacityCounter(string);
  void deletePointers();
};

#endif /* ZOO_HPP_ */
