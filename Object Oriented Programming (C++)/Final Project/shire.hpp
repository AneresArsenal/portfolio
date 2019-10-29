/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Shire class hpp file
*********************************************************************/

// include guard
#ifndef SHIRE_HPP_
#define SHIRE_HPP_
#include <iostream>
#include "menu.hpp"
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Shire : public Space
{
protected:
Menu programRunningShire;


public:
  Shire();
  bool event();
};

#endif /* SHIRE_HPP_ */