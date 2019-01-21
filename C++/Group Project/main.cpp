/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Main function of Predator and Prey game 
*********************************************************************/

#include "world.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Function prototypes
void startMenu(int &);
int getInteger(string);

/*********************************************************************
Function: main()
Date: July 23rd, 2018
Description: Main function of the program
Parameters: None
Return: 0 upon successful completion
**********************************************************************/
int main()
{
	srand(time(NULL));

	int timeSteps;
	int userInput;
	int row = 0;
	int column = 0;
	int turn = 1;
	int minSteps = 1;
	int maxSteps = 20;

	cout << "== Welcome to Predator and Prey== " << endl;
	cout << "The length of this game is measured in time steps." << endl;
	cout << "Time steps are positive integers only\n" << endl;

	World test;
	// World test();

	do
	{
		// Get user input for number of time steps, validate input
		timeSteps = getInteger("How many time steps would you like to take in this round?");


		while (timeSteps > maxSteps || timeSteps < minSteps)
		{
			cout << "The minimum number of steps is " << minSteps << "." << endl;
			cout << "The maximum number of steps is " << maxSteps << "." << endl;
			timeSteps = getInteger("Please enter a valid integer for the number of steps in game");
		}

		test.setSteps(timeSteps);

		cout << "\n\n\n== 2D Predator Prey ==" << endl;
		test.printBoard();
		do
		{
			cout << "== Step " << turn << " ==" << endl;
			test.moveCritter();
			test.breedCritter();
			test.printBoard();
			turn++;
		} while (test.getSteps() != 0);

		cout << "Would you like to continue?" << endl;
		cout << "1. Continue" << endl;
		userInput = getInteger("2. Exit");

		while (userInput < 1 || userInput > 2)
		{
			cout << "Invalid input! Please choose from following two options" << endl;
			cout << "1. Continue" << endl;
			cout << "2. Exit" << endl;
			userInput = getInteger("Invalid input! Please choose from following two options");
		}
	} while (userInput == 1);

	return 0;
}

/*********************************************************************
Function: startMenu(int &stpes)
Date: July 23rd, 2018
Description: Prints out menu for the program
Parameters: int steps (by reference)
Return: None
**********************************************************************/
void startMenu(int &steps)
{
}

/*********************************************************************
Function: getInteger(string)
Date: July 23rd, 2018
Description: Helper function
Validates user input according for a valid integer. 
Parameters: string prompt (Prompt shown for the user)
Return: Valid integer entered by user
**********************************************************************/
int getInteger(string prompt)
{
	string line = "";
	int value;
	int digits = 0;
	bool isValid;
	cout << prompt << endl;

	do
	{
		getline(cin, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (isdigit(line[i]))
			{
				digits += 1;
			}
		}
		if (digits == line.length() && !(line.length() == 0))
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid entry. Please enter an integer." << endl;
			isValid = false;
		}
		digits = 0;
	} while (!(isValid));

	value = stoi(line);
	line = "";
	return value;
}
