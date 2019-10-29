/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/

//Menu class cpp file

#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*Menu

You can customize the menu, or how the program prompt use for inputs however you want, as long as all the above requirements are met. You can even make the simulation information prompts a menu, by providing an option menu for each information, allowing user to modify the data as they wish before starting simulation, but it is not a requirement.
*/
Menu::Menu() //initialize member variables with default constructor
{
    countPlay = 0,
    menuChoice = 0;
}

int Menu::displayMenu()
{
    if (countPlay == 0)
    {
        cout << "Menu" << endl;
        cout << "Please choose only one of the following options." << endl;
        cout << "1. Start Langton's Ant simulation [enter 1]" << endl;
        cout << "2. Quit [enter 2]" << endl;
        // cout << "3. Start Langtonís Ant simulation (Random) [enter 3]" << endl;
        cin >> menuChoice;
        while ((menuChoice < 1) | (menuChoice > 2)) //input validation to ensure user enter the choices available
        {
            cout << "Please choose only either 1 or 2." << endl;
            cin >> menuChoice;
        }
        countPlay++;
    }

    else //After the simulation ended, the menu should provide user 2 choices: play again, or quit.
    {
        cout << "Menu" << endl;
        cout << "Please choose only one of the following options." << endl;
        cout << "1. Play again [enter 1]" << endl;
        cout << "2. Quit [enter 2]" << endl;
        cin >> menuChoice;
        while ((menuChoice < 1) | (menuChoice > 2)) //input validation to ensure user enter the choices available
        {
            cout << "Please choose only either 1 or 2." << endl;
            cin >> menuChoice;
        }
        countPlay++;
    }
    return 0;
}

int Menu::prompt(string parameter, int min, int max)
{
    cout << "Please enter a value for the " << parameter << " between " << min << " and " << max << endl;
    int input;
    cin >> input;

    while ((input < min) || (input > max)) //input validation to ensure user enter a number within specified range
    {
        cout << "Error! Please enter a value for " << parameter << " between " << min << " and " << max << endl;
        cin >> input;
    }
    return input;
}

int Menu::getMenuChoice()
{
    return menuChoice;
}
