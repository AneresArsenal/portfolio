/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/

//Simulation class header file

// include guard
#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_
#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Simulation
{
  private:
    int choice,
        rowCount,
        columnCount,
        stepCount,
        startingRow,
        startingColumn;

  public:
    Simulation(); //constructor

    void runSimulation();
    /*
    After the simulation starts, the program should prompt user for all the information to run the simulation, including:

    The number of rows for the board.
    The number of columns for the board.
    The number of steps during simulation.
    The starting row of the ant.
    The starting column of the ant.
*/
    int getRowCount();
    int getColumnCount();
    int getStepCount();
    int getStartingRow();
    int getStartingColumn();
};

// sources used to call function from different class:
// https://stackoverflow.com/questions/14173217/c-calling-a-function-from-another-class and Week 6 assignment from 161

#endif /* SIMULATION_HPP_ */
