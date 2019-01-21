/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Bruinen class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "bruinen.hpp"
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Bruinen::Bruinen()
{
    spaceName = "Ford of Bruinen";
}

bool Bruinen::event()
{
    int count = 0;
    cout << "The nazguls are behind you! What stands between you and the shelter of Rivendell is the mighty ford of Bruinen." << endl;
    cout << "To call upon the ancient spirits for safe passage, solve the following riddles!" << endl;
    cout << "Who forged the three elf-rings Nenya, Narya and Vilya?" << endl;
    int choice1 = programRunningBruinen.prompt("[1] Thranduil [2] Celebrimbor ", 1, 2);
    if (choice1 == 2)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice1 != 2)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
    }

    cout << "Iarwain Ben-adar we called him, oldest and fatherless." << endl;
    cout << "But many another name he has since been given by other folk:" << endl;
    cout << "Forn by the Dwarves, Orald by Northern Men, and other names beside." << endl;
    cout << "He is a strange creature...who is he?" << endl;
    int choice2 = programRunningBruinen.prompt("[1] Tharanduil [2] Beren [3] Tom Bombadil ", 1, 3);
    if (choice2 == 3)
    {
        cout << "You have answered correctly!" << endl;
        count += 1;
    }

    if (choice2 != 3)
    {
        cout << "Sorry, you have answered incorrectly!" << endl;
    }

    cout << "Tinuviel the elven-fair, Immortal maidenelven-wise..." << endl;
    cout << "Long was the way that fate them bore, O’er stony mountains cold and grey, " << endl;
    cout << "Through halls of iron and darkling door, And woods of nightshade morrowless. " << endl;
    cout << "The Sundering Seas between them lay." << endl;
    cout << "And yet at last they met once more, And long ago they passed away." << endl;
    cout << "Whose story is the excerpt of the song describing?" << endl;

    int choice3 = programRunningBruinen.prompt("[1] Tom Bombadil and Goldberry [2] Aragon and Arwen [3] Beren and Luthien ", 1, 3);
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
        cout << "Congratulations, you may pass the fords of Bruinen and have safe passage into Rivendell!" << endl;
        return true;
    }

    else
    {
        cout << "Sorry, you will need to try again." << endl;
        return false;
    }
}