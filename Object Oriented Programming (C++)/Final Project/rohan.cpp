/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Rohan class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "rohan.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Rohan::Rohan()
{
    spaceName = "Rohan the land of the horse-sires";
}

bool Rohan::event()
{
    int count = 0;
    cout << "Welcome to the house of the horselords Rohan." << endl;
    cout << "To claim your prize, a mighty stallion to ride to Gondor," << endl;
    cout << "we need to make sure you known how to care and ride a horse properly." << endl;
    cout << "Please answer the following questions." << endl;
    cout << "You will need to get all three questions correct to obtain your prize." << endl;
    cout << "What would make a good snack for a horse" << endl;
    int choice1 = programRunningRohan.prompt("[1] Apple [2] Ale ", 1, 2);
    if (choice1 == 1)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice1 != 1)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
        
    }

    cout << "Which is not a required horse riding equipment?" << endl;
    int choice2 = programRunningRohan.prompt("[1] Saddle [2] Strirrups [3] Staff ", 1, 3);
    if (choice2 == 3)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice2 != 3)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
      
    }

    cout << "He is the chief of the Mearas," << endl;
    cout << "tamed by Gandalf the White," << endl;
    cout << "A might horse of Rohan," << endl;
    cout << "that understands the speech of Man" << endl;
    cout << "Which Rohan stallion is described here?" << endl;

    int choice3 = programRunningRohan.prompt("[1] Shadowfax [2] Snowmane [3] Arod ", 1, 3);
    if (choice3 == 1)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice3 != 1)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
      
    }

    if (count == 3) //pass the test
    {
        cout << "Congratulations, you may obtain your Stallion and ride forth to Battle in Gondor!" << endl;
        return true;
    }

    else
    {
        cout << "Sorry, you will need to try again." << endl;
        return false;
    }
}