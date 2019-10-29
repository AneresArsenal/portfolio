/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Bluemen class hpp file
*********************************************************************/

// include guard
#ifndef BLUEMEN_HPP_
#define BLUEMEN_HPP_
#include <iostream>
#include "character.hpp"

class BlueMen : public Character
{
  private:
  int mobCount;
  public:
    BlueMen();
    int getAttack();
    int getDefense();
    int getArmor();
    int getStrengthPoints();
    void mob();
};

#endif 