/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Harry Potter class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "harryPotter.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*default contructor to intialize all class member variables per project requirements 
for the character*/

HarryPotter::HarryPotter()
{
    lifeCount = 1; // only can trigger the Hogwart function once
    characterType = 3,
    attack = 0,
    defense = 0,
    armor = 0,
    strengthPoints = 10,
    attackDieSides = 6,
    defenseDieSides = 6;
    characterName = "Harry Potter";
}

int HarryPotter::getAttack()
{
    attack = 0;
    for (int i = 0; i < 2; i++)
    {
        int currentAttack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer N
        attack += currentAttack;
    }
    return attack;
}
int HarryPotter::getDefense()
{
    defense = 0;
    for (int i = 0; i < 2; i++)
    {
        int currentDefense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer 6
        defense += currentDefense;
    }
    return defense;
}

int HarryPotter::getArmor()
{
    return armor;
}
int HarryPotter::getStrengthPoints()
{
    hogwarts(); //check strengthPoints and add 20 if 0
    return strengthPoints;
}

/*
If Harry Potter's strength reaches 0 or below, 
he immediately recovers and his total strength becomes 20. 
If he were to die again, then he’s dead.
*/

void HarryPotter::hogwarts()
{
    if (lifeCount == 1 && strengthPoints <= 0) //HP have zero strength points and one Hogwart charm to use
    {
        cout << "Harry Potter is revived after using his Hogwart charm!" << endl;
        strengthPoints = 20;
        lifeCount--;
        return;
    }

    else if (lifeCount == 0 && strengthPoints <= 0)
    {
        cout << "Harry Potter has used his Hogwart charms already and cannot be revived anymore :(" << endl;
        return;
    }

    else
    {
        return; //nothing happened
    }
}