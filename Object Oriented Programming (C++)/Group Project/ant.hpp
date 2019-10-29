/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Ant class header file
*********************************************************************/ 

//Ant class header file

// include guard
#ifndef ANT_HPP_
#define ANT_HPP_
#include <iostream>
#include <string>
#include "critter.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Ant: public Critter
{
	private: 

	public: 
		Ant(); 
		~Ant(); 
		char getSpace();
		bool move(Critter***, int, int);
		bool breed(Critter ***board, int i, int j);
		bool getBred();
	
};

#endif /* ANT_HPP_ */
