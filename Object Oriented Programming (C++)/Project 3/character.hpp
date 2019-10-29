/********************************************************************* 
** Author: Serena Tay
** Date: August 5, 2018
** Description: Project 3 Assignnment (Fantasy Combat Game)
** Character class hpp file
*********************************************************************/

// include guard
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>

using std::string;

class Character
{
protected:
  int characterType,
      attack,
      defense,
      armor,
      strengthPoints,
      attackDieSides,
      defenseDieSides;
      string characterName;

public:
  Character();
  int getCharacterType ();
  string getCharacterName();
  virtual int getAttack()=0; //virtual function
  virtual int getDefense(); 
  virtual int getArmor();
  virtual int getStrengthPoints();
  virtual void setStrengthPoints(int);
};

#endif