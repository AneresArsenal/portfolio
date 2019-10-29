/********************************************************************* 
** Author: Serena Tay
** Date: August 12, 2018
** Description: Final Project Assignnment
** Space class hpp file
*********************************************************************/

// include guard
#ifndef SPACE_HPP_
#define SPACE_HPP_
#include <iostream>
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;



class Space 
{
protected:
  Space *top;
  Space *down;
  Space *left;
  Space *right;
  string spaceName;
  bool  playerPresent; //to detect if player is present

public:
  Space();
  virtual bool event() = 0; //virtual function for an event that occur in every derived class
  string getSpaceName();
  //bool getPlayerPresent ();
  void setPointer (string, Space*);
  Space* getPointer(string);
};

#endif /* SPACE_HPP_ */