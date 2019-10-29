/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Medusa class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "medusa.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*default contructor to intialize all class member variables per project requirements 
for the character*/

Medusa::Medusa()
{
    characterType = 4,
    attack = 0,
    defense = 0,
    armor = 3,
    strengthPoints = 8,
    attackDieSides = 6,
    defenseDieSides = 6;
    characterName = "Medusa";
}

int Medusa::getAttack()
{
    attack = 0;
    for (int i = 0; i < 2; i++)
    {
        int currentAttack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
        attack += currentAttack;
    }

    if (attack == 12)
    {
        cout << "Medusa uses her glare and casted her opponent into stone!" << endl;
        attack = 50; //higher than any defense and strength points combination
        return attack;
    }

    else
    {
        return attack; //normal attack
    }
}
int Medusa::getDefense()
{
    defense = 0;
    defense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
    return defense;
}

int Medusa::getArmor()
{
    return armor;
}

int Medusa::getStrengthPoints()
{
    return strengthPoints;
}
