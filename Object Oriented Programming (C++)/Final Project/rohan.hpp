/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Rohan class hpp file
*********************************************************************/

// include guard
#ifndef ROHAN_HPP_
#define ROHAN_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Rohan : public Space
{
protected:
Menu programRunningRohan;

public:
  Rohan();
  bool event ();
};

#endif /* Rohan_HPP_ */