LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o simulation.o
	g++ -o simulation ../build/main.o ../build/simulation.o $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o ../build/main.o
simulation.o: simulation.cpp
	g++ -c simulation.cpp -o ../build/simulation.o
clear:
	rm ../build/*
	rm simulation
