#ifndef SIMULATION
#define SIMULATION

#include <SFML/Graphics.hpp>
#include "body.h"

class Simulation {
private:
  sf::Event event;
  sf::RenderWindow* window;
  Body body;
public:
  static const int WINDOW_WIDTH = 2000;
  static const int WINDOW_HEIGHT = 1500;
  Simulation();
  void update();
  void draw();
  bool isOpen();
};
#endif
