LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o simulation.o body.o randomizer.o
	g++ --std=c++11 -o simulation ../build/main.o ../build/simulation.o ../build/body.o ../build/randomizer.o $(LIBS)

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o ../build/main.o
simulation.o: simulation.cpp
	g++ -std=c++11 -c simulation.cpp -o ../build/simulation.o
body.o: body.cpp
	g++ -std=c++11 -c body.cpp -o ../build/body.o
randomizer.o: randomizer.cpp
	g++ -std=c++11 -c randomizer.cpp -o ../build/randomizer.o
clear:
	rm ../build/*
	rm simulation
