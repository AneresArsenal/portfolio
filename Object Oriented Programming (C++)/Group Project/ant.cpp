/********************************************************************* 
** Date: July 23rd, 2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Ant class implementation file
*********************************************************************/

//#include "menu.hpp"
//#include "simulation.hpp"
#include "ant.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

/*********************************************************************
Function: Ant()
Date: July 23rd, 2018
Description: Default constructor for Ant class
Parameters: None
Return: A new Ant class
**********************************************************************/

Ant::Ant()
{
	onSpace = 'O';
}

/*********************************************************************
Function: ~Ant()
Date: July 23rd, 2018
Description: Destructor for Ant class
Parameters: None
Return: None
**********************************************************************/
Ant::~Ant()
{
}

/*********************************************************************
Function getSpace()
Date: July 23rd, 2018
Description: Gets the character on the space ('O')
Parameters: None
Return: Character of the object ('O')
**********************************************************************/
char Ant::getSpace()
{
	return onSpace;
}

/*********************************************************************
Function move(Critter***, int, int)
Date: July 23rd, 2018
Description:
Ant checks to see if any neighboring cell is occupied, if so they stay put
Ant checks to see if a neighboring cell is an edge of the grid
If so, they make sure not to move there
Parameters: 
Critter ***board: Pointer to an object 
int i: Row location of current object 
int j: Column location of current object
Return: Boolean
Returns true if moved successfully
Returns false if did not move
**********************************************************************/
bool Ant::move(Critter ***board, int i, int j)
{
	bool moved = false;
	int result = (rand() % 4) + 1;
	// cout << result << endl;
	switch (result)
	{
	case 1: //up
	{
		if (i > 0 && (board[i - 1][j]->getSpace() == ' '))
		{
			//cout << "row: " << i << " column: " << j << " expected to move up" << endl;
			//cout << "current # of steps:" << stepCount << endl;
			delete board[i - 1][j];
			board[i - 1][j] = board[i][j];
			// delete board[i][j];
			board[i][j] = new Critter;
			moved = true;
			board[i - 1][j]->increaseSteps();
			// cout << "updated # of steps:" << stepCount << endl;
			board[i - 1][j]->setMoveCheck();
			board[i][j]->setMoveCheck();
			break;
		}
	}
	case 2: //right
	{
		if (j < 19 && (board[i][j + 1]->getSpace() == ' '))
		{
			//cout << "row: " << i << " column: " << j << " expected to move to right" << endl;
			delete board[i][j + 1];
			board[i][j + 1] = board[i][j];
			// delete board[i][j];
			board[i][j] = new Critter;
			moved = true;
			board[i][j + 1]->increaseSteps();
			board[i][j + 1]->setMoveCheck();
			board[i][j]->setMoveCheck();
			break;
		}
	}

	case 3: // down
	{
		if (i < 19 && (board[i + 1][j]->getSpace() == ' '))
		{
			//cout << "row: " << i << " column: " << j << " expected to move down" << endl;
			delete board[i + 1][j];
			board[i + 1][j] = board[i][j];
			// delete board[i][j];
			board[i][j] = new Critter;
			moved = true;
			board[i + 1][j]->increaseSteps();
			board[i + 1][j]->setMoveCheck();
			board[i][j]->setMoveCheck();
			break;
		}
	}

	case 4: //left
	{
		if (j > 0 && (board[i][j - 1]->getSpace() == ' '))
		{
			//cout << "row: " << i << " column: " << j << " expected to move to left" << endl;
			delete board[i][j - 1];
			board[i][j - 1] = board[i][j];
			// delete board[i][j];
			board[i][j] = new Critter;
			moved = true;
			board[i][j - 1]->increaseSteps();
			board[i][j - 1]->setMoveCheck();
			board[i][j]->setMoveCheck();
			break;
		}
	}
	
	default:
	{
		board[i][j]->increaseSteps();
	}
	}
	return moved;
}
/*********************************************************************
Function breed(Critter ***, int, int)
Date: July 23rd, 2018
Description: Generate extra ant object (breed) on an adjacent cell if 
it is empty
Parameters: 
Critter ***board: Pointer to an object 
int i: Row location of current object 
int j: Column location of current object
Return: Boolean
Returns true if bred successfully
Returns false if did not breed
**********************************************************************/
bool Ant::breed(Critter ***board, int i, int j)
{
	bred = false;
	if (stepCount >= 3)
	{
		if (stepCount % 3 == 0)
		{
			int result = (rand() % 4) + 1;
			// cout << result << endl;
			switch (result)
			{
				case 1: //up
				{
					if (i > 0 && (board[i - 1][j]->getSpace() == ' '))
					{
						// cout << "row: " << i << " column: " << j << " expected to breed to up" << endl;
						delete board[i - 1][j];
						board[i - 1][j] = new Ant;
						bred = true;
						break;
					}
				}
				case 2: //right
				{
					if (j < 19 && (board[i][j + 1]->getSpace() == ' '))
					{
						// cout << "row: " << i << " column: " << j << " expected to breed to right" << endl;
						delete board[i][j + 1];
						board[i][j + 1] = new Ant;
						bred = true;
						break;
					}
				}

				case 3: // down
				{
					if (i < 19 && (board[i + 1][j]->getSpace() == ' '))
					{
						// cout << "row: " << i << " column: " << j << " expected to breed down" << endl;
						delete board[i + 1][j];
						board[i + 1][j] = new Ant;
						bred = true;
						break;
					}
				}

				case 4: //left
				{
					if (j > 0 && (board[i][j - 1]->getSpace() == ' '))
					{
						// cout << "row: " << i << " column: " << j << " expected to breed to left" << endl;
						delete board[i][j - 1];
						board[i][j - 1] = new Ant;
						bred = true;
						break;
					}
				}
			}
		}
	}
	return bred;
}

/*******************************************************************
Function: getBred()
Date: July 28, 2018
Description: Gets bool 'bred'
Parameters: None
Return: Boolean
Returns boolean value of variable bred.
 *******************************************************************/
bool Ant::getBred()
{
	return bred;
}
