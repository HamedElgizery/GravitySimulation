LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o
	g++ -o simulation ../build/main.o $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o ../build/main.o
clear:
	rm ../build/*
	rm simulation
