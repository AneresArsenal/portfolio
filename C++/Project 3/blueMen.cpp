/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Bluemen class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "blueMen.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*default contructor to intialize all class member variables per project requirements 
for the character*/

BlueMen::BlueMen()
{
    characterType = 2,
    attack = 0,
    defense = 0,
    armor = 3,
    strengthPoints = 12,
    attackDieSides = 10,
    defenseDieSides = 6;
    characterName = "BlueMen";
    mobCount = 3;
}

int BlueMen::getAttack()
{
    attack = 0;
    for (int i = 0; i < 2; i++)
    {
        int currentAttack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 10
        attack += currentAttack;
    }
    return attack;
}
int BlueMen::getDefense()
{
    defense = 0;
    int count = mobCount;
    for (int i = count; i > 0; i--)
    {
        int currentDefense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
        defense += currentDefense;
    }
    return defense;
}

int BlueMen::getArmor()
{
    return armor;
}
int BlueMen::getStrengthPoints()
{
    mob(); //check strength points
    return strengthPoints;
}

/*
For every 4 points of damage, they lose one defense die. 
For example, if they have a strength of 8, they would have 2d6 for defense
*/
void BlueMen::mob()
{
    if (strengthPoints <= 8 && mobCount == 3) //if strength point is a multiple of 4 but not 12 or 0
    {
        cout << " Sadly the BlueMen lost one of their brothers and this has impacted their defensive front" << endl;
        mobCount -= 1;
        cout << " Number of defence dies decreased to " << mobCount << "." << endl;
    }

    if (strengthPoints <= 4 && mobCount == 2) //if strength point is a multiple of 4 but not 12 or 0
    {
        cout << " Sadly the BlueMen lost one of their brothers and this has impacted their defensive front" << endl;
        mobCount -= 1;
        cout << " Number of defence die decreased to " << mobCount << "." << endl;
    }
}