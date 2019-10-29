/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Game class cpp file
*********************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Game::Game()
{
    stepCount = 0,
    playChoice = 0;
    currentSpace = NULL;
    player = NULL;
}
/*
Game::~Game()
{
    shireSpace->setPointer("top", NULL);

    bruinenSpace->setPointer("down", NULL);
    bruinenSpace->setPointer("top", NULL);

    rivendellSpace->setPointer("down", NULL);
    rivendellSpace->setPointer("top", NULL);

    rohanSpace->setPointer("down", NULL);
    rohanSpace->setPointer("top", NULL);

    gondorSpace->setPointer("down", NULL);
    gondorSpace->setPointer("top", NULL);

    mordorSpace->setPointer("down", NULL);

    //delete currentSpace;

    delete shireSpace;
    delete bruinenSpace;
    delete rivendellSpace;
    delete rohanSpace;
    delete gondorSpace;
    delete mordorSpace;

    delete player;

    shireSpace = NULL;
    bruinenSpace = NULL;
    rivendellSpace = NULL;
    rohanSpace = NULL;
    gondorSpace = NULL;
    mordorSpace = NULL;
    currentSpace = NULL;
    player = NULL;
}
*/
void Game::runGame()
{
    Menu programRunning;
    playChoice = programRunning.displayMenu(); //display menu
    //playChoice = programRunning.getMenuChoice();

    while (playChoice != 6)
    {
        createCharacter(playChoice);
        createSpaces();

        stepCount = 0;
        playChoice = 0;
        runAdventure();
        playChoice = programRunning.displayMenu(); //display menu
        /*
        if (!runAdventure())
        {
            playChoice = 6; //break game
            return;
        }
        */
        deallocatePointers();
    }

    if (playChoice == 6) //quit simulation
    {
        //deallocatePointers(); //deallocate pointers
        cout << "Alas the quest has ended just in time for a proper hobbit supper! Thank you for playing!" << endl;
    }
}

void Game::createCharacter(int playerChoice)
{
    switch (playerChoice)
    {
    case 1:
    {
        player = new Player;
        player->setPlayerName("Aragon the Ranger");
        cout << "Welcome to the quest Aragon!" << endl;
        break;
    }

    case 2:
    {
        player = new Player;
        player->setPlayerName("Samwise Gamgee the loyal Hobbit");
        cout << "Welcome to the quest Sam!" << endl;
        break;
    }

    case 3:
    {
        player = new Player;
        player->setPlayerName("Legolas Greenleaf the Elf Prince");
        cout << "Welcome to the quest Legolas!" << endl;
        break;
    }

    case 4:
    {
        player = new Player;
        player->setPlayerName("Gimli son of Gloin");
        cout << "Welcome to the quest Gimli!" << endl;
        break;
    }

    case 5:
    {
        player = new Player;
        player->setPlayerName("Gandalf the Grey");
        cout << "Welcome to the quest Gandalf!" << endl;
        break;
    }
    }
}

bool Game::runAdventure()
{

    bool status = false; // reset status

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = shireSpace->event();
        stepCount++;
        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }

        if (status)
        {
            updatePouch(1);
        }
    };

    status = false; //reset status
    currentSpace = currentSpace->getPointer("top");

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = currentSpace->event();
        stepCount++;

        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }

        if (status)
        {
            updatePouch(2);
        }
    };

    status = false; //reset status
    currentSpace = currentSpace->getPointer("top");

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = currentSpace->event();
        stepCount++;

        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }

        if (status)
        {
            updatePouch(3);
        }
    };

    status = false; //reset status
    currentSpace = currentSpace->getPointer("top");

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = currentSpace->event();
        stepCount++;

        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }

        if (status)
        {
            updatePouch(4);
        }
    };

    status = false; //reset status
    currentSpace = currentSpace->getPointer("top");

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = currentSpace->event();
        stepCount++;

        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }

        if (status)
        {
            updatePouch(5);
        }
    };

    status = false; //reset status
    currentSpace = currentSpace->getPointer("top");

    while (!status)
    {
        cout << player->getPlayerName() << " is currently in " << currentSpace->getSpaceName() << endl;
        status = currentSpace->event();
        stepCount++;

        if (stepCount >= 10)
        {
            cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
            return false;
        }
        if (status)
        {
            updatePouch(6);
        }
    };

    if (status == false || player->getPouchCount() < 4)
    {
        cout << "You are too late, Middle-earth has fallen into the hands of Sauron." << endl;
        return false;
    }

    else //must win Mordor event and have 6 items in pouch
    {
        cout << "Congratulations! You have saved Middle-earth." << endl;
        return true;
    }
}

void Game::createSpaces()
{
    // Creating spaces dynamically.
    shireSpace = new Shire;
    bruinenSpace = new Bruinen;
    rivendellSpace = new Rivendell;
    rohanSpace = new Rohan;
    gondorSpace = new Gondor;
    mordorSpace = new Mordor;
    currentSpace = shireSpace;

    //linked list
    shireSpace->setPointer("top", bruinenSpace);

    bruinenSpace->setPointer("down", shireSpace);
    bruinenSpace->setPointer("top", rivendellSpace);

    rivendellSpace->setPointer("down", bruinenSpace);
    rivendellSpace->setPointer("top", rohanSpace);

    rohanSpace->setPointer("down", rivendellSpace);
    rohanSpace->setPointer("top", gondorSpace);

    gondorSpace->setPointer("down", rohanSpace);
    gondorSpace->setPointer("top", mordorSpace);

    mordorSpace->setPointer("down", gondorSpace);
}

void Game::deallocatePointers() //deallocate pointers
{
    shireSpace->setPointer("top", NULL);

    bruinenSpace->setPointer("down", NULL);
    bruinenSpace->setPointer("top", NULL);

    rivendellSpace->setPointer("down", NULL);
    rivendellSpace->setPointer("top", NULL);

    rohanSpace->setPointer("down", NULL);
    rohanSpace->setPointer("top", NULL);

    gondorSpace->setPointer("down", NULL);
    gondorSpace->setPointer("top", NULL);

    mordorSpace->setPointer("down", NULL);

    //delete currentSpace;

    delete shireSpace;
    delete bruinenSpace;
    delete rivendellSpace;
    delete rohanSpace;
    delete gondorSpace;
    delete mordorSpace;

    delete player;

    shireSpace = NULL;
    bruinenSpace = NULL;
    rivendellSpace = NULL;
    rohanSpace = NULL;
    gondorSpace = NULL;
    mordorSpace = NULL;
    currentSpace = NULL;
    player = NULL;
}

void Game::updatePouch(int space)
{
    switch (space)
    {
    case 1:
    {
        player->insertPlayerPouch("Shire's Accorn", 0);
        break;
    }

    case 2:
    {
        player->insertPlayerPouch("Pebble of Bruinen", 1);
        break;
    }

    case 3:
    {
        player->insertPlayerPouch("Lembas of Rivendell", 2);
        break;
    }

    case 4:
    {
        player->insertPlayerPouch("Stallion of Rohan", 3);
        break;
    }

    case 5:
    {
        player->insertPlayerPouch("Sword of Gondor", 4);
        break;
    }

    case 6:
    {
        player->insertPlayerPouch("Ring of Sauron", 5);
        break;
    }
    }
}