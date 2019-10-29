/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Critter class implementation file
*********************************************************************/
#include "critter.hpp"

/*******************************************************************
Function: Critter()
Date: July 23rd, 2018
Description: Default constructor for Critter.
Parameters: None
Return: None
*******************************************************************/
Critter::Critter()
{
	onSpace = ' ';
	// onSpace = '_'; //For testing purposes
	moveCheck = false;
	stepCount = 0;
}

/*******************************************************************
Function: ~Critter()
Date: July 23rd, 2018
Description: Destructor for Critter.
Parameters: None
Return: None
*******************************************************************/
Critter::~Critter()
{
}

/*******************************************************************
Function: increaseSteps()
Date: July 27th, 2018
Description: Increases the number of steps
Parameters: None
Return: None
*******************************************************************/
void Critter::increaseSteps()
{
	stepCount += 1;
}

/*******************************************************************
Function: getSpace()
Date: July 23rd, 2018
Description: Gets the character of Critter. 
Parameters: None
Return: 
char of Critter located on the location this function is called
'X' for doodlebugs
'O' for ants
*******************************************************************/
char Critter::getSpace()
{
	return onSpace;
}

/*******************************************************************
Function: move()
Date: July 23rd, 2018
Description: Increases the number of steps
This is a virtual function modified by inherited class
Parameters: None
Return: boolean
Returns false by default
*******************************************************************/
bool Critter::move(Critter ***, int, int)
{
	return false;
}

/*******************************************************************
Function: breed()
Date: July 24th, 2018
Description: Adds an object of Critter 
This is a virtual function modified by inherited class
Parameters: None
Return: boolean
Returns false by default. 
*******************************************************************/
bool Critter::breed(Critter***, int, int)
{
	return false;
}

/*******************************************************************
Function: getStepCount()
Date: July 24th, 2018
Description: Gets number of steps taken by Critter.
Parameters: None
Return: Number of steps taken by Critter (int).
*******************************************************************/
int Critter::getStepCount()
{
	return stepCount;
}

/*******************************************************************
Function: checkMoveCheck()
Date: July 26, 2018
Description: Gets the value of the variable moveCheck.
Parameters: None
Return: Boolean value of moveCheck.
*******************************************************************/
bool Critter::checkMoveCheck()
{
	return moveCheck;
}

/*******************************************************************
Function: setMoveCheck()
Date: July 26, 2018
Description: Sets bool moveCheck to true.
Parameters: None
Return: None.
*******************************************************************/
void Critter::setMoveCheck()
{
	moveCheck = true;
}

/*******************************************************************
Function: resetMoveCheck()
Date: July 26, 2018
Description: Sets bool moveCheck to false (default).
Parameters: None
Return: None.
 *******************************************************************/
void Critter::resetMoveCheck()
{
	moveCheck = false;
}

/*******************************************************************
Function: getBred()
Date: July 28, 2018
Description: Gets bool 'bred'
Parameters: None
Return: Boolean
Returns boolean value of variable bred.
 *******************************************************************/
bool Critter::getBred()
{
	return bred;
}
