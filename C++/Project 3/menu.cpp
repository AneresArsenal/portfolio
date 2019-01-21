/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
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
    if (countPlay == 0)
    {
        cout << "Welcome to the Fantasy Combat Game!" << endl;
        cout << "Please choose one of the following options." << endl;
        cout << "1. Start game [enter 1]" << endl;
        cout << "2. Exit game [enter 2]" << endl;

        while (!(cin >> menuChoice) || ((menuChoice < 1) || (menuChoice > 2)))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please choose only either 1 or 2." << endl;
        }

        countPlay++;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    else //After the game ended, the menu should provide user 2 choices: play again, or quit.
    {
        cout << "Menu" << endl;
        cout << "Please choose only one of the following options." << endl;
        cout << "1. Play again [enter 1]" << endl;
        cout << "2. Exit [enter 2]" << endl;
        //cin  >> menuChoice;

        while (!(cin >> menuChoice) || ((menuChoice < 1) || (menuChoice > 2))) //input validation to ensure user enter the choices available
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please choose only either 1 or 2." << endl;
        }

        countPlay++;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return 0;
}

int Menu::prompt(string parameter, int min, int max) //prompt function to gather input from user
{
    cout << "Please enter the " << parameter << ". Number has to be between " << min << " and " << max << endl;
    int input;

    while (!(cin >> input) || ((input < min) || (input > max))) //input validation to ensure user enter a number within specified range
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Please enter the " << parameter << ". Number has to be between " << min << " and " << max << endl;
    }

    cin.clear();
    cin.ignore(10000, '\n');
    return input;
}

int Menu::promptChoice() //display characters for user to choose
{
    cout << "Please choose a character from the following options" << endl;
    cout << "Enter [1] for Barbarian" << endl;
    cout << "Enter [2] for Blue Man" << endl;
    cout << "Enter [3] for Harry Potter" << endl;
    cout << "Enter [4] for Medusa" << endl;
    cout << "Enter [5] for Vampire" << endl;
    int input=0;

    while (!(cin >> input) || ((input < 1) || (input > 5))) //input validation to ensure user enter a number within specified range
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Choose from [1] to [5]" << endl;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    return input;
}

int Menu::getMenuChoice()
{
    return menuChoice;
}

int Menu::getCountPlay()
{
    return countPlay;
}
