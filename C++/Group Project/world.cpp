/*********************************************************************
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: World class implementation file 
*********************************************************************/

#include "world.hpp"

/*********************************************************************
Function: World()
Date: July 23th, 2018
Description: Default constructor for class World
Parameters: None
Return: Creates a new World class
*********************************************************************/
World::World()
{
	// Initalize World class variables
	rowCount = 20;
	columnCount = 20;
	numAnts = 100;
	numDoodlebugs = 5;

	// Create board of critter array
	board = new Critter **[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		board[i] = new Critter *[columnCount];
	}

	// Fill board with critter objects
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			board[i][j] = new Critter;
		}
	}

	//Fill board with ants
	while (numAnts > 0)
	{
		row = (rand() % rowCount);
		col = (rand() % columnCount);
		// Only able to place if spot is empty on the board
		if (board[row][col]->getSpace() == ' ')
		{
			delete board[row][col];
			board[row][col] = new Ant;
			numAnts--;
		}
	}

	while (numDoodlebugs > 0)
	{
		// Put doodlebugs on board randomly
		row = (rand() % rowCount);
		col = (rand() % columnCount);

		// Only able to place if spot is empty on the board
		if (board[row][col]->getSpace() == ' ')
		{
			delete board[row][col];
			board[row][col] = new Doodlebug;
			numDoodlebugs--;
		}
	}
	
	//Count ants and doodlebugs on board
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			// cout << board[i][j] -> getSpace() << endl;
			if (board[i][j]->getSpace() == 'O')
			{
				numAnts++;
			}
			if (board[i][j]->getSpace() == 'X')
			{
				numDoodlebugs++;
			}

		}
	}

	cout << "Number of Ants currently on board: " << numAnts << endl;
	cout << "Number of Doodlebugs currently on board: " << numDoodlebugs << endl;
}

/*********************************************************************
Function: ~World()
Date: July 23th, 2018
Description: Destructor for class World
Parameters: None
Return: None
*********************************************************************/
World::~World()
{
	//Delete Critter Array
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			delete board[i][j];
		}
		delete[] board[i];
	}
	delete[] board;
}

/*********************************************************************
Function: setSteps(int s)
Date: July 23th, 2018
Description: Sets number of steps for the world
Parameters: int s - Number of steps designated by user
Return: None
*********************************************************************/
void World::setSteps(int s)
{
	timeSteps = s;
}

/*********************************************************************
Function: getSteps()
Date: July 23th, 2018
Description: Gets current number of steps taken
Parameters: None
Return: Integer value of step counts
*********************************************************************/
int World::getSteps()
{
	return timeSteps;
}

/*********************************************************************
Function: printBoard()
Date: July 23th, 2018
Description: Prints the board
Parameters: None
Return: None
*********************************************************************/
void World::printBoard()
{
	//Simple version
	// srand(time(0));

	// for (int i = 0; i < rowCount; i++)
	// {
	// 	for (int j = 0; j < columnCount; j++)
	// 	{
	// 		cout << board[i][j]->getSpace();
	// 	}
	// 	cout << endl;
	// }

	cout << endl;

	//Beautified Version (Comment out the simple version above and uncomment below codes)
	srand(time(0));
	// print critter board
	// cout << "--";

	// Upper bound
	cout << "  ";
	for (int i = 0; i < (columnCount); i++)
	{
		cout << " " << std::setw(2) << i;
		// cout << "---";
	}
	cout << endl;

	for (int i = 0; i < rowCount; i++)
	{
		// Left boundary
		cout << std::setw(2) << i << "  "; //Numeric version
		// cout << "| "; //boundary
		for (int j = 0; j < columnCount; j++)
		{
			// cout << board[i][j]->getSpace();
			// Add space between columns for better visual
			cout << board[i][j]->getSpace() << "  ";
		}
		// Right Boundary
		cout << std::setw(2) << i << "  "; //Numeric version
		// cout << "|"; //boundary
		cout << endl;
	}

	// Lower boundary
	// cout << "--"; //boundary
	cout << "   "; //Numeric version
	for (int i = 0; i < (columnCount); i++)
	{
		cout << std::setw(2) << i << " "; //Numeric version
		// cout << "---"; //boundary
	}
	cout << endl;
}

