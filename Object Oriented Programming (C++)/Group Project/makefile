#********************************************************************* 
## Date: July 23rd,  2018
## Description: 162 Group Project Assignnment (2D Predator Prey)
## Group Members:
## Kukrim Choe
## Leah Gustitus
## Kyle Schuetz
## Serena Tay
## File Description: Makefile for Predator and Prey game 
##*********************************************************************/

PredatorPrey: main.o world.o doodlebug.o critter.o ant.o 
	g++ -std=c++0x -g main.o world.o doodlebug.o critter.o ant.o -o PredatorPrey

main.o: main.cpp
	g++ -std=c++0x main.cpp -c  

world.o: world.cpp
	g++ -std=c++0x world.cpp -c

doodlebug.o: doodlebug.cpp
	g++ -std=c++0x doodlebug.cpp -c

critter.o: critter.cpp
	g++ -std=c++0x critter.cpp -c

ant.o: ant.cpp
	g++ -std=c++0x ant.cpp -c 
	
# all: 
	# g++ -std=c++11 *.cpp -o PredatorPrey

debug: 
	# rm $(objects) PredatorPrey
	g++ -std=c++11 *.cpp -o PredatorPrey
	valgrind --leak-check=full --track-origins=yes ./PredatorPrey

zip: 
	zip -D CS162_Group1.zip *.cpp *.hpp *.pdf *.txt makefile

clean:
	rm *.o PredatorPrey
#end of Makefile 
