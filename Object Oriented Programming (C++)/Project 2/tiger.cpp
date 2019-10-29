/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Tiger class cpp file
*********************************************************************/

#include <iostream>
#include "tiger.hpp"
#include "zoo.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Tiger::Tiger ()
{
    Tiger::age = 1;
    Tiger::cost = 10000;
    Tiger::numberOfBabies = 1;
    Tiger::baseFoodCost = 5 * Animal::baseFoodCost;
    Tiger::payoff = Tiger::baseFoodCost * (2 / 10);
}

Tiger::Tiger(int baby)
{
    Tiger::age = baby;
    Tiger::cost = 10000;
    Tiger::numberOfBabies = 1;
    Tiger::baseFoodCost = 5 * Animal::baseFoodCost;
    Tiger::payoff = Tiger::baseFoodCost * (2 / 10);
}

/*
Age
Adult if age >= 3 days
Baby if age < 3 days

Cost
Tiger cost $10,000

Number of Babies
Tigers have 1 baby

Base Food Cost
Tigers have a feeding cost of 5 times the base cost

Payoff
A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)


*/
