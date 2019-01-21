/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Penguin class cpp file
*********************************************************************/

#include <iostream>
#include "penguin.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Penguin::Penguin()
{
    Penguin::age = 1;
    Penguin::cost = 1000;
    Penguin::numberOfBabies = 5;
    Penguin::baseFoodCost = Animal::baseFoodCost;
    Penguin::payoff = 0.1 * Penguin::baseFoodCost;
}

Penguin::Penguin(int baby)
{
    Penguin::age = baby;
    Penguin::cost = 1000;
    Penguin::numberOfBabies = 5;
    Penguin::baseFoodCost = Animal::baseFoodCost;
    Penguin::payoff = 0.1 * Penguin::baseFoodCost;
}
/*
Age
Adult if age >= 3 days
Baby if age < 3 days

Cost
Penguin cost $1,000

Number of Babies
Penguins have 5 babies

Base Food Cost
Penguins have a feeding cost that is the same as the base cost

Payoff
A penguin’s payoff per day is 10% of their cost per animal

*/
