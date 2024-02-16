LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o simulation.o body.o randomizer.o
	g++ -o simulation ../build/main.o ../build/simulation.o ../build/body.o ../build/randomizer.o $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o ../build/main.o
simulation.o: simulation.cpp
	g++ -c simulation.cpp -o ../build/simulation.o
body.o: body.cpp
	g++ -c body.cpp -o ../build/body.o
randomizer.o: randomizer.cpp
	g++ -c randomizer.cpp -o ../build/randomizer.o
clear:
	rm ../build/*
	rm simulation
