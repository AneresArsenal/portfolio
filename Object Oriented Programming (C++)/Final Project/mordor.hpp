/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Mordor class hpp file
*********************************************************************/

// include guard
#ifndef MORDOR_HPP_
#define MORDOR_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Mordor : public Space
{
protected:
  Menu programRunningMordor;
  int mordorArmy,
      gondorArmy,
      lifeCount;

public:
  Mordor();
  bool event();
};

#endif /* MORDOR_HPP_ */