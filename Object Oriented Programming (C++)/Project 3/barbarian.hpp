/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Barbarian class hpp file
*********************************************************************/

// include guard
#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_
#include <iostream>
#include "character.hpp"

class Barbarian : public Character
{
  private:
  public:
    Barbarian();
    int getAttack();
    int getDefense();
    int getArmor();
    int getStrengthPoints();
};

#endif 