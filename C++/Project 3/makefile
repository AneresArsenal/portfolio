
all: 
	g++ -std=c++11 *.cpp -o FantasyCombat

debug: 
	# rm $(objects) FantasyCombat
	g++ -std=c++11 *.cpp -o FantasyCombat
	valgrind --leak-check=full --track-origins=yes ./Project3

zip: 
	zip -D Project3_Tay_Serena.zip *.cpp *.hpp *.pdf *.txt makefile

clean:
	rm *.o FantasyCombat

target: dependencies
	action