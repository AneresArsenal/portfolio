/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Rivendell class hpp file
*********************************************************************/

// include guard
#ifndef RIVENDELL_HPP_
#define RIVENDELL_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Rivendell : public Space
{
protected:
Menu programRunningRivendell;


public:
  Rivendell();
  bool event();
};

#endif /* RIVENDELL_HPP_ */