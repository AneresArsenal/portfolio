/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Gondor class hpp file
*********************************************************************/

// include guard
#ifndef GONDOR_HPP_
#define GONDOR_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Gondor : public Space
{
protected:
  int urukHaiLifeCount,
      lifeCount;
      Menu programRunningGondor;

public:
  Gondor();
  bool event();
  
};

#endif /* GONDOR_HPP_ */