/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Character class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Character::Character()
{
    characterType = 0;
    attack = 0,
    defense = 0,
    armor = 0,
    strengthPoints = 0,
    attackDieSides = 0,
    defenseDieSides = 0,
    characterName = " ";
}

int Character::getCharacterType()
{
    return characterType;
}

string Character::getCharacterName()
{
    return characterName;
}

/* removed as this function should be pure virtual functions
int Character::getAttack()
{
    
    attack = 0;
    attack = (rand() % attackDieSides) + 1; //to obtain a pseudo-random number between 1 and integer N
    //source used: http://www.cplusplus.com/forum/beginner/22286/
    return attack;
    
}
*/

int Character::getDefense()
{
    defense = 0;
    defense = (rand() % defenseDieSides) + 1; //to obtain a pseudo-random number between 1 and integer N
    //source used: http://www.cplusplus.com/forum/beginner/22286/
    return defense;
}


int Character::getArmor()
{
    return armor;
}
int Character::getStrengthPoints()
{
    return strengthPoints;
}

void Character::setStrengthPoints(int damage)
{
    strengthPoints -= damage;
}
