/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Rivendell class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "rivendell.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Rivendell::Rivendell()
{
    spaceName = "Haven of Rivendell";
}

bool Rivendell::event()
{
    int count = 0;
    cout << "Welcome to Rivendell. Here is where your will be tested and honed for the road ahead!" << endl;
    cout << "Would you wish to be tested for your physical strength or your wisdom " << endl;
    int choice1 = programRunningRivendell.prompt("[1] Physical strength [2] Wisdom ", 1, 2);

    if (choice1 == 1)
    {
        int strength = 0;
        while (count < 4)
        {
            int result = 0;
            result = (rand() % 25) + 1;
            strength += result;
            count += 1;
        }

        if (strength >= 50) //pass the test
        {
            cout << "Congratulations, you have the strength and will in you to continue on the journey!" << endl;
            return true;
        }

        else
        {
            cout << "Sorry, you will need to train and try again." << endl;
            return false;
        }
    }

    else //choice is two
    {
        int wisdom = 0;
        while (count < 4)
        {
            int result = 0;
            result = (rand() % 25) + 1;
            wisdom += result;
            count += 1;
        }

        if (wisdom >= 50) //pass the test
        {
            cout << "Congratulations, you have the wisdom and wit in you to continue on the journey!" << endl;
            return true;
        }

        else
        {
            cout << "Sorry, you will need to train and try again." << endl;
            return false;
        }
    }
}