/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: World class header file
*********************************************************************/

// include guard
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "ant.hpp"
#include "doodlebug.hpp"

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class World
{
	private:
		int row;
		int col;
		int rowCount;
		int columnCount;
		int numAnts; 
		int numDoodlebugs; 	
		int timeSteps; //Total number of time steps taken
		Critter ***board = nullptr; 
	
	public:
		World();
		~World();  
		void setSteps(int); 
		int getSteps(); 	
    	void printBoard();
		void moveCritter();
		void breedCritter();
		bool checkAdjacentDoodlebug(int, int);
		bool spaceAvail(Critter ***board, int i, int j);
};

#endif /* WORLD_HPP_ */
