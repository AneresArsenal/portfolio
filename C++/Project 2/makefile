
output: main.o menu.o game.o animal.o penguin.o tiger.o turtle.o zoo.o
	g++ -g main.o menu.o game.o animal.o penguin.o tiger.o turtle.o zoo.o -o main -std=c++11

main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

menu.o: menu.cpp menu.hpp
	g++ -g -c menu.cpp -std=c++11

game.o: game.cpp game.hpp
	g++ -g -c game.cpp -std=c++11

animal.o: animal.cpp animal.hpp
	g++ -g -c animal.cpp -std=c++11

penguin.o: penguin.cpp penguin.hpp
	g++ -g -c penguin.cpp -std=c++11

tiger.o: tiger.cpp tiger.hpp
	g++ -g -c tiger.cpp -std=c++11

turtle.o: turtle.cpp turtle.hpp
	g++ -g -c turtle.cpp -std=c++11

zoo.o: zoo.cpp zoo.hpp
	g++ -g -c zoo.cpp -std=c++11

clean:
	rm *.o main

target: dependencies
	action