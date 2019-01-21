/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Doodlebug class header file
*********************************************************************/ 

#ifndef DOODLEBUG_HPP_
#define DOODLEBUG_HPP_
#include "critter.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

class Doodlebug: public Critter
{
	private: 
		int starveDay; //Number of days starved

	public: 
		Doodlebug(); 
		~Doodlebug(); 
		char getSpace(); 	
		bool move(Critter***, int, int);
		bool breed(Critter ***board, int i, int j);
		bool eat (Critter ***board, int i, int j);
		bool antCheck (Critter ***board, int i, int j);
		bool getBred();
		int getStarveDay();
		void addStarveDay();
		void resetStarveDay();
};

#endif /* DOODLEBUG_HPP_ */
