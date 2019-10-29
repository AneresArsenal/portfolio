/********************************************************************* 
** Author: Serena Tay
** Date: June 30, 2018
** Description: Project 1 Assignnment (Langton's Ant)
*********************************************************************/

//Menu header file

// include guard
#ifndef MENU_HPP_
#define MENU_HPP_
#include <iostream>
#include "menu.hpp"
#include "simulation.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Menu
{
  private:
    int countPlay,
        menuChoice;

  public:
    Menu (); //default constructor
    int displayMenu();
    /*When the program starts the menu should provide 2 options:
    1.Start Langtonís Ant simulation
    2.Quit
    If the user decided to quit, the program should quit. 
    Otherwise, start the Langtonís Ant simulation.*/

    int prompt(string, int, int);
    //prompt function to display instructions to user

    int getMenuChoice();
};

#endif /* MENU_HPP_ */