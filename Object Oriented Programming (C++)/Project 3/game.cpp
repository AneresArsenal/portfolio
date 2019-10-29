/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
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

Menu programRunning;

Game::Game()
{
    srand(time(NULL));
    round = 1,
    playChoice = 0,
    characterChoice1 = 0,
    characterChoice2 = 0,
    damage1 = 0,
    damage2 = 0,
    attackRoll1 = 0,
    defenderRoll1 = 0,
    defenderArmor1 = 0,
    attackRoll2 = 0,
    defenderRoll2 = 0,
    defenderArmor2 = 0;
}
void Game::runGame()
{
    programRunning.displayMenu(); //display menu
    playChoice = programRunning.getMenuChoice();

    while (playChoice == 1)
    {
        round = 1;
        playChoice = 0,
        characterChoice1 = 0,
        characterChoice2 = 0,
        damage1 = 0,
        damage2 = 0,
        attackRoll1 = 0,
        defenderRoll1 = 0,
        defenderArmor1 = 0,
        attackRoll2 = 0,
        defenderRoll2 = 0,
        defenderArmor2 = 0;

        cout << "Player 1:" << endl;
        characterChoice1 = programRunning.promptChoice();
        createCharacter(1, characterChoice1);
        cout << "Player 2:" << endl;
        characterChoice2 = programRunning.promptChoice();
        createCharacter(2, characterChoice2);
        runRound();
        programRunning.displayMenu(); //display menu
        playChoice = programRunning.getMenuChoice();
        deallocatePointers(); //deallocate pointers
    }

    if (playChoice == 2) //quit simulation
    {
        cout << "Game ended. Thank you for playing!" << endl;
    }
}

void Game::createCharacter(int player, int characterChoice)
{
    /*
    use the following ints for all character reference in this game
    [1] for Barbarian
    [2] for Blue Man
    [3] for Harry Potter
    [4] for Medusa
    [5] for Vampire
    */
    if (characterChoice == 1)
    {
        if (player == 1)
        {
            character1 = new Barbarian;
        }
        else
        {
            character2 = new Barbarian;
        }
    }

    else if (characterChoice == 2)
    {
        if (player == 1)
        {
            character1 = new BlueMen;
        }
        else
        {
            character2 = new BlueMen;
        }
    }

    else if (characterChoice == 3)
    {
        if (player == 1)
        {
            character1 = new HarryPotter;
        }
        else
        {
            character2 = new HarryPotter;
        }
    }

    else if (characterChoice == 4)
    {
        if (player == 1)
        {
            character1 = new Medusa;
        }
        else
        {
            character2 = new Medusa;
        }
    }

    else
    {
        if (player == 1)
        {
            character1 = new Vampire;
        }
        else
        {
            character2 = new Vampire;
        }
    }
}

void Game::runRound()
{
    bool gameStatus = true;

    while (gameStatus == true)
    //while ((character1->getStrengthPoints() > 0) && (character2->getStrengthPoints() > 0)) //while both characters are still alive
    {
        //reset all status to zero after every round
        damage1 = 0,
        damage2 = 0,
        attackRoll1 = 0,
        defenderRoll1 = 0,
        defenderArmor1 = 0,
        attackRoll2 = 0,
        defenderRoll2 = 0,
        defenderArmor2 = 0;

        //Player 1 attack Player 2
        attackRoll1 = character1->getAttack();
        defenderRoll2 = character2->getDefense();
        defenderArmor2 = character2->getArmor();
        damage1 = attackRoll1 - defenderRoll2 - defenderArmor2;

        if (processDamage(damage1, 2) == false) //player 2 died
        {
            gameStatus = false;
            return; //break function
        }

        //Player 2 attack Player 1
        attackRoll2 = character2->getAttack();
        defenderRoll1 = character1->getDefense();
        defenderArmor1 = character1->getArmor();
        damage2 = attackRoll2 - defenderRoll1 - defenderArmor1;
        if (processDamage(damage2, 1) == false) //player 1 died
        {
            gameStatus = false;
            return; //break function
        }
        /*
        if (damage2 > 0) //postive damage
        {
            cout << character1->getCharacterName() << " initially had " << character1->getStrengthPoints() << " strength points." << endl;
            character1->setStrengthPoints(damage2);   //reduce defender strength points
            if (character1->getStrengthPoints() <= 0) //player 1 died
            {
                printResult(2);
                return;
            }
            else
                printResult(3);
        }

        else
        {
            printResult(4);
        }
        */
        round++;
    }
}

bool Game::processDamage(int damage, int defender)
{
    if (defender == 2)
    {
        if (damage > 0) //postive damage
        {
            cout << endl;
            cout << " Player 2 " << character2->getCharacterName() << " initially had " << character2->getStrengthPoints() << " strength points." << endl;
            character2->setStrengthPoints(damage);   //reduce defender strength points
            if (character2->getStrengthPoints() > 0) //player 2 still alive
            {
                printResult(3);
                return true;
            }
            else //player 2 died
            {
                printResult(1);
                return false;
            }
        }
        else //negative or 0 damage
        {
            printResult(3); //if Player 2 didn't die, print results for the first attack
            return true;
        }
    }

    if (defender == 1)
    {
        if (damage > 0) //postive damage
        {
            cout << endl;
            cout << " Player 1 " << character1->getCharacterName() << " initially had " << character1->getStrengthPoints() << " strength points." << endl;
            character1->setStrengthPoints(damage);   //reduce defender strength points
            if (character1->getStrengthPoints() > 0) //player 2 still alive
            {
                printResult(4);
                return true;
            }
            else //player 1 died
            {
                printResult(2);
                return false;
            }
        }
        else //negative or 0 damage
        {
            printResult(4); //if Player 2 didn't die, print results for the first attack
            return true;
        }
    }
    return true;
}

