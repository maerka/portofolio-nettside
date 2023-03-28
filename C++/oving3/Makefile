
all:
	g++ -o utilities.o -c utilities.cpp
	g++ -o cannonball.o -c cannonball.cpp
	g++ -o main.prog utilities.o cannonball.o main.cpp

clean:
	rm -f *.o
	rm -f main.prog
run: all
	./main.prog
