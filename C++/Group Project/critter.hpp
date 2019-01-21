/********************************************************************* 
** Date: July 23rd,  2018
** Description: 162 Group Project Assignnment (2D Predator Prey)
** Group Members:
** Kukrim Choe
** Leah Gustitus
** Kyle Schuetz
** Serena Tay
** File Description: Critter class header file
*********************************************************************/

#ifndef CRITTER_HPP_
#define CRITTER_HPP_
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Critter
{

	protected:
		int stepsToBreed; //Steps needed to breed
		int stepCount; //Number of steps taken by critter
        bool moveCheck; //Boolean used to check if the object has been moved during current turn
		char onSpace;  	
		bool bred;
		
	public:
		Critter();
		~Critter();  

		//Move function for critter class. 
		virtual bool move(Critter***, int, int);
		virtual bool breed(Critter***, int, int);
		
		//Getter functions
		virtual char getSpace();
		virtual int getStepCount();
		virtual bool getBred();
    
		//Helper functions
		void increaseSteps();
        virtual bool checkMoveCheck();
        virtual void setMoveCheck();
        virtual void resetMoveCheck();
};

#endif /* CRITTER_HPP_ */
