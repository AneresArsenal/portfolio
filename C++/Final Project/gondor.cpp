/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Gondor class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "gondor.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Gondor::Gondor()
{
    spaceName = "Realm of Gondor";
    urukHaiLifeCount = 50;
    
}

bool Gondor::event()
{
    urukHaiLifeCount = 50;
    

    cout << "To advance to Mordor, first you need to defeat the mighty Uruk Hai! You only two options." << endl;
    int choice = programRunningGondor.prompt("[1] have normal five attacks to kill him or [2] three ultra mode attacks.", 1, 2);

    switch (choice)
    {
    case (1):
    {
        int count = 0;
        while (urukHaiLifeCount > 0)
        {

            while (count < 5)
            {
                int attackResult = 0;
                attackResult = (rand() % 20) + 1;
                urukHaiLifeCount -= attackResult;
                cout << "Round: " << (count + 1) << endl;
                cout << "Attack result: " << attackResult << endl;
                cout << "Uruk Hai life remaining: " << urukHaiLifeCount << endl;
                if (urukHaiLifeCount <= 0)
                {
                    break;
                }
                count += 1;
            }

            if (urukHaiLifeCount <= 0) //pass the test
            {
                cout << "Congratulations, you have slayed the evil Uruk-Hai!" << endl;
                return true;
            }

            else
            {
                cout << "Sorry, you used up all your chances but the Uruk-Hai was too strong and fled." << endl;
                return false;
            }
        }
        break;
    }

    case (2):
    {
        int count = 0;
        while (urukHaiLifeCount > 0)
        {

            while (count < 3)
            {
                int attackResult = 0;
                attackResult = (rand() % 20) + 10;
                urukHaiLifeCount -= attackResult;
                cout << "Round: " << (count + 1) << endl;
                cout << "Attack result: " << attackResult << endl;
                cout << "Uruk Hai life remaining: " << urukHaiLifeCount << endl;
                if (urukHaiLifeCount <= 0)
                {
                    break;
                }
                count += 1;
            }

            if (urukHaiLifeCount <= 0) //pass the test
            {
                cout << "Congratulations, you have slayed the evil Uruk-Hai!" << endl;
                return true;
            }

            else
            {
                cout << "Sorry, you used up all your chances but the Uruk-Hai was too strong and fled." << endl;
                return false;
            }
        }
        break;
    }
    }
}