/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Harry Potter class hpp file
*********************************************************************/

// include guard
#ifndef HARRYPOTTER_HPP_
#define HARRYPOTTER_HPP_
#include <iostream>
#include "character.hpp"

class HarryPotter : public Character
{
private:
  int lifeCount; //for hogwarts
public:
  HarryPotter();
  int getAttack();
  int getDefense();
  int getArmor();
  int getStrengthPoints();
  void hogwarts();
  
};

#endif