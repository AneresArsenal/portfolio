/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Bruinen class hpp file
*********************************************************************/

// include guard
#ifndef BRUINEN_HPP_
#define BRUINEN_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Bruinen: public Space
{
protected:
Menu programRunningBruinen;


public:
  Bruinen();
  bool event();
};

#endif /* BRUINEN_HPP_ */