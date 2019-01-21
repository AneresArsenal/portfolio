/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Vampire class hpp file
*********************************************************************/

// include guard
#ifndef VAMPIRE_HPP_
#define VAMPIRE_HPP_
#include <iostream>
#include "character.hpp"

class Vampire : public Character
{
private:
  bool charmStatus;

public:
  Vampire();
  int getAttack();
  int getDefense();
  int getArmor();
  int getStrengthPoints();
  bool charm();
  bool getCharmStatus();
  void setStrengthPoints(int); //virtual function from character override
};

#endif