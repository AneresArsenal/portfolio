/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Turtle class cpp file
*********************************************************************/

#include <iostream>
#include "turtle.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;

Turtle::Turtle()
{
    Turtle::age = 1;
    Turtle::cost = 100;
    Turtle::numberOfBabies = 10;
    Turtle::baseFoodCost = Animal::baseFoodCost * (50 / 100);
    Turtle::payoff = Turtle::baseFoodCost * (5 / 100);
}

Turtle::Turtle(int baby)
{
    Turtle::age = baby;
    Turtle::cost = 100;
    Turtle::numberOfBabies = 10;
    Turtle::baseFoodCost = Animal::baseFoodCost * (50 / 100);
    Turtle::payoff = Turtle::baseFoodCost * (5 / 100);
}
/*
Age
Adult if age >= 3 days
Baby if age < 3 days

Cost
Turtle cost $100

Number of Babies
Turtles have 10 babies

Base Food Cost
Turtles have a feeding cost that is 50% the base cost

Payoff
A turtle’s payoff per day is 5% of their cost per animal

*/
