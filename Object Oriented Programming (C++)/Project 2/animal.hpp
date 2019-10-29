/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Animal class hpp file
*********************************************************************/

// include guard
#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Animal
{
protected:
  int age,
      cost,
      numberOfBabies,
      payoff,
      baseFoodCost;

public:
  Animal();

  Animal(int age, int cost, int numberOfBabies, int payoff, int baseFoodCost) : age(age), cost(cost), numberOfBabies(numberOfBabies), payoff(payoff), baseFoodCost(baseFoodCost)
  {
  }
  void growOld();
  int getAge();
  int getCost();
};

#endif /* ANIMAL_HPP_ */
