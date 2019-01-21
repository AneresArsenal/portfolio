/********************************************************************* 
** Author: Serena Tay
** Date: July 22, 2018
** Description: Project 2 Assignnment (Zoo Tycoon)
** Main cpp file
*********************************************************************/

#include <iostream>
#include "animal.hpp"
#include "game.hpp"
#include "menu.hpp"
#include "zoo.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Game gameRunning;
    gameRunning.runGame();
    return 0;
}