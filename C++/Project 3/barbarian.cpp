/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Barbarian class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "barbarian.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*default contructor to intialize all class member variables per project requirements 
for the character*/

Barbarian::Barbarian()
{
    characterType = 1,
    attack = 0,
    defense = 0,
    armor = 0,
    strengthPoints = 12,
    attackDieSides = 6,
    defenseDieSides = 6;
    characterName = "Barbarian";
}

int Barbarian::getAttack()
{
    attack = 0;
    for (int i = 0; i < 2; i++)
    {
        int currentAttack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
        attack += currentAttack;
    }
    return attack;
}
int Barbarian::getDefense()
{
    defense = 0;
    for (int i = 0; i < 2; i++)
    {
    int currentDefense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
    defense += currentDefense;
    }
    return defense;
}

int Barbarian::getArmor()
{
    return armor;
}
int Barbarian::getStrengthPoints()
{
    return strengthPoints;
}