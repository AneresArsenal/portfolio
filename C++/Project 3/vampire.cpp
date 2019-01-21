/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Vampire class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "vampire.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*default contructor to intialize all class member variables per project requirements 
for the character*/

Vampire::Vampire()
{
    characterType = 5,
    attack = 0,
    defense = 0,
    armor = 1,
    strengthPoints = 18,
    attackDieSides = 12,
    defenseDieSides = 6;
    characterName = "Vampire";
    charmStatus = false;
}

int Vampire::getAttack()
{
    attack = 0;
    attack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer N
    return attack;
}
int Vampire::getDefense()
{
    defense = 0;
    defense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer N
    return defense;
}

int Vampire::getArmor()
{
    return armor;
}
int Vampire::getStrengthPoints()
{
    return strengthPoints;
}

bool Vampire::charm()
{
    charmStatus = false;
    // For a given attack there is a 50% chance that their opponent does not actually attack them
    int result = (rand() % 2) + 1;
    if (result == 1)
    {
        charmStatus = true;
        return true; //attack if true
        
    }
    else
    {
        charmStatus = false;
        return false; //dont attack if false
    }
}

bool Vampire::getCharmStatus()
{
    return charmStatus;
}

void Vampire::setStrengthPoints(int damage)
{
    if (charmStatus==true)
    {
        strengthPoints -= damage;
    }

    else if (charmStatus==false)
    {
        cout << "Hold on! Vampire seems to have another trick up his sleeve! He used his Charm and the apponent did not attack!" << endl;
    }
}
