/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Animal class cpp file
*********************************************************************/

#include <iostream>
#include "animal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Animal::Animal()
{
    age = 0;
    cost = 0;
    numberOfBabies = 0;
    payoff = 0;
    baseFoodCost = 10;
}

void Animal::growOld()
{
    age += 1;
}
int Animal::getAge()
{
    return age;
}

int Animal::getCost()
{
    return cost;
}