/*********************************************************************
Function: moveCritter()
Date: July 23th, 2018
Description: Move critters on board
Parameters: None
Return: None
*********************************************************************/
void World::moveCritter()
{
	numAnts = 0;
	numDoodlebugs = 0;

	//Move Doodlebug
	// cout << "Moving doodlebugs" << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			if (board[i][j]->getSpace() == 'X')
			{
				if (!board[i][j]->checkMoveCheck())
				{
					board[i][j]->move(board, i, j);
				}
			}
		}
	}

	// cout << "Moving ants" << endl;
	//Move ant
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			// cout << board[i][j] -> getSpace() << endl;
			if (board[i][j]->getSpace() == 'O')
			{
				if (!board[i][j]->checkMoveCheck())
				{
					board[i][j]->move(board, i, j);
				}
			}
		}
	}

	//Reset all moveChecks to false
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			board[i][j]->resetMoveCheck();
		}
	}
	timeSteps -= 1;

	//Count ants and doodlebugs on board
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			// cout << board[i][j] -> getSpace() << endl;
			if (board[i][j]->getSpace() == 'O')
			{
				numAnts++;
			}
			if (board[i][j]->getSpace() == 'X')
			{
				numDoodlebugs++;
			}

		}
	}
	cout << "After move: " << endl;
	cout << "Number of Ants: " << numAnts << endl;
	cout << "Number of Doodlebugs: " << numDoodlebugs << "\n" << endl;
}

/*********************************************************************
Function: breedCritter()
Date: July 27th, 2018
Description: Breed critters on board
Breeds only if there is an empty space on an adjacent cell(up, down, left right). 
Parameters: None
Return: None
*********************************************************************/
void World::breedCritter()
{
	numAnts = 0;
	numDoodlebugs = 0;

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			//breed ant	
			if (board[i][j]->getSpace() == 'O' && spaceAvail(board, i, j))
			{
				if (board[i][j]->getStepCount() % 3 == 0)
				{
					do
					{
						board[i][j]->breed(board, i, j);
					} while(!(board[i][j]->getBred()) && board[i][j]->getStepCount()!= 0);
				}
			}
			//breed doodlebug
			else if (board[i][j]->getSpace() == 'X' && spaceAvail(board, i, j))
			{
				if (board[i][j]->getStepCount() % 8 == 0)
				{
					do
					{
						board[i][j]->breed(board, i, j);
					} while(!(board[i][j]->getBred()) && board[i][j]->getStepCount()!= 0);
				}
			}
		}
	}

	//Count ants and doodlebugs on board
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			// cout << board[i][j] -> getSpace() << endl;
			if (board[i][j]->getSpace() == 'O')
			{
				numAnts++;
			}
			if (board[i][j]->getSpace() == 'X')
			{
				numDoodlebugs++;
			}

		}
	}
	cout << "After breeding: " << endl;
	cout << "Number of Ants: " << numAnts << endl;
	cout << "Number of Doodlebugs: " << numDoodlebugs << "\n" << endl;
}

/*********************************************************************
Function: spaceAvail()
Date: July 27th, 2018
Description: Checks if space is available for breading
Parameters: 
Critter ***board: Pointer to Critter object on board
int i = Row number passed in
int j = Column number passed in
Return: Boolean
True if a space is available for breeding
False if there is no space available for breeding
*********************************************************************/
bool World::spaceAvail(Critter ***board, int i, int j)
{
	bool available = false;

	if ((i > 0 && (board[i - 1][j]->getSpace() == ' ')) || (j < 19 && (board[i][j + 1]->getSpace() == ' ')) || (i < 19 && (board[i + 1][j]->getSpace() == ' ')) || (j > 0 && (board[i][j - 1]->getSpace() == ' ')))
	{
		available = true;
	}

	return available;
}