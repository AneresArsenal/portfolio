/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/

//Simulation class cpp file

#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

Simulation::Simulation() //constructor
{
    choice = 0;
    rowCount = 0;
    columnCount = 0;
    stepCount = 0;
    startingRow = 0;
    startingColumn = 0;
}

void Simulation::runSimulation() //start simulation
{
    Menu programRunning;
    programRunning.displayMenu(); //display menu
    choice = programRunning.getMenuChoice();

    while (choice == 1)
    {
        rowCount = programRunning.prompt("number of rows", 5, 100);
        columnCount = programRunning.prompt("number of columns", 5, 100);

        //int maxSteps = ((rowCount * columnCount) -1); //input validation to ensure steps is less that the available boxes available in the board
        /*input validation to ensure 2 conditions are met
            1. stepCount is less that the available boxes available in the board
            2. greater than 0 (at least 1 step)
        */
        stepCount = programRunning.prompt("number of steps", 1, 100);

        startingRow = programRunning.prompt("ant's starting row", 0, (rowCount - 1));
        /*input validation to ensure starting row is within the allowable range:
        1. Greater than zero
        2. Smaller than rowCount - 1
        */

        startingColumn = programRunning.prompt("ant's starting column", 0, (columnCount - 1));
        /*input validation to ensure starting row is within the allowable range:
        1. Greater than zero
        2. Smaller than columnCount - 1
        */

        Ant antCreated(rowCount, columnCount, stepCount, startingRow, startingColumn);
        antCreated.createBoard();
        antCreated.placeAnt();
        antCreated.printBoard(); //intial board
        antCreated.moveAnt();
        antCreated.deleteBoard();

        programRunning.displayMenu(); //show program when program ended
        choice = programRunning.getMenuChoice();
    }

    if (choice == 2) //quit simulation
    {
        cout << "Simulation ended. Thank you for playing!" << endl;
    }

    /*
    else if (menuChoice ==3) //random play
    */
}

//get functions to pass data into ant class
int Simulation::getRowCount()
{
    return rowCount;
}

int Simulation::getColumnCount()
{
    return columnCount;
}

int Simulation::getStepCount()
{
    return stepCount;
}

int Simulation::getStartingRow()
{
    return startingRow;
}

int Simulation::getStartingColumn()
{
    return startingColumn;
}