/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Penguin class hpp file
*********************************************************************/

// include guard
#ifndef PENGUIN_HPP_
#define PENGUIN_HPP_
#include <iostream>
#include "animal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Penguin : public Animal
{

public:
  Penguin();
  Penguin(int); //for baby penguins
};

#endif /* PENGUIN_HPP_ */