void Game::printResult(int status) //print round result
{
    cout << endl;
    cout << "Round: " << round << endl;
    /* 4 cases
    1: player 2 died
    2: player 1 died
    3: both players alive, Player 1 turn to attack
    4: both players alive, Player 2 turn to attack
    */

    switch (status)
    {
    case 1: // player 2 died
    {
        cout << " Player 1 " << character1->getCharacterName() << " attack with " << attackRoll1 << " points." << endl;
        cout << " Player 2 " << character2->getCharacterName() << " defended with " << defenderRoll2 << " points." << endl;
        cout << " Player 2 " << character2->getCharacterName() << " armour shielded attack with " << defenderArmor2 << " points." << endl;
        cout << " Player 1 " << character1->getCharacterName() << " inflicted a damage of " << damage1 << " points on " << " Player 2 " << character2->getCharacterName() << endl;
        cout << " Player 2 " << character2->getCharacterName() << " has no strength points left and died in the battle." << endl;
        cout << " Player 1 " << character1->getCharacterName() << " wins! " << endl;
        cout << endl;
        break;
    }

    case 2: // player 1 died
    {
        cout << " Player 2 " << character2->getCharacterName() << " attack with " << attackRoll2 << " points." << endl;
        cout << " Player 1 " << character1->getCharacterName() << " defended with " << defenderRoll1 << " points." << endl;
        cout << " Player 1 " << character1->getCharacterName() << " armour shielded attack with " << defenderArmor1 << " points." << endl;
        cout << " Player 2 " << character2->getCharacterName() << " inflicted a damage of " << damage2 << " points on " << " Player 1 " << character1->getCharacterName() << endl;
        cout << " Player 1 " << character1->getCharacterName() << " has no strength points left and died in the battle." << endl;
        cout << " Player 2 " << character2->getCharacterName() << " wins! " << endl;
        cout << endl;
        break;
    }

    case 3: // both alive, player 1 attacks
    {
        if (damage1 > 0 && character2->getCharacterType() == 5 && static_cast<Vampire *>(character2)->Vampire::getCharmStatus() == false)
        {
            cout << "Vampire charm power caused zero damage on himself." << endl;
        }

        else if (damage1 > 0)
        {
            cout << " Player 1 " << character1->getCharacterName() << " attack with " << attackRoll1 << " points." << endl;
            cout << " Player 2 " << character2->getCharacterName() << " defended with " << defenderRoll2 << " points." << endl;
            cout << " Player 2 " << character2->getCharacterName() << " armour shielded attack with " << defenderArmor2 << " points." << endl;
            cout << " Player 1 " << character1->getCharacterName() << " inflicted a damage of " << damage1 << " points on " << " Player 2 " << character2->getCharacterName() << endl;
            cout << " Player 2 " << character2->getCharacterName() << " has " << character2->getStrengthPoints() << " strength points left " << endl;
        }
        else
        {
            cout << " Player 1 " << character1->getCharacterName() << " attack with " << attackRoll1 << " points." << endl;
            cout << " Player 2 " << character2->getCharacterName() << " defended with " << defenderRoll2 << " points." << endl;
            cout << " Player 2 " << character2->getCharacterName() << " armour shielded attack with " << defenderArmor2 << " points." << endl;
            cout << "No damage was inflicted." << endl;
        }
        cout << endl;
        break;
    }

    case 4: // both alive, player 2 attacks
    {
        if (damage2 > 0 && character1->getCharacterType() == 5 && static_cast<Vampire *>(character1)->Vampire::getCharmStatus() == false)
        {
            cout << "Vampire charm power caused zero damage on himself." << endl;
        }

        else if (damage2 > 0)
        {
            cout << " Player 2 " << character2->getCharacterName() << " attack with " << attackRoll2 << " points." << endl;
            cout << " Player 1 " << character1->getCharacterName() << " defended with " << defenderRoll1 << " points." << endl;
            cout << " Player 1 " << character1->getCharacterName() << " armour shielded attack with " << defenderArmor1 << " points." << endl;
            cout << " Player 2 " << character2->getCharacterName() << " inflicted a damage of " << damage2 << " points on " << " Player 1 " << character1->getCharacterName() << endl;
            cout << " Player 1 " << character1->getCharacterName() << " has " << character1->getStrengthPoints() << " strength points left " << endl;
        }
        else
        {
            cout << " Player 2 " << character2->getCharacterName() << " attack with " << attackRoll2 << " points." << endl;
            cout << " Player 1 " << character1->getCharacterName() << " defended with " << defenderRoll1 << " points." << endl;
            cout << " Player 1 " << character1->getCharacterName() << " armour shielded attack with " << defenderArmor1 << " points." << endl;
            cout << "No damage was inflicted." << endl;
        }
        cout << endl;
        break;
    }
    }
}

void Game::deallocatePointers() //deallocate pointers
{
    delete character1;
    delete character2;
}