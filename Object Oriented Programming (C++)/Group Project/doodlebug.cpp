/*********************************************************************
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Critter class header file
*********************************************************************/

#include "doodlebug.hpp"

/*************************************************************************
Function: Doodlebug()
Date: July 23rd,  2018
Description: Default constructor for Doodlebug
Parameters: None
Return: None
**************************************************************************/
Doodlebug::Doodlebug()
{
	onSpace = 'X';
	starveDay = 0;
}

/*************************************************************************
Function: ~Doodlebug()
Date: July 23rd,  2018
Description: Destructor for Doodlebug
Parameters: None
Return: None
**************************************************************************/
Doodlebug::~Doodlebug()
{
}

/*************************************************************************
Function: getSpace()
Date: July 23rd,  2018
Description: Get current space's character
Parameters: None
Return: Character for the space. 'o' for ant, 'x' for doodlebug
**************************************************************************/
char Doodlebug::getSpace()
{
	return onSpace;
}

/*************************************************************************
Function: move(Critter***, int, int)
Date: July 24th, 2018
Description: Regular move for doodlebug.
If there are no ants in adjacent spaces, the doodlebug moves randomly to an empty space
Parameters: 
Pointer to the board (Critter ***), 
Integer for row number, 
Integer for column number
Return: Boolean
True if critter has moved
False if critter has not moved
**************************************************************************/
bool Doodlebug::move(Critter ***board, int i, int j)
{
	bool moved = false;
	bool ate = false;
	int selection = (rand() % 4) + 1;

	//Eat&move
	if (antCheck(board, i, j))
	{
		if (i > 0 && (board[i - 1][j]->getSpace() == 'O'))
		{
			// cout << "row: " << i << " column: " << j << " saw an ant above" << endl;
			selection = 1;
		}
		else if (j < 19 && (board[i][j + 1]->getSpace() == 'O'))
		{
			// cout << "row: " << i << " column: " << j << " saw an ant on right" << endl;
			selection = 2;
		}
		else if (i < 19 && (board[i + 1][j]->getSpace() == 'O'))
		{
			// cout << "row: " << i << " column: " << j << " saw an and below" << endl;
			selection = 3;
		}
		else if (j > 0 && (board[i][j - 1]->getSpace() == 'O'))
		{
			// cout << "row: " << i << " column: " << j << " saw an ant on left" << endl;
			selection = 4;
		}
		//Reset starve day to 0
		ate = true;
	}

	//Reset starveDay to 0 if Doodlebug ate an ant
	if (ate)
	{
		starveDay = 0;
	}
	else
	{
		starveDay++;

		//If moved without eating for 3 time steps, doodlebug dies
		if (starveDay == 3)
		{
			delete board[i][j];
			board[i][j] = new Critter;
			selection = 0;
		}
	}
	
	switch (selection)
	{
		case 1: //up
		{
			if (i > 0 && (board[i - 1][j]->getSpace() == ' ' || board[i - 1][j]->getSpace() == 'O'))
			{
				// cout << "row: " << i << " column: " << j << " expected to move up" << endl;
				// cout << "current # of steps:" << stepCount << endl;
				delete board[i - 1][j];
				board[i - 1][j] = board[i][j];
				board[i][j] = new Critter;
				moved = true;
				board[i - 1][j]->increaseSteps();
				// cout << "Doodlebug updated # of steps:" << stepCount << endl;
				board[i - 1][j]->setMoveCheck();
				board[i][j]->setMoveCheck();
				break;
			}
		}
		case 2: //right
		{
			if (j < 19 && (board[i][j + 1]->getSpace() == ' ' || board[i][j+1]->getSpace() == 'O'))
			{
				// cout << "row: " << i << " column: " << j << " expected to move to right" << endl;
				delete board[i][j + 1];
				board[i][j + 1] = board[i][j];
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
			if (i < 19 && (board[i + 1][j]->getSpace() == ' ' || board[i + 1][j]->getSpace() == 'O'))
			{
				// cout << "row: " << i << " column: " << j << " expected to move down" << endl;
				delete board[i + 1][j];
				board[i + 1][j] = board[i][j];
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
			if (j > 0 && (board[i][j - 1]->getSpace() == ' ' || board[i][j-1]->getSpace() == 'O'))
			{
				// cout << "row: " << i << " column: " << j << " expected to move to left" << endl;
				delete board[i][j - 1];
				board[i][j - 1] = board[i][j];
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
			cout << "Doodlebug starved to death on row: " << i << ", column: " << j << endl;
		}
	}

	return moved;
}

/*************************************************************************
Function: antCheck(Critter***, int, int)
Date: July 24th, 2018
Description: 
Doodlebug checks if any ants are adjacent to eat them, if so moves to eat one
Parameters: 
Pointer to the board (Critter ***), 
Integer for current row number, 
Integer for current column number
Return: Boolean
True if ant is found
False if ant is not found
**************************************************************************/
bool Doodlebug::antCheck(Critter ***board, int i, int j)
{
	bool antLocated = false;

	if ((i > 0 && (board[i - 1][j]->getSpace() == 'O')) || (j < 19 && (board[i][j + 1]->getSpace() == 'O')) || (i < 19 && (board[i + 1][j]->getSpace() == 'O')) || (j > 0 && (board[i][j - 1]->getSpace() == 'O')))
	{
		antLocated = true;
	}

	return antLocated;
}

/*************************************************************************
Function: breed()
Date: July 27th, 2018
Description: Breed a doodlebug after 8 steps
Parameters: 
Pointer to the board (Critter ***), 
Integer for current row number, 
Integer for current column number
Return: Boolean
True if doodlebug bred
False if doodlebug has not bred
**************************************************************************/
bool Doodlebug::breed(Critter ***board, int i, int j)
{
	bred = false;
	//cout << "This is the Doodlebug breeding" << endl;
	if (stepCount >= 8)
	{
		if (stepCount % 8 == 0)
		{
			cout << "Breeding doodlebug" << endl;
			int result = (rand() % 4) + 1;

			switch (result)
			{
				case 1: //up
				{
					if (i > 0 && (board[i - 1][j]->getSpace() == ' '))
					{
						// cout << "row: " << i << " column: " << j << " expected to breed to up" << endl;
						delete board[i - 1][j];
						board[i - 1][j] = new Doodlebug;
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
						board[i][j + 1] = new Doodlebug;
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
						board[i + 1][j] = new Doodlebug;
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
						board[i][j - 1] = new Doodlebug;
						bred = true;
						break;
					}
				}
			}
		}
	}
	return bred;
}

/*************************************************************************
Function: getStarveDay()
Date: July 24th, 2018
Description: Get number of days starved
Parameters: None
Return: Number of days starved by doodlebug
**************************************************************************/
int Doodlebug::getStarveDay()
{
	return starveDay;
}

/*************************************************************************
Function: addStarveDay()
Date: July 27th,  2018
Description: Add 1 to starved days variable 'starveDay'
Parameters: None
Return: None
**************************************************************************/
void Doodlebug::addStarveDay()
{
	starveDay++;
}

/*************************************************************************
Function: resetStarveDay()
Date: July 27th,  2018
Description: Reset starveDay to 0
Parameters: None
Return: None
**************************************************************************/
void Doodlebug::resetStarveDay()
{
	starveDay = 0;
}

/*******************************************************************
Function: getBred()
Date: July 28, 2018
Description: Gets bool 'bred'
Parameters: None
Return: Boolean
Returns boolean value of variable bred.
 *******************************************************************/
bool Doodlebug::getBred()
{
	return bred;
}