/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Space class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "space.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Space::Space()
{
    top = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    spaceName = "Space";
    playerPresent = false;
}

string Space::getSpaceName()
{
    return spaceName;
}

/*
bool Space::getPlayerPresent()
{
    return playerPresent;
}
*/

void Space::setPointer(string input, Space *pointer)
{
    if (input == "top")
    {
        top = pointer;
    }

    if (input == "down")
    {
        down = pointer;
    }

    if (input == "left")
    {
         left = pointer;
    }

    if (input == "right")
    {
         right = pointer;
    }
}


Space* Space::getPointer(string input)
{
    if (input == "top")
    {
        return top;
    }

    if (input == "down")
    {
        return down;
    }

    if (input == "left")
    {
        return left;
    }

    if (input == "right")
    {
        return right;
    }
}
