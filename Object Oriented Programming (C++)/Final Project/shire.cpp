/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Shire class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "shire.hpp"
#include "player.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Shire::Shire()
{
    spaceName = "Region of Shire";
}

bool Shire::event()
{
    int count = 0;
    int choice1 = 0,
        choice2 = 0,
        choice3 = 0;

    cout << "To ensure you are prepared mentally to embark on this quest. " << endl;
    cout << "You will need to obtain 2 out of the 3 question correctly. Good luck!" << endl;
    cout << "What is the best/most popular pipe-weed in Middle Earth? " << endl;

    choice1 = programRunningShire.prompt("[1] Longbottom Leaf [2] Gundolin's Pipe ", 1, 2);
    if (choice1 == 1)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice1 != 1)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
    }

    cout << "What is the type of herb that saved Frodo when he was stabbed by the chief of the Nazgul? " << endl;

    choice2 = programRunningShire.prompt("[1] Elanor [2] Athelas [3] Lembas ", 1, 3);
    if (choice2 == 2)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice2 != 2)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
    }

    cout << "There are three rings forged for the elves." << endl;
    cout << "Nenya, the Ring of Water is beared by Lady Galadriel of Lothlorien " << endl;
    cout << "while Narya, the Ring of Fire is entrusted to Gandalf the Grey. " << endl;
    cout << "Vilya, the Ring of Air, mightiest of the Three is held by who? " << endl;

    choice3 = programRunningShire.prompt("[1] Aragorn [2] Tom Bombadil [3] Elrond ", 1, 3);
    if (choice3 == 3)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice3 != 3)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
    }

    if (count >= 2) //pass the test
    {
        cout << "Congratulations, you have passed the test and are ready to go on this perilous journey!" << endl;
        return true;
    }

    else
    {
        cout << "Sorry, you will need to try again." << endl;
        return false;
    }
}