/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Medusa class hpp file
*********************************************************************/

// include guard
#ifndef MEDUSA_HPP_
#define MEDUSA_HPP_
#include <iostream>
#include "character.hpp"

class Medusa : public Character
{
  private:
  public:
    Medusa();
    int getAttack();
    int getDefense();
    int getArmor();
    int getStrengthPoints();
};

#endif 