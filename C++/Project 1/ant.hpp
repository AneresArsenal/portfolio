/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/ 

//Ant class header file

// include guard
#ifndef ANT_HPP_
#define ANT_HPP_
#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*Ant Class

The Ant class to contain the following member variables:
1. The ant’s location
2. The ant’s orientation (the direction of the ant)
3. How do you keep track of the color of the board’s spaces? How about the ant’s orientation?

How about class functions? 
Make sure only the class function can modify the variables of Ant class, 
which means outside program cannot directly change the variables inside the Ant class, 
and instead should call the functions inside Ant class to indirectly modify variables. 
You can determine whether you need to have a separate board class and how you should design it.
*/

class Ant
{
    private:
    int rowCount,
        columnCount,
        stepCount,
        rowLocation,
        columnLocation,
        orientation;
    char    colour;
    char** board;

    public:
    Ant(); 
    Ant(int rowCnt, int columnCnt, int stepCnt, int startingRowCnt, int startingColumnCnt);

    void setOrientation (char);
    void printOrientation(int);

    void setColour (char);
    void saveNextStepColour ();

    void placeAnt ();
    void stepForward();
    void moveAnt ();

    void createBoard ();
    //to create a 2D array for the board
    void printBoard ();
    //to print a 2D array for the board
    void deleteBoard ();

};


#endif /* ANT_HPP_ */