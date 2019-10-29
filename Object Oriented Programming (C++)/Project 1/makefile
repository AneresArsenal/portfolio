
output: main.o ant.o menu.o simulation.o
	g++ -g main.o ant.o menu.o simulation.o -o main

main.o: main.cpp
	g++ -g -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -g -c ant.cpp

menu.o: menu.cpp menu.hpp
	g++ -g -c menu.cpp

simulation.o: simulation.cpp simulation.hpp
	g++ -g -c simulation.cpp

clean:
	rm *.o main

target: dependencies
	action