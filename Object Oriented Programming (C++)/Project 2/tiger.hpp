/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Tiger class hpp file
*********************************************************************/

// include guard
#ifndef TIGER_HPP_
#define TIGER_HPP_
#include <iostream>
#include "animal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Tiger : public Animal
{
public:
  Tiger();
  Tiger(int);
};

#endif /* TIGER_HPP_ */