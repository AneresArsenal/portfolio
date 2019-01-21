/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Main cpp file
*********************************************************************/

#include <iostream>
#include <ctime>
#include <random>
#include "game.hpp"
#include "menu.hpp"



using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    srand(time(NULL));
    Game gameRunning;
    gameRunning.runGame();

    return 0;
}