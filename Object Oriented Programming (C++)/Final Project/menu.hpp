/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Menu class hpp file
*********************************************************************/

// include guard
#ifndef MENU_HPP_
#define MENU_HPP_
#include <iostream>



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
  Menu(); //default constructor
  int displayMenu();
  /*When the program starts the menu should provide 2 options:
    1.Start game
    2.Exit game
    If the user decided to quit, the program should quit. 
    Otherwise, start the game.*/

  int prompt(string, int, int);
  //prompt function to display instructions to user
};

#endif /* MENU_HPP_ */