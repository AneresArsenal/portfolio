/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Menu class cpp file
*********************************************************************/

#include <iostream>
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Menu::Menu() //initialize member variables with default constructor
{
    countPlay = 0,
    menuChoice = 0;
}

int Menu::displayMenu() //display menu to user
{
    cout << "Welcome to the Lord of the Ring Quest!" << endl;
    cout << "Choose from following the following character. Choose wisely." << endl;
    cout << "Enter [1] Aragon the Ranger" << endl;
    cout << "Enter [2] Samwise Gamgee the loyal Hobbit" << endl;
    cout << "Enter [3] Legolas Greenleaf the Elf Prince" << endl;
    cout << "Enter [4] Gimli son of Gloin" << endl;
    cout << "Enter [5] Gandalf the Grey" << endl;
    cout << "Enter [6] End the quest." << endl;

    while (!(cin >> menuChoice) || ((menuChoice < 1) || (menuChoice > 6)))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Hasty young one, learn to read carefully or else you might end up in the mouth of Shelob!" << endl;
        cout << "Please choose from following options only:" << endl;
        cout << "Enter [1] Aragon the Ranger" << endl;
        cout << "Enter [2] Samwise Gamgee the loyal Hobbit" << endl;
        cout << "Enter [3] Legolas Greenleaf the Elf Prince" << endl;
        cout << "Enter [4] Gimli son of Gloin" << endl;
        cout << "Enter [5] Gandalf the Grey" << endl;
        cout << "Enter [6] End the quest." << endl;
    }

    //countPlay++;
    cin.clear();
    cin.ignore(10000, '\n');
    return menuChoice;
}

int Menu::prompt(string parameter, int min, int max) //prompt function to gather input from user
{
    cout << parameter << " Choice has to be between " << min << " and " << max << endl;
    int input;

    while (!(cin >> input) || ((input < min) || (input > max))) //input validation to ensure user enter a number within specified range
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error!" << parameter << " Number has to be between " << min << " and " << max << endl;
    }

    cin.clear();
    cin.ignore(10000, '\n');
    return input;
}
