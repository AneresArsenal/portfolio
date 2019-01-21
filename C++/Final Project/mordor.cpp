/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Mordor class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "mordor.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Mordor::Mordor()
{
    spaceName = "Fortress of Mordor";
    mordorArmy = 100;
    gondorArmy = 100;
}

bool Mordor::event()
{
    mordorArmy = 100;
    cout << "To defeat the army of Mordor, you will need to muster all the strengths you have against their might hoard." << endl;
    cout << "With their steeds, Rohirrims will have 3 rounds of attack and of a swifter blow." << endl;
    cout << "Sturdy and courageous army under the banner of the White Tree, the army of Minas Tirith" << endl;
    cout << "will have five rounds of attack but at a slower and smaller impact." << endl;
    int choice = programRunningMordor.prompt("[1] Attack with the Rohirrims or [2] Army of Minas Tirith.", 1, 2);
    int count = 0;

    switch (choice)
    {
    case 1:
    {
        while (mordorArmy > 0)
        {
            while (count < 3)
            {
                int attackResult = 0;
                attackResult = (rand() % 50) + 25;
                mordorArmy -= attackResult;
                cout << "Round: " << (count + 1) << endl;
                cout << "Attack result: " << attackResult << endl;
                cout << "Mordor army remaining: " << mordorArmy << endl;
                if (mordorArmy <= 0)
                {
                    break;
                }
                count += 1;
            }

            if (mordorArmy <= 0) //pass the test
            {
                cout << "Congratulations, the Rohirrims have won the war!" << endl;
                return true;
            }

            else
            {
                cout << "Sorry, the Rohirrims perished and the battle was lost." << endl;
                return false;
            }
        }
        break;
    }

    case 2:
    {
        while (mordorArmy > 0)
        {

            while (count < 5)
            {
                int attackResult = 0;
                attackResult = (rand() % 30) + 1;
                mordorArmy -= attackResult;
                cout << "Round: " << (count + 1) << endl;
                cout << "Attack result: " << attackResult << endl;
                cout << "Mordor army remaining: " << mordorArmy << endl;
                
                if (mordorArmy <= 0)
                {
                    break;
                }
                count += 1;
            }

            if (mordorArmy <= 0) //pass the test
            {
                cout << "Congratulations, the army of Gondor have won the war!" << endl;
                return true;
            }

            else
            {
                cout << "Sorry, army of Gondor failed and the battle was lost." << endl;
                return false;
            }
        }
        break;
    }
    }
}