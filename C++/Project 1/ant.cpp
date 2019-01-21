/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/

//Ant class cpp file

#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

Ant::Ant() //default constructor
{
    Simulation simRunning;
    rowCount = simRunning.getRowCount();
    columnCount = simRunning.getColumnCount();
    stepCount = simRunning.getStepCount();
    rowLocation = simRunning.getStartingRow();
    columnLocation = simRunning.getStartingColumn();
    orientation = 4; //no requirements noted for user input so default to Left (using 1 for Up, 2 Down, 3 Left, 4 Right)
    colour = 'W';    //space is white, # is black
}

Ant::Ant(int rowCnt, int columnCnt, int stepCnt, int startingRowCnt, int startingColumnCnt) // constructor
{
    rowCount = rowCnt;
    columnCount = columnCnt;
    stepCount = stepCnt;
    rowLocation = startingRowCnt;
    columnLocation = startingColumnCnt;
    orientation = 4; //no requirements noted for user input so default to Up (using 1 for Up, 2 Right, 3 Down, 4 Left)
    colour = 'W';    //space is white, # is black
}

void Ant::setOrientation(char direction)
{
    switch (direction)
    {
    case ('L'): //turn left 90 degrees
    {
        if (orientation == 1)
            orientation = 4; //to turn left from up
        else
            orientation -= 1;
        break;
    }

    case ('R'): //turn right 90 degrees
    {
        if (orientation == 4)
            orientation = 1; //to turn to up from left
        else
            orientation += 1;
        break;
    }
    }
}

void Ant::printOrientation(int direction)
{
    switch (direction)
    {
    case (1):
    {
        cout << "Up" << endl;
        break;
    }
    case (2):
    {
        cout << "Right" << endl;
        break;
    }
    case (3):
    {
        cout << "Down" << endl;
        break;
    }
    case (4):
    {
        cout << "Left" << endl;
        break;
    }
    }
}

void Ant::setColour(char set)
{
    if (set == 'W') //switch space to white
    {
        board[rowLocation][columnLocation] = ' ';
    }

    if (set == 'B') //switch space to black
    {
        board[rowLocation][columnLocation] = '#';
    }
}

void Ant::saveNextStepColour()
{
    if (board[rowLocation][columnLocation] == ' ')
        colour = 'W';

    if (board[rowLocation][columnLocation] == '#')
        colour = 'B';
}

void Ant::placeAnt()
{
    board[rowLocation][columnLocation] = '*'; //place ant on starting position
}

void Ant::stepForward() //move ant forward to new location
//source used to prevent memory leak when ant reach the border of the board: Canvas Project 1 Instructions
{
    if (orientation == 1) //facing up
    {
        if (rowLocation != 0)
        {
            rowLocation = rowLocation - 1;
        }

        else //when ant is at the top of the board and about to move out of the board
        {
            rowLocation = (rowCount - 1); //goes to the bottom of the board aka 'wrap-around'
        }
    }

    else if (orientation == 2) //facing right
    {
        if (columnLocation != (columnCount - 1))
        {
            columnLocation = columnLocation + 1;
        }

        else //when ant is at the right end of the board and about to move out of the board
        {
            columnLocation = 0; //goes to the left end of the board aka 'wrap-around'
        }
    }

    else if (orientation == 3) //facing down
    {
        if (rowLocation != (rowCount - 1))
        {
            rowLocation = rowLocation + 1;
        }

        else //when ant is at the bottom of the board and about to move out of the board
        {
            rowLocation = 0; //goes to the top of the board aka 'wrap-around'
        }
    }

    else if (orientation == 4) //facing left
    {
        if (columnLocation != 0)
        {
            columnLocation = columnLocation - 1;
        }

        else //when ant is at the left end of the board and about to move out of the board
        {
            columnLocation = (columnCount - 1); //goes to the rightf end of the board aka 'wrap-around'
        }
    }
}

void Ant::moveAnt()
{
    for (int count = 0; count < stepCount; count++)
    {

        /* Please disregard
        if (board[rowLocation][columnLocation] == '*') // for first step when ant is placed
        {
            setOrientation('R');                      //turn right 90 degrees
            setColour('B');                           //change the current space to black.
            stepForward();                            //change location of ant
            saveNextStepColour();                     //save next step's colour before changing it to ant *
            board[rowLocation][columnLocation] = '*'; //place ant on new position
            printBoard();                             //print board
            cout << "Step: " << stepCount << endl;
            cout << "Row: " << rowLocation << endl;
            cout << "Col: " << columnLocation << endl;
            cout << "Orientation: " << orientation << endl;
            cout << "Colour: " << colour << endl;
        }
        */
        if (colour == 'W') //step is white
        {
            setOrientation('R');                      //turn right 90 degrees
            setColour('B');                           //change the current space to black.
            stepForward();                            //change location of ant
            saveNextStepColour();                     //save next step's colour before changing it to ant *
            board[rowLocation][columnLocation] = '*'; //place ant on new position
            printBoard();                             //print board
            /*
            cout << "Step: " << count << endl;
            cout << "Row: " << rowLocation << endl;
            cout << "Col: " << columnLocation << endl;
            cout << "Orientation: " << orientation << endl;
            cout << "Colour: " << colour << endl;
            */
        }
        else if (colour == 'B') //step is black
        {
            setOrientation('L');                      //turn left 90 degrees
            setColour('W');                           //change the current space to white.
            stepForward();                            //change location of ant
            saveNextStepColour();                     //save next step's colour before changing it to ant *
            board[rowLocation][columnLocation] = '*'; //place ant on new position
            printBoard();                             //print board
            /*
            cout << "Step: " << count << endl;
            cout << "Row: " << rowLocation << endl;
            cout << "Col: " << columnLocation << endl;
            cout << "Orientation: " << orientation << endl;
            cout << "Colour: " << colour << endl;
            */
        }
    }
}

//void Ant::moveAnt ()

/*Langton’s Ant Rule

The rule of Langton’s Ant is very simple: 
the ant is placed onto the board that is filled with white spaces, and starts moving forward. 
For each step forward, the Langton’s ant will follow 2 rules:

If the ant is on a white space, turn right 90 degrees and change the space to black.
If the ant is on a black space, turn left 90 degrees and change the space to white.
After that the ant moves to the next step and continue moving forward. 
The ant will follow these rules, and continue moving around the board, until the number of steps runs out.
*/

void Ant::createBoard()
{
    cout << "Row Count: " << rowCount << endl;
    cout << "Col Count: " << columnCount << endl;
    cout << "Starting Row: " << rowLocation << endl;
    cout << "Starting Col: " << columnLocation << endl;
    cout << "Step Count: " << stepCount << endl;

    board = new char *[rowCount]; //Dynamically allocates the memory space for the board based on users input
    for (int i = 0; i < rowCount; i++)
    {
        board[i] = new char[columnCount];
    }

    for (int i = 0; i < rowCount; i++) //fill the default board with white spaces
    {
        for (int j = 0; j < columnCount; j++)
            board[i][j] = ' ';
    }
}

void Ant::printBoard() //Display the board to the user.
{
    cout << "-";
    for (int a = 0; a < columnCount; a++)
    {
        cout << "-" << a;
    }
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        cout << i << "|";
        for (int j = 0; j < columnCount; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }
    for (int b = 0; b < (columnCount + 1); b++)
    {
        cout << "--";
    }
    cout << endl;
}

void Ant::deleteBoard() //Free the dynamically allocated memory
{
    for (int i = 0; i < rowCount; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}