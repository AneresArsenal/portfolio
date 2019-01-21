/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Turtle class hpp file
*********************************************************************/

// include guard
#ifndef TURTLE_HPP_
#define TURTLE_HPP_
#include <iostream>
#include "animal.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;

class Turtle : public Animal
{
private:
public:
  Turtle();
  Turtle(int);
};

#endif /* TURTLE_HPP_ */